
let () =
  let port = 2000 in
  let s = SFUdpSocket.create () in
  SFUdpSocket.bind s port;
  SFUdpSocket.setBlocking s false;

  let len = 512 in
  let data = String.create len in

  let loop = ref true in
  while !loop do
    try
      let n, addr, _port = SFUdpSocket.receive s data in
      Printf.printf " port: %d   address: %s\n%!" _port addr;
      let got = String.sub data 0 n in
      print_endline got;
      if got = "quit" then loop := false;
    with _ ->
      SFTime.sleep (SFTime.of_seconds 0.01);
  done;

  SFUdpSocket.unbind s;
  SFUdpSocket.destroy s;
;;
