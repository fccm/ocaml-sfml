type t =
  | Closed
  | MouseMoved of int * int  (** x, y *)
  | Resized of int * int  (** width, height *)
  | MouseButtonPressed of SFMouse.mouse_button * int * int  (** x, y *)
  | MouseButtonReleased of SFMouse.mouse_button * int * int  (** x, y *)
  | MouseWheelMoved of int * int * int [@deprecated "Use MouseWheelScrolled instead"]  (** delta, x, y *)
  | MouseWheelScrolled of SFMouse.mouse_wheel * float * int * int  (** wheel, delta, x, y *)
  | KeyPressed of SFKey.t * bool * bool * bool * bool   (** alt, control, shift, system *)
  | KeyReleased of SFKey.t * bool * bool * bool * bool   (** alt, control, shift, system *)
  | TextEntered of int32
  | MouseEntered
  | MouseLeft
  | LostFocus
  | GainedFocus
  | JoystickMoved of int * SFJoystick.axis * float  (** joystickId, axis, position *)
  | JoystickButtonPressed of int * int  (** joystickId, button *)
  | JoystickButtonReleased of int * int  (** joystickId, button *)
  | JoystickConnected of int  (** joystickId *)
  | JoystickDisconnected of int  (** joystickId *)
