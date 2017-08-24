type t

val zero : t

val of_seconds : float -> t

val of_milliseconds : int32 -> t

external of_microseconds : int64 -> t = "%identity"

val asSeconds : t -> float

val asMilliseconds : t -> int32

external asMicroseconds : t -> int64 = "%identity"

val add : t -> t -> t

val sub : t -> t -> t

val mul : t -> float -> t

val div : t -> float -> t

val ratio : t -> t -> float

val rem : t -> t -> t

val ( + ) : t -> t -> t

val ( - ) : t -> t -> t

val ( * ) : t -> float -> t

val ( / ) : t -> float -> t

val ( // ) : t -> t -> float

val ( mod ) : t -> t -> t

val compare : t -> t -> int

external sleep : t -> unit = "caml_sfSleep"
