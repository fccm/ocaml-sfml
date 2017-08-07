type t

external create: mode:SFVideoMode.t -> title:string ->
  style:SFStyle.t list -> settings:SFContextSettings.t -> t
  = "caml_sfRenderWindow_create"

external createFromHandle: handle:nativeint -> settings:SFContextSettings.t -> t
  = "caml_sfRenderWindow_createFromHandle"

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

external isOpen: t -> bool = "caml_sfRenderWindow_isOpen"
external close: t -> unit = "caml_sfRenderWindow_close"
external display: t -> unit = "caml_sfRenderWindow_display"
external destroy: t -> unit = "caml_sfRenderWindow_destroy"

external pollEvent: t -> SFEvent.t option = "caml_sfRenderWindow_pollEvent"
external waitEvent : t -> SFEvent.t = "caml_sfRenderWindow_waitEvent"

external clear: t -> SFColor.t -> unit = "caml_sfRenderWindow_clear"
external blank: t -> unit = "caml_sfRenderWindow_blank"

external getSettings: t -> SFContextSettings.t = "caml_sfRenderWindow_getSettings"

external getSize: t -> int * int = "caml_sfRenderWindow_getSize"
external getWidth: t -> int = "caml_sfRenderWindow_getWidth"
external getHeight: t -> int = "caml_sfRenderWindow_getHeight"

external setSize: t -> size:int * int -> unit
  = "caml_sfRenderWindow_setSize2"

external setSize2: t -> width:int -> height:int -> unit
  = "caml_sfRenderWindow_setSize"

external setMouseCursorVisible: t -> show:bool -> unit = "caml_sfRenderWindow_setMouseCursorVisible"
external setMouseCursorGrabbed: t -> grabbed:bool -> unit = "caml_sfRenderWindow_setMouseCursorGrabbed"
external setVisible: t -> visible:bool -> unit = "caml_sfRenderWindow_setVisible"
external setKeyRepeatEnabled: t -> enabled:bool -> unit = "caml_sfRenderWindow_setKeyRepeatEnabled"
external setActive: t -> active:bool -> unit = "caml_sfRenderWindow_setActive"

external drawSprite: t -> sprite:SFSprite.t -> ?states:SFRenderStates.t -> unit -> unit
  = "caml_sfRenderWindow_drawSprite"
external drawText: t -> text:SFText.t -> ?states:SFRenderStates.t -> unit -> unit
  = "caml_sfRenderWindow_drawText"
external drawShape: t -> shape:SFShape.t -> ?states:SFRenderStates.t -> unit -> unit
  = "caml_sfRenderWindow_drawShape"

external drawCircleShape: t -> circle:SFCircleShape.t ->
  ?states:SFRenderStates.t -> unit -> unit
  = "caml_sfRenderWindow_drawCircleShape"

external setPosition: t -> pos:int * int -> unit
  = "caml_sfRenderWindow_setPosition2"

external setPosition2: t -> left:int -> top:int -> unit
  = "caml_sfRenderWindow_setPosition"

external setFramerateLimit: t -> limit:int -> unit
  = "caml_sfRenderWindow_setFramerateLimit"

external setView: t -> view:SFView.t -> unit = "caml_sfRenderWindow_setView"

(* TODO
external convertCoords:
  t -> point:int * int -> targetView:SFView.t -> float * float
  = "caml_sfRenderWindow_convertCoords"
*)

external setVerticalSyncEnabled: t -> enabled:bool -> unit
  = "caml_sfRenderWindow_setVerticalSyncEnabled"

external setJoystickThreshold: t -> threshold:float -> unit
  = "caml_sfRenderWindow_setJoystickThreshold"

external setTitle: t -> title:string -> unit = "caml_sfRenderWindow_setTitle"

external pushGLStates: t -> unit = "caml_sfRenderWindow_pushGLStates"
external popGLStates: t -> unit = "caml_sfRenderWindow_popGLStates"
external resetGLStates: t -> unit = "caml_sfRenderWindow_resetGLStates"

external getView: t -> SFView.t = "caml_sfRenderWindow_getView"

external capture: t -> SFImage.t = "caml_sfRenderWindow_capture"

external getMousePosition: relativeTo:t -> int * int = "caml_sfRenderWindow_getMousePosition"
external setMousePosition: relativeTo:t -> int * int -> unit = "caml_sfRenderWindow_setMousePosition"
(** these functions are also in [SFMouse] but without the [relativeTo] parameter *)
