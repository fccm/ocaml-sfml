type t

external create: unit -> t = "caml_sfView_create"
external createFromRect: rect:float SFRect.t -> t = "caml_sfView_createFromRect"
external copy: view:t -> unit = "caml_sfView_copy"
external setCenter: view:t -> center:float * float -> unit
  = "caml_sfView_setCenter"
external setCenter2: view:t -> x:float -> y:float -> unit
  = "caml_sfView_setCenter2"
external setSize: view:t -> size:float * float -> unit
  = "caml_sfView_setSize"
external setSize2: view:t -> width:float -> height:float -> unit
  = "caml_sfView_setSize2"
external move: view:t -> offset:float * float -> unit
  = "caml_sfView_move"
external move2: view:t -> offsetX:float -> offsetY:float -> unit
  = "caml_sfView_move2"
external zoom: view:t -> factor:float -> unit = "caml_sfView_zoom"
external getCenter: view:t -> float * float = "caml_sfView_getCenter"
external getSize: view:t -> float * float = "caml_sfView_getSize"
