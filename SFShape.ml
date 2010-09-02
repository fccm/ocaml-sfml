type t

external create: unit -> t = "caml_sfShape_Create"
external destroy: shape:t -> unit = "caml_sfShape_Destroy"

external createLine:
  p1:float * float -> p2:float * float -> thickness:float ->
  color:SFColor.t -> outline:float -> outlineCol:SFColor.t -> t
  = "caml_sfShape_CreateLine_bytecode"
    "caml_sfShape_CreateLine"

external createRectangle:
  p1:float * float -> p2:float * float ->
  color:SFColor.t -> outline:float -> outlineCol:SFColor.t -> t
  = "caml_sfShape_CreateRectangle"

external createCircle: center:float * float -> radius:float ->
  color:SFColor.t -> outline:float -> outlineCol:SFColor.t -> t
  = "caml_sfShape_CreateCircle"

external move: shape:t -> offsetX:float -> offsetY:float -> unit = "caml_sfShape_Move"
external move2: shape:t -> offset:float * float -> unit = "caml_sfShape_Move2"
external rotate: shape:t -> angle:float -> unit = "caml_sfShape_Rotate"
external scale: shape:t -> factorX:float -> factorY:float -> unit
  = "caml_sfShape_Scale"
external scale2: shape:t -> factor:float * float -> unit
  = "caml_sfShape_Scale2"

external setBlendMode: shape:t -> mode:SFBlendMode.t -> unit
  = "caml_sfShape_SetBlendMode"

external addPoint: shape:t -> pos:float * float -> color:SFColor.t ->
  outlineCol:SFColor.t -> unit = "caml_sfShape_AddPoint"
