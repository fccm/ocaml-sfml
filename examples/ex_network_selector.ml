(* Create a client and connect it to the server *)
let do_client ~port ~server_address =
  (* the server address *)
  let address = SFIpAddress.fromString server_address in

  (* create a socket for exchanging data with the server *)
  let socket = SFTcpSocket.create () in

  (* connect to the server *)
  SFTcpSocket.connect ~socket ~port ~address
    ~timeout:(SFTime.of_seconds 4.0) ();

  (* send messages until we are disconnected *)
  let connected = ref true in
  while !connected do
    (* let the user write a message *)
    let data = "Say something to the server." in

    (* send it to the server *)
    try
      SFTcpSocket.send ~socket ~data;
      SFTime.sleep (SFTime.of_seconds 1.0);
    with _ -> connected := false
  done;

  (* close the socket *)
  SFTcpSocket.destroy socket


(* Launch a server and receive incoming messages *)
let do_server ~port =
  (* Create a socket for listening to incoming connections *)
  SFTcpListener.init ();
  let listener = SFTcpListener.create () in
  SFTcpListener.listen listener port;
  Printf.printf "Listening to port %d, waiting for connections...\n%!" port;

  (* Create a selector for handling several sockets
     (the listener + the socket associated to each client) *)
  let selector = SFSocketSelector.create () in

  (* Add the listener *)
  SFSocketSelector.addTcpListener selector listener;

  (* Loop while... we close the program :) *)
  while true do
    (* Make the selector wait for data on any socket *)
    if SFSocketSelector.wait ~selector ~timeout:(SFTime.of_seconds 8.0) () then
    begin

      (* Get the current socket *)
      if SFSocketSelector.isTcpListenerReady selector listener then
      begin
        (* If the listening socket is ready,
           it means that we can accept a new connection *)
        let client = SFTcpListener.accept listener in
        (*
        Printf.printf "Client connected ! (%s)\n%!" address;  (* TODO *)
        *)
        Printf.printf "Client connected !\n%!";

        (* Add it to the selector *)
        SFSocketSelector.addTcpSocket selector client;
      end else begin
        (* Else, it is a client socket so we can read the data he sent *)
        try
          let message = SFTcpSocket.receive_str socket in
          (* display then message *)
          Printf.printf "A client says : \"%s\"\n%!" message;
        with _ ->
          (* Error : we'd better remove the socket from the selector *)
          SFSocketSelector.TCP.remove selector socket;
      end

    end

  done


let () =
  (* Choose a random port for opening sockets (ports < 1024 are reserved) *)
  let port = 54545 in
  let server_address = "127.0.0.1" in

  (* Client or server? *)
  match Sys.argv with
  | [| _; "-server" |] -> do_server ~port
  | [| _; "-client" |] -> do_client ~port ~server_address
  | _ -> Printf.printf "usage: %s [-server|-client]\n" Sys.argv.(0)
