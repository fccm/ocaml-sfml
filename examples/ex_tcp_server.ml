let filter_some lst =
  List.fold_left
    (fun acc -> function Some v -> v::acc | None -> acc) []
    (List.rev lst)

let () =
  let port = 2000 in
  let s = SFSocketTCP.create () in
  SFSocketTCP.setBlocking s false;

  SFSocketTCP.listen s port;
  print_endline "listening";

  let len = 1024 in
  let data = String.create len in

  let accept s cls =
    try
      let cl, addr = SFSocketTCP.accept s in
      Printf.printf "accepted: %s\n%!" addr;
      SFSocketTCP.setBlocking cl false;
      (cl :: cls)
    with SFSocketTCP.Socket_Not_Ready ->
      Printf.printf "-%!";
      SFClock.sleep 0.2;
      (cls)
  in
  let receive cl =
    try
      let n = SFSocketTCP.receive cl data in
      Some(String.sub data 0 n)
    with
    | SFSocketTCP.Socket_Not_Ready -> None
    | SFSocketTCP.Socket_Disconnected -> None
  in
  let rec aux cls =
    let cls = accept s cls in
    let gs = List.map receive cls in
    let gs = filter_some gs in
    List.iter print_endline gs;
    Printf.printf ".%!";
    SFClock.sleep 0.2;
    aux cls
  in
  let _ = aux [] in
  SFSocketTCP.destroy s;
;;
