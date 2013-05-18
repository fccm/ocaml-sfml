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
