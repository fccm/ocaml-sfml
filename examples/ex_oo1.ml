open Oo_sfml_system
open Oo_sfml_graphics

let () =
  (* Create the main window *)
  let app = new render_window (800, 600) "SFML window" in

  (* Create a graphical string to display *)
  let font = new font (`FromFile "./data/Vera.ttf") in
  let text = new text ~font ~charSize:30 ~color:SFColor.white "Hello SFML" in

  let pixels =
    Array.init 256 (fun y ->
      Array.init 256 (fun x -> (x, 0, y, 255)))
  in
  let image = new image (`FromPixelsArray pixels) in
  let sprite = new sprite in
  sprite#set_texture (new texture (`FromImage image) ()) false;
  let p = image#get_pixel4 ~x:127 ~y:127 in
  begin match p with
  | SFColor.RGB (r, g, b) -> Printf.printf "rgb: %d %d %d\n%!" r g b;
  | SFColor.RGBA (r, g, b, a) -> Printf.printf "rgba: %d %d %d %d\n%!" r g b a;
  end;

  let transform = SFTransform.getIdentity () in
  SFTransform.rotate transform 30.0;
  let states = new render_states ~transform () in

  (* Start the game loop *)
  while app#is_open do
    (* Process events *)
    let rec proc_ev () =
      match app#poll_event () with
      | Some SFEvent.Closed
      | Some (SFEvent.KeyPressed (SFKey.Escape,_,_,_,_)) ->
          (* Close window : exit *)
          app#close ();
          proc_ev ()
      | Some _ ->
          proc_ev ()
      | None -> ()
    in
    proc_ev ();

    (* Clear screen *)
    app#clear ~color:SFColor.white ();

    (* Draw the sprite *)
    app#draw sprite ();

    (* Draw the string *)
    app#draw text ~states ();

    (* Update the window *)
    app#display ();
  done;

  ignore (transform);
;;
