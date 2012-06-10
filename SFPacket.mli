(** *)
type t

val create : unit -> t
(** Create a new empty packet *)

val append: packet:t -> data:string -> unit
(** Append data to the end of a packet *)

val clear: packet:t -> unit
(** Clear all the data of a packet. *)

val getData: packet:t -> string

val endOfPacket: packet:t -> bool
(** Tell if the reading position has reached the end of the packet.
    Return true if all data have been read into the packet. *)

val canRead: packet:t -> bool
(** Return the validity of packet.
    Return true if last data extraction from packet was successful. *)

(** Functions to insert data into a packet *)

val writeBool  : packet:t -> v:bool  -> unit
val writeFloat : packet:t -> v:float -> unit
val writeDouble: packet:t -> v:float -> unit
val writeString: packet:t -> v:string -> unit

val writeInt8  : packet:t -> v:int -> unit
val writeUint8 : packet:t -> v:int -> unit
val writeInt16 : packet:t -> v:int -> unit
val writeUint16: packet:t -> v:int -> unit
val writeInt31 : packet:t -> v:int -> unit
val writeInt32 : packet:t -> v:int32 -> unit

(** Functions to extract data from a packet *)

val readBool  : packet:t -> bool
val readFloat : packet:t -> float
val readDouble: packet:t -> float
val readString: packet:t -> string

val readInt8  : packet:t -> int
val readUint8 : packet:t -> int
val readInt16 : packet:t -> int
val readUint16: packet:t -> int
val readInt31 : packet:t -> int
val readInt32 : packet:t -> int32
