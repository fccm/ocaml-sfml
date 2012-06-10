
let () =
  let port = 2000 in
  let s = SFSocketUDP.create () in
  SFSocketUDP.bind s port;
  SFSocketUDP.setBlocking s false;

  let len = 512 in
  let data = String.create len in

  let loop = ref true in
  while !loop do
    try
      let n, addr, _port = SFSocketUDP.receive s data in
      Printf.printf " %d %s\n%!" _port addr;
      let got = String.sub data 0 n in
      print_endline got;
      if got = "quit" then loop := false;
    with _ ->
      SFClock.sleep 0.01;
  done;

  SFSocketUDP.unbind s;
  SFSocketUDP.destroy s;
;;
