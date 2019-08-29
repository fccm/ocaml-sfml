
let () =
  let port = 2000 in

  (* Create a server socket to accept new connections *)
  let listener = SFTcpListener.create () in

  (* Listen to the given port for incoming connections *)
  SFTcpListener.listen listener port;

  print_endline ("Server is listening to port " ^
      (string_of_int port) ^ ", waiting for connections... ");

  (* Wait for a connection *)
  let socket = SFTcpListener.accept listener in

  print_endline ("Client connected: " ^ (SFIpAddress.toString (
          SFTcpSocket.getRemoteAddress socket)));

  (* Send a message to the connected client *)
  let out = "Hi, I'm the server" in
  SFTcpSocket.send socket out;
  print_endline ("Message sent to the client: '" ^ out ^ "'");

  (* Receive a message back from the client *)
  let received = SFTcpSocket.receive_str socket in
  print_endline ("Answer received from the client: '" ^ received ^ "'");
;;
