type t

type uint = int

type contents = {
  width: uint;
  height: uint;
  bitsPerPixel: uint;
}

external getFullscreenModes: unit -> contents array
  = "caml_sfVideoMode_getFullscreenModes"

external getDesktopMode: unit -> contents
  = "caml_sfVideoMode_getDesktopMode"

let make ?(bpp = 32) (width, height) = {
  width; height;
  bitsPerPixel = bpp;
}
