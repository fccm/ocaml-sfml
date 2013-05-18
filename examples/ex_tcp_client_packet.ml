
let () =
  let host, port =
    try (Sys.argv.(1), int_of_string Sys.argv.(2))
    with _ ->
      Printf.eprintf "Usage: %s host port\n" Sys.argv.(0);
      exit 1
  in
  let socket = SFTcpSocket.create () in
  let timeout = SFTime.of_seconds 1000.0 in
  let address = SFIpAddress.fromString host in
  SFTcpSocket.connect ~socket ~port ~address ~timeout ();

  let loop = ref true in
  while !loop do
    print_endline "Fill the buffer";
    let data = read_line () in
    let p = SFPacket.create () in
    SFPacket.append p data;
    SFTcpSocket.sendPacket socket p;
    if data = "quit" then loop := false
  done;

  SFTcpSocket.destroy socket;
;;
