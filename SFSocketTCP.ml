type t

exception Socket_Not_Ready
exception Socket_Disconnected
exception Socket_Error

let init () =
  Callback.register_exception "SFSocketTCP.Socket_Not_Ready" Socket_Not_Ready;
  Callback.register_exception "SFSocketTCP.Socket_Disconnected" Socket_Disconnected;
  Callback.register_exception "SFSocketTCP.Socket_Error" Socket_Error;
;;

let () = init ()

external create: unit -> t = "caml_sfSocketTCP_Create"
external destroy: socket:t -> unit = "caml_sfSocketTCP_Destroy"

external setBlocking: socket:t -> blocking:bool -> unit = "caml_sfSocketTCP_SetBlocking"

external connect: socket:t -> port:int -> address:string -> timeout:float -> unit
  = "caml_sfSocketTCP_Connect"

external listen: socket:t -> port:int -> unit = "caml_sfSocketTCP_Listen"
external accept: socket:t -> t * string = "caml_sfSocketTCP_Accept"

external send: socket:t -> data:string -> unit = "caml_sfSocketTCP_Send"
external send_sub: socket:t -> data:string -> ofs:int -> len:int -> unit = "caml_sfSocketTCP_Send_sub"

external receive: socket:t -> data:string -> int = "caml_sfSocketTCP_Receive"

let receive_str =
  let rec_buf = String.create (800 * 1024) in
  fun ~socket ->
    let n = receive ~socket ~data:rec_buf in
    (String.sub rec_buf 0 n)

external sendPacket: socket:t -> packet:SFPacket.t -> unit = "caml_sfSocketTCP_SendPacket"
external receivePacket: socket:t -> packet:SFPacket.t -> unit = "caml_sfSocketTCP_ReceivePacket"

external isValid: socket:t -> bool = "caml_sfSocketTCP_IsValid"
