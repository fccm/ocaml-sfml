type t

type matrix = {
    a00: float;
    a01: float;
    a02: float;
    a10: float;
    a11: float;
    a12: float;
    a20: float;
    a21: float;
    a22: float;
  }

external fromMatrix: matrix:matrix -> t = "caml_sfTransform_fromMatrix"
external getIdentity: unit -> t = "caml_sfTransform_Identity"
external getMatrix: transform:t -> float array = "caml_sfTransform_getMatrix"
external getInverse: transform:t -> t = "caml_sfTransform_getInverse"
external combine: transform:t -> other:t -> unit = "caml_sfTransform_combine"

external translate: transform:t -> (float * float) -> unit
  = "caml_sfTransform_translate2"
external translate2: transform:t -> x:float -> y:float -> unit
  = "caml_sfTransform_translate"

external rotate: transform:t -> angle:float -> unit = "caml_sfTransform_rotate"

external rotateWithCenter:
  transform:t -> angle:float -> center:float * float -> unit
  = "caml_sfTransform_rotateWithCenter2"

external rotateWithCenter2:
  transform:t -> angle:float -> centerX:float -> centerY:float -> unit
  = "caml_sfTransform_rotateWithCenter"

external scale: transform:t -> scaleX:float -> scaleY:float -> unit
  = "caml_sfTransform_scale"
