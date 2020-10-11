(**  *)
(** {{:https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Event.php}
  Online documentation for the Event class} *)

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
  | TouchBegan of int * int * int  (** finger, x, y *)
  | TouchMoved of int * int * int  (** finger, x, y *)
  | TouchEnded of int * int * int  (** finger, x, y *)
  | SensorChanged of SFSensor.sensor_type * (float * float * float) (** type, x, y, z *)
