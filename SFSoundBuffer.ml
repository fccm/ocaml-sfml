type u
external createFromFile: filename:string -> u = "caml_sfSoundBuffer_CreateFromFile"
external createFromMemory: data:string -> u = "caml_sfSoundBuffer_CreateFromMemory"

external destroy: soundBuffer:u -> unit = "caml_sfSoundBuffer_Destroy"
external getSamplesCount: soundBuffer:u -> int = "caml_sfSoundBuffer_GetSamplesCount"
external getSampleRate: soundBuffer:u -> int = "caml_sfSoundBuffer_GetSampleRate"
external getChannelsCount: soundBuffer:u -> int = "caml_sfSoundBuffer_GetChannelsCount"
external getDuration: soundBuffer:u -> float = "caml_sfSoundBuffer_GetDuration"
external saveToFile: soundBuffer:u -> filename:string -> unit = "caml_sfSoundBuffer_SaveToFile"

(* ================ *)

type t = { u:u; s:string }

let destroy sbuf = destroy sbuf.u

let createFromFile ~filename =
  let u = createFromFile ~filename in
  let t = {u=u; s=" "} in
  Gc.finalise destroy t;
  (t)

let createFromMemory ~data =
  let u = createFromMemory ~data in
  let t = {u=u; s=" "} in
  Gc.finalise destroy t;
  (t)

let getSamplesCount ~soundBuffer:t  = getSamplesCount ~soundBuffer:t.u
let getSampleRate ~soundBuffer:t    = getSampleRate ~soundBuffer:t.u
let getChannelsCount ~soundBuffer:t = getChannelsCount ~soundBuffer:t.u
let getDuration ~soundBuffer:t      = getDuration ~soundBuffer:t.u
let saveToFile ~soundBuffer:t       = saveToFile ~soundBuffer:t.u
