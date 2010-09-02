type mouse_button =
  | ButtonLeft
  | ButtonRight
  | ButtonMiddle
  | ButtonX1
  | ButtonX2

type joy_axis =
  | JoyAxisX
  | JoyAxisY
  | JoyAxisZ
  | JoyAxisR
  | JoyAxisU
  | JoyAxisV
  | JoyAxisPOV

type t =
  | Closed
  | MouseMoved of int * int  (** x, y *)
  | Resized of int * int  (** width, height *)
  | MouseButtonPressed of mouse_button * int * int  (** x, y *)
  | MouseButtonReleased of mouse_button * int * int  (** x, y *)
  | MouseWheelMoved of int  (** delta *)
  | KeyPressed of SFKey.t * bool * bool * bool   (** alt, control, shift *)
  | KeyReleased of SFKey.t * bool * bool * bool   (** alt, control, shift *)
  | TextEntered of int32
  | MouseEntered
  | MouseLeft
  | LostFocus
  | GainedFocus
  | JoyMoved of int * joy_axis * float  (** joystickId, axis, position *)
  | JoyButtonPressed of int * int  (** joystickId, button *)
  | JoyButtonReleased of int * int  (** joystickId, button *)
