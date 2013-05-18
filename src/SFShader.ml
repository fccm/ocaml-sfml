type t

external loadFromFile:
  ?vertexShaderFilename:string -> ?fragmentShaderFilename:string -> unit -> t
  = "caml_sfShader_loadFromFile"

external loadFromMemory:
  ?vertexShader:string -> ?fragmentShader:string -> unit -> t
  = "caml_sfShader_loadFromMemory"

type input = [ `Filename of string | `Buffer of string ]

let load ?(vertexShader : input option) ?(fragmentShader : input option) () =
  match vertexShader, fragmentShader with
  | Some(`Filename vertexShaderFilename), Some(`Filename fragmentShaderFilename) ->
      loadFromFile ~vertexShaderFilename ~fragmentShaderFilename ()
  | Some(`Filename vertexShaderFilename), None ->
      loadFromFile ~vertexShaderFilename ()
  | None, Some(`Filename fragmentShaderFilename) ->
      loadFromFile ~fragmentShaderFilename ()

  | Some(`Buffer vertexShader), Some(`Buffer fragmentShader) ->
      loadFromMemory ~vertexShader ~fragmentShader ()
  | Some(`Buffer vertexShader), None ->
      loadFromMemory ~vertexShader ()
  | None, Some(`Buffer fragmentShader) ->
      loadFromMemory ~fragmentShader ()

  | None, None ->
      failwith "SFShader.load: no input provided"

  | Some(`Filename _), Some(`Buffer _)
  | Some(`Buffer _), Some(`Filename _) ->
      failwith "SFShader.load: incompatible input"
;;

external destroy: shader:t -> unit = "caml_sfShader_destroy"

external bind: shader:t -> unit = "caml_sfShader_bind"
(* TODO
external unbind: shader:t -> unit = "caml_sfShader_unbind"
*)
external isAvailable: unit -> bool = "caml_sfShader_isAvailable"

external setFloatParameter: shader:t -> name:string -> x:float -> unit
  = "caml_sfShader_setFloatParameter"
external setFloat2Parameter: shader:t -> name:string -> x:float -> y:float -> unit
  = "caml_sfShader_setFloat2Parameter"
external setFloat3Parameter: shader:t -> name:string -> x:float -> y:float -> z:float -> unit
  = "caml_sfShader_setFloat3Parameter"
external setFloat4Parameter: shader:t -> name:string -> x:float -> y:float -> z:float -> w:float -> unit
  = "caml_sfShader_setFloat4Parameter_bytecode"
    "caml_sfShader_setFloat4Parameter_native"
