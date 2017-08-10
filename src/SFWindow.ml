type t

external create: mode:SFVideoMode.t -> title:string ->
  style:SFStyle.t list -> settings:SFContextSettings.t -> t
  = "caml_sfWindow_create"

let make ?(style = SFStyle.default) ?(bpp = 32)
    ?(settings = SFContextSettings.default) (width, height) title =
  let mode =
    { SFVideoMode.
      width = width;
      height = height;
      bitsPerPixel = bpp;
    }
  in
  (create ~mode ~title ~style ~settings)

type window_handle = nativeint

external createFromHandle:
  handle:window_handle -> settings:SFContextSettings.t -> t
  = "caml_sfWindow_createFromHandle"

external close: t -> unit = "caml_sfWindow_close"

external isOpen: t -> bool = "caml_sfWindow_isOpen"

external getSettings: t -> SFContextSettings.t = "caml_sfWindow_getSettings"

external pollEvent: t -> SFEvent.t option = "caml_sfWindow_pollEvent"

external waitEvent: t -> SFEvent.t = "caml_sfWindow_waitEvent"

external getPosition: t -> int * int = "caml_sfWindow_getPosition"

external setPosition: t -> pos:int * int -> unit = "caml_sfWindow_setPosition"

external setPosition2: t -> left:int -> top:int -> unit
  = "caml_sfWindow_setPosition2"

external getSize: t -> int * int = "caml_sfWindow_getSize"

external getWidth: t -> int = "caml_sfWindow_getWidth"

external getHeight: t -> int = "caml_sfWindow_getHeight"

external setSize: t -> size:int * int -> unit = "caml_sfWindow_setSize"

external setSize2: t -> width:int -> height:int -> unit
  = "caml_sfWindow_setSize2"

external setTitle: t -> title:string -> unit = "caml_sfWindow_setTitle"
(*
external setIcon: t -> size:int * int -> pixels:bytes -> unit
  = "caml_sfWindow_setIcon"
*)
external setVisible: t -> visible:bool -> unit = "caml_sfWindow_setVisible"

external setVerticalSyncEnabled: t -> enabled:bool -> unit
  = "caml_sfWindow_setVerticalSyncEnabled"

external setMouseCursorVisible: t -> visible:bool -> unit
  = "caml_sfWindow_setMouseCursorVisible"

external setMouseCursorGrabbed: t -> grabbed:bool -> unit
  = "caml_sfWindow_setMouseCursorGrabbed"

external setKeyRepeatEnabled: t -> enabled:bool -> unit
  = "caml_sfWindow_setKeyRepeatEnabled"

external setFramerateLimit: t -> limit:int -> unit
  = "caml_sfWindow_setFramerateLimit"

external setJoystickThreshold: t -> threshold:float -> unit
  = "caml_sfWindow_setJoystickThreshold"

external setActive: t -> active:bool -> bool = "caml_sfWindow_setActive"

external requestFocus: t -> unit = "caml_sfWindow_requestFocus"

external hasFocus: t -> bool = "caml_sfWindow_hasFocus"

external display: t -> unit = "caml_sfWindow_display"

external getSystemHandle: t -> window_handle = "caml_sfWindow_getSystemHandle"

(** These functions are also in [SFMouse] but without the [relativeTo] parameter *)
external getMousePosition: relativeTo:t -> int * int
  = "caml_sfWindow_getMousePosition"

external setMousePosition: relativeTo:t -> int * int -> unit
  = "caml_sfWindow_setMousePosition"
