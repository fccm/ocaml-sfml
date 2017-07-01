type t

exception Socket_Not_Ready
exception Socket_Disconnected
exception Socket_Error

let init () =
  Callback.register_exception "SFTcpListener.Socket_Not_Ready" Socket_Not_Ready;
  Callback.register_exception "SFTcpListener.Socket_Disconnected" Socket_Disconnected;
  Callback.register_exception "SFTcpListener.Socket_Error" Socket_Error;
;;

let () = init ()

external create: unit -> t = "caml_sfTcpListener_create"
external destroy: listener:t -> unit = "caml_sfTcpListener_destroy"
external setBlocking: listener:t -> blocking:bool -> unit
  = "caml_sfTcpListener_setBlocking"
external isBlocking: listener:t -> bool = "caml_sfTcpListener_isBlocking"
external getLocalPort: listener:t -> int = "caml_sfTcpListener_getLocalPort"
external listen: listener:t -> ?address:SFIpAddress.t -> port:int -> unit = "caml_sfTcpListener_listen"
external accept: listener:t -> SFTcpSocket.t = "caml_sfTcpListener_accept"

let link_me = ()
