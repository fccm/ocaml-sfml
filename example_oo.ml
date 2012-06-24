open SFML_oo

let () =
  (* Create the main window *)
  let app = new renderWindow (800, 600) "SFML window" in

  (* Load a sprite to display *)
  let image = new image (`FromFile "./data/texture.jpg") in
  let sprite = new sprite ~image () in

  (* Create a graphical string to display *)
  let font = new font (`FromFile "./data/Vera.ttf") in
  let text = new text ~font ~size:50.0 ~color:(SFColor.blue) "Hello SFML" in

  (* Load a music to play *)
  let music = new music (`FromFile "./data/nice_music.ogg") in

  (* Play the music *)
  music#play();

  (* Start the game loop *)
  while app#isOpened do
    (* Process events *)
    let rec proc_ev() =
      match app#getEvent() with
      | Some SFEvent.Closed
      | Some (SFEvent.KeyPressed (SFKey.Escape, _,_,_)) ->
          (* Close window : exit *)
          app#close()
      | Some _ -> proc_ev()
      | None -> ()
    in
    proc_ev();

    (* Clear screen *)
    app#clear();

    (* Draw the sprite *)
    app#drawSprite sprite;

    (* Draw the string *)
    app#drawText text;

    (* Update the window *)
    app#display();
  done
