(** OO style interface for sfml-network *)
(* Copyright (C) 2012 Florent Monnier (email: monnier dot florent on gmail)
   Code provided under MIT license:
   See the file COPYING.txt or this URL:
   https://secure.wikimedia.org/wikipedia/en/wiki/MIT_License
   This software is provided "AS IS", without warranty of any kind. *)


(** {3 IP Address} *)

type ip_address_src = [
  | `FromString of string
  | `FromBytes of (char * char * char * char)
  | `FromInteger of int32
  | `GetLocalAddress
  | `GetPublicAddress of Oo_sfml_system.time
  | `LocalHost
  ]

class ip_address (src : ip_address_src) =
  object
    val address =
      match src with
      | `FromString str -> SFIpAddress.fromString ~str
      | `FromBytes (b0, b1, b2, b3) -> SFIpAddress.fromBytes ~b0 ~b1 ~b2 ~b3
      | `FromInteger d -> SFIpAddress.fromInteger d
      | `GetLocalAddress -> SFIpAddress.getLocalAddress ()
      | `GetPublicAddress time -> SFIpAddress.getPublicAddress ~timeout:time#t
      | `LocalHost -> SFIpAddress.localHost ()

    method to_string () = SFIpAddress.toString ~address
    method to_integer () = SFIpAddress.toInteger ~address
    method t = address
  end


(** {3 Packet} *)

type write_value = [
  | `Bool of bool
  | `Float of float
  | `Double of float
  | `String of string
  | `Int8 of int
  | `Uint8 of int
  | `Int16 of int
  | `Uint16 of int
  | `Int31 of int
  | `Int32 of int32
  ]

type read_value = [
  | `inBool
  | `inFloat
  | `inDouble
  | `inString
  | `inInt8
  | `inUint8
  | `inInt16
  | `inUint16
  | `inInt31
  | `inInt32
  ]

class packet =
  object
    val packet = SFPacket.create ()
    method t = packet

    method append ~data  = SFPacket.append ~packet ~data
    method clear ()      = SFPacket.clear ~packet
    method get_data ()    = SFPacket.getData ~packet
    method end_of_packet  = SFPacket.endOfPacket ~packet
    method can_read       = SFPacket.canRead ~packet

    method write_bool v   = SFPacket.writeBool ~packet ~v
    method write_float v  = SFPacket.writeFloat ~packet ~v
    method write_double v = SFPacket.writeDouble ~packet ~v
    method write_string v = SFPacket.writeString ~packet ~v
    method write_int8 v   = SFPacket.writeInt8 ~packet ~v
    method write_uint8 v  = SFPacket.writeUint8 ~packet ~v
    method write_int16 v  = SFPacket.writeInt16 ~packet ~v
    method write_uint16 v = SFPacket.writeUint16 ~packet ~v
    method write_int31 v  = SFPacket.writeInt31 ~packet ~v
    method write_int32 v  = SFPacket.writeInt32 ~packet ~v

    method write (vs : write_value list) =
      List.iter (function
      | `Bool v   -> SFPacket.writeBool ~packet ~v
      | `Float v  -> SFPacket.writeFloat ~packet ~v
      | `Double v -> SFPacket.writeDouble ~packet ~v
      | `String v -> SFPacket.writeString ~packet ~v
      | `Int8 v   -> SFPacket.writeInt8 ~packet ~v
      | `Uint8 v  -> SFPacket.writeUint8 ~packet ~v
      | `Int16 v  -> SFPacket.writeInt16 ~packet ~v
      | `Uint16 v -> SFPacket.writeUint16 ~packet ~v
      | `Int31 v  -> SFPacket.writeInt31 ~packet ~v
      | `Int32 v  -> SFPacket.writeInt32 ~packet ~v
      ) vs

    method read_bool   () = SFPacket.readBool ~packet
    method read_float  () = SFPacket.readFloat ~packet
    method read_double () = SFPacket.readDouble ~packet
    method read_string () = SFPacket.readString ~packet
    method read_int8   () = SFPacket.readInt8 ~packet
    method read_uint8  () = SFPacket.readUint8 ~packet
    method read_int16  () = SFPacket.readInt16 ~packet
    method read_uint16 () = SFPacket.readUint16 ~packet
    method read_int31  () = SFPacket.readInt31 ~packet
    method read_int32  () = SFPacket.readInt32 ~packet

    method read (vs : read_value list) =
      (List.map (function
      | `inBool   -> `Bool   (SFPacket.readBool ~packet)
      | `inFloat  -> `Float  (SFPacket.readFloat ~packet)
      | `inDouble -> `Double (SFPacket.readDouble ~packet)
      | `inString -> `String (SFPacket.readString ~packet)
      | `inInt8   -> `Int8   (SFPacket.readInt8 ~packet)
      | `inUint8  -> `Uint8  (SFPacket.readUint8 ~packet)
      | `inInt16  -> `Int16  (SFPacket.readInt16 ~packet)
      | `inUint16 -> `Uint16 (SFPacket.readUint16 ~packet)
      | `inInt31  -> `Int31  (SFPacket.readInt31 ~packet)
      | `inInt32  -> `Int32  (SFPacket.readInt32 ~packet)
      ) vs : write_value list)
  end


(** {3 TCP Socket} *)

class tcp_socket =
  object
    val socket = SFTcpSocket.create ()
    initializer SFTcpSocket.init ()
    method t = socket

    method destroy ()                      = SFTcpSocket.destroy ~socket
    method set_blocking ~blocking          = SFTcpSocket.setBlocking ~socket ~blocking
    method connect ~port ~address ~timeout = SFTcpSocket.connect ~socket ~port ~address ~timeout
    method send ~data                      = SFTcpSocket.send ~socket ~data
    method send_sub ~data ~ofs ~len        = SFTcpSocket.send_sub ~socket ~data ~ofs ~len
    method receive_buf ~buf                = SFTcpSocket.receive ~socket ~data:buf
    method receive ()                      = SFTcpSocket.receive_str ~socket
    method send_packet ~packet:(p : packet) = SFTcpSocket.sendPacket ~socket ~packet:p#t
    method receive_packet ~packet:(p : packet) = SFTcpSocket.receivePacket ~socket ~packet:p#t
  end


(** {3 UDP Socket} *)

class udp_socket =
  object
    val socket = SFUdpSocket.create ()
    initializer SFUdpSocket.init ()
    method t = socket

    method destroy ()                = SFUdpSocket.destroy ~socket
    method set_blocking ~blocking    = SFUdpSocket.setBlocking ~socket ~blocking
    method bind ~port                = SFUdpSocket.bind ~socket ~port
    method unbind ()                 = SFUdpSocket.unbind ~socket
    method send ~data ~address ~port = SFUdpSocket.send ~socket ~data ~address ~port
    method receive ~data             = SFUdpSocket.receive ~socket ~data
    method send_packet ~packet:(p : packet) ~address ~port =
      SFUdpSocket.sendPacket ~socket ~packet:p#t ~address ~port
    method receive_packet ~packet:(p : packet) =
      SFUdpSocket.receivePacket  ~socket ~packet:p#t
  end


(** {3 HTTP} *)

class http_request =
  object
    val request = SFHttp.Request.create ()
    method destroy () = SFHttp.Request.destroy request
    method set_field ~field ~value = SFHttp.Request.setField request ~field ~value
    method set_method http_method = SFHttp.Request.setMethod request http_method
    method set_uri ~uri = SFHttp.Request.setUri request ~uri
    method set_http_version ~major ~minor = SFHttp.Request.setHttpVersion request ~major ~minor
    method set_body ~body = SFHttp.Request.setBody request ~body
    method t = request
  end


class http_response response =
  object
    val response = response
    method body = SFHttp.Response.getBody response
    method status = SFHttp.Response.getStatus response
    method destroy () = SFHttp.Response.destroy response
    method get_field ~field = SFHttp.Response.getField response ~field
    method major_http_version = SFHttp.Response.getMajorHttpVersion response
    method minor_http_version = SFHttp.Response.getMinorHttpVersion response
  end


class http =
  object
    val http = SFHttp.create ()
    method destroy () = SFHttp.destroy http
    method set_host ~host ?port () = SFHttp.setHost http ~host ?port ()
    method send_request
      ~request:(r : http_request)
      ?timeout:(t : Oo_sfml_system.time option) () =
        let timeout = match t with None -> None | Some t -> Some t#t in
        let resp = SFHttp.sendRequest http ~request:r#t ?timeout () in
        new http_response resp
  end


(** {3 FTP} *)


class response resp =
  object
    val resp = resp
    method destroy    () = SFFtp.Response.destroy resp
    method is_ok      () = SFFtp.Response.isOk resp
    method get_status () = SFFtp.Response.getStatus resp
    method get_message () = SFFtp.Response.getMessage resp
  end


class directory_response dir_resp =
  object
    val dir_resp = dir_resp
    method destroy       () = SFFtp.DirectoryResponse.destroy dir_resp
    method is_ok         () = SFFtp.DirectoryResponse.isOk dir_resp
    method get_status    () = SFFtp.DirectoryResponse.getStatus dir_resp
    method get_message   () = SFFtp.DirectoryResponse.getMessage dir_resp
    method get_directory () = SFFtp.DirectoryResponse.getDirectory dir_resp
  end


class listing_response lst_resp =
  object
    val lst_resp = lst_resp
    method destroy     () = SFFtp.ListingResponse.destroy
    method is_ok       () = SFFtp.ListingResponse.isOk
    method get_status  () = SFFtp.ListingResponse.getStatus
    method get_message () = SFFtp.ListingResponse.getMessage
    method get_listing () = SFFtp.ListingResponse.getListing
  end


class ftp =
  object
    val ftp = SFFtp.create ()

    method destroy () = SFFtp.destroy ftp

    method connect
      ~server:(s : ip_address)
      ?port
      ?timeout:(tm : Oo_sfml_system.time option)
      () =
      let timeout = match tm with None -> None
        | Some tm -> Some tm#t in
      let resp = SFFtp.connect ftp ~server:s#t ?port ?timeout () in
      (new response resp)

    method login_anonymous () =
      let resp = SFFtp.loginAnonymous ftp in
      (new response resp)

    method login ftp ~userName ~password =
      let resp = SFFtp.login ftp ~userName ~password in
      (new response resp)

    method disconnect () =
      let resp = SFFtp.disconnect ftp in
      (new response resp)

    method keep_alive () =
      let resp = SFFtp.keepAlive ftp in
      (new response resp)

    method change_directory ~directory =
      let resp = SFFtp.changeDirectory ftp ~directory in
      (new response resp)

    method parent_directory () =
      let resp = SFFtp.parentDirectory ftp in
      (new response resp)

    method create_directory ~name =
      let resp = SFFtp.createDirectory ftp ~name in
      (new response resp)

    method delete_directory ~name =
      let resp = SFFtp.deleteDirectory ftp ~name in
      (new response resp)

    method rename_file ~file ~newName =
      let resp = SFFtp.renameFile ftp ~file ~newName in
      (new response resp)

    method delete_file ~name =
      let resp = SFFtp.deleteFile ftp ~name in
      (new response resp)

    method upload ~localFile ~destPath ~mode =
      let resp = SFFtp.upload ftp ~localFile ~destPath ~mode in
      (new response resp)

    method download ~distantFile ~destPath ~mode =
      let resp = SFFtp.download ftp ~distantFile ~destPath ~mode in
      (new response resp)

    method get_directory_listing ~directory =
      let lst_resp = SFFtp.getDirectoryListing ftp ~directory in
      (new listing_response lst_resp)

    method get_working_directory () =
      let dir_resp = SFFtp.getWorkingDirectory ftp in
      (new directory_response dir_resp)
  end

