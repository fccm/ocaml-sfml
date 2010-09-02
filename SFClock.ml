type t

external create: unit -> t = "caml_sfClock_Create"
external destroy: clock:t -> unit = "caml_sfClock_Destroy"
external getTime: clock:t -> float = "caml_sfClock_GetTime"
external reset: clock:t -> unit = "caml_sfClock_Reset"

external sleep: duration:float -> unit = "caml_sfSleep"
