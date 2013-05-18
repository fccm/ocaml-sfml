type t
val create : ?radius:float -> ?pointCount:int -> unit -> t
val setPointCount: circle:t -> count:int -> unit
val getPointCount: circle:t -> int

val setPosition: circle:t -> position:float * float -> unit
val setFillColor: circle:t -> color:SFColor.t -> unit
val setRadius: circle:t -> radius:float -> unit
val getRadius: circle:t -> float

val setOutlineColor: circle:t -> color:SFColor.t -> unit
val setOutlineThickness: circle:t -> thickness:float -> unit
