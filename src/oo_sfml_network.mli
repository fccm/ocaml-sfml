(** *)
(** {{:http://www.sfml-dev.org/documentation/2.0/group__network.php}
  Online documentation for the network module} *)

type ip_address_src =
    [ `FromBytes of char * char * char * char
    | `FromInteger of int32
    | `FromString of string
    | `GetLocalAddress
    | `GetPublicAddress of Oo_sfml_system.time
    | `LocalHost ]
class ip_address :
  ip_address_src ->
  object
    val address : SFIpAddress.t
    method t : SFIpAddress.t
    method to_integer : unit -> int32
    method to_string : unit -> string
  end
type write_value =
    [ `Bool of bool
    | `Double of float
    | `Float of float
    | `Int16 of int
    | `Int31 of int
    | `Int32 of int32
    | `Int8 of int
    | `String of string
    | `Uint16 of int
    | `Uint8 of int ]
type read_value =
    [ `inBool
    | `inDouble
    | `inFloat
    | `inInt16
    | `inInt31
    | `inInt32
    | `inInt8
    | `inString
    | `inUint16
    | `inUint8 ]
class packet :
  object
    val packet : SFPacket.t
    method append : data:string -> unit
    method can_read : bool
    method clear : unit -> unit
    method end_of_packet : bool
    method get_data : unit -> string
    method read : read_value list -> write_value list
    method read_bool : unit -> bool
    method read_double : unit -> float
    method read_float : unit -> float
    method read_int16 : unit -> int
    method read_int31 : unit -> int
    method read_int32 : unit -> int32
    method read_int8 : unit -> int
    method read_string : unit -> string
    method read_uint16 : unit -> int
    method read_uint8 : unit -> int
    method t : SFPacket.t
    method write : write_value list -> unit
    method write_bool : bool -> unit
    method write_double : float -> unit
    method write_float : float -> unit
    method write_int16 : int -> unit
    method write_int31 : int -> unit
    method write_int32 : int32 -> unit
    method write_int64 : int64 -> unit
    method write_int8 : int -> unit
    method write_string : string -> unit
    method write_uint16 : int -> unit
    method write_uint8 : int -> unit
  end
class tcp_socket :
  object
    val socket : SFTcpSocket.t
    method connect :
      port:int -> address:SFIpAddress.t -> timeout:SFTime.t -> unit -> unit
    method destroy : unit -> unit
    method receive : unit -> bytes
    method receive_buf : buf:bytes -> int
    method receive_packet : packet:packet -> unit
    method send : data:string -> unit
    method send_packet : packet:packet -> unit
    method send_sub : data:string -> ofs:int -> len:int -> unit
    method set_blocking : blocking:bool -> unit
    method t : SFTcpSocket.t
  end
class udp_socket :
  object
    val socket : SFUdpSocket.t
    method bind : port:int -> ?address:SFIpAddress.t -> unit
    method destroy : unit -> unit
    method receive : data:bytes -> int * SFIpAddress.t * int
    method receive_packet : packet:packet -> SFIpAddress.t * int
    method send : data:string -> address:SFIpAddress.t -> port:int -> unit
    method send_packet :
      packet:packet -> address:SFIpAddress.t -> port:int -> unit
    method set_blocking : blocking:bool -> unit
    method t : SFUdpSocket.t
    method unbind : unit -> unit
  end
class http_request :
  object
    val request : SFHttp.Request.t
    method destroy : unit -> unit
    method set_body : body:string -> unit
    method set_field : field:string -> value:string -> unit
    method set_http_version : major:int -> minor:int -> unit
    method set_method : SFHttp.http_method -> unit
    method set_uri : uri:string -> unit
    method t : SFHttp.Request.t
  end
class http_response :
  SFHttp.Response.t ->
  object
    val response : SFHttp.Response.t
    method body : string
    method destroy : unit -> unit
    method get_field : field:string -> string
    method major_http_version : int
    method minor_http_version : int
    method status : SFHttp.status
  end
class http :
  object
    val http : SFHttp.t
    method destroy : unit -> unit
    method send_request :
      request:http_request ->
      ?timeout:Oo_sfml_system.time -> unit -> http_response
    method set_host : host:string -> ?port:int -> unit -> unit
  end
class response :
  SFFtp.response ->
  object
    val resp : SFFtp.response
    method destroy : unit -> unit
    method get_message : unit -> string
    method get_status : unit -> SFFtp.status
    method is_ok : unit -> bool
  end
class directory_response :
  SFFtp.directoryResponse ->
  object
    val dir_resp : SFFtp.directoryResponse
    method destroy : unit -> unit
    method get_directory : unit -> string
    method get_message : unit -> string
    method get_status : unit -> SFFtp.status
    method is_ok : unit -> bool
  end
class listing_response :
  'a ->
  object
    val lst_resp : 'a
    method destroy : unit -> SFFtp.listingResponse -> unit
    method get_listing : unit -> SFFtp.listingResponse -> string array
    method get_message : unit -> SFFtp.listingResponse -> string
    method get_status : unit -> SFFtp.listingResponse -> SFFtp.status
    method is_ok : unit -> SFFtp.listingResponse -> bool
  end
class ftp :
  object
    val ftp : SFFtp.ftp
    method change_directory : directory:string -> response
    method connect :
      server:ip_address ->
      ?port:int -> ?timeout:Oo_sfml_system.time -> unit -> response
    method create_directory : name:string -> response
    method delete_directory : name:string -> response
    method delete_file : name:string -> response
    method destroy : unit -> unit
    method disconnect : unit -> response
    method download :
      distantFile:string ->
      destPath:string -> mode:SFFtp.transferMode -> response
    method get_directory_listing : directory:string -> listing_response
    method get_working_directory : unit -> directory_response
    method keep_alive : unit -> response
    method login :
      SFFtp.ftp -> userName:string -> password:string -> response
    method login_anonymous : unit -> response
    method parent_directory : unit -> response
    method rename_file : file:string -> newName:string -> response
    method send_command : command:string -> parameter:string -> response
    method upload :
      localFile:string ->
      destPath:string -> mode:SFFtp.transferMode -> response
  end
