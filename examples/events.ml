open SFRenderWindow
open SFEvent

let string_of_mouse_button = function
  | SFMouse.ButtonLeft       -> "ButtonLeft"
  | SFMouse.ButtonRight      -> "ButtonRight"
  | SFMouse.ButtonMiddle     -> "ButtonMiddle"
  | SFMouse.ButtonX1         -> "ButtonX1"
  | SFMouse.ButtonX2         -> "ButtonX2"

let string_of_joy_axis = function
  | SFEvent.JoystickX    -> "JoystickX"
  | SFEvent.JoystickY    -> "JoystickY"
  | SFEvent.JoystickZ    -> "JoystickZ"
  | SFEvent.JoystickR    -> "JoystickR"
  | SFEvent.JoystickU    -> "JoystickU"
  | SFEvent.JoystickV    -> "JoystickV"
  | SFEvent.JoystickPovX -> "JoystickPovX"
  | SFEvent.JoystickPovY -> "JoystickPovY"

let b = function true -> '1' | false -> '0'
let c = SFKey.string_of_keyCode

let () =
  let mode = { width = 640; height = 480; bitsPerPixel = 32 } in
  let settings =
    { depthBits = 24;
      stencilBits = 8;
      antialiasingLevel = 0;
      majorVersion = 0;
      minorVersion = 0;
    }
  in
  let app = SFRenderWindow.create mode "SFML window" [`resize; `close] settings in

  while SFRenderWindow.isOpen app do
    let rec proc_ev() =
      let print_event = function
      | SFEvent.MouseMoved (x, y) -> Printf.printf " (%d,%d)%!" x y
      | SFEvent.Resized (width, height) ->
          Printf.printf " Resized(%d,%d)\n%!" width height

      | SFEvent.MouseButtonPressed (mbut, x, y) ->
          Printf.printf " MouseButtonPressed(%d,%d,%s)\n%!"
            x y (string_of_mouse_button mbut)

      | SFEvent.MouseButtonReleased (mbut, x, y) ->
          Printf.printf " MouseButtonReleased(%d,%d,%s)\n%!"
            x y (string_of_mouse_button mbut)

      | SFEvent.MouseWheelMoved (delta, x, y) ->
          Printf.printf " MouseWheel(%d, %d, %d)\n%!" delta x y

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

