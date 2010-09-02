type t
val create : unit -> t
val make :
  ?size:float ->
  ?font:SFFont.t ->
  ?color:SFColor.t ->
  ?blend:SFBlendMode.t ->
  ?pos:float * float ->
  ?rotation:float -> ?scale:float * float -> string -> t
val setText : text:t -> str:string -> unit
val setSize : text:t -> size:float -> unit
val setFont : text:t -> font:SFFont.t -> unit
val setPosition : text:t -> left:float -> top:float -> unit
val setPosition2 : text:t -> pos:float * float -> unit
val setColor : text:t -> color:SFColor.t -> unit
val setRotation : text:t -> rotation:float -> unit
val setScale : text:t -> scaleX:float -> scaleY:float -> unit
val move : text:t -> offsetX:float -> offsetY:float -> unit
val move2 : text:t -> offset:float * float -> unit
val rotate : text:t -> angle:float -> unit
val scale : text:t -> factorX:float -> factorY:float -> unit
val scale2 : text:t -> factor:float * float -> unit
val setBlendMode : text:t -> mode:SFBlendMode.t -> unit
val getX : text:t -> float
val getY : text:t -> float
val getXY : text:t -> float * float
val getRect: text:t -> float SFRect.t
