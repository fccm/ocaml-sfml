let width, height = (640, 480)

(* main *)
let () =
  (* Create the main window *)
  let mode, settings =
    { SFVideoMode.width; height; bitsPerPixel = 32 },
    { SFContextSettings.depthBits = 24; stencilBits = 8; antialiasingLevel = 2;
      majorVersion = 0; minorVersion = 0;
      attributes = []; sRgbCapable = false }
  in
  let app =
    SFRenderWindow.create ~mode ~title:"SFML window"
        ~style:[SFStyle.Resize; SFStyle.Close] ~settings in

  (* Create a graphical string to display *)
  let font = SFFont.createFromFile "./data/Vera.ttf" in
  let text = SFText.create () in
  SFText.setString text "Drawing Circles";
  SFText.setFont text font;
  SFText.setCharacterSize text 30;
  SFText.setPosition text (20.0, 10.0);

  let rgb r g b = SFColor.RGB(r, g, b) in
  let pointCount = 32 in
  let radius = 30.0 in
  let cx, cy = (float width /. 2.0, float height /. 2.0) in

  let circle1 = SFCircleShape.create ~radius ~pointCount () in
  SFCircleShape.setFillColor circle1 (rgb 255 0 0);
  SFCircleShape.setPosition circle1 (cx -. 40.0, cy);

  let circle2 = SFCircleShape.create ~radius ~pointCount () in
  SFCircleShape.setFillColor circle2 (rgb 0 255 0);
  SFCircleShape.setPosition circle2 (cx +. 40.0, cy);

  let circle3 = SFCircleShape.create ~radius ~pointCount () in
  SFCircleShape.setFillColor circle3 (rgb 0 0 255);
  SFCircleShape.setPosition circle3 (cx, cy -. 68.0);

  (* Start the game loop *)
  while SFRenderWindow.isOpen app do
    (* Process events *)
    let rec proc_ev () =
      match SFRenderWindow.pollEvent app with
      | Some SFEvent.Closed
      | Some SFEvent.KeyPressed (SFKey.Escape,_,_,_,_) ->
          SFRenderWindow.close app

      | None -> ()
      | _ -> proc_ev ()
    in
    proc_ev ();

    SFRenderWindow.clear app SFColor.black;
    SFRenderWindow.drawText app text ();
    List.iter (fun circle ->
      SFRenderWindow.drawCircleShape app circle ();
    ) [circle1; circle2; circle3];
    SFRenderWindow.display app;
  done;

  (* Cleanup resources *)
  SFRenderWindow.destroy app;
;;

