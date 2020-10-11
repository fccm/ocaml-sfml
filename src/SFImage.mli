(**  *)
(** {{:https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Image.php}
  Online documentation for the Image class} *)

type t

val createFromFile: filename:string -> t
val createFromColor: width:int -> height:int -> color:SFColor.t -> t
val createFromMemory: data:bytes -> t
val createFromPixels: width:int -> height:int -> data:bytes -> t
val createFromPixelsArray: pixels:(int * int * int * int) array array -> t

type input =
  [ `Filename of string
  | `Memory of bytes
  | `Color of int * int * SFColor.t
  | `Pixels of int * int * bytes
  | `PixelsArray of (int * int * int * int) array array
  ]

val create: input -> t

val getWidth: image:t -> int
val getHeight: image:t -> int
val getSize: image:t -> int * int

type gl_image =
  (int, Bigarray.int8_unsigned_elt, Bigarray.c_layout) Bigarray.Genarray.t
(** the same type defined in glMLite *)

val getPixelsBA: image:t -> gl_image
val getPixelsStr: image:t -> string

val getPixel4: image:t -> x:int -> y:int -> SFColor.t
val getPixel3: image:t -> x:int -> y:int -> SFColor.t
val getPixelRGB: image:t -> x:int -> y:int -> SFColor.rgb
val getPixelRGBA: image:t -> x:int -> y:int -> SFColor.rgba

val saveToFile: image:t -> filename:string -> unit
val setPixel: image:t -> x:int -> y:int -> color:SFColor.t -> unit

val createMaskFromColor: image:t -> color:SFColor.t -> alpha:int -> unit

val flipHorizontally: image:t -> unit
val flipVertically: image:t -> unit
