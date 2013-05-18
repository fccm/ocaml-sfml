type u

external create: ?radius:float -> ?pointCount:int -> unit -> u
  = "caml_sfCircleShape_create"

external destroy: u -> unit = "caml_sfCircleShape_destroy"

external setPointCount: circle:u -> count:int -> unit
  = "caml_sfCircleShape_setPointCount"

external getPointCount: circle:u -> int = "caml_sfCircleShape_getPointCount"

external setPosition: circle:u -> position:float * float -> unit
  = "caml_sfCircleShape_setPosition"

external setFillColor: circle:u -> color:SFColor.t -> unit
  = "caml_sfCircleShape_setFillColor"

external setRadius: circle:u -> radius:float -> unit
  = "caml_sfCircleShape_setRadius"

external getRadius: circle:u -> float
  = "caml_sfCircleShape_getRadius"

external setOutlineColor: circle:u -> color:SFColor.t -> unit
  = "caml_sfCircleShape_setOutlineColor"

external setOutlineThickness: circle:u -> thickness:float -> unit
  = "caml_sfCircleShape_setOutlineThickness"

(* ================ *)

type t = { u:u; s:string }

let destroy circle =
  Printf.printf "# destroying circle (%s)...\n%!" circle.s;
  destroy circle.u

let create ?radius ?pointCount () =
  let u = create ?radius ?pointCount () in
  let t = {u=u; s=" "} in
  Gc.finalise destroy t;
  (t)

let setPointCount ~circle:c ~count =
  setPointCount ~circle:c.u ~count

let getPointCount ~circle:c =
  getPointCount ~circle:c.u

let setPosition ~circle:c ~position =
  setPosition ~circle:c.u ~position

let setFillColor ~circle:c ~color =
  setFillColor ~circle:c.u ~color

let setRadius ~circle:c ~radius =
  setRadius ~circle:c.u ~radius

let getRadius ~circle:c =
  getRadius ~circle:c.u

let setOutlineColor ~circle:c ~color =
  setOutlineColor ~circle:c.u ~color

let setOutlineThickness ~circle:c ~thickness =
  setOutlineThickness ~circle:c.u ~thickness
