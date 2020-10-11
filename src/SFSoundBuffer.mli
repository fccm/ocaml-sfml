(**  *)
(** {{:https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1SoundBuffer.php}
  Online documentation for the SoundBuffer class} *)

type t
type samples =
  (int, Bigarray.int16_signed_elt, Bigarray.c_layout) Bigarray.Array1.t

val loadFromFile : filename:string -> t
val loadFromMemory : data:string -> t
val loadFromSamples :
  samples:samples ->
  channelCount:int -> sampleRate:int -> t

type input = [
  | `File of string
  | `Memory of string
  | `Samples of (samples * int * int)
  ]

val load : input -> t

val getSampleCount : t -> int
val getSampleRate : t -> int
val getChannelCount : t -> int
val getDuration : t -> SFTime.t
val saveToFile : t -> filename:string -> unit
