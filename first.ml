
let () =
  (* Create the main window *)
  let app = SFRenderWindow.make (800, 600) "OCaml-SFML test" in

  (* Create a graphical string to display *)
  let text = SFString.make "Hello SFML" in

  (* Start the game loop *)
  let rec loop() =
    let continue =
      match SFRenderWindow.getEvent app with
      | Some SFEvent.Closed -> false
      | _ -> true
    in
    (* Clear screen, draw the text, and update the window *)
    SFRenderWindow.clear app SFColor.black;
    SFRenderWindow.drawString app text;
    SFRenderWindow.display app;
    if continue then loop()
  in
  loop()
