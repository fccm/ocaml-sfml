
type t = {
  width: int;
  height: int;
  bitsPerPixel: int;
}

external getFullscreenModes: unit -> t array
  = "caml_sfVideoMode_getFullscreenModes"

external getDesktopMode: unit -> t
  = "caml_sfVideoMode_getDesktopMode"

external isValid: t -> bool
  = "caml_sfVideoMode_isValid"

let make ?(bpp = 32) (width, height) = {
  width; height;
  bitsPerPixel = bpp;
}

