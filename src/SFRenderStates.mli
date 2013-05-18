(**  *)
(** {{:http://sfml-dev.org/documentation/2.0/classsf_1_1RenderStates.php}
  Online documentation for the RenderStates class} *)

type t

val create :
  ?blendMode:SFBlendMode.t ->
  ?transform:SFTransform.t ->
  ?texture:SFTexture.t ->
  ?shader:SFShader.t ->
  unit -> t
