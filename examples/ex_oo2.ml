open Oo_sfml_system
open Oo_sfml_audio
open Oo_sfml_graphics

let () =
  (* Create the main window *)
  let app = new render_window (800, 600) "SFML window" in

  (* Load a sprite to display *)
  let image = new image (`FromFile "./data/texture.jpg") in
  let sprite = new sprite in
  sprite#set_texture (new texture (`FromImage image) ()) false;

  (* Create a graphical string to display *)
  let font = new font (`FromFile "./data/Vera.ttf") in
  let text = new text ~font ~charSize:30 ~color:(SFColor.blue) "Hello SFML" in

  (* Load a music to play *)
  let music = new music (`FromFile "./data/nice_music.ogg") in

  (* Play the music *)
  music#play();

  (* Start the game loop *)
  while app#is_open do
    (* Process events *)
    let rec proc_ev () =
      match app#poll_event () with
      | Some SFEvent.Closed
      | Some (SFEvent.KeyPressed (SFKey.Escape,_,_,_,_)) ->
          (* Close window : exit *)
          app#close ()
      | Some _ -> proc_ev ()
      | None -> ()
    in
    proc_ev ();

    (* Clear screen *)
    app#clear ();

    (* Draw the sprite *)
    app#draw_sprite sprite ();

    (* Draw the string *)
    app#draw_text text ();

    (* Update the window *)
    app#display ();
  done
