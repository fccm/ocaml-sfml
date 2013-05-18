(**  *)
(** {{:http://sfml-dev.org/documentation/2.0/classsf_1_1SoundBuffer.php}
  Online documentation for the SoundBuffer class} *)

type t
val loadFromFile : filename:string -> t
val loadFromMemory : data:string -> t
val loadFromSamples :
  samples:
    (int, Bigarray.int16_signed_elt, Bigarray.c_layout) Bigarray.Array1.t ->
  channelCount:int -> sampleRate:int -> t

val getSampleCount : soundBuffer:t -> int
val getSampleRate : soundBuffer:t -> int
val getChannelCount : soundBuffer:t -> int
val getDuration : soundBuffer:t -> SFTime.t
val saveToFile : soundBuffer:t -> filename:string -> unit
