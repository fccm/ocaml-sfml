type t
external create: unit -> t = "caml_sfeMovie_create"
external openFromFile: movie:t -> filename:string -> unit
  = "caml_sfeMovie_openFromFile"

external play: movie:t -> unit = "caml_sfeMovie_play"
external stop: movie:t -> unit = "caml_sfeMovie_stop"
external pause: movie:t -> unit = "caml_sfeMovie_pause"

external draw: window:SFRenderWindow.t -> movie:t -> unit
  = "caml_sfeMovie_draw"

external resizeToFrame:
  movie:t -> x:int -> y:int -> width:int -> height:int ->
  unit -> unit
  = "caml_sfeMovie_resizeToFrame_bytecode"
    "caml_sfeMovie_resizeToFrame_native"

type status =
  | Stopped
  | Paused
  | Playing

external getStatus: movie:t -> status = "caml_sfeMovie_getStatus"

