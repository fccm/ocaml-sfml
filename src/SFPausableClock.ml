type t

external create: paused:bool -> t = "caml_sfPausableClock_create"
external destroy: clock:t -> unit = "caml_sfPausableClock_destroy"
external isPaused: clock:t -> bool = "caml_sfPausableClock_isPaused"
external getElapsedTime: clock:t -> SFTime.t = "caml_sfPausableClock_getElapsedTime"
external restart: clock:t -> paused:bool -> SFTime.t = "caml_sfPausableClock_restart"
external pause: clock:t -> unit = "caml_sfPausableClock_pause"
external start: clock:t -> unit = "caml_sfPausableClock_start"

external getElapsedTime_asSeconds: clock:t -> float
  = "caml_sfPausableClock_getElapsedTime_asSeconds"
