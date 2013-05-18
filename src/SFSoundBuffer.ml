type u
external loadFromFile: filename:string -> u = "caml_sfSoundBuffer_loadFromFile"
external loadFromMemory: data:string -> u = "caml_sfSoundBuffer_loadFromMemory"

external loadFromSamples:
  samples:
    (int, Bigarray.int16_signed_elt, Bigarray.c_layout) Bigarray.Array1.t ->
  channelCount:int -> sampleRate:int -> u
  = "caml_sfSoundBuffer_loadFromSamples"

external destroy: u -> unit = "caml_sfSoundBuffer_destroy"
external getSampleCount: soundBuffer:u -> int = "caml_sfSoundBuffer_getSampleCount"
external getSampleRate: soundBuffer:u -> int = "caml_sfSoundBuffer_getSampleRate"
external getChannelCount: soundBuffer:u -> int = "caml_sfSoundBuffer_getChannelCount"
external getDuration: soundBuffer:u -> SFTime.t = "caml_sfSoundBuffer_getDuration"
external saveToFile: soundBuffer:u -> filename:string -> unit = "caml_sfSoundBuffer_saveToFile"

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

let getSampleCount ~soundBuffer:t  = getSampleCount ~soundBuffer:t.u
let getSampleRate ~soundBuffer:t   = getSampleRate ~soundBuffer:t.u
let getChannelCount ~soundBuffer:t = getChannelCount ~soundBuffer:t.u
let getDuration ~soundBuffer:t     = getDuration ~soundBuffer:t.u
let saveToFile ~soundBuffer:t      = saveToFile ~soundBuffer:t.u
