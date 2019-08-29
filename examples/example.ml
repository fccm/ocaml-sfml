
(* main *)
let () =
  (* Create the main window *)
  let mode, settings =
    { SFVideoMode.width = 800; height = 600; bitsPerPixel = 32 },
    { SFContextSettings.depthBits = 24; stencilBits = 8; antialiasingLevel = 0;
      majorVersion = 0; minorVersion = 0;
      attributes = []; sRgbCapable = false }
  in
  let app =
    SFRenderWindow.create ~mode ~settings ~title:"SFML window"
        ~style:[SFStyle.Resize; SFStyle.Close] in

  (* Load a sprite to display *)
  let image = SFImage.createFromFile "./data/background.jpg" in
  let sprite = SFSprite.create () in
  SFSprite.setTexture sprite (SFTexture.createFromImage image ()) true;

  (* Create a graphical string to display *)
  let font = SFFont.createFromFile "./data/Vera.ttf" in
  let text = SFText.create() in
  SFText.setString text "Hello SFML";
  SFText.setFont text font;
  SFText.setCharacterSize text 50;
  SFText.setPosition text (20.0, 10.0);

  (* Load a music to play *)
  let music = SFMusic.openFromFile "./data/nice_music.ogg" in
  (*
  SFMusic.setVolume music 50.0;
  *)

  (* Play the music *)
  SFMusic.play music;

  let rgb r g b = SFColor.RGB(r, g, b) in
  (*
  let shape =
    SFShape.createRectangle
      ~p1:(200.0, 100.0) ~p2:(260.0, 120.0)
      ~color:(rgb 255 0 0)
      ~outline:1.0
      ~outlineCol:(rgb 0 255 0)
  in
  *)
  let polygon =
    (*
    SFShape.create [|
      (  0.0, -50.0);
      ( 50.0,   0.0);
      ( 50.0,  50.0);
      (  0.0, 100.0);
      (-50.0,  50.0);
      (-50.0,   0.0);
    |]
    *)
    (*
    let circle = SFCircleShape.create ~radius:150.0 () in
    SFCircleShape.setPointCount ~circle ~count:12;
    Printf.printf "circ: %d\n" (SFCircleShape.getPointCount ~circle);
    (SFShape.of_circle circle)
    *)
    let rectangle = SFRectangleShape.create ~size:(150.0, 100.0) () in
    (SFShape.of_rectangle rectangle)
  in
  (*
  Printf.printf "poly: %d\n" (SFShape.getPointCount polygon);
  *)
  SFShape.setFillColor polygon (rgb 255 0 0);
  SFShape.setOutlineColor polygon (rgb 0 255 0);
  SFShape.setOutlineThickness polygon 8.0;
  SFShape.move2 polygon 120.0 180.0;
  (*
  let polygon = SFShape.create () in
  SFShape.addPoint polygon (  0.0, -50.0) (rgb 255   0   0) (rgb 0 128 128);
  SFShape.addPoint polygon ( 50.0,   0.0) (rgb 255  85  85) (rgb 0 128 128);
  SFShape.addPoint polygon ( 50.0,  50.0) (rgb 255 170 170) (rgb 0 128 128);
  SFShape.addPoint polygon (  0.0, 100.0) (rgb 255 255 255) (rgb 0 128 128);
  SFShape.addPoint polygon (-50.0,  50.0) (rgb 255 170 170) (rgb 0 128 128);
  SFShape.addPoint polygon (-50.0,   0.0) (rgb 255  85  85) (rgb 0 128 128);
  SFShape.move2 polygon 60.0 140.0;
  *)

  (* Start the game loop *)
  while SFRenderWindow.isOpen app do
    (* Process events *)
    let rec proc_ev () =
      match SFRenderWindow.pollEvent app with
      | Some SFEvent.Closed
      | Some SFEvent.KeyPressed (SFKey.Escape,_,_,_,_) ->
          (* Close window : exit *)
          SFRenderWindow.close app

      | None -> ()
      | _ -> proc_ev ()
    in
    proc_ev ();

    (* Clear the screen *)
    SFRenderWindow.clear app SFColor.black;

    (* Draw the sprite *)
    SFRenderWindow.drawSprite app sprite ();

    (* Draw the string *)
    SFRenderWindow.drawText app text ();

    (* Draw the rectangle shape *)
    (*
    SFRenderWindow.drawShape app shape ();
    *)
    SFRenderWindow.drawShape app polygon ();

    (* Update the window *)
    SFRenderWindow.display app;
  done;

  (* Cleanup resources *)
  SFMusic.destroy music;
  (*
  SFShape.destroy shape;
  SFShape.destroy polygon;
  *)
  SFRenderWindow.destroy app;
;;

