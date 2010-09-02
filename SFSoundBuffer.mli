type t
val createFromFile : filename:string -> t
val createFromMemory : data:string -> t
val getSamplesCount : soundBuffer:t -> int
val getSampleRate : soundBuffer:t -> int
val getChannelsCount : soundBuffer:t -> int
val getDuration : soundBuffer:t -> float
val saveToFile : soundBuffer:t -> filename:string -> unit
