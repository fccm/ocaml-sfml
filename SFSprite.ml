type u

external create: unit -> u = "caml_sfSprite_Create"
external destroy: sprite:u -> unit = "caml_sfSprite_Destroy"


external setImage: sprite:u -> image:SFImage.t -> unit
  = "caml_sfSprite_SetImage"

external resize: sprite:u -> width:float -> height:float -> unit
  = "caml_sfSprite_Resize"

external setX: sprite:u -> x:float -> unit = "caml_sfSprite_SetX"
external setY: sprite:u -> y:float -> unit = "caml_sfSprite_SetY"
external setXY: sprite:u -> x:float -> y:float -> unit = "caml_sfSprite_SetXY"

external setPosition: sprite:u -> x:float -> y:float -> unit
  = "caml_sfSprite_SetPosition"

external setPosition2: sprite:u -> pos:float * float -> unit
  = "caml_sfSprite_SetPosition2"

external move: sprite:u -> offsetX:float -> offsetY:float -> unit
  = "caml_sfSprite_Move"

external move2: sprite:u -> offset:float * float -> unit
  = "caml_sfSprite_Move2"

external scale: sprite:u -> factorX:float -> factorY:float -> unit
  = "caml_sfSprite_Scale"

external scale2: sprite:u -> factor:float * float -> unit
  = "caml_sfSprite_Scale2"

external rotate: sprite:u -> angle:float -> unit = "caml_sfSprite_Rotate"

external flipX: sprite:u -> flipped:bool -> unit
  = "caml_sfSprite_FlipX"
external flipY: sprite:u -> flipped:bool -> unit
  = "caml_sfSprite_FlipY"

external setScaleX: sprite:u -> scale:float -> unit = "caml_sfSprite_SetScaleX"
external setScaleY: sprite:u -> scale:float -> unit = "caml_sfSprite_SetScaleY"

external setScale: sprite:u -> scaleX:float -> scaleY:float -> unit
  = "caml_sfSprite_SetScale"

external setScale2: sprite:u -> scale:float * float -> unit
  = "caml_sfSprite_SetScale2"

external setRotation: sprite:u -> rotation:float -> unit
  = "caml_sfSprite_SetRotation"

external setCenter: sprite:u -> x:float -> y:float -> unit
  = "caml_sfSprite_SetCenter"

external setCenter2: sprite:u -> center:float * float -> unit
  = "caml_sfSprite_SetCenter2"

external setColor: sprite:u -> color:SFColor.t -> unit
  = "caml_sfSprite_SetColor"

external setBlendMode: sprite:u -> mode:SFBlendMode.t -> unit
  = "caml_sfSprite_SetBlendMode"

external getX: sprite:u -> float = "caml_sfSprite_GetX"
external getY: sprite:u -> float = "caml_sfSprite_GetY"
external getXY: sprite:u -> float * float = "caml_sfSprite_GetXY"
external getWidth: sprite:u -> float = "caml_sfSprite_GetWidth"
external getHeight: sprite:u -> float = "caml_sfSprite_GetHeight"
external getDims: sprite:u -> float * float = "caml_sfSprite_GetDimensions"
external getScaleX: sprite:u -> float = "caml_sfSprite_GetScaleX"
external getScaleY: sprite:u -> float = "caml_sfSprite_GetScaleY"
external getScale: sprite:u -> float * float = "caml_sfSprite_GetScale"
external getRotation: sprite:u -> float = "caml_sfSprite_GetRotation"
external getCenterX: sprite:u -> float = "caml_sfSprite_GetCenterX"
external getCenterY: sprite:u -> float = "caml_sfSprite_GetCenterY"
external getCenter: sprite:u -> float * float = "caml_sfSprite_GetCenter"
external getSubRect: sprite:u -> int SFRect.t = "caml_sfSprite_GetSubRect"
external getPixel: sprite:u -> x:int -> y:int -> SFColor.t = "caml_sfSprite_GetPixel"

(* ================ *)

type t = { u:u; mutable img: SFImage.t option; s:string }

let destroy sprite = destroy sprite.u

let create() =
  let u = create() in
  let t = {u=u; img=None; s=" "} in
  Gc.finalise destroy t;
  (t)

let resize ~sprite       = resize ~sprite:sprite.u
let setX ~sprite         = setX ~sprite:sprite.u
let setY ~sprite         = setY ~sprite:sprite.u
let setXY ~sprite        = setXY ~sprite:sprite.u
let setPosition ~sprite  = setPosition ~sprite:sprite.u
let setPosition2 ~sprite = setPosition2 ~sprite:sprite.u
let move ~sprite         = move ~sprite:sprite.u
let move2 ~sprite        = move2 ~sprite:sprite.u
let scale ~sprite        = scale ~sprite:sprite.u
let scale2 ~sprite       = scale2 ~sprite:sprite.u
let rotate ~sprite       = rotate ~sprite:sprite.u
let flipX ~sprite        = flipX ~sprite:sprite.u
let flipY ~sprite        = flipY ~sprite:sprite.u
let setScaleX ~sprite    = setScaleX ~sprite:sprite.u
let setScaleY ~sprite    = setScaleY ~sprite:sprite.u
let setScale ~sprite     = setScale ~sprite:sprite.u
let setScale2 ~sprite    = setScale2 ~sprite:sprite.u
let setRotation ~sprite  = setRotation ~sprite:sprite.u
let setCenter ~sprite    = setCenter ~sprite:sprite.u
let setCenter2 ~sprite   = setCenter2 ~sprite:sprite.u
let setColor ~sprite     = setColor ~sprite:sprite.u
let setBlendMode ~sprite = setBlendMode ~sprite:sprite.u

let getX ~sprite        = getX ~sprite:sprite.u
let getY ~sprite        = getY ~sprite:sprite.u
let getXY ~sprite       = getXY ~sprite:sprite.u
let getWidth ~sprite    = getWidth ~sprite:sprite.u
let getHeight ~sprite   = getHeight ~sprite:sprite.u
let getDims ~sprite     = getDims ~sprite:sprite.u
let getScaleX ~sprite   = getScaleX ~sprite:sprite.u
let getScaleY ~sprite   = getScaleY ~sprite:sprite.u
let getScale ~sprite    = getScale ~sprite:sprite.u
let getRotation ~sprite = getRotation ~sprite:sprite.u
let getCenterX ~sprite  = getCenterX ~sprite:sprite.u
let getCenterY ~sprite  = getCenterY ~sprite:sprite.u
let getCenter ~sprite   = getCenter ~sprite:sprite.u
let getSubRect ~sprite  = getSubRect ~sprite:sprite.u
let getPixel ~sprite    = getPixel ~sprite:sprite.u


let setImage ~sprite ~image =
  sprite.img <- Some image;
  setImage ~sprite:sprite.u ~image;
;;

let make ?image () =
  let sprite = create() in
  (match image with Some image -> setImage ~sprite ~image | _ -> ());
  (sprite)

