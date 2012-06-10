
let () =
  let host, port =
    try (Sys.argv.(1), int_of_string Sys.argv.(2))
    with _ ->
      Printf.eprintf "Usage: %s host port\n" Sys.argv.(0);
      exit 1
  in
  let s = SFSocketTCP.create () in
  let timeout = 1000.0 in
  let address = SFIPAddress.fromString host in
  SFSocketTCP.connect s port address timeout;

  let loop = ref true in
  while !loop do
    print_endline "Fill the buffer";
    let data = read_line() in
    SFSocketTCP.send s data;
    if data = "quit" then loop := false
  done;

  SFSocketTCP.destroy s;
;;
