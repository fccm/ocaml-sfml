external isConnected: joystick:int -> bool = "caml_sfJoystick_isConnected"

external getButtonCount: joystick:int -> int = "caml_sfJoystick_getButtonCount"

external update: unit -> unit = "caml_sfJoystick_update"

external isButtonPressed: joystick:int -> button:int -> bool
  = "caml_sfJoystick_isButtonPressed"

external getMaxJoystickCount: unit -> int = "caml_sfJoystickCount"
external getMaxJoystickButtonCount: unit -> int = "caml_sfJoystickButtonCount"
external getMaxJoystickAxisCount: unit -> int = "caml_sfJoystickAxisCount"

external normaliseDirectionProportional:
  x:float -> y:float -> float * float
  = "caml_sfJoystick_normaliseDirectionProportional"

type axis =
  | X
  | Y
  | Z
  | R
  | U
  | V
  | PovX
  | PovY

external hasAxis: joystick:int -> axis:axis -> bool
  = "caml_sfJoystick_hasAxis"

external getAxisPosition: joystick:int -> axis:axis -> float
  = "caml_sfJoystick_getAxisPosition"

let string_of_axis = function
  | X     -> "X"
  | Y     -> "Y"
  | Z     -> "Z"
  | R     -> "R"
  | U     -> "U"
  | V     -> "V"
  | PovX  -> "PovX"
  | PovY  -> "PovY"

let axis_of_string s =
  match String.lowercase s with
  | "x"     -> X
  | "y"     -> Y
  | "z"     -> Z
  | "r"     -> R
  | "u"     -> U
  | "v"     -> V
  | "povx"  -> PovX
  | "povy"  -> PovY
  | _ -> invalid_arg "axis_of_string"
