type t
val getDefaultFont: unit -> t
val createFromFile : ?charSize:int -> ?charset:int32 -> string -> t
val createFromMemory : ?charSize:int -> ?charset:int32 -> string -> t
val getCharacterSize: font:t -> int
