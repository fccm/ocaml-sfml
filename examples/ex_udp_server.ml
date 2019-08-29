
let () =
  let port = 2000 in
  let s = SFUdpSocket.create () in
  SFUdpSocket.bind s port;
  SFUdpSocket.setBlocking s false;

  let len = 512 in
  let data = Bytes.create len in

  let loop = ref true in
  while !loop do
    try
      let n, addr, _port = SFUdpSocket.receive s data in
      Printf.printf " port: %d   address: %s\n%!" _port addr;
      let got = Bytes.sub data 0 n in
      print_bytes got;
      print_newline ();
      if got = (Bytes.of_string "quit") then loop := false;
    with _ ->
      SFTime.sleep (SFTime.of_seconds 0.01);
  done;

  SFUdpSocket.unbind s;
  SFUdpSocket.destroy s;
;;
