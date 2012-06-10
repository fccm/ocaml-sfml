type t = string

external fromString: string -> t = "caml_sfIPAddress_FromString"
(** Construct an address from a string.
    @param string IP address ("xxx.xxx.xxx.xxx") or network name *)

external fromBytes: b0:char -> b1:char -> b2:char -> b3:char -> t
  = "caml_sfIPAddress_FromBytes"
(** Construct an address from 4 bytes
    @param b0  First byte of the address
    @param b1  Second byte of the address
    @param b2  Third byte of the address
    @param b3  Fourth byte of the address *)


(** [ipAddress_from_*] return the value that you can provide as the parameter
    [address] to [SFSocketUDP.send] *)

external fromInteger: int32 -> t = "caml_sfIPAddress_FromInteger"
(** Construct the address from a 32-bits integer *)

external isValid: address:t -> bool = "caml_sfIPAddress_IsValid"
(** Tell if an address is a valid one.
    Return true if address has a valid syntax *)

let isValid_or_fail ~address =
  if not(isValid ~address)
  then invalid_arg "SFIPAddress.t"

external toString: address:t -> string = "caml_sfIPAddress_ToString"

external toInteger: address:t -> int32 = "caml_sfIPAddress_ToInteger"
(** Get an integer representation of the address,
    return 32-bits integer containing the 4 bytes of the address,
    in system endianness *)

external getLocalAddress: unit -> t = "caml_sfIPAddress_GetLocalAddress"
(** Get the computer's local IP address (from the LAN point of view) *)

external getPublicAddress: timeout:float -> t = "caml_sfIPAddress_GetPublicAddress"
(** Get the computer's public IP address (from the web point of view).
    The only way to get a public address is to ask it to a
    distant website ; as a consequence, this function may be
    very slow -- use it as few as possible !
   
    @param timeout  Maximum time to wait, in seconds (use 0 for no timeout) *)

external localHost: unit -> t = "caml_sfIPAddress_LocalHost"
(** Get the computer's loopback address.
   
    Return the local host IP address (127.0.0.1, or "localhost") *)
