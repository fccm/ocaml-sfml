type t
external create: unit -> t = "caml_sfSocketSelector_create"
external copy: selector:t -> t = "caml_sfSocketSelector_copy"
external destroy: selector:t -> unit = "caml_sfSocketSelector_destroy"
external addTcpListener: selector:t -> socket:SFTcpListener.t -> unit
  = "caml_sfSocketSelector_addTcpListener"
external addTcpSocket: selector:t -> socket:SFTcpSocket.t -> unit
  = "caml_sfSocketSelector_addTcpSocket"
external addUdpSocket: selector:t -> socket:SFUdpSocket.t -> unit
  = "caml_sfSocketSelector_addUdpSocket"
external removeTcpSocket: selector:t -> socket:SFTcpSocket.t -> unit
  = "caml_sfSocketSelector_removeTcpSocket"
external clear: selector:t -> unit = "caml_sfSocketSelector_clear"
external wait: selector:t -> ?timeout:SFTime.t -> unit -> bool
  = "caml_sfSocketSelector_wait"
external isTcpListenerReady: selector:t -> socket:SFTcpListener.t -> bool
  = "caml_sfSocketSelector_isTcpListenerReady"
external isTcpSocketReady: selector:t -> socket:SFTcpSocket.t -> bool
  = "caml_sfSocketSelector_isTcpSocketReady"
external isUdpSocketReady: selector:t -> socket:SFUdpSocket.t -> bool
  = "caml_sfSocketSelector_isUdpSocketReady"
