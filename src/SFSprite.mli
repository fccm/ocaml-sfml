(** *)
(** {{:https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Sprite.php}
  Online documentation for the Sprite class} *)

type t
val create : unit -> t
val copy : sprite:t -> t
val setPosition : sprite:t -> pos:float * float -> unit
val setPosition2 : sprite:t -> x:float -> y:float -> unit
val move : sprite:t -> offset:float * float -> unit
val move2 : sprite:t -> offsetX:float -> offsetY:float -> unit
val scale : sprite:t -> factors:float * float -> unit
val scale2 : sprite:t -> factorX:float -> factorY:float -> unit
val rotate : sprite:t -> angle:float -> unit
val setScale : sprite:t -> scale:float * float -> unit
val setScale2 : sprite:t -> scaleX:float -> scaleY:float -> unit
val setRotation : sprite:t -> rotation:float -> unit
val setOrigin : sprite:t -> origin:float * float -> unit
val setColor : sprite:t -> color:SFColor.t -> unit
val setTexture: sprite:t -> texture:SFTexture.t -> resetRect:bool -> unit
val getScaleX : sprite:t -> float
val getScaleY : sprite:t -> float
val getScale : sprite:t -> float * float
val getRotation : sprite:t -> float
