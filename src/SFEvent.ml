type joystick_axis =
  | JoystickX
  | JoystickY
  | JoystickZ
  | JoystickR
  | JoystickU
  | JoystickV
  | JoystickPovX
  | JoystickPovY

type t =
  | Closed
  | MouseMoved of int * int  (** x, y *)
  | Resized of int * int  (** width, height *)
  | MouseButtonPressed of SFMouse.mouse_button * int * int  (** x, y *)
  | MouseButtonReleased of SFMouse.mouse_button * int * int  (** x, y *)
  | MouseWheelMoved of int * int * int  (** delta, x, y *)
  | KeyPressed of SFKey.t * bool * bool * bool * bool   (** alt, control, shift, system *)
  | KeyReleased of SFKey.t * bool * bool * bool * bool   (** alt, control, shift, system *)
  | TextEntered of int32
  | MouseEntered
  | MouseLeft
  | LostFocus
  | GainedFocus
  | JoystickMoved of int * joystick_axis * float  (** joystickId, axis, position *)
  | JoystickButtonPressed of int * int  (** joystickId, button *)
  | JoystickButtonReleased of int * int  (** joystickId, button *)
  | JoystickConnected of int  (** joystickId *)
  | JoystickDisconnected of int  (** joystickId *)
