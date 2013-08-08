(** *)
(** {{:http://www.sfml-dev.org/documentation/2.0/group__window.php}
  Online documentation for the window module} *)

class window :
  ?style:SFWindow.window_style list ->
  ?bpp:int ->
  ?depth:int ->
  ?stencil:int ->
  ?antialiasing:int ->
  ?version:int * int ->
  int * int ->
  string ->
  object
    val this : SFWindow.t
    method close : unit -> unit
    method destroy : unit -> unit
    method display : unit -> unit
    method get_mouse_position : unit -> int * int
    method height : int
    method is_open : bool
    method poll_event : unit -> SFEvent.t option
    method position : int * int
    method set_active : active:bool -> bool
    method set_framerate_limit : limit:int -> unit
    method set_joystick_threshold : threshold:float -> unit
    method set_key_repeat_enabled : enabled:bool -> unit
    method set_mouse_cursor_visible : visible:bool -> unit
    method set_mouse_position : int * int -> unit
    method set_position : pos:int * int -> unit
    method set_position2 : left:int -> top:int -> unit
    method set_size : size:int * int -> unit
    method set_size2 : width:int -> height:int -> unit
    method set_title : title:string -> unit
    method set_vertical_sync_enabled : enabled:bool -> unit
    method set_visible : visible:bool -> unit
    method size : int * int
    method wait_event : unit -> SFEvent.t
    method width : int
  end
