type t =
  | Alpha     (** Pixel = Src * a + Dest * (1 - a) *)
  | Add       (** Pixel = Src + Dest *)
  | Multiply  (** Pixel = Src * Dest *)
  | None      (** No blending *)
