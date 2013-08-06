type u
type samples =
  (int, Bigarray.int16_signed_elt, Bigarray.c_layout) Bigarray.Array1.t

external loadFromFile: filename:string -> u = "caml_sfSoundBuffer_loadFromFile"
external loadFromMemory: data:string -> u = "caml_sfSoundBuffer_loadFromMemory"

external loadFromSamples:
  samples:samples ->
  channelCount:int -> sampleRate:int -> u
  = "caml_sfSoundBuffer_loadFromSamples"

external destroy: u -> unit = "caml_sfSoundBuffer_destroy"
external getSampleCount: u -> int = "caml_sfSoundBuffer_getSampleCount"
external getSampleRate: u -> int = "caml_sfSoundBuffer_getSampleRate"
external getChannelCount: u -> int = "caml_sfSoundBuffer_getChannelCount"
external getDuration: u -> SFTime.t = "caml_sfSoundBuffer_getDuration"
external saveToFile: u -> filename:string -> unit = "caml_sfSoundBuffer_saveToFile"

(* ================ *)

type t = { u:u; s:string }

let destroy sbuf =
  Printf.printf "# destroying soundBuffer (%s)...\n%!" sbuf.s;
  destroy sbuf.u

let loadFromFile ~filename =
  let u = loadFromFile ~filename in
  let t = {u=u; s=" "} in
  Gc.finalise destroy t;
  (t)

let loadFromMemory ~data =
  let u = loadFromMemory ~data in
  let t = {u=u; s=" "} in
  Gc.finalise destroy t;
  (t)

let loadFromSamples ~samples ~channelCount ~sampleRate =
  let u = loadFromSamples ~samples ~channelCount ~sampleRate in
  let t = {u=u; s=" "} in
  Gc.finalise destroy t;
  (t)

let getSampleCount soundBuffer  = getSampleCount soundBuffer.u
let getSampleRate soundBuffer   = getSampleRate soundBuffer.u
let getChannelCount soundBuffer = getChannelCount soundBuffer.u
let getDuration soundBuffer     = getDuration soundBuffer.u
let saveToFile soundBuffer      = saveToFile soundBuffer.u

type input = [
  | `File of string
  | `Memory of string
  | `Samples of (samples * int * int)
  ]

let load = function
  | `File filename -> loadFromFile ~filename
  | `Memory data -> loadFromMemory ~data
  | `Samples (samples, channelCount, sampleRate) ->
      loadFromSamples ~samples ~channelCount ~sampleRate
