(**  *)
(** {{:https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Shape.php}
  Online documentation for the Shape class} *)

type t
val create : (float * float) array -> t

val move : shape:t -> offset:float * float -> unit
val move2 : shape:t -> offsetX:float -> offsetY:float -> unit

val rotate : shape:t -> angle:float -> unit

val scale : shape:t -> factors:float * float -> unit
val scale2 : shape:t -> factorX:float -> factorY:float -> unit

val setPosition : shape:t -> pos:float * float -> unit
val setPosition2 : shape:t -> posX:float -> posY:float -> unit

val setRotation : shape:t -> angle:float -> unit

val setScale : shape:t -> scale:float * float -> unit
val setScale2 : shape:t -> scaleX:float -> scaleY:float -> unit

val setOrigin : shape:t -> origin:float * float -> unit
val setOrigin2 : shape:t -> originX:float -> originY:float -> unit

val setFillColor : shape:t -> color:SFColor.t -> unit
val setOutlineColor : shape:t -> color:SFColor.t -> unit
val setOutlineThickness : shape:t -> thickness:float -> unit
val update : shape:t -> unit
val getPointCount: shape:t -> int

val of_circle : SFCircleShape.t -> t
val of_rectangle : SFRectangleShape.t -> t
