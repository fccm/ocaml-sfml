type t

external create: paused:bool -> t = "caml_sfPausableClock_Create"
external destroy: clock:t -> unit = "caml_sfPausableClock_Destroy"
external getTime: clock:t -> float = "caml_sfPausableClock_GetTime"
external reset: clock:t -> paused:bool -> unit = "caml_sfPausableClock_Reset"
external pause: clock:t -> unit = "caml_sfPausableClock_Pause"
external start: clock:t -> unit = "caml_sfPausableClock_Start"
