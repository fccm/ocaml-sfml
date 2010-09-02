type t
val createFromFile : filename:string -> t
val getWidth : image:t -> int
val getHeight : image:t -> int
val getDims : image:t -> int * int

(* the same type defined in glMLite *)
type gl_image =
  (int, Bigarray.int8_unsigned_elt, Bigarray.c_layout) Bigarray.Genarray.t

val getPixelsBA : image:t -> gl_image

val saveToFile: image:t -> filename:string -> unit
val setPixel: image:t -> x:int -> y:int -> color:SFColor.t -> unit
val setSmooth: image:t -> smooth:bool -> unit
val isSmooth: image:t -> bool
val bind: image:t -> unit
