
let () =
  let port = 2000 in
  let server = SFIpAddress.localHost () in

  (* Create a socket for communicating with the server *)
  let socket = SFTcpSocket.create () in

  (* Connect to the server *)
  SFTcpSocket.connect socket port server ();
  print_endline ("Connected to server " ^ (SFIpAddress.toString server));

  (* Send an answer to the server *)
  let out = "Hi, I'm a client" in
  SFTcpSocket.send socket out;
  print_endline ("Message sent to the server: '" ^ out ^ "'");
;;
