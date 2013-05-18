(**  *)
(** {{:http://sfml-dev.org/documentation/2.0/classsf_1_1VideoMode.php}
  Online documentation for the VideoMode class} *)

type t
type uint = int
type contents = { width : uint; height : uint; bitsPerPixel : uint; }
external getFullscreenModes : unit -> contents array
  = "caml_sfVideoMode_getFullscreenModes"
external getDesktopMode : unit -> contents
  = "caml_sfVideoMode_getDesktopMode"
