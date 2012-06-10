
let () =
  let host, port =
    try (Sys.argv.(1), int_of_string Sys.argv.(2))
    with _ ->
      Printf.eprintf "Usage: %s host port\n" Sys.argv.(0);
      exit 1
  in
  let address = SFIPAddress.fromString host in

  let s = SFSocketUDP.create () in

  let loop = ref true in
  while !loop do
    print_endline "Fill the buffer";
    let data = read_line() in
    SFSocketUDP.send s data address port;

    if data = "quit" then loop := false
  done;

  SFSocketUDP.destroy s;
;;
