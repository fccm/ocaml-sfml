(** *)
(** {{:http://www.sfml-dev.org/documentation/2.0/group__system.php}
  Online documentation for the system module} *)

type time_src =
    [ `of_microseconds of int64
    | `of_milliseconds of int32
    | `of_seconds of float
    | `of_sfTime of SFTime.t ]
class time :
  time_src ->
  object
    val time : SFTime.t
    method as_microseconds : unit -> int64
    method as_milliseconds : unit -> int32
    method as_seconds : unit -> float
    method t : SFTime.t
  end
module Time :
  sig
    val add : time -> time -> time
    val sub : time -> time -> time
    val mul : float -> time -> time
    val mult : time -> float -> time
    val div : time -> float -> time
    val ( + ) : time -> time -> time
    val ( - ) : time -> time -> time
    val ( * ) : float -> time -> time
    val ( *. ) : time -> float -> time
    val ( / ) : time -> float -> time
  end
val sleep : duration:time -> unit
val sleep_sec : duration:float -> unit
val sleep_msec : duration:int32 -> unit
val sleep_musec : duration:int64 -> unit
type time_as = [ `microseconds | `milliseconds | `seconds ]
class clock :
  object
    val clock : SFClock.t
    method destroy : unit -> unit
    method elapsed_time_as_microseconds : int64
    method elapsed_time_as_milliseconds : int32
    method elapsed_time_as_seconds : float
    method get_elapsed_time : unit -> SFTime.t
    method get_elapsed_time_as : time_as -> float
    method restart : unit -> SFTime.t
    method restart_as : time_as -> float
    method restart_as_microseconds : unit -> int64
    method restart_as_milliseconds : unit -> int32
    method restart_as_seconds : unit -> float
  end
class pausable_clock :
  paused:bool ->
  object
    val clock : SFPausableClock.t
    method destroy : unit -> unit
    method elapsed_time : SFTime.t
    method get_elapsed_time : unit -> SFTime.t
    method is_paused : unit -> bool
    method pause : unit -> unit
    method restart : paused:bool -> SFTime.t
    method start : unit -> unit
  end
val config : < compiled_version : int * int >
