type t

external create: unit -> t = "caml_sfClock_create"

external restart: t -> SFTime.t = "caml_sfClock_restart"

external getElapsedTime: t -> SFTime.t = "caml_sfClock_getElapsedTime"
