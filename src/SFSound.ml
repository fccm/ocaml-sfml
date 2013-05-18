type u

external create: unit -> u = "caml_sfSound_create"
external destroy: u -> unit = "caml_sfSound_destroy"
external copy: sound:u -> u = "caml_sfSound_copy"

external play: sound:u -> unit = "caml_sfSound_play"
external pause: sound:u -> unit = "caml_sfSound_pause"
external stop: sound:u -> unit = "caml_sfSound_stop"

external setLoop: sound:u -> loop:bool -> unit = "caml_sfSound_setLoop"
external getLoop: sound:u -> bool = "caml_sfSound_getLoop"

type sound_status =
  | Stopped  (* sound is not playing *)
  | Paused   (* sound is paused *)
  | Playing  (* sound is playing *)

external getStatus: sound:u -> sound_status = "caml_sfSound_getStatus"
external setPitch: sound:u -> pitch:float -> unit = "caml_sfSound_setPitch"
external setVolume: sound:u -> volume:float -> unit = "caml_sfSound_setVolume"
external setPosition: sound:u -> x:float -> y:float -> z:float -> unit = "caml_sfSound_setPosition"
external setPosition3: sound:u -> pos:float * float * float -> unit = "caml_sfSound_setPosition3"
external setRelativeToListener: sound:u -> relative:bool -> unit = "caml_sfSound_setRelativeToListener"
external setMinDistance: sound:u -> minDistance:float -> unit = "caml_sfSound_setMinDistance"
external setAttenuation: sound:u -> attenuation:float -> unit = "caml_sfSound_setAttenuation"
external setPlayingOffset: sound:u -> timeOffset:SFTime.t -> unit = "caml_sfSound_setPlayingOffset"
external getPlayingOffset: sound:u -> SFTime.t = "caml_sfSound_getPlayingOffset"
external setBuffer: sound:u -> buffer:SFSoundBuffer.t -> unit = "caml_sfSound_setBuffer"
external getPitch: sound:u -> float = "caml_sfSound_getPitch"
external getVolume: sound:u -> float = "caml_sfSound_getVolume"
external isRelativeToListener: sound:u -> bool = "caml_sfSound_isRelativeToListener"
external getPosition: sound:u -> float * float * float = "caml_sfSound_getPosition"
external getMinDistance: sound:u -> float = "caml_sfSound_getMinDistance"
external getAttenuation: sound:u -> float = "caml_sfSound_getAttenuation"

(* ================ *)

type t = { u:u; mutable buf:SFSoundBuffer.t option; s:string }

let destroy sound =
  Printf.printf "# destroying sound (%s)...\n%!" sound.s;
  destroy sound.u

let create () =
  let u = create () in
  let t = {u=u; buf=None; s=" "} in
  Gc.finalise destroy t;
  (t)

let copy ~sound:t =
  let u = copy ~sound:t.u in
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
let setPosition3 ~sound:t          = setPosition3 ~sound:t.u
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
