type u
type t = { u:u; s:string }

external createFromFile: filename:string -> u = "caml_sfImage_CreateFromFile"
external destroy: image:u -> unit = "caml_sfImage_Destroy"

external createFromColor: width:int -> height:int -> color:SFColor.t -> u
  = "caml_sfImage_CreateFromColor"

external createFromMemory: data:string -> u
  = "caml_sfImage_CreateFromMemory"

external createFromPixels: width:int -> height:int -> data:string -> u
  = "caml_sfImage_CreateFromPixels"

external getWidth: image:u -> int = "caml_sfImage_GetWidth"
external getHeight: image:u -> int = "caml_sfImage_GetHeight"
external getDims: image:u -> int * int = "caml_sfImage_GetDimensions"

(* the same type defined in glMLite *)
type gl_image =
  (int, Bigarray.int8_unsigned_elt, Bigarray.c_layout) Bigarray.Genarray.t

external getPixelsBA: image:u -> gl_image = "caml_sfImage_GetPixelsPtr"

external saveToFile: image:u -> filename:string -> unit = "caml_sfImage_SaveToFile"
external setPixel: image:u -> x:int -> y:int -> color:SFColor.t -> unit = "caml_sfImage_SetPixel"
external setSmooth: image:u -> smooth:bool -> unit = "caml_sfImage_SetSmooth"
external isSmooth: image:u -> bool = "caml_sfImage_IsSmooth"
external bind: image:u -> unit = "caml_sfImage_Bind"


let getWidth ~image    = getWidth ~image:image.u
let getHeight ~image   = getHeight ~image:image.u
let getDims ~image     = getDims ~image:image.u
let getPixelsBA ~image = getPixelsBA ~image:image.u
let saveToFile ~image  = saveToFile ~image:image.u
let setPixel ~image    = setPixel ~image:image.u
let setSmooth ~image   = setSmooth ~image:image.u
let isSmooth  ~image   = isSmooth ~image:image.u
let bind      ~image   = bind ~image:image.u


let destroy img = destroy img.u

let createFromFile ~filename =
  let u = createFromFile ~filename in
  let t = {u=u; s=" "} in
  Gc.finalise destroy t;
  (t)

let createFromColor ~width ~height ~color =
  let u = createFromColor ~width ~height ~color in
  let t = {u=u; s=" "} in
  Gc.finalise destroy t;
  (t)

let createFromMemory ~data =
  let u = createFromMemory ~data in
  let t = {u=u; s=" "} in
  Gc.finalise destroy t;
  (t)

let createFromPixels ~width ~height ~data =
  let u = createFromPixels ~width ~height ~data in
  let t = {u=u; s=" "} in
  Gc.finalise destroy t;
  (t)

let createFromPixelsArray ~pixels =
  let height = Array.length pixels in
  if height = 0 then invalid_arg "SFImage.createFromPixelsArray";
  let width = Array.length pixels.(0) in
  let data = String.create (width * height * 4) in
  for y = 0 to pred height do
    let pixels_y = Array.unsafe_get pixels y in
    if Array.length pixels_y <> width then
      invalid_arg "SFImage.createFromPixelsArray";
    for x = 0 to pred width do
      let r, g, b, a = Array.unsafe_get pixels_y x in
      let r, g, b, a =
        try
          (char_of_int r,
           char_of_int g,
           char_of_int b,
           char_of_int a)
        with Invalid_argument "char_of_int" ->
          invalid_arg "SFImage.createFromPixelsArray"
      in
      let ofs = ((y * width) + x) * 4 in
      String.unsafe_set data (ofs) r;
      String.unsafe_set data (ofs+1) g;
      String.unsafe_set data (ofs+2) b;
      String.unsafe_set data (ofs+3) a;
    done;
  done;
  (createFromPixels ~width ~height ~data)
