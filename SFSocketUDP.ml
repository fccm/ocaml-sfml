type t

exception Socket_Not_Ready
exception Socket_Disconnected
exception Socket_Error

let init () =
  Callback.register_exception "SFSocketUDP.Socket_Not_Ready" Socket_Not_Ready;
  Callback.register_exception "SFSocketUDP.Socket_Disconnected" Socket_Disconnected;
  Callback.register_exception "SFSocketUDP.Socket_Error" Socket_Error;
;;

let () = init ()

external create: unit -> t = "caml_sfSocketUDP_Create"
(** Construct a new UDP socket *)

external destroy: socket:t -> unit = "caml_sfSocketUDP_Destroy"
(** Destroy an existing UDP socket *)

external setBlocking: socket:t -> blocking:bool -> unit
  = "caml_sfSocketUDP_SetBlocking"
(** Change the blocking state of a UDP socket.
    The default behaviour of a socket is blocking *)

external bind: socket:t -> port:int -> unit = "caml_sfSocketUDP_Bind"
(** Bind a socket to a specific port *)

external unbind: socket:t -> unit = "caml_sfSocketUDP_Unbind"
(** Unbind a socket from its previous port, if any *)

external send: socket:t -> data:string -> address:string -> port:int -> unit
  = "caml_sfSocketUDP_Send"
(** Send data *)

external receive: socket:t -> data:string -> int * string * int
  = "caml_sfSocketUDP_Receive"
(** Receive data. This function is blocking, ie. it won't return before some
    bytes have been received.
    Return the number of bytes received, the address of the computer which sent
    the data, and the port on which the remote computer sent the data. *)


external sendPacket: socket:t -> packet:SFPacket.t -> address:string -> port:int -> unit
  = "caml_sfSocketUDP_SendPacket"
(** Send a packet of data.

    @param socket  Socket to use for sending
    @param packet  Packet to send
    @param address Address of the computer to send the packet to
    @param port    Port to use for communication *)

external receivePacket: socket:t -> packet:SFPacket.t -> string * int
  = "caml_sfSocketUDP_ReceivePacket"
(** Receive a packet. This function is blocking, ie. it won't return before a
    packet is received.
    Return the address of the computer which sent the data, and the port on
    which the remote computer sent the data. *)

external isValid: socket:t -> bool = "caml_sfSocketUDP_IsValid"
(** Check if a socket is in a valid state ; this function
    can be called any time to check if the socket is OK.
    Returns true if the socket is valid. *)

