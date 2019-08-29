type t

exception Socket_Not_Ready
exception Socket_Disconnected
exception Socket_Error

let init () =
  Callback.register_exception "SFUdpSocket.Socket_Not_Ready" Socket_Not_Ready;
  Callback.register_exception "SFUdpSocket.Socket_Disconnected" Socket_Disconnected;
  Callback.register_exception "SFUdpSocket.Socket_Error" Socket_Error;
;;

let () = init ()

external create: unit -> t = "caml_sfUdpSocket_create"
(** Construct a new UDP socket *)

external destroy: socket:t -> unit = "caml_sfUdpSocket_destroy"
external setBlocking: socket:t -> blocking:bool -> unit
  = "caml_sfUdpSocket_setBlocking"
external bind: socket:t -> ?address:SFIpAddress.t -> port:int -> unit = "caml_sfUdpSocket_bind"
external unbind: socket:t -> unit = "caml_sfUdpSocket_unbind"
external send: socket:t -> data:string -> address:SFIpAddress.t -> port:int -> unit
  = "caml_sfUdpSocket_send"
external receive: socket:t -> data:bytes -> int * SFIpAddress.t * int
  = "caml_sfUdpSocket_receive"
external sendPacket: socket:t -> packet:SFPacket.t -> address:SFIpAddress.t -> port:int -> unit
  = "caml_sfUdpSocket_sendPacket"
external receivePacket: socket:t -> packet:SFPacket.t -> SFIpAddress.t * int
  = "caml_sfUdpSocket_receivePacket"
external isBlocking: socket:t -> bool = "caml_sfUdpSocket_isBlocking"
external getLocalPort: socket:t -> int = "caml_sfUdpSocket_getLocalPort"
external maxDatagramSize: unit -> int = "caml_sfUdpSocket_maxDatagramSize"

let link_me = ()
