type t

external create: unit -> t = "caml_sfView_create"
external createFromRect: rect:float SFRect.t -> t = "caml_sfView_createFromRect"
external destroy: view:t -> unit = "caml_sfView_destroy"
external setCenter: view:t -> x:float -> y:float -> unit
  = "caml_sfView_setCenter"
external setCenter2: view:t -> center:float * float -> unit
  = "caml_sfView_setCenter2"
external move: view:t -> offsetX:float -> offsetY:float -> unit
  = "caml_sfView_move"
external move2: view:t -> offset:float * float -> unit
  = "caml_sfView_move2"
external zoom: view:t -> factor:float -> unit = "caml_sfView_zoom"
external getCenter: view:t -> float * float = "caml_sfView_getCenter"
external getSize: view:t -> float * float = "caml_sfView_getSize"
