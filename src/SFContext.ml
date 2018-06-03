type t

external create: unit -> t = "caml_sfContext_create"
external destroy: context:t -> unit = "caml_sfContext_destroy"
external setActive: context:t -> active:bool -> unit
  = "caml_sfContext_setActive"
external getActiveContext: unit -> t option = "caml_sfContext_getActiveContext"
external getActiveContextId: unit -> int64 = "caml_sfContext_getActiveContextId"
