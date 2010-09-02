type t

external create: unit -> t = "caml_sfView_Create"
external createFromRect: rect:float SFRect.t -> t = "caml_sfView_CreateFromRect"
external destroy: view:t -> unit = "caml_sfView_Destroy"
external setFromRect: view:t -> rect:float SFRect.t -> unit
  = "caml_sfView_SetFromRect"
external setCenter: view:t -> x:float -> y:float -> unit
  = "caml_sfView_SetCenter"
external move: view:t -> offsetX:float -> offsetY:float -> unit
  = "caml_sfView_Move"
external move2: view:t -> offset:float * float -> unit
  = "caml_sfView_Move2"
external zoom: view:t -> factor:float -> unit = "caml_sfView_Zoom"
external setHalfSize: view:t -> halfWidth:float -> halfHeight:float -> unit
  = "caml_sfView_SetHalfSize"
external getRect: view:t -> float SFRect.t = "caml_sfView_GetRect"
external getCenter: view:t -> float * float = "caml_sfView_GetCenter"
external getHalfSize: view:t -> float * float = "caml_sfView_GetHalfSize"
