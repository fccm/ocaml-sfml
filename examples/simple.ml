let () =
  let app = SFWindow.make (320, 240) Sys.argv.(0) in

  let rec loop () =
    SFWindow.display app;
    match SFWindow.pollEvent app with
    | Some SFEvent.Closed -> ()
    | _ -> loop ()
  in
  loop ()
