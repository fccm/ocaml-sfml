type t

external createFromFile: filename:string -> t = "caml_sfMusic_CreateFromFile"
external createFromMemory: data:string -> t = "caml_sfMusic_CreateFromMemory"
external destroy: music:t -> unit = "caml_sfMusic_Destroy"
external play: music:t -> unit = "caml_sfMusic_Play"
external stop: music:t -> unit = "caml_sfMusic_Stop"
external pause: music:t -> unit = "caml_sfMusic_Pause"
external setLoop: music:t -> loop:bool -> unit = "caml_sfMusic_SetLoop"
external setVolume: music:t -> volume:float -> unit = "caml_sfMusic_SetVolume"
external getVolume: music:t -> float = "caml_sfMusic_GetVolume"
external setPitch: music:t -> pitch:float -> unit = "caml_sfMusic_SetPitch"
external setMinDistance: music:t -> minDistance:float -> unit = "caml_sfMusic_SetMinDistance"
external setAttenuation: music:t -> attenuation:float -> unit = "caml_sfMusic_SetAttenuation"
external setPosition: music:t -> x:float -> y:float -> z:float -> unit = "caml_sfMusic_SetPosition"
external setRelativeToListener: music:t -> relative:bool -> unit = "caml_sfMusic_SetRelativeToListener"
external getDuration: music:t -> float = "caml_sfMusic_GetDuration"
external getSampleRate: music:t -> int = "caml_sfMusic_GetSampleRate"
external getChannelsCount: music:t -> int = "caml_sfMusic_GetChannelsCount"
external getPlayingOffset: music:t -> float = "caml_sfMusic_GetPlayingOffset"

type sound_status =
  | Stopped  (** music is not playing *)
  | Paused   (** music is paused *)
  | Playing  (** music is playing *)

external getStatus: music:t -> sound_status = "caml_sfMusic_GetStatus"
