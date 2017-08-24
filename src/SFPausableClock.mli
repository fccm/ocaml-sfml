type t

val create : paused:bool -> t

val isPaused : t -> bool

val getElapsedTime : t -> SFTime.t

val restart : t -> paused:bool -> SFTime.t

val pause : t -> unit

val start : t -> unit
