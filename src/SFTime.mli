(**  *)
(** {{:http://sfml-dev.org/documentation/2.0/classsf_1_1Time.php}
  Online documentation for the Time class} *)

type t
val of_seconds : amount:float -> t
val of_milliseconds : amount:int32 -> t
val of_microseconds : amount:int64 -> t
val asSeconds : t -> float
val asMilliseconds : t -> int32
val asMicroseconds : t -> int64
val add : t -> t -> t
val sub : t -> t -> t
val mul : float -> t -> t
val mult : t -> float -> t
val div : t -> float -> t
val ratio : t -> t -> float
val rem : t -> t -> t
val eq : t -> t -> bool
val gt : t -> t -> bool
val lt : t -> t -> bool
val sleep : duration:t -> unit
val sleep_sec : duration:float -> unit
val sleep_msec : duration:int32 -> unit
val sleep_musec : duration:int64 -> unit
