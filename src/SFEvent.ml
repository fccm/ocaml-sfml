type t =
  | Closed
  | MouseMoved of int * int
  | Resized of int * int
  | MouseButtonPressed of SFMouse.mouse_button * int * int
  | MouseButtonReleased of SFMouse.mouse_button * int * int
  | MouseWheelMoved of int * int * int [@deprecated "Use MouseWheelScrolled instead"]
  | MouseWheelScrolled of SFMouse.mouse_wheel * float * int * int
  | KeyPressed of SFKey.t * bool * bool * bool * bool
  | KeyReleased of SFKey.t * bool * bool * bool * bool
  | TextEntered of int32
  | MouseEntered
  | MouseLeft
  | LostFocus
  | GainedFocus
  | JoystickMoved of int * SFJoystick.axis * float
  | JoystickButtonPressed of int * int
  | JoystickButtonReleased of int * int
  | JoystickConnected of int
  | JoystickDisconnected of int
  | TouchBegan of int * int * int
  | TouchMoved of int * int * int
  | TouchEnded of int * int * int
  | SensorChanged of SFSensor.sensor_type * (float * float * float)
