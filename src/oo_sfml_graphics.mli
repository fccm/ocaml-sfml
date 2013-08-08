(** *)
(** {{:http://www.sfml-dev.org/documentation/2.0/group__graphics.php}
  Online documentation for the graphics module} *)

class int_rect :
  (int * int) * (int * int) ->
  object
    val rect : int SFRect.t
    method contains : int * int -> bool
    method height : int
    method intersection : int_rect -> int_rect option
    method intersects : int_rect -> bool
    method left : int
    method t : int SFRect.t
    method top : int
    method width : int
  end
class float_rect :
  (float * float) * (float * float) ->
  object
    val rect : float SFRect.t
    method contains : float * float -> bool
    method height : float
    method intersection : float_rect -> float_rect option
    method intersects : float_rect -> bool
    method left : float
    method t : float SFRect.t
    method top : float
    method width : float
  end
type image_src =
    [ `FromColor of int * int * SFColor.t
    | `FromFile of string
    | `FromMemory of string
    | `FromPixels of int * int * string
    | `FromPixelsArray of (int * int * int * int) array array
    | `FromSFImage of SFImage.t ]
type flip_direction = [ `horizontally | `vertically ]
class image :
  image_src ->
  object
    val image : SFImage.t
    method flip : flip_direction -> unit
    method flip_horizontally : unit -> unit
    method flip_vertically : unit -> unit
    method get_pixel3 : x:int -> y:int -> SFColor.t
    method get_pixel4 : x:int -> y:int -> SFColor.t
    method get_pixel_rgb : x:int -> y:int -> SFColor.rgb
    method get_pixel_rgba : x:int -> y:int -> SFColor.rgba
    method get_pixels_ba : unit -> SFImage.gl_image
    method get_pixels_str : unit -> string
    method height : int
    method save_to_file : filename:string -> unit
    method set_pixel : x:int -> y:int -> color:SFColor.t -> unit
    method size : int * int
    method t : SFImage.t
    method width : int
  end
type texture_src =
    [ `FromDims of int * int
    | `FromFile of string
    | `FromImage of image
    | `FromMemory of string ]
val get_texture_max_size : unit -> int
class texture :
  texture_src ->
  ?area:int SFRect.t ->
  unit ->
  object
    val texture : SFTexture.t
    method bind : unit -> unit
    method destroy : unit -> unit
    method is_repeated : bool
    method is_smooth : bool
    method set_repeated : repeated:bool -> unit
    method set_smooth : smooth:bool -> unit
    method size : int * int
    method t : SFTexture.t
  end
class render_states :
  ?blend_mode:SFBlendMode.t ->
  ?transform:SFTransform.t ->
  ?texture:SFTexture.t ->
  ?shader:SFShader.t ->
  unit ->
  object val states : SFRenderStates.t method t : SFRenderStates.t end
type draw_type =
    Sprite of SFSprite.t
  | Text of SFText.t
  | Shape of SFShape.t
  | Circle of SFCircleShape.t
class virtual drawable :
  object
    method virtual draw :
      SFRenderWindow.t -> ?states:render_states -> unit -> unit
    method virtual draw_item : draw_type
  end
class sprite :
  object
    val sprite : SFSprite.t
    method draw : SFRenderWindow.t -> ?states:render_states -> unit -> unit
    method draw_item : draw_type
    method get_rotation : unit -> float
    method get_scale : unit -> float * float
    method get_scale_x : unit -> float
    method get_scale_y : unit -> float
    method move : offset:float * float -> unit
    method move2 : offset_x:float -> offset_y:float -> unit
    method rotate : angle:float -> unit
    method scale : factors:float * float -> unit
    method scale2 : factor_x:float -> factor_y:float -> unit
    method set_color : color:SFColor.t -> unit
    method set_origin : origin:float * float -> unit
    method set_position : pos:float * float -> unit
    method set_position2 : x:float -> y:float -> unit
    method set_rotation : rotation:float -> unit
    method set_scale : scale:float * float -> unit
    method set_scale2 : scale_x:float -> scale_y:float -> unit
    method set_texture : texture:texture -> resetRect:bool -> unit
    method t : SFSprite.t
  end
class shape :
  (float * float) array ->
  object
    val shape : SFShape.t
    method draw : SFRenderWindow.t -> ?states:render_states -> unit -> unit
    method draw_item : draw_type
    method get_point_count : unit -> int
    method move : offset:float * float -> unit
    method move2 : offset_x:float -> offset_y:float -> unit
    method rotate : angle:float -> unit
    method scale : factors:float * float -> unit
    method scale2 : factor_x:float -> factor_y:float -> unit
    method set_fill_color : color:SFColor.t -> unit
    method set_outline_color : color:SFColor.t -> unit
    method set_outline_thickness : thickness:float -> unit
    method t : SFShape.t
    method update : unit -> unit
  end
class circle_shape :
  ?radius:float ->
  ?pointCount:int ->
  unit ->
  object
    val circle : SFCircleShape.t
    method draw : SFRenderWindow.t -> ?states:render_states -> unit -> unit
    method draw_item : draw_type
    method get_point_count : unit -> int
    method set_fill_color : color:SFColor.t -> unit
    method set_point_count : count:int -> unit
    method set_position : position:float * float -> unit
    method set_radius : radius:float -> unit
    method t : SFCircleShape.t
  end
type font_src = [ `FromFile of string | `FromMemory of string ]
class font : font_src -> object val font : SFFont.t method t : SFFont.t end
class text :
  ?font:font ->
  ?color:SFColor.t ->
  ?charSize:int ->
  ?pos:float * float ->
  ?rotation:float ->
  ?scale:float * float ->
  ?origin:float * float ->
  string ->
  object
    val text : SFText.t
    method draw : SFRenderWindow.t -> ?states:render_states -> unit -> unit
    method draw_item : draw_type
    method global_bounds : float_rect
    method local_bounds : float_rect
    method move : offset:float * float -> unit
    method move2 : offset_x:float -> offset_y:float -> unit
    method rotate : angle:float -> unit
    method scale : factors:float * float -> unit
    method scale2 : factor_x:float -> factor_y:float -> unit
    method set_character_size : size:int -> unit
    method set_color : color:SFColor.t -> unit
    method set_font : font:font -> unit
    method set_origin : origin:float * float -> unit
    method set_position : pos:float * float -> unit
    method set_position2 : left:float -> top:float -> unit
    method set_rotation : rotation:float -> unit
    method set_scale : scale:float * float -> unit
    method set_scale2 : scale_x:float -> scale_y:float -> unit
    method set_string : str:string -> unit
    method t : SFText.t
  end
class view :
  ?rect:float SFRect.t ->
  unit ->
  object
    val view : SFView.t
    method center : float * float
    method destroy : unit -> unit
    method move : offset:float * float -> unit
    method move2 : offset_x:float -> offset_y:float -> unit
    method set_center : center:float * float -> unit
    method set_center2 : x:float -> y:float -> unit
    method t : SFView.t
    method zoom : factor:float -> unit
  end
class render_window :
  ?style:SFRenderWindow.window_style list ->
  ?bpp:int ->
  ?depth:int ->
  ?stencil:int ->
  ?antialiasing:int ->
  int * int ->
  string ->
  object
    val this : SFRenderWindow.t
    method blank : unit -> unit
    method clear : ?color:SFColor.t -> unit -> unit
    method close : unit -> unit
    method destroy : unit -> unit
    method display : unit -> unit
    method draw :
      < draw : SFRenderWindow.t -> ?states:render_states -> unit -> unit;
        .. > ->
      ?states:render_states -> unit -> unit
    method draw_shape :
      shape:shape -> ?states:SFRenderStates.t -> unit -> unit
    method draw_sprite :
      sprite:sprite -> ?states:SFRenderStates.t -> unit -> unit
    method draw_text : text:text -> ?states:SFRenderStates.t -> unit -> unit
    method height : int
    method is_open : bool
    method poll_event : unit -> SFEvent.t option
    method pop_gl_states : unit -> unit
    method push_gl_states : unit -> unit
    method reset_gl_states : unit -> unit
    method set_active : active:bool -> unit
    method set_framerate_limit : limit:int -> unit
    method set_joystick_threshold : threshold:float -> unit
    method set_key_repeat_enabled : enabled:bool -> unit
    method set_mouse_cursor_invisible : unit -> unit
    method set_mouse_cursor_visible : unit -> unit
    method set_position : pos:int * int -> unit
    method set_position2 : left:int -> top:int -> unit
    method set_size : size:int * int -> unit
    method set_size2 : width:int -> height:int -> unit
    method set_title : title:string -> unit
    method set_vertical_sync_enabled : enabled:bool -> unit
    method set_view : view:view -> unit
    method set_visible : visible:bool -> unit
    method size : int * int
    method wait_event : unit -> SFEvent.t
    method width : int
  end
