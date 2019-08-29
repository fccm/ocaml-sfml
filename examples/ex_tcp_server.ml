let filter_some lst =
  List.fold_left
    (fun acc -> function Some v -> v::acc | None -> acc) []
    (List.rev lst)

let () =
  let port = 2000 in

  let li = SFTcpListener.create () in
  SFTcpListener.listen li port;
  print_endline "listening";

  let len = 1024 in
  let data = Bytes.create len in

  let accept cls =
    try
      let cl = SFTcpListener.accept li in
      (*
      SFTcpSocket.setBlocking cl false;
      *)
      (cl :: cls)
    with SFTcpSocket.Socket_Not_Ready ->
      Printf.printf "-%!";
      SFTime.sleep (SFTime.of_seconds 0.2);
      (cls)
  in
  let receive cl =
    try
      let n = SFTcpSocket.receive cl data in
      Some(Bytes.sub data 0 n)
    with
    | SFTcpSocket.Socket_Not_Ready -> None
    | SFTcpSocket.Socket_Disconnected -> None
  in
  let rec aux cls =
    let cls = accept cls in
    let gs = List.map receive cls in
    let gs = filter_some gs in
    List.iter (fun b -> print_bytes b; print_newline ()) gs;
    Printf.printf ".%!";
    SFTime.sleep (SFTime.of_seconds 0.2);
    aux cls
  in
  let _ = aux [] in

  SFTcpListener.destroy li;
;;
