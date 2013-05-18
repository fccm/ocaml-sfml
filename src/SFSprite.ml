type u

external create: unit -> u = "caml_sfSprite_create"
external destroy: u -> unit = "caml_sfSprite_destroy"

external copy: sprite:u -> u = "caml_sfSprite_copy"

external setPosition: sprite:u -> pos:float * float -> unit
  = "caml_sfSprite_setPosition"

external setPosition2: sprite:u -> x:float -> y:float -> unit
  = "caml_sfSprite_setPosition2"

external move: sprite:u -> offset:float * float -> unit
  = "caml_sfSprite_move"

external move2: sprite:u -> offsetX:float -> offsetY:float -> unit
  = "caml_sfSprite_move2"

external scale: sprite:u -> factors:float * float -> unit
  = "caml_sfSprite_scale"

external scale2: sprite:u -> factorX:float -> factorY:float -> unit
  = "caml_sfSprite_scale2"

external rotate: sprite:u -> angle:float -> unit = "caml_sfSprite_rotate"

external setScale: sprite:u -> scale:float * float -> unit
  = "caml_sfSprite_setScale"

external setScale2: sprite:u -> scaleX:float -> scaleY:float -> unit
  = "caml_sfSprite_setScale2"

external setRotation: sprite:u -> rotation:float -> unit
  = "caml_sfSprite_setRotation"

external setOrigin: sprite:u -> origin:float * float -> unit
  = "caml_sfSprite_setOrigin"

external setColor: sprite:u -> color:SFColor.t -> unit
  = "caml_sfSprite_setColor"

external setTexture: sprite:u -> texture:SFTexture.t -> resetRect:bool -> unit
  = "caml_sfSprite_setTexture"

external getScaleX: sprite:u -> float = "caml_sfSprite_getScaleX"
external getScaleY: sprite:u -> float = "caml_sfSprite_getScaleY"
external getScale: sprite:u -> float * float = "caml_sfSprite_getScale"
external getRotation: sprite:u -> float = "caml_sfSprite_getRotation"

(* ================ *)

type t = { u:u; s:string }

let destroy sprite =
  Printf.printf "# destroying sprite (%s)...\n%!" sprite.s;
  destroy sprite.u

let create () =
  let u = create () in
  let t = {u=u; s=" "} in
  Gc.finalise destroy t;
  (t)

let copy ~sprite:s =
  let u = copy ~sprite:s.u in
  let t = {u=u; s=" "} in
  Gc.finalise destroy t;
  (t)

let setPosition ~sprite  = setPosition ~sprite:sprite.u
let setPosition2 ~sprite = setPosition2 ~sprite:sprite.u
let move ~sprite         = move ~sprite:sprite.u
let move2 ~sprite        = move2 ~sprite:sprite.u
let scale ~sprite        = scale ~sprite:sprite.u
let scale2 ~sprite       = scale2 ~sprite:sprite.u
let rotate ~sprite       = rotate ~sprite:sprite.u
let setScale ~sprite     = setScale ~sprite:sprite.u
let setScale2 ~sprite    = setScale2 ~sprite:sprite.u
let setRotation ~sprite  = setRotation ~sprite:sprite.u
let setOrigin ~sprite    = setOrigin ~sprite:sprite.u
let setColor ~sprite     = setColor ~sprite:sprite.u
let setTexture ~sprite   = setTexture ~sprite:sprite.u
let getScaleX ~sprite    = getScaleX ~sprite:sprite.u
let getScaleY ~sprite    = getScaleY ~sprite:sprite.u
let getScale ~sprite     = getScale ~sprite:sprite.u
let getRotation ~sprite  = getRotation ~sprite:sprite.u
