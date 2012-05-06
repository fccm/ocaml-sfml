(**  *)

type t

val createFromFile : filename:string -> t
val createFromColor: width:int -> height:int -> color:SFColor.t -> t
val createFromMemory: data:string -> t
val createFromPixels: width:int -> height:int -> data:string -> t
val createFromPixelsArray: pixels:(int * int * int * int) array array -> t

val getWidth : image:t -> int
val getHeight : image:t -> int
val getDims : image:t -> int * int

type gl_image =
  (int, Bigarray.int8_unsigned_elt, Bigarray.c_layout) Bigarray.Genarray.t
(** the same type defined in glMLite *)

val getPixelsBA : image:t -> gl_image

val getPixel4: image:t -> x:int -> y:int -> SFColor.t
val getPixel3: image:t -> x:int -> y:int -> SFColor.t
val getPixelRGB: image:t -> x:int -> y:int -> SFColor.rgb
val getPixelRGBA: image:t -> x:int -> y:int -> SFColor.rgba

val saveToFile: image:t -> filename:string -> unit
val setPixel: image:t -> x:int -> y:int -> color:SFColor.t -> unit
val setSmooth: image:t -> smooth:bool -> unit
val isSmooth: image:t -> bool
val bind: image:t -> unit
