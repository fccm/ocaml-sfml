type t

external openFromFile: filename:string -> t = "caml_sfMusic_openFromFile"
external openFromMemory: data:string -> t = "caml_sfMusic_openFromMemory"
external destroy: music:t -> unit = "caml_sfMusic_destroy"

external getDuration: music:t -> SFTime.t = "caml_sfMusic_getDuration"

(* in C++ class inherited from sf::SoundStream *)

external play: music:t -> unit = "caml_sfMusic_play"
external pause: music:t -> unit = "caml_sfMusic_pause"
external stop: music:t -> unit = "caml_sfMusic_stop"

external getChannelCount: music:t -> int = "caml_sfMusic_getChannelCount"
external getSampleRate: music:t -> int = "caml_sfMusic_getSampleRate"

type sound_status =
  | Stopped  (** music is not playing *)
  | Paused   (** music is paused *)
  | Playing  (** music is playing *)

external getStatus: music:t -> sound_status = "caml_sfMusic_getStatus"

external setPlayingOffset: music:t -> timeOffset:SFTime.t -> unit = "caml_sfMusic_setPlayingOffset"
external getPlayingOffset: music:t -> SFTime.t = "caml_sfMusic_getPlayingOffset"

external setLoop: music:t -> loop:bool -> unit = "caml_sfMusic_setLoop"
external getLoop: music:t -> bool = "caml_sfMusic_getLoop"

(* in C++ class inherited from sf::SoundSource *)

external setVolume: music:t -> volume:float -> unit = "caml_sfMusic_setVolume"
external getVolume: music:t -> float = "caml_sfMusic_getVolume"

external setPitch: music:t -> pitch:float -> unit = "caml_sfMusic_setPitch"
external getPitch: music:t -> float = "caml_sfMusic_getPitch"

external setRelativeToListener: music:t -> relative:bool -> unit = "caml_sfMusic_setRelativeToListener"
external isRelativeToListener: music:t -> bool = "caml_sfMusic_isRelativeToListener"

external setMinDistance: music:t -> minDistance:float -> unit = "caml_sfMusic_setMinDistance"
external getMinDistance: music:t -> float = "caml_sfMusic_getMinDistance"

external setAttenuation: music:t -> attenuation:float -> unit = "caml_sfMusic_setAttenuation"
external getAttenuation: music:t -> float = "caml_sfMusic_getAttenuation"

external setPosition: music:t -> pos:float * float * float -> unit = "caml_sfMusic_setPosition3"
external setPosition3: music:t -> x:float -> y:float -> z:float -> unit = "caml_sfMusic_setPosition"
external getPosition: music:t -> float * float * float = "caml_sfMusic_getPosition"
