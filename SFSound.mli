type t

type sound_status =
  | Stopped  (* sound is not playing *)
  | Paused   (* sound is paused *)
  | Playing  (* sound is playing *)

val create : unit -> t
val setBuffer : sound:t -> buffer:SFSoundBuffer.t -> unit
val play : sound:t -> unit
val pause : sound:t -> unit
val stop : sound:t -> unit
val setLoop : sound:t -> loop:bool -> unit
val getLoop : sound:t -> bool
val getStatus : sound:t -> sound_status
val setPitch : sound:t -> pitch:float -> unit
val setVolume : sound:t -> volume:float -> unit
val setPosition : sound:t -> x:float -> y:float -> z:float -> unit
val setRelativeToListener : sound:t -> relative:bool -> unit
val setMinDistance : sound:t -> minDistance:float -> unit
val setAttenuation : sound:t -> attenuation:float -> unit
val setPlayingOffset : sound:t -> timeOffset:float -> unit
val getPlayingOffset : sound:t -> float
val getPitch: sound:t -> float
val getVolume: sound:t -> float
val isRelativeToListener: sound:t -> bool
val getPosition: sound:t -> float * float * float
val getMinDistance: sound:t -> float
val getAttenuation: sound:t -> float
