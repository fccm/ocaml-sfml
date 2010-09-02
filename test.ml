
(* main *)
let () =
  (* Create the main window *)
  let mode, settings =
    { SFRenderWindow.width = 800; height = 600; bitsPerPixel = 32 },
    { SFRenderWindow.depthBits = 24; stencilBits = 8; antialiasingLevel = 0 }
  in
  let app = SFRenderWindow.create mode "SFML window" [`resize; `close] settings in

  (* Load a sprite to display *)
  let image = SFImage.createFromFile "./data/background.jpg" in
  let sprite = SFSprite.create() in
  SFSprite.setImage sprite image;

  (* Create a graphical string to display *)
  let font = SFFont.createFromFile ~charSize:50 "./data/Vera.ttf" in
  let text = SFString.create() in
  SFString.setText text "Hello SFML";
  SFString.setFont text font;
  SFString.setSize text 50.0;
  SFString.setPosition2 text (20.0, 10.0);

  (* Load a music to play *)
  let music = SFMusic.createFromFile "./data/nice_music.ogg" in
  (*
  SFMusic.setVolume music 50.0;
  *)

  (* Play the music *)
  SFMusic.play music;

  let rgb r g b = SFColor.RGB(r, g, b) in
  let shape =
    SFShape.createRectangle
      ~p1:(200.0, 100.0) ~p2:(260.0, 120.0)
      ~color:(rgb 255 0 0)
      ~outline:1.0
      ~outlineCol:(rgb 0 255 0)
  in
  let polygon = SFShape.create () in
  SFShape.addPoint polygon (  0.0, -50.0) (rgb 255   0   0) (rgb 0 128 128);
  SFShape.addPoint polygon ( 50.0,   0.0) (rgb 255  85  85) (rgb 0 128 128);
  SFShape.addPoint polygon ( 50.0,  50.0) (rgb 255 170 170) (rgb 0 128 128);
  SFShape.addPoint polygon (  0.0, 100.0) (rgb 255 255 255) (rgb 0 128 128);
  SFShape.addPoint polygon (-50.0,  50.0) (rgb 255 170 170) (rgb 0 128 128);
  SFShape.addPoint polygon (-50.0,   0.0) (rgb 255  85  85) (rgb 0 128 128);
  SFShape.move polygon 60.0 140.0;

  (* Start the game loop *)
  while SFRenderWindow.isOpened app do
    (* Process events *)
    let rec proc_ev() =
      match SFRenderWindow.getEvent app with
      | Some SFEvent.Closed
      | Some SFEvent.KeyPressed (SFKey.Escape,_,_,_) ->
          (* Close window : exit *)
          SFRenderWindow.close app

      | None -> ()
      | _ -> proc_ev()
    in
    proc_ev();

    (* Clear the screen *)
    SFRenderWindow.clear app SFColor.black;

    (* Draw the sprite *)
    SFRenderWindow.drawSprite app sprite;

    (* Draw the string *)
    SFRenderWindow.drawString app text;

    (* Draw the rectangle shape *)
    SFRenderWindow.drawShape app shape;
    SFRenderWindow.drawShape app polygon;

    (* Update the window *)
    SFRenderWindow.display app;
  done;

  (* Cleanup resources *)
  SFMusic.destroy music;
  SFShape.destroy shape;
  SFRenderWindow.destroy app;
;;

