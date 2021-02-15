type u

external create: (float * float) array -> u = "caml_sfShape_create"
external destroy: u -> unit = "caml_sfShape_destroy"

external move: shape:u -> offset:float * float -> unit = "caml_sfShape_move2"
external move2: shape:u -> offsetX:float -> offsetY:float -> unit = "caml_sfShape_move"
external rotate: shape:u -> angle:float -> unit = "caml_sfShape_rotate"
external scale: shape:u -> factors:float * float -> unit = "caml_sfShape_scale2"
external scale2: shape:u -> factorX:float -> factorY:float -> unit = "caml_sfShape_scale"

external setPosition: shape:u -> pos:float * float -> unit = "caml_sfShape_setPosition2"
external setPosition2: shape:u -> posX:float -> posY:float -> unit = "caml_sfShape_setPosition"
external setRotation: shape:u -> angle:float -> unit = "caml_sfShape_setRotation"
external setScale: shape:u -> scale:float * float -> unit = "caml_sfShape_setScale2"
external setScale2: shape:u -> scaleX:float -> scaleY:float -> unit = "caml_sfShape_setScale"
external setOrigin: shape:u -> origin:float * float -> unit = "caml_sfShape_setOrigin2"
external setOrigin2: shape:u -> originX:float -> originY:float -> unit = "caml_sfShape_setOrigin"

external setFillColor: shape:u -> color:SFColor.t -> unit = "caml_sfShape_setFillColor"
external setOutlineColor: shape:u -> color:SFColor.t -> unit = "caml_sfShape_setOutlineColor"
external setOutlineThickness: shape:u -> thickness:float -> unit = "caml_sfShape_setOutlineThickness"

external update: shape:u -> unit = "caml_sfShape_update"

external getPointCount: shape:u -> int = "caml_sfShape_getPointCount"

(* ================ *)

type t = { u:u }

let debug = true

let destroy shape =
  if debug
  then Printf.eprintf "# finalising shape...\n%!";
  destroy shape.u

let create pts =
  let u = create pts in
  let t = { u=u } in
  Gc.finalise destroy t;
  (t)

external of_circle : SFCircleShape.t -> t = "%identity"
external of_rectangle : SFRectangleShape.t -> t = "%identity"

let move ~shape:t = move ~shape:t.u
let move2 ~shape:t = move2 ~shape:t.u
let rotate ~shape:t = rotate ~shape:t.u
let scale ~shape:t = scale ~shape:t.u
let scale2 ~shape:t = scale2 ~shape:t.u
let setPosition ~shape:t = setPosition ~shape:t.u
let setPosition2 ~shape:t = setPosition2 ~shape:t.u
let setRotation ~shape:t = setRotation ~shape:t.u
let setScale ~shape:t = setScale ~shape:t.u
let setScale2 ~shape:t = setScale2 ~shape:t.u
let setOrigin ~shape:t = setOrigin ~shape:t.u
let setOrigin2 ~shape:t = setOrigin2 ~shape:t.u
let setFillColor ~shape:t = setFillColor ~shape:t.u
let setOutlineColor ~shape:t = setOutlineColor ~shape:t.u
let setOutlineThickness ~shape:t = setOutlineThickness ~shape:t.u
let update ~shape:t = update ~shape:t.u
let getPointCount ~shape:t = getPointCount ~shape:t.u
