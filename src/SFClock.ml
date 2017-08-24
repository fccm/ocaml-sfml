type t

external create: unit -> t = "caml_sfClock_create"

external restart: clock:t -> SFTime.t = "caml_sfClock_restart"

external getElapsedTime: clock:t -> SFTime.t = "caml_sfClock_getElapsedTime"
