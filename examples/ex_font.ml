
let test f =
  begin
    let font = f () in
    Printf.printf "line spacing: %d\n%!" (SFFont.getLineSpacing font 1);
  end;
  Gc.full_major ();
  print_endline "Done";
;;

let () =
  test (fun () -> SFFont.createFromFile ~filename:"./data/Vera.ttf");
;;
