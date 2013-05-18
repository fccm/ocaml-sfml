type u

external createFromFile: filename:string -> u = "caml_sfImage_createFromFile"
external destroy: u -> unit = "caml_sfImage_destroy"

external createFromColor: width:int -> height:int -> color:SFColor.t -> u
  = "caml_sfImage_createFromColor"

external createFromMemory: data:string -> u
  = "caml_sfImage_createFromMemory"

external createFromPixels: width:int -> height:int -> data:string -> u
  = "caml_sfImage_createFromPixels"

external getWidth: image:u -> int = "caml_sfImage_getWidth"
external getHeight: image:u -> int = "caml_sfImage_getHeight"
external getSize: image:u -> int * int = "caml_sfImage_getSize"

(* the same type defined in glMLite *)
type gl_image =
  (int, Bigarray.int8_unsigned_elt, Bigarray.c_layout) Bigarray.Genarray.t

external getPixelsBA: image:u -> gl_image = "caml_sfImage_getPixelsBA"
external getPixelsStr: image:u -> string = "caml_sfImage_getPixelsStr"

external getPixel4: image:u -> x:int -> y:int -> SFColor.t = "caml_sfImage_getPixel4"
external getPixel3: image:u -> x:int -> y:int -> SFColor.t = "caml_sfImage_getPixel3"

external getPixelRGB: image:u -> x:int -> y:int -> SFColor.rgb = "caml_sfImage_getPixelRGB"
external getPixelRGBA: image:u -> x:int -> y:int -> SFColor.rgba = "caml_sfImage_getPixelRGBA"


external saveToFile: image:u -> filename:string -> unit = "caml_sfImage_saveToFile"
external setPixel: image:u -> x:int -> y:int -> color:SFColor.t -> unit = "caml_sfImage_setPixel"

external createMaskFromColor: image:u -> color:SFColor.t -> alpha:int -> unit
  = "caml_sfImage_createMaskFromColor"

external flipHorizontally: image:u -> unit = "caml_sfImage_flipHorizontally"
external flipVertically: image:u -> unit = "caml_sfImage_flipVertically"


(* ================ *)

type t = { u:u; s:string }

let getWidth ~image     = getWidth ~image:image.u
let getHeight ~image    = getHeight ~image:image.u
let getSize ~image      = getSize ~image:image.u
let getPixelsBA ~image  = getPixelsBA ~image:image.u
let getPixelsStr ~image = getPixelsStr ~image:image.u
(*
let saveToFile ~image ~filename  = saveToFile ~image:image.u ~filename
let setPixel ~image ~x ~y ~color = setPixel ~image:image.u ~x ~y ~color
let getPixel4    ~image ~x ~y = getPixel4 ~image:image.u ~x ~y
let getPixel3    ~image ~x ~y = getPixel3 ~image:image.u ~x ~y
let getPixelRGB  ~image ~x ~y = getPixelRGB ~image:image.u ~x ~y
let getPixelRGBA ~image ~x ~y = getPixelRGBA ~image:image.u ~x ~y
*)
let saveToFile ~image   = saveToFile ~image:image.u
let setPixel ~image     = setPixel ~image:image.u
let getPixel4    ~image = getPixel4 ~image:image.u
let getPixel3    ~image = getPixel3 ~image:image.u
let getPixelRGB  ~image = getPixelRGB ~image:image.u
let getPixelRGBA ~image = getPixelRGBA ~image:image.u

let createMaskFromColor ~image ~color ~alpha =
  createMaskFromColor ~image:image.u ~color ~alpha

let flipHorizontally ~image = flipHorizontally ~image:image.u
let flipVertically   ~image = flipVertically ~image:image.u


let destroy img =
  Printf.printf "# destroying image (%s)...\n%!" img.s;
  destroy img.u

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


type input =
  [ `Filename of string
  | `Memory of string
  | `Color of int * int * SFColor.t
  | `Pixels of int * int * string
  | `PixelsArray of (int * int * int * int) array array
  ]

let create = function
  | `Filename filename -> createFromFile ~filename
  | `Memory data -> createFromMemory ~data
  | `Color (width, height, color) -> createFromColor ~width ~height ~color
  | `Pixels (width, height, data) -> createFromPixels ~width ~height ~data
  | `PixelsArray pixels -> createFromPixelsArray ~pixels
