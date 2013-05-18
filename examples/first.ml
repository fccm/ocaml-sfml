
let () =
  (* Create the main window *)
  let app = SFRenderWindow.make (640, 480) "OCaml-SFML test" in

  (* Create a graphical string to display *)
  let text = SFText.make "Hello SFML" in
  let font = SFFont.createFromFile ~filename:"./data/Vera.ttf" in
  SFText.setFont ~text ~font;

  (* Start the game loop *)
  let rec loop () =
    let continue =
      match SFRenderWindow.pollEvent app with
      | Some SFEvent.Closed -> false
      | _ -> true
    in
    (* Clear screen, draw the text, and update the window *)
    SFRenderWindow.clear app SFColor.green;
    SFRenderWindow.drawText app text ();
    SFRenderWindow.display app;
    if continue then loop ()
  in
  loop ()
