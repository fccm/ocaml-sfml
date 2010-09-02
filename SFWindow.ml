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
  = "caml_sfWindow_Create"

let make ?(style = [`resize; `close]) ?(bpp = 32)
    ?(depth = 24) ?(stencil = 8) ?(antialiasing = 0)
    (width, height) title =
  let mode, settings =
    { width = width; height = height; bitsPerPixel = bpp },
    { depthBits = depth; stencilBits = stencil; antialiasingLevel = antialiasing }
  in
  (create ~mode ~title ~style ~settings)

(*
sfWindow* sfWindow_CreateFromHandle(sfWindowHandle Handle, sfWindowSettings Params);
*)

external isOpened: t -> bool = "caml_sfWindow_IsOpened"
external close: t -> unit = "caml_sfWindow_Close"
external display: t -> unit = "caml_sfWindow_Display"
external destroy: t -> unit = "caml_sfWindow_Destroy"

external getEvent: t -> SFEvent.t option = "caml_sfWindow_GetEvent"

external getWidth: t -> int = "caml_sfWindow_GetWidth"
external getHeight: t -> int = "caml_sfWindow_GetHeight"
external getSize: t -> int * int = "caml_sfWindow_GetSize"

external setSize: t -> width:int -> height:int -> unit
  = "caml_sfWindow_SetSize"

external showMouseCursor: t -> show:bool -> unit
  = "caml_sfWindow_ShowMouseCursor"
external setCursorPosition: t -> left:int -> top:int -> unit
  = "caml_sfWindow_SetCursorPosition"

external getInput: t -> SFInput.t = "caml_sfWindow_GetInput"

external useVerticalSync: t -> enabled:bool -> unit
  = "caml_sfWindow_UseVerticalSync"

external setPosition: t -> left:int -> top:int -> unit
  = "caml_sfWindow_SetPosition"

external show: t -> state:bool -> unit = "caml_sfWindow_Show"

external enableKeyRepeat: t -> enabled:bool -> unit
  = "caml_sfWindow_EnableKeyRepeat"

external setFramerateLimit: t -> limit:int -> unit
  = "caml_sfWindow_SetFramerateLimit"

external setJoystickThreshold: t -> threshold:float -> unit
  = "caml_sfWindow_SetJoystickThreshold"

external setActive: t -> active:bool -> bool = "caml_sfWindow_SetActive"

external getFrameTime: t -> float = "caml_sfWindow_GetFrameTime"
