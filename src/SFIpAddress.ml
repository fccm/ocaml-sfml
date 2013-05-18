type t = string
external fromString: str:string -> t = "caml_sfIpAddress_fromString"
external fromBytes: b0:char -> b1:char -> b2:char -> b3:char -> t
  = "caml_sfIpAddress_fromBytes"
external fromInteger: int32 -> t = "caml_sfIpAddress_fromInteger"
external toString: address:t -> string = "caml_sfIpAddress_toString"
external toInteger: address:t -> int32 = "caml_sfIpAddress_toInteger"
external getLocalAddress: unit -> t = "caml_sfIpAddress_getLocalAddress"
external getPublicAddress: timeout:SFTime.t -> t
  = "caml_sfIpAddress_getPublicAddress"
external localHost: unit -> t = "caml_sfIpAddress_localHost"
external none: unit -> t = "caml_sfIpAddress_None"
external broadcast: unit -> t = "caml_sfIpAddress_Broadcast"
