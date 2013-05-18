type t

external create: width:int -> height:int -> t = "caml_sfTexture_create"
external createFromFile: filename:string -> ?area:int SFRect.t -> unit -> t
  = "caml_sfTexture_createFromFile"

external createFromMemory: data:string -> ?area:int SFRect.t -> unit -> t
  = "caml_sfTexture_createFromMemory"

external createFromImage: image:SFImage.t -> ?area:int SFRect.t -> unit -> t
  = "caml_sfTexture_createFromImage"

external copy: t -> t = "caml_sfTexture_copy"

external destroy: t -> unit = "caml_sfTexture_destroy"

type coordinateType =
  | Normalized
  | Pixels

external bind: t -> unit = "caml_sfTexture_bind"

external getSize: t -> int * int = "caml_sfTexture_getSize"
external setSmooth: t -> smooth:bool -> unit = "caml_sfTexture_setSmooth"
external isSmooth: t -> bool = "caml_sfTexture_isSmooth"
external setRepeated: t -> repeated:bool -> unit = "caml_sfTexture_setRepeated"
external isRepeated: t -> bool = "caml_sfTexture_isRepeated"

external getMaximumSize: unit -> int = "caml_sfTexture_getMaximumSize"

type input =
  [ `Filename of string
  | `Memory of string
  | `Image of SFImage.t
  ]

let create_from ?area (input : input) =
  match input with
  | `Filename filename -> createFromFile ~filename ?area ()
  | `Memory data -> createFromMemory ~data ?area ()
  | `Image image -> createFromImage ~image ?area ()
