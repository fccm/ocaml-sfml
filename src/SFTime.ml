type u

external of_seconds: amount:float -> u = "caml_sfSeconds"
external of_milliseconds: amount:int32 -> u = "caml_sfMilliseconds"
external of_microseconds: amount:int64 -> u = "caml_sfMicroseconds"

external asSeconds: u -> float = "caml_sfTime_asSeconds"
external asMilliseconds: u -> int32 = "caml_sfTime_asMilliseconds"
external asMicroseconds: u -> int64 = "caml_sfTime_asMicroseconds"

external add: u -> u -> u = "caml_sfTime_add"
external sub: u -> u -> u = "caml_sfTime_sub"
external mul: float -> u -> u = "caml_sfTime_mul"
external mult: u -> float -> u = "caml_sfTime_mult"
external div: u -> float -> u = "caml_sfTime_div"

external eq: u -> u -> bool = "caml_sfTime_eq"
external gt: u -> u -> bool = "caml_sfTime_gt"
external lt: u -> u -> bool = "caml_sfTime_lt"

external destroy: u -> unit = "caml_sfTime_destroy"

external sleep: duration:u -> unit = "caml_sfSleep"
external sleep_sec: duration:float -> unit = "caml_sfSleep_sec"
(* equivalent than: SFTime.sleep (SFTime.of_seconds x) *)

external sleep_msec: duration:int32 -> unit = "caml_sfSleep_msec"
external sleep_musec: duration:int64 -> unit = "caml_sfSleep_musec"

(* ================ *)

type t = { u:u; s:string }

let destroy t =
  Printf.printf "# destroying time (%s)...\n%!" t.s;
  destroy t.u

let of_seconds ~amount =
  let u = of_seconds ~amount in
  let t = {u=u; s=" "} in
  Gc.finalise destroy t;
  (t)

let of_milliseconds ~amount =
  let u = of_milliseconds ~amount in
  let t = {u=u; s=" "} in
  Gc.finalise destroy t;
  (t)

let of_microseconds ~amount =
  let u = of_microseconds ~amount in
  let t = {u=u; s=" "} in
  Gc.finalise destroy t;
  (t)

let asSeconds t = asSeconds t.u
let asMilliseconds t = asMilliseconds t.u
let asMicroseconds t = asMicroseconds t.u

let add a b =
  let u = add a.u b.u in
  let t = {u=u; s=" "} in
  Gc.finalise destroy t;
  (t)

let sub a b =
  let u = sub a.u b.u in
  let t = {u=u; s=" "} in
  Gc.finalise destroy t;
  (t)

let mul a b =
  let u = mul a b.u in
  let t = {u=u; s=" "} in
  Gc.finalise destroy t;
  (t)

let mult a b =
  let u = mult a.u b in
  let t = {u=u; s=" "} in
  Gc.finalise destroy t;
  (t)

let div a b =
  let u = div a.u b in
  let t = {u=u; s=" "} in
  Gc.finalise destroy t;
  (t)

let eq a b =
  (eq a.u b.u)

let gt a b =
  (gt a.u b.u)

let lt a b =
  (lt a.u b.u)

let sleep ~duration:t =
  sleep ~duration:t.u

