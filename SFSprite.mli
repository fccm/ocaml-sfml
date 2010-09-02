type t
val create : unit -> t
val make : ?image:SFImage.t -> unit -> t
val setImage : sprite:t -> image:SFImage.t -> unit
val resize : sprite:t -> width:float -> height:float -> unit
val setX : sprite:t -> x:float -> unit
val setY : sprite:t -> y:float -> unit
val setXY : sprite:t -> x:float -> y:float -> unit
val setPosition : sprite:t -> x:float -> y:float -> unit
val setPosition2 : sprite:t -> pos:float * float -> unit
val move : sprite:t -> offsetX:float -> offsetY:float -> unit
val move2 : sprite:t -> offset:float * float -> unit
val scale : sprite:t -> factorX:float -> factorY:float -> unit
val scale2 : sprite:t -> factor:float * float -> unit
val rotate : sprite:t -> angle:float -> unit
val flipX : sprite:t -> flipped:bool -> unit
val flipY : sprite:t -> flipped:bool -> unit
val setScaleX : sprite:t -> scale:float -> unit
val setScaleY : sprite:t -> scale:float -> unit
val setScale : sprite:t -> scaleX:float -> scaleY:float -> unit
val setScale2 : sprite:t -> scale:float * float -> unit
val setRotation : sprite:t -> rotation:float -> unit
val setCenter : sprite:t -> x:float -> y:float -> unit
val setCenter2 : sprite:t -> center:float * float -> unit
val setColor : sprite:t -> color:SFColor.t -> unit
val setBlendMode : sprite:t -> mode:SFBlendMode.t -> unit
val getX : sprite:t -> float
val getY : sprite:t -> float
val getXY : sprite:t -> float * float
val getWidth : sprite:t -> float
val getHeight : sprite:t -> float
val getDims : sprite:t -> float * float
val getScaleX : sprite:t -> float
val getScaleY : sprite:t -> float
val getScale : sprite:t -> float * float
val getRotation : sprite:t -> float
val getCenterX : sprite:t -> float
val getCenterY : sprite:t -> float
val getCenter : sprite:t -> float * float
val getSubRect: sprite:t -> int SFRect.t
