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

external getUnderlinePosition: u -> characterSize:int -> float
  = "caml_sfFont_getUnderlinePosition"

external getUnderlineThickness: u -> characterSize:int -> float
  = "caml_sfFont_getUnderlineThickness"

(* annotation "boxed" is explained here:
   http://caml.inria.fr/pub/docs/manual-ocaml-4.08/intfc.html#sec433 *)
type info = { family: string } [@@boxed]

external getInfo: u -> info = "caml_sfFont_getInfo"

(* ================ *)

type t = { u:u }

let debug = true

let destroy font =
  if debug
  then Printf.eprintf "# finalising font...\n%!";
  destroy font.u

let createFromFile ~filename =
  let u = createFromFile ~filename in
  let t = { u=u } in
  Gc.finalise destroy t;
  (t)

let createFromMemory ~data =
  let u = createFromMemory ~data in
  let t = { u=u } in
  Gc.finalise destroy t;
  (t)

let copy font =
  let u = copy font.u in
  let t = { u=u } in
  Gc.finalise destroy t;
  (t)

let getGlyph font = getGlyph font.u
let getKerning font = getKerning font.u
let getLineSpacing font = getLineSpacing font.u
let getUnderlinePosition font = getUnderlinePosition font.u
let getUnderlineThickness font = getUnderlineThickness font.u

let getInfo font = getInfo font.u
