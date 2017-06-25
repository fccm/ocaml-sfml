(** Enumeration of the blending factors

    The factors are mapped directly to their OpenGL equivalents,
    specified by glBlendFunc() or glBlendFuncSeparate(). *)
type factor =
  | Zero             (** (0, 0, 0, 0) *)
  | One              (** (1, 1, 1, 1) *)
  | SrcColor         (** (src.r, src.g, src.b, src.a) *)
  | OneMinusSrcColor (** (1, 1, 1, 1) - (src.r, src.g, src.b, src.a) *)
  | DstColor         (** (dst.r, dst.g, dst.b, dst.a) *)
  | OneMinusDstColor (** (1, 1, 1, 1) - (dst.r, dst.g, dst.b, dst.a) *)
  | SrcAlpha         (** (src.a, src.a, src.a, src.a) *)
  | OneMinusSrcAlpha (** (1, 1, 1, 1) - (src.a, src.a, src.a, src.a) *)
  | DstAlpha         (** (dst.a, dst.a, dst.a, dst.a) *)
  | OneMinusDstAlpha (** (1 1, 1, 1) - (dst.a, dst.a, dst.a, dst.a) *)

(** Enumeration of the blending equations

    The equations are mapped directly to their OpenGL equivalents,
    specified by glBlendEquation() or glBlendEquationSeparate(). *)
type equation =
  | Add             (** Pixel = Src * SrcFactor + Dst * DstFactor *)
  | Subtract        (** Pixel = Src * SrcFactor - Dst * DstFactor *)
  | ReverseSubtract (** Pixel = Dst * DstFactor - Src * SrcFactor *)

(** Blending modes for drawing *)
type t = {
  color_src_factor : factor; (** Source blending factor for the color channels *)
  color_dst_factor : factor; (** Destination blending factor for the color channels *)
  color_equation : equation; (** Blending equation for the color channels *)
  alpha_src_factor : factor; (** Source blending factor for the alpha channel *)
  alpha_dst_factor : factor; (** Destination blending factor for the alpha channel *)
  alpha_equation : equation  (** Blending equation for the alpha channel *)
}

(** Construct the blend mode given the factors and equation.

    This constructor uses the same factors and equation for both
    color and alpha components. It also defaults to the Add equation. *)
val make : ?equation:equation -> factor -> factor -> t

(** Commonly used blending modes *)
val alpha : t    (** Blend source and dest according to dest alpha *)
val add : t      (** Add source to dest *)
val multiply : t (** Multiply source and dest *)
val none : t     (** Overwrite dest with source *)
