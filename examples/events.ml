open SFEvent

let string_of_joy_axis = function
  | SFJoystick.X    -> "SFJoystick.X"
  | SFJoystick.Y    -> "SFJoystick.Y"
  | SFJoystick.Z    -> "SFJoystick.Z"
  | SFJoystick.R    -> "SFJoystick.R"
  | SFJoystick.U    -> "SFJoystick.U"
  | SFJoystick.V    -> "SFJoystick.V"
  | SFJoystick.PovX -> "SFJoystick.PovX"
  | SFJoystick.PovY -> "SFJoystick.PovY"

let b = function true -> '1' | false -> '0'
let c = SFKey.string_of_keyCode

let () =
  let mode, settings =
    { SFVideoMode.width = 640; height = 480; bitsPerPixel = 32 },
    { SFContextSettings.depthBits = 24; stencilBits = 8; antialiasingLevel = 0;
      majorVersion = 0; minorVersion = 0;
      attributes = []; sRgbCapable = false }
  in
  let app =
    SFRenderWindow.create ~mode ~title:"SFML window"
        ~style:[SFStyle.Resize; SFStyle.Close] ~settings in

  while SFRenderWindow.isOpen app do
    let rec proc_ev() =
      let print_event = function
      | SFEvent.MouseMoved (x, y) -> Printf.printf " (%d,%d)%!" x y
      | SFEvent.Resized (width, height) ->
          Printf.printf " Resized(%d,%d)\n%!" width height

      | SFEvent.MouseButtonPressed (mbut, x, y) ->
          Printf.printf " MouseButtonPressed(%d,%d,%s)\n%!"
            x y (SFMouse.string_of_button mbut)

      | SFEvent.MouseButtonReleased (mbut, x, y) ->
          Printf.printf " MouseButtonReleased(%d,%d,%s)\n%!"
            x y (SFMouse.string_of_button mbut)

      | SFEvent.MouseWheelScrolled (wheel, delta, x, y) ->
          Printf.printf " MouseWheelScrolled(%s, %g, %d, %d)\n%!"
            (SFMouse.string_of_wheel wheel) delta x y
      | SFEvent.MouseWheelMoved (_, _, _) -> ()

      | SFEvent.KeyPressed (key, alt, control, shift, system) ->
          Printf.printf " KeyPressed(%s,%c,%c,%c,%c)\n%!"
            (c key) (b alt) (b control) (b shift) (b system)

      | SFEvent.KeyReleased (key, alt, control, shift, system) ->
          Printf.printf " KeyReleased(%s,%c,%c,%c,%c)\n%!"
            (c key) (b alt) (b control) (b shift) (b system)

      | SFEvent.TextEntered code ->
          Printf.printf " TextEntered(%ld)\n%!" code

      | SFEvent.MouseEntered -> Printf.printf " MouseEntered\n%!"
      | SFEvent.MouseLeft -> Printf.printf " MouseLeft\n%!"
      | SFEvent.LostFocus -> Printf.printf " LostFocus\n%!"
      | SFEvent.GainedFocus -> Printf.printf " GainedFocus\n%!"

      | SFEvent.JoystickButtonPressed (joystickId, button) ->
          Printf.printf " JoystickButtonPressed => joystickId(%d), button(%d)\n%!"
            joystickId button

      | SFEvent.JoystickButtonReleased (joystickId, button) ->
          Printf.printf " JoystickButtonReleased => joystickId(%d), button(%d)\n%!"
            joystickId button

      | SFEvent.JoystickMoved (joystickId, axis, position) ->
          Printf.printf " JoystickMoved => joystickId(%d), axis(%s), position(%f)\n%!"
            joystickId (string_of_joy_axis axis) position

      | SFEvent.JoystickDisconnected _ ->
          Printf.printf " JoystickDisconnected\n%!"
      | SFEvent.JoystickConnected _ ->
          Printf.printf " JoystickConnected\n%!"
      | SFEvent.Closed -> assert false

      | SFEvent.TouchBegan (_, _, _)
      | SFEvent.TouchMoved (_, _, _)
      | SFEvent.TouchEnded (_, _, _)
      | SFEvent.SensorChanged (_, _) -> ()
      in
      match SFRenderWindow.pollEvent app with
      | None -> ()
      | Some SFEvent.Closed
      | Some SFEvent.KeyPressed (SFKey.Escape,_,_,_,_) ->
          SFRenderWindow.close app
      | Some ev ->
          print_event ev;
          proc_ev ()
    in
    proc_ev();

    SFRenderWindow.clear app SFColor.black;
    SFRenderWindow.display app;
  done;

  SFRenderWindow.destroy app;
  print_newline();
;;

