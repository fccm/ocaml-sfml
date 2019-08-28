(** OO style interface for sfml-audio *)
(* Copyright (C) 2012 Florent Monnier (email: monnier dot florent on gmail)
   Code provided under MIT license:
   See the file COPYING.txt or this URL:
   https://secure.wikimedia.org/wikipedia/en/wiki/MIT_License
   This software is provided "AS IS", without warranty of any kind. *)


type music_src = [
  | `FromFile of string
  | `FromMemory of string
  ]

class music (src : music_src) =
  object
    val music =
      match src with
      | `FromFile filename -> SFMusic.openFromFile ~filename
      | `FromMemory data -> SFMusic.openFromMemory ~data

    method destroy ()         = SFMusic.destroy ~music
    method play ()            = SFMusic.play ~music
    method stop ()            = SFMusic.stop ~music
    method pause ()           = SFMusic.pause ~music
    method set_loop ~loop     = SFMusic.setLoop ~music ~loop
    method set_volume ~volume = SFMusic.setVolume ~music ~volume
    method set_pitch ~pitch   = SFMusic.setPitch ~music ~pitch
    method set_min_distance ~minDistance = SFMusic.setMinDistance ~music ~minDistance
    method set_attenuation ~attenuation  = SFMusic.setAttenuation ~music ~attenuation
    method set_position ~pos             = SFMusic.setPosition ~music ~pos
    method set_position3 ~x ~y ~z        = SFMusic.setPosition3 ~music ~x ~y ~z
    method set_relative_to_listener ~relative = SFMusic.setRelativeToListener ~music ~relative
    method volume             = SFMusic.getVolume ~music
    method duration           = SFMusic.getDuration ~music
    method sample_rate        = SFMusic.getSampleRate ~music
    method channels_count     = SFMusic.getChannelCount ~music
    method playing_offset     = SFMusic.getPlayingOffset ~music
    method loop               = SFMusic.getLoop ~music
    method pitch              = SFMusic.getPitch ~music
    method position           = SFMusic.getPosition ~music
    method status             = SFMusic.getStatus ~music
  end


class listener =
  object
    method set_global_volume ~volume = SFListener.setGlobalVolume ~volume
    method set_position ~pos = SFListener.setPosition ~pos
    method set_position3 ~posX ~posY ~posZ = SFListener.setPosition3 ~posX ~posY ~posZ
    method set_direction ~orientation = SFListener.setDirection ~orientation
    method set_up_vector ~vector = SFListener.setUpVector ~vector
    method set_up_vector3 ~vecX ~vecY ~vecZ = SFListener.setUpVector3 ~vecX ~vecY ~vecZ
    method global_volume = SFListener.getGlobalVolume ()
    method position = SFListener.getPosition ()
    method direction = SFListener.getDirection ()
    method up_vector = SFListener.getUpVector ()
  end


type sound_buffer_src = [
  | `FromFile of string
  | `FromMemory of string
  | `FromSamples of
      (int, Bigarray.int16_signed_elt, Bigarray.c_layout) Bigarray.Array1.t *
      int * int
  ]

class sound_buffer (src : sound_buffer_src) =
  object
    val soundBuffer =
      match src with
      | `FromFile filename -> SFSoundBuffer.loadFromFile ~filename
      | `FromMemory data -> SFSoundBuffer.loadFromMemory ~data
      | `FromSamples (samples, channelCount, sampleRate) ->
          SFSoundBuffer.loadFromSamples ~samples ~channelCount ~sampleRate
      
    method save_to_file ~filename = SFSoundBuffer.saveToFile soundBuffer ~filename
    method sample_count  = SFSoundBuffer.getSampleCount soundBuffer
    method sample_rate   = SFSoundBuffer.getSampleRate soundBuffer
    method channel_count = SFSoundBuffer.getChannelCount soundBuffer
    method duration      = SFSoundBuffer.getDuration soundBuffer
    method t = soundBuffer
  end


type sound_status = [ `stopped | `paused | `playing ]

class sound =
  object
    val sound = SFSound.create ()

    method get_status () =
      ((match SFSound.getStatus ~sound with
        | SFSound.Stopped -> `stopped
        | SFSound.Paused  -> `paused 
        | SFSound.Playing -> `playing) : sound_status)

    method set_buffer ~buffer:(b : sound_buffer) = SFSound.setBuffer ~sound ~buffer:b#t
    method play ()        = SFSound.play ~sound
    method pause ()       = SFSound.pause ~sound
    method stop ()        = SFSound.stop ~sound
    method set_loop ~loop = SFSound.setLoop ~sound ~loop
    method get_loop ()    = SFSound.getLoop ~sound
                                           
    method set_pitch ~pitch      = SFSound.setPitch ~sound ~pitch
    method set_volume ~volume    = SFSound.setVolume ~sound ~volume
    method set_position3 ~x ~y ~z = SFSound.setPosition3 ~sound ~x ~y ~z
    method set_position ~pos     = SFSound.setPosition ~sound ~pos
    method set_relative_to_listener ~relative = SFSound.setRelativeToListener ~sound ~relative
    method set_mindistance ~minDistance     = SFSound.setMinDistance ~sound ~minDistance
    method set_attenuation ~attenuation     = SFSound.setAttenuation ~sound ~attenuation
    method set_playing_offset ~timeOffset   = SFSound.setPlayingOffset ~sound ~timeOffset
    method playing_offset        = SFSound.getPlayingOffset ~sound
    method pitch                 = SFSound.getPitch ~sound
    method volume                = SFSound.getVolume ~sound
    method is_relative_to_listener () = SFSound.isRelativeToListener ~sound
    method position              = SFSound.getPosition ~sound
    method min_distance          = SFSound.getMinDistance ~sound
    method attenuation           = SFSound.getAttenuation ~sound
  end

