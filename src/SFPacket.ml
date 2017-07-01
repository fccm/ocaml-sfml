type u
type t = { u:u; s:string }

external create: unit -> u = "caml_sfPacket_create"
external destroy: u -> unit = "caml_sfPacket_destroy"
external copy: packet:u -> u = "caml_sfPacket_copy"

let destroy packet =
  Printf.printf "# destroying packet (%s)...\n%!" packet.s;
  destroy packet.u

let create () =
  let u = create () in
  let t = {u=u; s=" "} in
  Gc.finalise destroy t;
  (t)

let copy ~packet:p =
  let u = copy ~packet:p.u in
  let t = {u=u; s=" "} in
  Gc.finalise destroy t;
  (t)

external append: packet:u -> data:string -> unit = "caml_sfPacket_append"
external clear: packet:u -> unit = "caml_sfPacket_clear"
external getData: packet:u -> string = "caml_sfPacket_getData"
external endOfPacket: packet:u -> bool = "caml_sfPacket_endOfPacket"
external canRead: packet:u -> bool = "caml_sfPacket_canRead"

let append ~packet:p ~data = append ~packet:p.u ~data
let clear ~packet:p        = clear ~packet:p.u
let getData ~packet:p      = getData ~packet:p.u
let endOfPacket ~packet:p  = endOfPacket ~packet:p.u
let canRead ~packet:p      = canRead ~packet:p.u

external writeBool  : packet:u -> bool -> unit = "caml_sfPacket_writeBool"
external writeFloat : packet:u -> float -> unit = "caml_sfPacket_writeFloat"
external writeDouble: packet:u -> float -> unit = "caml_sfPacket_writeDouble"
external writeString: packet:u -> string -> unit = "caml_sfPacket_writeString"

external writeInt8  : packet:u -> int -> unit = "caml_sfPacket_writeInt8"
external writeUint8 : packet:u -> int -> unit = "caml_sfPacket_writeUint8"
external writeInt16 : packet:u -> int -> unit = "caml_sfPacket_writeInt16"
external writeUint16: packet:u -> int -> unit = "caml_sfPacket_writeUint16"
external writeInt31 : packet:u -> int -> unit = "caml_sfPacket_writeInt32"
external writeInt32 : packet:u -> int32 -> unit = "caml_sfPacket_writeInt32_l"
external writeInt64 : packet:u -> int64 -> unit = "caml_sfPacket_writeInt64"


external readBool  : packet:u -> bool = "caml_sfPacket_readBool"
external readFloat : packet:u -> float = "caml_sfPacket_readFloat"
external readDouble: packet:u -> float = "caml_sfPacket_readDouble"
external readString: packet:u -> string = "caml_sfPacket_readString"

external readInt8  : packet:u -> int = "caml_sfPacket_readInt8"
external readUint8 : packet:u -> int = "caml_sfPacket_readUint8"
external readInt16 : packet:u -> int = "caml_sfPacket_readInt16"
external readUint16: packet:u -> int = "caml_sfPacket_readUint16"
external readInt31 : packet:u -> int = "caml_sfPacket_readInt31"
external readInt32 : packet:u -> int32 = "caml_sfPacket_readInt32_l"
external readInt64 : packet:u -> int64 = "caml_sfPacket_readInt64"

let writeBool   ~packet:p ~v = writeBool   ~packet:p.u v
let writeFloat  ~packet:p ~v = writeFloat  ~packet:p.u v
let writeDouble ~packet:p ~v = writeDouble ~packet:p.u v
let writeString ~packet:p ~v = writeString ~packet:p.u v

let readBool   ~packet:p = readBool   ~packet:p.u
let readFloat  ~packet:p = readFloat  ~packet:p.u
let readDouble ~packet:p = readDouble ~packet:p.u
let readString ~packet:p = readString ~packet:p.u

let int8_min = -128
let int8_max = 127

let int16_min = -32768
let int16_max = 32767

let uint8_max  = 255
let uint16_max = 65535

let int31_min = -1073741824
let int31_max = 1073741823

let range (s, a, b) v =
  if v < a || v > b then invalid_arg s

let p_int8   = ("SFPacket.writeInt8", int8_min, int8_max)
let p_int16  = ("SFPacket.writeInt16", int16_min, int16_max)
let p_uint8  = ("SFPacket.writeUint8", 0, uint8_max)
let p_uint16 = ("SFPacket.writeUint16", 0, uint16_max)
let p_int31  = ("SFPacket.writeInt31", int31_min, int31_max)

let writeInt8   ~packet:p ~v = range p_int8   v; writeInt8   ~packet:p.u v
let writeUint8  ~packet:p ~v = range p_uint8  v; writeUint8  ~packet:p.u v
let writeInt16  ~packet:p ~v = range p_int16  v; writeInt16  ~packet:p.u v
let writeUint16 ~packet:p ~v = range p_uint16 v; writeUint16 ~packet:p.u v
let writeInt31  ~packet:p ~v = range p_int31  v; writeInt31  ~packet:p.u v
let writeInt32  ~packet:p ~v = writeInt32 ~packet:p.u v
let writeInt64  ~packet:p ~v = writeInt64 ~packet:p.u v

let readInt8   ~packet:p = readInt8   ~packet:p.u
let readUint8  ~packet:p = readUint8  ~packet:p.u
let readInt16  ~packet:p = readInt16  ~packet:p.u
let readUint16 ~packet:p = readUint16 ~packet:p.u
let readInt31  ~packet:p = readInt31  ~packet:p.u
let readInt32  ~packet:p = readInt32  ~packet:p.u
let readInt64  ~packet:p = readInt64  ~packet:p.u
