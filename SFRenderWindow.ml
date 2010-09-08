type t

type window_style =
  [ `titlebar
  | `resize  
  | `close   
  | `fullscreen
  ]

type video_mode =
  { width : int;
    height : int;
    bitsPerPixel : int;
  }

type window_settings =
  { depthBits : int;
    stencilBits : int;
    antialiasingLevel : int;
  }

let mode ~width ~height ~bitsPerPixel =
  { width = width;
    height = height;
    bitsPerPixel = bitsPerPixel;
  }

let settings ~depthBits ~stencilBits ~antialiasingLevel =
  { depthBits = depthBits;
    stencilBits = stencilBits;
    antialiasingLevel = antialiasingLevel;
  }

external create: mode:video_mode -> title:string ->
  style:window_style list -> settings:window_settings -> t
  = "caml_sfRenderWindow_Create"

external createFromHandle: handle:int32 -> settings:window_settings -> t
  = "caml_sfRenderWindow_CreateFromHandle"

let make ?(style = [`resize; `close]) ?(bpp = 32)
    ?(depth = 24) ?(stencil = 8) ?(antialiasing = 0)
    (width, height) title =
  let mode, settings =
    { width = width; height = height; bitsPerPixel = bpp },
    { depthBits = depth; stencilBits = stencil; antialiasingLevel = antialiasing }
  in
  (create ~mode ~title ~style ~settings)

external isOpened: t -> bool = "caml_sfRenderWindow_IsOpened"
external close: t -> unit = "caml_sfRenderWindow_Close"
external display: t -> unit = "caml_sfRenderWindow_Display"
external destroy: t -> unit = "caml_sfRenderWindow_Destroy"

external getEvent: t -> SFEvent.t option = "caml_sfRenderWindow_GetEvent"
external clear: t -> SFColor.t -> unit = "caml_sfRenderWindow_Clear"
external blank: t -> unit = "caml_sfRenderWindow_Blank"

external getWidth: t -> int = "caml_sfRenderWindow_GetWidth"
external getHeight: t -> int = "caml_sfRenderWindow_GetHeight"
external getSize: t -> int * int = "caml_sfRenderWindow_GetSize"

external setSize: t -> width:int -> height:int -> unit
  = "caml_sfRenderWindow_SetSize"

external showMouseCursor: t -> show:bool -> unit = "caml_sfRenderWindow_ShowMouseCursor"
external show: t -> state:bool -> unit = "caml_sfRenderWindow_Show"
external enableKeyRepeat: t -> enabled:bool -> unit = "caml_sfRenderWindow_EnableKeyRepeat"
external setActive: t -> active:bool -> unit = "caml_sfRenderWindow_SetActive"

external drawSprite: t -> sprite:SFSprite.t -> unit = "caml_sfRenderWindow_DrawSprite"
external drawString: t -> text:SFString.t -> unit = "caml_sfRenderWindow_DrawString"
external drawShape: t -> shape:SFShape.t -> unit = "caml_sfRenderWindow_DrawShape"

external preserveOpenGLStates: t -> preserve:bool -> unit
  = "caml_sfRenderWindow_PreserveOpenGLStates"

external setCursorPosition: t -> left:int -> top:int -> unit
  = "caml_sfRenderWindow_SetCursorPosition"
external setPosition: t -> left:int -> top:int -> unit
  = "caml_sfRenderWindow_SetPosition"

external setFramerateLimit: t -> limit:int -> unit
  = "caml_sfRenderWindow_SetFramerateLimit"

external getFrameTime: t -> float = "caml_sfRenderWindow_GetFrameTime"

external setView: t -> view:SFView.t -> unit = "caml_sfRenderWindow_SetView"

external convertCoords:
  t -> winX:int -> winY:int -> targetView:SFView.t -> float * float
  = "caml_sfRenderWindow_ConvertCoords"

external useVerticalSync: t -> enabled:bool -> unit
  = "caml_sfRenderWindow_UseVerticalSync"

external setJoystickThreshold: t -> threshold:float -> unit
  = "caml_sfRenderWindow_SetJoystickThreshold"

external getInput: t -> SFInput.t = "caml_sfRenderWindow_GetInput"
