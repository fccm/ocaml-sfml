(**  *)
(** {{:http://sfml-dev.org/documentation/2.0/classsf_1_1ml_system_oo.php}
  Online documentation for the ml_system_oo class} *)

type time_src =
    [ `of_microseconds of int64
    | `of_milliseconds of int32
    | `of_seconds of float
    | `of_sfTime of SFTime.t ]
class time :
  time_src ->
  object
    val time : SFTime.t
    method asMicroseconds : unit -> int64
    method asMilliseconds : unit -> int32
    method asSeconds : unit -> float
    method t : SFTime.t
  end
module Time :
  sig
    val add : < t : SFTime.t; .. > -> < t : SFTime.t; .. > -> time
    val sub : < t : SFTime.t; .. > -> < t : SFTime.t; .. > -> time
    val mul : float -> < t : SFTime.t; .. > -> time
    val mult : < t : SFTime.t; .. > -> float -> time
    val div : < t : SFTime.t; .. > -> float -> time
    val ( + ) : < t : SFTime.t; .. > -> < t : SFTime.t; .. > -> time
    val ( - ) : < t : SFTime.t; .. > -> < t : SFTime.t; .. > -> time
    val ( * ) : float -> < t : SFTime.t; .. > -> time
    val ( *. ) : < t : SFTime.t; .. > -> float -> time
    val ( / ) : < t : SFTime.t; .. > -> float -> time
  end
val sleep : duration:time -> unit
val sleep_sec : duration:float -> unit
val sleep_msec : duration:int32 -> unit
val sleep_musec : duration:int64 -> unit
class clock :
  object
    val clock : SFClock.t
    method destroy : unit -> unit
    method getElapsedTime : unit -> SFTime.t
    method getElapsedTime_asMicroseconds : unit -> int64
    method getElapsedTime_asMilliseconds : unit -> int32
    method getElapsedTime_asSeconds : unit -> float
    method restart : unit -> SFTime.t
    method restart_asSeconds : unit -> float
  end
class pausableClock :
  paused:bool ->
  object
    val clock : SFPausableClock.t
    method destroy : unit -> unit
    method getElapsedTime : unit -> SFTime.t
    method isPaused : unit -> bool
    method pause : unit -> unit
    method restart : paused:bool -> SFTime.t
    method start : unit -> unit
  end
