(** *)
(** {{:http://sfml-dev.org/documentation/2.0/classsf_1_1Text.php}
  Online documentation for the Text class} *)

type t
val create : unit -> t

val make :
  ?font:SFFont.t ->
  ?color:SFColor.t ->
  ?charSize:int ->
  ?pos:float * float ->
  ?rotation:float ->
  ?scale:float * float -> ?origin:float * float -> string -> t

val setString : text:t -> str:string -> unit
val setFont : text:t -> font:SFFont.t -> unit
val setPosition : text:t -> pos:float * float -> unit
val setPosition2 : text:t -> left:float -> top:float -> unit
val setColor : text:t -> color:SFColor.t -> unit [@deprecated "use set{Outline,Fill}Color instead"]
val setOutlineThickness : text:t -> thickness:float -> unit
val setOutlineColor : text:t -> color:SFColor.t -> unit
val setFillColor : text:t -> color:SFColor.t -> unit
val setCharacterSize : text:t -> size:int -> unit
val setOrigin : text:t -> origin:float * float -> unit
val setRotation : text:t -> rotation:float -> unit
val setScale : text:t -> scale:float * float -> unit
val setScale2 : text:t -> scaleX:float -> scaleY:float -> unit
val move : text:t -> offset:float * float -> unit
val move2 : text:t -> offsetX:float -> offsetY:float -> unit
val rotate : text:t -> angle:float -> unit
val scale : text:t -> factors:float * float -> unit
val scale2 : text:t -> factorX:float -> factorY:float -> unit
val getLocalBounds : text:t -> float SFRect.t
val getGlobalBounds : text:t -> float SFRect.t
