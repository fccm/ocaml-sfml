module TCP = struct
  type t
  external create: unit -> t = "caml_sfSelectorTCP_Create"
  (** Create a new selector *)

  external destroy: selector:t -> unit = "caml_sfSelectorTCP_Destroy"
  (** Destroy an existing selector *)

  external add: selector:t -> socket:SFSocketTCP.t -> unit = "caml_sfSelectorTCP_Add"
  (** Add a socket to watch to a selector *)

  external remove: selector:t -> socket:SFSocketTCP.t -> unit = "caml_sfSelectorTCP_Remove"
  (** Remove a socket from a selector *)

  external clear: selector:t -> unit = "caml_sfSelectorTCP_Clear"
  (** Remove all sockets from a selector *)

  external wait: selector:t -> timeout:float -> int = "caml_sfSelectorTCP_Wait"
  (** Wait and collect sockets which are ready for reading.
      This functions will return either when at least one socket
      is ready, or when the given time is out.
      [timeout] is the maximum time to wait, in seconds (0 to disable timeout).
      Return the number of sockets ready. *)

  external getSocketReady: selector:t -> index:int -> SFSocketTCP.t
    = "caml_sfSelectorTCP_GetSocketReady"
  (** After a call to [wait], get the index-th socket which is
      ready for reading. The total number of sockets ready
      is the integer returned by the previous call to [wait]. *)
end

module UDP = struct
  type t
  external create: unit -> t = "caml_sfSelectorUDP_Create"
  (** Create a new selector *)

  external destroy: selector:t -> unit = "caml_sfSelectorUDP_Destroy"
  (** Destroy an existing selector *)

  external add: selector:t -> socket:SFSocketUDP.t -> unit = "caml_sfSelectorUDP_Add"
  (** Add a socket to watch to a selector *)

  external remove: selector:t -> socket:SFSocketUDP.t -> unit = "caml_sfSelectorUDP_Remove"
  (** Remove a socket from a selector *)

  external clear: selector:t -> unit = "caml_sfSelectorUDP_Clear"
  (** Remove all sockets from a selector *)

  external wait: selector:t -> timeout:float -> int = "caml_sfSelectorUDP_Wait"
  (** Wait and collect sockets which are ready for reading.
      This functions will return either when at least one socket
      is ready, or when the given time is out.
      [timeout] is the maximum time to wait, in seconds (0 to disable timeout).
      Return the number of sockets ready. *)

  external getSocketReady: selector:t -> index:int -> SFSocketUDP.t
    = "caml_sfSelectorUDP_GetSocketReady"
  (** After a call to [wait], get the index-th socket which is
      ready for reading. The total number of sockets ready
      is the integer returned by the previous call to [wait]. *)
end
