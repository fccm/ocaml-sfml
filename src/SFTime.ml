type t = int64

let zero = Int64.zero

let of_seconds amount =
  Int64.of_float (amount *. 1000000.)

let of_milliseconds amount =
  Int64.(mul (of_int (Int32.to_int amount)) 1000L)

external of_microseconds : int64 -> t = "%identity"

let asSeconds t =
  Int64.to_float t /. 1000000.

let asMilliseconds t =
  Int32.of_int Int64.(to_int (div t 1000L))

external asMicroseconds : t -> int64 = "%identity"

let add t1 t2 = Int64.add t1 t2

let sub t1 t2 = Int64.sub t1 t2

let mul t f = Int64.(of_float (to_float t *. f))

let div t f = Int64.(of_float (to_float t /. f))

let ratio t1 t2 = Int64.(to_float t1 /. to_float t2)

let rem t1 t2 = Int64.rem t1 t2

let (+) t1 t2 = add t1 t2

let (-) t1 t2 = sub t1 t2

let ( * ) t f = mul t f

let (/) t f = div t f

let (//) t1 t2 = ratio t1 t2

let (mod) t1 t2 = rem t1 t2

let compare t1 t2 = Int64.compare t1 t2

external sleep : t -> unit = "caml_sfSleep"
