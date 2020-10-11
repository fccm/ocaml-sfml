(** *)
(** {{:https://www.sfml-dev.org/documentation/2.5.1/group__audio.php}
  Online documentation for the audio module} *)

type music_src = [ `FromFile of string | `FromMemory of string ]
class music :
  music_src ->
  object
    val music : SFMusic.t
    method channels_count : int
    method destroy : unit -> unit
    method duration : SFTime.t
    method loop : bool
    method pause : unit -> unit
    method pitch : float
    method play : unit -> unit
    method playing_offset : SFTime.t
    method position : float * float * float
    method sample_rate : int
    method set_attenuation : attenuation:float -> unit
    method set_loop : loop:bool -> unit
    method set_min_distance : minDistance:float -> unit
    method set_pitch : pitch:float -> unit
    method set_position : pos:float * float * float -> unit
    method set_position3 : x:float -> y:float -> z:float -> unit
    method set_relative_to_listener : relative:bool -> unit
    method set_volume : volume:float -> unit
    method status : SFMusic.sound_status
    method stop : unit -> unit
    method volume : float
  end
class listener :
  object
    method direction : float * float * float
    method global_volume : float
    method position : float * float * float
    method set_direction : orientation:float * float * float -> unit
    method set_global_volume : volume:float -> unit
    method set_position : pos:float * float * float -> unit
    method set_position3 : posX:float -> posY:float -> posZ:float -> unit
    method set_up_vector : vector:float * float * float -> unit
    method set_up_vector3 : vecX:float -> vecY:float -> vecZ:float -> unit
    method up_vector : float * float * float
  end
type sound_buffer_src =
    [ `FromFile of string
    | `FromMemory of string
    | `FromSamples of
        (int, Bigarray.int16_signed_elt, Bigarray.c_layout) Bigarray.Array1.t *
        int * int ]
class sound_buffer :
  sound_buffer_src ->
  object
    val soundBuffer : SFSoundBuffer.t
    method channel_count : int
    method duration : SFTime.t
    method sample_count : int
    method sample_rate : int
    method save_to_file : filename:string -> unit
    method t : SFSoundBuffer.t
  end
type sound_status = [ `paused | `playing | `stopped ]
class sound :
  object
    val sound : SFSound.t
    method attenuation : float
    method get_loop : unit -> bool
    method get_status : unit -> sound_status
    method is_relative_to_listener : unit -> bool
    method min_distance : float
    method pause : unit -> unit
    method pitch : float
    method play : unit -> unit
    method playing_offset : SFTime.t
    method position : float * float * float
    method set_attenuation : attenuation:float -> unit
    method set_buffer : buffer:sound_buffer -> unit
    method set_loop : loop:bool -> unit
    method set_mindistance : minDistance:float -> unit
    method set_pitch : pitch:float -> unit
    method set_playing_offset : timeOffset:SFTime.t -> unit
    method set_position : pos:float * float * float -> unit
    method set_position3 : x:float -> y:float -> z:float -> unit
    method set_relative_to_listener : relative:bool -> unit
    method set_volume : volume:float -> unit
    method stop : unit -> unit
    method volume : float
  end
