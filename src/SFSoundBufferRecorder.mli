(**  *)
(** {{:https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1SoundBufferRecorder.php}
  Online documentation for the SoundBufferRecorder class} *)

type t
external create : unit -> t = "caml_sfSoundBufferRecorder_create"
external destroy : sbr:t -> unit = "caml_sfSoundBufferRecorder_destroy"
external start : sbr:t -> sampleRate:int -> unit
  = "caml_sfSoundBufferRecorder_start"
external stop : sbr:t -> unit = "caml_sfSoundBufferRecorder_stop"
external getSampleRate : sbr:t -> int
  = "caml_sfSoundBufferRecorder_getSampleRate"
