type mouse_button =
  | ButtonLeft
  | ButtonRight
  | ButtonMiddle
  | ButtonX1
  | ButtonX2

external getButtonCount: unit -> int = "caml_sfMouseButtonCount"
external isButtonPressed: button:mouse_button -> bool
  = "caml_sfMouse_isButtonPressed"

external getPosition: unit -> int * int = "caml_sfMouse_getPosition"
external setPosition: pos:int * int -> unit = "caml_sfMouse_setPosition"
(** for the [relativeTo] parameters, see the module [SFWindow] *)

let string_of_button = function
  | ButtonLeft    -> "ButtonLeft"
  | ButtonRight   -> "ButtonRight"
  | ButtonMiddle  -> "ButtonMiddle"
  | ButtonX1      -> "ButtonX1"
  | ButtonX2      -> "ButtonX2"

let button_of_string s =
  match String.lowercase s with
  | "buttonleft"    -> ButtonLeft
  | "buttonright"   -> ButtonRight
  | "buttonmiddle"  -> ButtonMiddle
  | "buttonx1"      -> ButtonX1
  | "buttonx2"      -> ButtonX2
  | _ -> invalid_arg "SFMouse.button_of_string"

