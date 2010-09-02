type u
type t = { u:u; s:string }

external createFromFile:
  ?charSize:int -> ?charset:int32 -> string -> u
  = "caml_sfFont_CreateFromFile"

external destroy: font:u -> unit = "caml_sfFont_Destroy"

let destroy font = destroy font.u

let createFromFile ?charSize ?charset str =
  let u = createFromFile ?charSize ?charset str in
  let t = {u=u; s=" "} in
  Gc.finalise destroy t;
  (t)
