(** *)
(** {{:https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Sound.php}
  Online documentation for the Sound class} *)

type t

type sound_status =
  | Stopped  (** sound is not playing *)
  | Paused   (** sound is paused *)
  | Playing  (** sound is playing *)

val create : unit -> t
val copy : sound:t -> t
val setBuffer : sound:t -> buffer:SFSoundBuffer.t -> unit
val play : sound:t -> unit
val pause : sound:t -> unit
val stop : sound:t -> unit
val setLoop : sound:t -> loop:bool -> unit
val getLoop : sound:t -> bool
val getStatus : sound:t -> sound_status
val setPitch : sound:t -> pitch:float -> unit
val setVolume : sound:t -> volume:float -> unit
val setPosition : sound:t -> pos:float * float * float -> unit
val setPosition3 : sound:t -> x:float -> y:float -> z:float -> unit
val setRelativeToListener : sound:t -> relative:bool -> unit
val setMinDistance : sound:t -> minDistance:float -> unit
val setAttenuation : sound:t -> attenuation:float -> unit
val setPlayingOffset : sound:t -> timeOffset:SFTime.t -> unit
val getPlayingOffset : sound:t -> SFTime.t
val getPitch : sound:t -> float
val getVolume : sound:t -> float
val isRelativeToListener : sound:t -> bool
val getPosition : sound:t -> float * float * float
val getMinDistance : sound:t -> float
val getAttenuation : sound:t -> float
