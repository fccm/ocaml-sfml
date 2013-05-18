type t

external create: unit -> t = "caml_sfClock_create"
external destroy: clock:t -> unit = "caml_sfClock_destroy"
external restart: clock:t -> SFTime.t = "caml_sfClock_restart"

external restart_asSeconds: clock:t -> float = "caml_sfClock_restart_asSeconds"
external restart_asMilliseconds: clock:t -> int32 = "caml_sfClock_restart_asMilliseconds"
external restart_asMicroseconds: clock:t -> int64 = "caml_sfClock_restart_asMicroseconds"

(*
external copy: clock:t -> t = "caml_sfClock_copy"
*)

external getElapsedTime: clock:t -> SFTime.t = "caml_sfClock_getElapsedTime"

external getElapsedTime_asSeconds: clock:t -> float
  = "caml_sfClock_getElapsedTime_asSeconds"

external getElapsedTime_asMilliseconds: clock:t -> int32
  = "caml_sfClock_getElapsedTime_asMilliseconds"

external getElapsedTime_asMicroseconds: clock:t -> int64
  = "caml_sfClock_getElapsedTime_asMicroseconds"
