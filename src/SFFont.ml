type u

external createFromFile: filename:string -> u = "caml_sfFont_createFromFile"
external createFromMemory: data:string -> u = "caml_sfFont_createFromMemory"
external copy: u -> u = "caml_sfFont_copy"

external destroy: u -> unit = "caml_sfFont_destroy"

type glyph = {
    advance: float;
    bounds: float SFRect.t;
    textureRect: int SFRect.t;
  }

external getGlyph: u -> codePoint:int32 -> characterSize:int -> bold:bool -> glyph
  = "caml_sfFont_getGlyph"

external getKerning: u -> first:int32 -> second:int32 -> characterSize:int -> float
  = "caml_sfFont_getKerning"

external getLineSpacing: u -> characterSize:int -> float
  = "caml_sfFont_getLineSpacing"

(* ================ *)

type t = { u:u; s:string }

let destroy font =
  Printf.printf "# destroying font (%s)...\n%!" font.s;
  destroy font.u

let createFromFile ~filename =
  let u = createFromFile ~filename in
  let t = {u=u; s=" " } in
  Gc.finalise destroy t;
  (t)

let createFromMemory ~data =
  let u = createFromMemory ~data in
  let t = {u=u; s=" " } in
  Gc.finalise destroy t;
  (t)

let copy font =
  let u = copy font.u in
  let t = {u=u; s=" " } in
  Gc.finalise destroy t;
  (t)

let getGlyph font = getGlyph font.u
let getKerning font = getKerning font.u
let getLineSpacing font = getLineSpacing font.u
