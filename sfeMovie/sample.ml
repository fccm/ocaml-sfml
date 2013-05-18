(* Here is a little use sample for sfeMovie.
 * It'll open and display the movie specified by MOVIE_FILE above.
 *
 * This sample implements basic controls as follow:
 *  - Escape key to exit
 *  - Space key to play/pause the movie playback
 *  - S key to stop and go back to the beginning of the movie
 *  - R key to restart playing from the beginning of the movie
 *  - F key to toggle between windowed and fullscreen mode
 *)

let () =
  (* Some settings *)
  let windowTitle = "sfeMovie Player" in
  let windowWidth = 800
  and windowHeight = 600 in
  let fullscreen = ref false in

  print_endline "Going to open movie file";

  (* Create window *)
  let window =
    SFRenderWindow.make
      ~style:[`close]
      (*
      ?bpp:int ->
      ?depth:int ->
      ?stencil:int ->
      ?antialiasing:int ->
      ?version:int * int ->
      *)
      (windowWidth, windowHeight)
      windowTitle
  in

  let movie_file = Sys.argv.(1) in

  (* Create and open movie *)
  let movie = SFEMovie.create () in
  SFEMovie.openFromFile movie movie_file;

  (* Scale movie to the window drawing area and enable VSync *)
  let w, h = SFRenderWindow.getSize window in
  SFEMovie.resizeToFrame movie 0 0 w h ();
  SFRenderWindow.setVerticalSyncEnabled window true;

  (* Start movie playback *)
  SFEMovie.play movie;

  while SFRenderWindow.isOpen window do
    begin match SFRenderWindow.pollEvent window with
    | None -> ()
    | Some ev ->
      match ev with
      (* Window closure *)
      | SFEvent.Closed
      | SFEvent.KeyPressed (SFKey.Escape, _,_,_,_) ->
          SFRenderWindow.close window
      | SFEvent.KeyPressed (key, _,_,_,_) ->
        begin match key with
        | SFKey.P -> (* Play/Pause *)
            if (SFEMovie.getStatus movie) <> SFEMovie.Playing
            then SFEMovie.play movie
            else SFEMovie.pause movie

        | SFKey.S -> (* Stop *)
            SFEMovie.stop movie

        | SFKey.R -> (* Restart playback *)
            SFEMovie.stop movie;
            SFEMovie.play movie;

        | _ -> ()
        end
      | _ -> ()
    end;

    (*
    while (window.pollEvent(ev))
    {
      (* Handle basic controls *)
      else if (ev.type == sf::Event::KeyPressed)
      {
        (* Toggle fullscreen mode *)
        if (ev.key.code == sf::Keyboard::F)
        {
          fullscreen := not !fullscreen;

          (* We want to switch to the full screen mode *)
          if !fullscreen then
          begin
            window.create(sf::VideoMode::getDesktopMode(), windowTitle, sf::Style::Fullscreen);
            SFRenderWindow.setVerticalSyncEnabled window true;
            let w, h = SFRenderWindow.getSize window in
            SFEMovie.resizeToFrame movie 0 0 w h ();
          end
          else
          (* We want to switch back to the windowed mode *)
          begin
            window.create(sf::VideoMode(windowWidth, windowHeight), windowTitle, sf::Style::Close);
            SFRenderWindow.setVerticalSyncEnabled window true;
            let w, h = SFRenderWindow.getSize window in
            SFEMovie.resizeToFrame movie 0 0 w h ();
          end
        }
      }
    }
    *)

    (* Render movie *)
    SFRenderWindow.clear window (SFColor.RGBA(0, 0, 0, 255));
    (*
    SFRenderWindow.drawShape window (Obj.magic movie) ();
    *)
    SFEMovie.draw window movie;
    SFRenderWindow.display window;
  done
