open GL
open Glu

(* main *)
let () =
  (* Create the main window *)
  let mode, settings =
    { SFRenderWindow.width = 800; height = 600; bitsPerPixel = 32 },
    { SFRenderWindow.depthBits = 24; stencilBits = 8; antialiasingLevel = 0;
      majorVersion = 0; minorVersion = 0 }
  in
  let app =
    SFRenderWindow.create mode "SFML window" [`resize; `close] settings
  in

  (* Create a sprite for the background *)
  let background_image = SFImage.createFromFile "./data/background.jpg" in
  let background = SFSprite.create () in
  let background_texture = SFTexture.createFromImage background_image () in
  SFSprite.setTexture background background_texture true;

  (* Load an OpenGL texture. *)
  (* We could directly use a SFImage.t as an OpenGL texture (with its bind()
     function), but here we want more control on it (generate mipmaps, ...)
     so we create a new one *)
  let texture =
    let image = SFImage.createFromFile "./data/texture.jpg" in
    let texture = glGenTexture () in
    glBindTexture BindTex.GL_TEXTURE_2D texture;

    gluBuild2DMipmaps InternalFormat.GL_RGBA
                      (SFImage.getWidth image)
                      (SFImage.getHeight image)
                      GL_RGBA GL_UNSIGNED_BYTE
                      (SFImage.getPixelsBA image);

    let mag_filter = Mag.GL_LINEAR in
    let min_filter = Min.GL_LINEAR_MIPMAP_LINEAR in

    let tex_mag_filter = TexParam.GL_TEXTURE_MAG_FILTER mag_filter in
    let tex_min_filter = TexParam.GL_TEXTURE_MIN_FILTER min_filter in

    glTexParameter TexParam.GL_TEXTURE_2D tex_mag_filter;
    glTexParameter TexParam.GL_TEXTURE_2D tex_min_filter;

    (texture)
  in

  (* Enable Z-buffer read and write *)
  glEnable GL_DEPTH_TEST;
  glDepthMask true;
  glClearDepth 1.0;

  (* Setup a perspective projection *)
  let set_projection ~width ~height =
    glMatrixMode GL_PROJECTION;
    glLoadIdentity ();
    gluPerspective 90.0 (float width /. float height) 1.0 500.0;
  in
  set_projection ~width:800 ~height:600;

  (* Bind our texture *)
  glEnable GL_TEXTURE_2D;
  glBindTexture BindTex.GL_TEXTURE_2D texture;
  glColor4 1.0 1.0 1.0 1.0;

  (* Create a graphical string to display *)
  let text = SFText.create () in
  SFText.setString text "This is a rotating cube";

  (* define the color of the text *)
  let color = SFColor.RGB(128, 0, 128) in

  (* Create a clock for measuring the time elapsed *)
  let clock = SFClock.create () in

  (* Used to calculate FPS *)
  let t0 = SFClock.getElapsedTime_asSeconds clock in
  let frames = ref 0 in

  (* Start game loop *)
  while SFRenderWindow.isOpen app do
    (* Process events *)
    let rec proc_ev () =
      match SFRenderWindow.pollEvent app with
      | None -> ()
      | Some ev ->
          begin match ev with
          | SFEvent.Closed ->
              (* Close window : exit *)
              SFRenderWindow.close app

          | SFEvent.KeyPressed (SFKey.Escape,_,_,_,_) ->
              (* Escape key : exit *)
              SFRenderWindow.close app

          | SFEvent.Resized (width, height) ->
              (* Adjust the viewport when the window is resized *)
              glViewport 0 0 width height;
              set_projection ~width ~height;

          | _ -> ()
          end;
          proc_ev ()
    in
    proc_ev ();

    SFRenderWindow.pushGLStates app;

    (* Draw background *)
    SFRenderWindow.drawSprite app background ();

    SFRenderWindow.popGLStates app;

    (* Clear depth buffer *)
    glClear [GL_DEPTH_BUFFER_BIT];

    (* Apply some transformations *)
    glMatrixMode GL_MODELVIEW;
    glLoadIdentity ();
    glTranslate 0.0 0.0 (-200.0);
    let time = SFTime.asSeconds (SFClock.getElapsedTime clock) in
    glRotate (time *. 50.0) 1.0 0.0 0.0;
    glRotate (time *. 30.0) 0.0 1.0 0.0;
    glRotate (time *. 90.0) 0.0 0.0 1.0;

    glEnable GL_TEXTURE_2D;
    glBindTexture BindTex.GL_TEXTURE_2D texture;

    (* Draw a cube *)
    glBegin GL_QUADS;

      glTexCoord2 0. 0.; glVertex3v (-50.0, -50.0, -50.0);
      glTexCoord2 0. 1.; glVertex3v (-50.0,  50.0, -50.0);
      glTexCoord2 1. 1.; glVertex3v ( 50.0,  50.0, -50.0);
      glTexCoord2 1. 0.; glVertex3v ( 50.0, -50.0, -50.0);

      glTexCoord2 0. 0.; glVertex3v (-50.0, -50.0,  50.0);
      glTexCoord2 0. 1.; glVertex3v (-50.0,  50.0,  50.0);
      glTexCoord2 1. 1.; glVertex3v ( 50.0,  50.0,  50.0);
      glTexCoord2 1. 0.; glVertex3v ( 50.0, -50.0,  50.0);

      glTexCoord2 0. 0.; glVertex3v (-50.0, -50.0, -50.0);
      glTexCoord2 0. 1.; glVertex3v (-50.0,  50.0, -50.0);
      glTexCoord2 1. 1.; glVertex3v (-50.0,  50.0,  50.0);
      glTexCoord2 1. 0.; glVertex3v (-50.0, -50.0,  50.0);

      glTexCoord2 0. 0.; glVertex3v ( 50.0, -50.0, -50.0);
      glTexCoord2 0. 1.; glVertex3v ( 50.0,  50.0, -50.0);
      glTexCoord2 1. 1.; glVertex3v ( 50.0,  50.0,  50.0);
      glTexCoord2 1. 0.; glVertex3v ( 50.0, -50.0,  50.0);

      glTexCoord2 0. 1.; glVertex3v (-50.0, -50.0,  50.0);
      glTexCoord2 0. 0.; glVertex3v (-50.0, -50.0, -50.0);
      glTexCoord2 1. 0.; glVertex3v ( 50.0, -50.0, -50.0);
      glTexCoord2 1. 1.; glVertex3v ( 50.0, -50.0,  50.0);

      glTexCoord2 0. 1.; glVertex3v (-50.0,  50.0,  50.0);
      glTexCoord2 0. 0.; glVertex3v (-50.0,  50.0, -50.0);
      glTexCoord2 1. 0.; glVertex3v ( 50.0,  50.0, -50.0);
      glTexCoord2 1. 1.; glVertex3v ( 50.0,  50.0,  50.0);

    glEnd();

    SFRenderWindow.pushGLStates app;

    (* Draw some text on top of our OpenGL object *)
    SFText.setPosition text (250.0, 300.0);
    SFText.setColor text color;
    SFRenderWindow.drawText app text ();

    SFRenderWindow.popGLStates app;

    incr frames;

    (* Finally, display the rendered frame on screen *)
    SFRenderWindow.display app;
  done;

  (* Print FPS *)
  let t1 = SFClock.getElapsedTime_asSeconds clock in
  let elapsed = (t1 -. t0) in
  Printf.printf " clock(%f) frames(%d) : fps(%f)\n" elapsed !frames
                (float !frames /. elapsed);

  (* Don't forget to destroy our texture *)
  glDeleteTexture texture;

  (* Cleanup resources *)
  SFClock.destroy clock;
  SFRenderWindow.destroy app;
;;
