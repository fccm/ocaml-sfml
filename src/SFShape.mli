(**  *)
(** {{:http://sfml-dev.org/documentation/2.0/classsf_1_1Shape.php}
  Online documentation for the Shape class} *)

type t
val create : (float * float) array -> t
val move : shape:t -> offsetX:float -> offsetY:float -> unit
val move2 : shape:t -> offset:float * float -> unit
val rotate : shape:t -> angle:float -> unit
val scale : shape:t -> factorX:float -> factorY:float -> unit
val scale2 : shape:t -> factors:float * float -> unit
val setPosition : shape:t -> posX:float -> posY:float -> unit
val setPosition2 : shape:t -> pos:float * float -> unit
val setRotation : shape:t -> angle:float -> unit
val setScale : shape:t -> scaleX:float -> scaleY:float -> unit
val setScale2 : shape:t -> scale:float * float -> unit
val setOrigin : shape:t -> originX:float -> originY:float -> unit
val setOrigin2 : shape:t -> origin:float * float -> unit
val setFillColor : shape:t -> color:SFColor.t -> unit
val setOutlineColor : shape:t -> color:SFColor.t -> unit
val setOutlineThickness : shape:t -> thickness:float -> unit
val update : shape:t -> unit
val getPointCount: shape:t -> int

val of_circle : SFCircleShape.t -> t
val of_rectangle : SFRectangleShape.t -> t
