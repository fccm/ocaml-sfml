type native_cursor =
  | Arrow
  | ArrowWait
  | Wait
  | Text
  | Hand
  | SizeHorizontal
  | SizeVertical
  | SizeTopLeftBottomRight
  | SizeBottomLeftTopRight
  | SizeAll
  | Cross
  | Help
  | NotAllowed

type t

external loadFromPixels: data:bytes -> size:int * int -> hotspot:int * int -> t
  = "caml_sfCursor_loadFromPixels"
external loadFromSystem: native_cursor -> t = "caml_sfCursor_loadFromSystem"
