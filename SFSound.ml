type u

external create: unit -> u = "caml_sfSound_Create"
external destroy: sound:u -> unit = "caml_sfSound_Destroy"

external play: sound:u -> unit = "caml_sfSound_Play"
external pause: sound:u -> unit = "caml_sfSound_Pause"
external stop: sound:u -> unit = "caml_sfSound_Stop"

external setLoop: sound:u -> loop:bool -> unit = "caml_sfSound_SetLoop"
external getLoop: sound:u -> bool = "caml_sfSound_GetLoop"

type sound_status =
  | Stopped  (* sound is not playing *)
  | Paused   (* sound is paused *)
  | Playing  (* sound is playing *)

external getStatus: sound:u -> sound_status = "caml_sfSound_GetStatus"
external setPitch: sound:u -> pitch:float -> unit = "caml_sfSound_SetPitch"
external setVolume: sound:u -> volume:float -> unit = "caml_sfSound_SetVolume"
external setPosition: sound:u -> x:float -> y:float -> z:float -> unit = "caml_sfSound_SetPosition"
external setRelativeToListener: sound:u -> relative:bool -> unit = "caml_sfSound_SetRelativeToListener"
external setMinDistance: sound:u -> minDistance:float -> unit = "caml_sfSound_SetMinDistance"
external setAttenuation: sound:u -> attenuation:float -> unit = "caml_sfSound_SetAttenuation"
external setPlayingOffset: sound:u -> timeOffset:float -> unit = "caml_sfSound_SetPlayingOffset"
external getPlayingOffset: sound:u -> float = "caml_sfSound_GetPlayingOffset"
external setBuffer: sound:u -> buffer:SFSoundBuffer.t -> unit = "caml_sfSound_SetBuffer"
external getPitch: sound:u -> float = "caml_sfSound_GetPitch"
external getVolume: sound:u -> float = "caml_sfSound_GetVolume"
external isRelativeToListener: sound:u -> bool = "caml_sfSound_IsRelativeToListener"
external getPosition: sound:u -> float * float * float = "caml_sfSound_GetPosition"
external getMinDistance: sound:u -> float = "caml_sfSound_GetMinDistance"
external getAttenuation: sound:u -> float = "caml_sfSound_GetAttenuation"

(* ================ *)

type t = { u:u; mutable buf:SFSoundBuffer.t option; s:string }

let destroy sound = destroy sound.u

let create() =
  let u = create() in
  let t = {u=u; buf=None; s=" "} in
  Gc.finalise destroy t;
  (t)

let setBuffer ~sound ~buffer =
  sound.buf <- Some buffer;
  setBuffer ~sound:sound.u ~buffer

let play ~sound:t                  = play ~sound:t.u
let pause ~sound:t                 = pause ~sound:t.u
let stop ~sound:t                  = stop ~sound:t.u
let setLoop ~sound:t               = setLoop ~sound:t.u
let getLoop ~sound:t               = getLoop ~sound:t.u
let getStatus ~sound:t             = getStatus ~sound:t.u
let setPitch ~sound:t              = setPitch ~sound:t.u
let setVolume ~sound:t             = setVolume ~sound:t.u
let setPosition ~sound:t           = setPosition ~sound:t.u
let setRelativeToListener ~sound:t = setRelativeToListener ~sound:t.u
let setMinDistance ~sound:t        = setMinDistance ~sound:t.u
let setAttenuation ~sound:t        = setAttenuation ~sound:t.u
let setPlayingOffset ~sound:t      = setPlayingOffset ~sound:t.u
let getPlayingOffset ~sound:t      = getPlayingOffset ~sound:t.u
let getPitch ~sound:t              = getPitch ~sound:t.u
let getVolume ~sound:t             = getVolume ~sound:t.u
let isRelativeToListener ~sound:t  = isRelativeToListener ~sound:t.u
let getPosition ~sound:t           = getPosition ~sound:t.u
let getMinDistance ~sound:t        = getMinDistance ~sound:t.u
let getAttenuation ~sound:t        = getAttenuation ~sound:t.u
