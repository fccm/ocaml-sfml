(** OO style interface for sfml-system *)
(* Copyright (C) 2012 Florent Monnier (email: monnier dot florent on gmail)
   Code provided under MIT license:
   See the file COPYING.txt or this URL:
   https://secure.wikimedia.org/wikipedia/en/wiki/MIT_License
   This software is provided "AS IS", without warranty of any kind. *)


type time_src = [
  | `of_seconds of float
  | `of_milliseconds of int32
  | `of_microseconds of int64
  | `of_sfTime of SFTime.t
  ]


class time (src : time_src) =
  object
    val time =
      match src with
      | `of_seconds amount -> SFTime.of_seconds ~amount
      | `of_milliseconds amount -> SFTime.of_milliseconds ~amount
      | `of_microseconds amount -> SFTime.of_microseconds ~amount
      | `of_sfTime t -> t

    method as_seconds () = SFTime.asSeconds time
    method as_milliseconds () = SFTime.asMilliseconds time
    method as_microseconds () = SFTime.asMicroseconds time

    method t = time
  end


module Time = struct
  let add (t1 : time) (t2 : time) =
    new time (`of_sfTime (SFTime.add t1#t t2#t))

  let sub (t1 : time) (t2 : time) =
    new time (`of_sfTime (SFTime.sub t1#t t2#t))

  let mul f (t : time) =
    new time (`of_sfTime (SFTime.mul f t#t))

  let mult (t : time) f =
    new time (`of_sfTime (SFTime.mult t#t f))

  let div (t : time) d =
    new time (`of_sfTime (SFTime.div t#t d))

  let ( + ) = add
  let ( - ) = sub
  let ( * ) = mul
  let ( *. ) = mult
  let ( / ) = div
end



let sleep ~duration:(d : time) = SFTime.sleep ~duration:d#t

let sleep_sec   = SFTime.sleep_sec ;;
let sleep_msec  = SFTime.sleep_msec ;;
let sleep_musec = SFTime.sleep_musec ;;


type time_as = [
  | `seconds
  | `milliseconds
  | `microseconds
  ]

class clock =
  object
    val clock = SFClock.create ()
    method destroy () = SFClock.destroy ~clock
    method restart () = SFClock.restart ~clock

    method restart_as_seconds ()      = SFClock.restart_asSeconds ~clock
    method restart_as_milliseconds () = SFClock.restart_asMilliseconds ~clock
    method restart_as_microseconds () = SFClock.restart_asMicroseconds ~clock

    method restart_as (u : time_as) =
      match u with
      | `seconds      -> SFClock.restart_asSeconds ~clock
      | `milliseconds -> Int32.to_float (SFClock.restart_asMilliseconds ~clock)
      | `microseconds -> Int64.to_float (SFClock.restart_asMicroseconds ~clock)

    method get_elapsed_time () = SFClock.getElapsedTime ~clock

    method elapsed_time_as_seconds      = SFClock.getElapsedTime_asSeconds ~clock
    method elapsed_time_as_milliseconds = SFClock.getElapsedTime_asMilliseconds ~clock
    method elapsed_time_as_microseconds = SFClock.getElapsedTime_asMicroseconds ~clock

    method get_elapsed_time_as (u : time_as) =
      match u with
      | `seconds      -> SFClock.getElapsedTime_asSeconds ~clock
      | `milliseconds -> Int32.to_float (SFClock.getElapsedTime_asMilliseconds ~clock)
      | `microseconds -> Int64.to_float (SFClock.getElapsedTime_asMicroseconds ~clock)
  end


class pausable_clock ~paused =
  object
    val clock = SFPausableClock.create ~paused
    method destroy () = SFPausableClock.destroy ~clock
    method pause () = SFPausableClock.pause ~clock
    method is_paused () = SFPausableClock.isPaused ~clock
    method start () = SFPausableClock.start ~clock
    method restart ~paused = SFPausableClock.restart ~clock ~paused
    method get_elapsed_time () = SFPausableClock.getElapsedTime ~clock
    method elapsed_time = SFPausableClock.getElapsedTime ~clock
  end


let config =
  object
    val comp_ver = SFConfig.getCompiledVersion ()
    method compiled_version = comp_ver
  end
