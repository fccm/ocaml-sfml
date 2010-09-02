type u

external create: unit -> u = "caml_sfString_Create"
external destroy: text:u -> unit = "caml_sfString_Destroy"

external setText: text:u -> str:string -> unit = "caml_sfString_SetText"
external setSize: text:u -> size:float -> unit = "caml_sfString_SetSize"
external setPosition: text:u -> left:float -> top:float -> unit = "caml_sfString_SetPosition"
external setPosition2: text:u -> pos:float * float -> unit = "caml_sfString_SetPosition2"
external setColor: text:u -> color:SFColor.t -> unit = "caml_sfString_SetColor"
external setFont: text:u -> font:SFFont.t -> unit = "caml_sfString_SetFont"
external setRotation: text:u -> rotation:float -> unit = "caml_sfString_SetRotation"
external setScale: text:u -> scaleX:float -> scaleY:float -> unit = "caml_sfString_SetScale"
external setScale2: text:u -> scale:float * float -> unit = "caml_sfString_SetScale2"
external move: text:u -> offsetX:float -> offsetY:float -> unit = "caml_sfString_Move"
external move2: text:u -> offset:float * float -> unit = "caml_sfString_Move2"
external rotate: text:u -> angle:float -> unit = "caml_sfString_Rotate"
external scale: text:u -> factorX:float -> factorY:float -> unit = "caml_sfString_Scale"
external scale2: text:u -> factor:float * float -> unit = "caml_sfString_Scale2"
external setBlendMode: text:u -> mode:SFBlendMode.t -> unit = "caml_sfString_SetBlendMode"
external getX: text:u -> float = "caml_sfString_GetX"
external getY: text:u -> float = "caml_sfString_GetY"
external getXY: text:u -> float * float = "caml_sfString_GetXY"
external getRect: text:u -> float SFRect.t = "caml_sfString_GetRect"

(* ================ *)

type t = { u:u; mutable font: SFFont.t option; s:string }

let destroy text = destroy text.u

let create() =
  let u = create() in
  let t = {u=u; font=None; s=" "} in
  Gc.finalise destroy t;
  (t)

let setText ~text:t      = setText ~text:t.u
let setSize ~text:t      = setSize ~text:t.u
let setPosition ~text:t  = setPosition ~text:t.u
let setPosition2 ~text:t = setPosition2 ~text:t.u
let setColor ~text:t     = setColor ~text:t.u
let setRotation ~text:t  = setRotation ~text:t.u
let setScale ~text:t     = setScale ~text:t.u
let setScale2 ~text:t    = setScale2 ~text:t.u
let move ~text:t         = move ~text:t.u
let move2 ~text:t        = move2 ~text:t.u
let rotate ~text:t       = rotate ~text:t.u
let scale ~text:t        = scale ~text:t.u
let scale2 ~text:t       = scale2 ~text:t.u
let setBlendMode ~text:t = setBlendMode ~text:t.u
let getX ~text:t         = getX ~text:t.u
let getY ~text:t         = getY ~text:t.u
let getXY ~text:t        = getXY ~text:t.u
let getRect ~text:t      = getRect ~text:t.u

let setFont ~text:t ~font =
  t.font <- Some font;
  setFont ~text:t.u ~font;
;;

let make ?size ?font ?color ?blend ?pos ?rotation ?scale str =
  let text = create() in
  setText ~text ~str;
  (match size with Some size -> setSize ~text ~size | _ -> ());
  (match pos with Some pos -> setPosition2 ~text ~pos | _ -> ());
  (match color with Some color -> setColor ~text ~color | _ -> ());
  (match font with Some font -> setFont ~text ~font | _ -> ());
  (match rotation with Some rotation -> setRotation ~text ~rotation | _ -> ());
  (match scale with Some (scaleX, scaleY) -> setScale ~text ~scaleX ~scaleY | _ -> ());
  (match blend with Some mode -> setBlendMode ~text ~mode | _ -> ());
  (text)

