(** *)
(** {{:http://sfml-dev.org/documentation/2.0/classsf_1_1Font.php}
  Online documentation for the Font class} *)

type t

val createFromFile: filename:string -> t
val createFromMemory: data:string -> t

val copy: t -> t

type glyph = {
    advance: float;
    bounds: float SFRect.t;
    textureRect: int SFRect.t;
  }

val getGlyph: t -> codePoint:int32 -> characterSize:int -> bold:bool -> glyph
val getKerning: t -> first:int32 -> second:int32 -> characterSize:int -> float
val getLineSpacing: t -> characterSize:int -> float
val getUnderlinePosition: t -> characterSize:int -> float
val getUnderlineThickness: t -> characterSize:int -> float

type info = { family: string }

val getInfo: t -> info
