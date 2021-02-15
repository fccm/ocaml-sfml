type u
(*
type style =
  | Regular
  | Bold
  | Italic
  | Underlined
*)

external create: unit -> u = "caml_sfText_create"
external destroy: u -> unit = "caml_sfText_destroy"

external setString: text:u -> str:string -> unit = "caml_sfText_setString"
external setPosition: text:u -> pos:float * float -> unit = "caml_sfText_setPosition"
external setPosition2: text:u -> left:float -> top:float -> unit = "caml_sfText_setPosition2"
external setColor: text:u -> color:SFColor.t -> unit = "caml_sfText_setColor"
external setOutlineThickness: text:u -> thickness:float -> unit = "caml_sfText_setOutlineThickness"
external setOutlineColor: text:u -> color:SFColor.t -> unit = "caml_sfText_setOutlineColor"
external setFillColor: text:u -> color:SFColor.t -> unit = "caml_sfText_setFillColor"
external setFont: text:u -> font:SFFont.t -> unit = "caml_sfText_setFont"
external setCharacterSize: text:u -> size:int -> unit = "caml_sfText_setCharacterSize"
external setOrigin: text:u -> origin:float * float -> unit = "caml_sfText_setOrigin"
external setRotation: text:u -> rotation:float -> unit = "caml_sfText_setRotation"
external setScale: text:u -> scale:float * float -> unit = "caml_sfText_setScale"
external setScale2: text:u -> scaleX:float -> scaleY:float -> unit = "caml_sfText_setScale2"
external move: text:u -> offset:float * float -> unit = "caml_sfText_move"
external move2: text:u -> offsetX:float -> offsetY:float -> unit = "caml_sfText_move2"
external rotate: text:u -> angle:float -> unit = "caml_sfText_rotate"
external scale: text:u -> factors:float * float -> unit = "caml_sfText_scale"
external scale2: text:u -> factorX:float -> factorY:float -> unit = "caml_sfText_scale2"
external getLocalBounds: text:u -> float SFRect.t = "caml_sfText_getLocalBounds"
external getGlobalBounds: text:u -> float SFRect.t = "caml_sfText_getGlobalBounds"

(* ================ *)

type t = { u:u; mutable font: SFFont.t option }

let debug = true

let destroy text =
  if debug
  then Printf.eprintf "# finalising text...\n%!";
  destroy text.u

let create () =
  let u = create () in
  let t = { u=u; font=None } in
  Gc.finalise destroy t;
  (t)

let setString ~text:t    = setString ~text:t.u
let setPosition ~text:t  = setPosition ~text:t.u
let setPosition2 ~text:t = setPosition2 ~text:t.u
let setColor ~text:t     = setColor ~text:t.u
let setOutlineThickness ~text:t = setOutlineThickness ~text:t.u
let setOutlineColor ~text:t = setOutlineColor ~text:t.u
let setFillColor ~text:t = setFillColor ~text:t.u
let setCharacterSize ~text:t = setCharacterSize ~text:t.u
let setOrigin ~text:t    = setOrigin ~text:t.u
let setRotation ~text:t  = setRotation ~text:t.u
let setScale ~text:t     = setScale ~text:t.u
let setScale2 ~text:t    = setScale2 ~text:t.u
let move ~text:t         = move ~text:t.u
let move2 ~text:t        = move2 ~text:t.u
let rotate ~text:t       = rotate ~text:t.u
let scale ~text:t        = scale ~text:t.u
let scale2 ~text:t       = scale2 ~text:t.u
let getLocalBounds ~text:t = getLocalBounds ~text:t.u
let getGlobalBounds ~text:t = getGlobalBounds ~text:t.u

let setFont ~text:t ~font =
  t.font <- Some font;
  setFont ~text:t.u ~font;
;;

let make ?font ?color ?charSize ?pos ?rotation ?scale ?origin str =
  let text = create () in
  setString ~text ~str;
  (match pos with Some pos -> setPosition ~text ~pos | _ -> ());
  (match color with Some color -> setColor ~text ~color | _ -> ());
  (match charSize with Some size -> setCharacterSize ~text ~size | _ -> ());
  (match font with Some font -> setFont ~text ~font | _ -> ());
  (match rotation with Some rotation -> setRotation ~text ~rotation | _ -> ());
  (match scale with Some scale -> setScale ~text ~scale | _ -> ());
  (match origin with Some origin -> setOrigin ~text ~origin | _ -> ());
  (text)
