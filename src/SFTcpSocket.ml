type t

exception Socket_Not_Ready
exception Socket_Disconnected
exception Socket_Error

let init () =
  Callback.register_exception "SFTcpSocket.Socket_Not_Ready" Socket_Not_Ready;
  Callback.register_exception "SFTcpSocket.Socket_Disconnected" Socket_Disconnected;
  Callback.register_exception "SFTcpSocket.Socket_Error" Socket_Error;
;;

let () = init ()

external create: unit -> t = "caml_sfTcpSocket_create"
external destroy: socket:t -> unit = "caml_sfTcpSocket_destroy"

external connect: socket:t -> port:int -> address:SFIpAddress.t ->
  ?timeout:SFTime.t -> unit -> unit
  = "caml_sfTcpSocket_connect"

external disconnect: socket:t -> unit = "caml_sfTcpSocket_disconnect"

external setBlocking: socket:t -> blocking:bool -> unit
  = "caml_sfTcpSocket_setBlocking"

external isBlocking: socket:t -> bool = "caml_sfTcpSocket_isBlocking"

external send: socket:t -> data:string -> unit = "caml_sfTcpSocket_send"
external send_sub: socket:t -> data:string -> ofs:int -> len:int -> unit
  = "caml_sfTcpSocket_send_sub"

external receive: socket:t -> data:bytes -> int = "caml_sfTcpSocket_receive"

let receive_str =
  let rec_buf = Bytes.create (800 * 1024) in
  fun ~socket ->
    let n = receive ~socket ~data:rec_buf in
    (Bytes.sub rec_buf 0 n)

external sendPacket: socket:t -> packet:SFPacket.t -> unit
  = "caml_sfTcpSocket_sendPacket"

external receivePacket: socket:t -> packet:SFPacket.t -> unit
  = "caml_sfTcpSocket_receivePacket"

external getLocalPort: socket:t -> int = "caml_sfTcpSocket_getLocalPort"
external getRemotePort: socket:t -> int = "caml_sfTcpSocket_getRemotePort"

let link_me = ()
