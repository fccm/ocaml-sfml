(** OO style interface for sfml-graphics *)
(* Copyright (C) 2012 Florent Monnier (email: monnier dot florent on gmail)
   Code provided under MIT license:
   See the file COPYING.txt or this URL:
   https://secure.wikimedia.org/wikipedia/en/wiki/MIT_License
   This software is provided "AS IS", without warranty of any kind. *)


class int_rect ((left, top), (width, height)) =
  object
    val rect = { SFRect. left; top; width; height }

    method left   = rect.SFRect.left
    method top    = rect.SFRect.top
    method width  = rect.SFRect.width
    method height = rect.SFRect.height

    method contains (x, y) =
      SFRect.contains_i ~rect ~x ~y

    method intersects (rect2 : int_rect) =
      SFRect.intersects_i ~rect1:rect ~rect2:rect2#t

    method intersection (rect2 : int_rect) =
      match SFRect.intersection_i ~rect1:rect ~rect2:rect2#t with
      | None -> None
      | Some r -> Some (
          new int_rect (
            (r.SFRect.left,
             r.SFRect.top),
            (r.SFRect.width,
             r.SFRect.height)
          )
        )

    method t = rect
  end


class float_rect ((left, top), (width, height)) =
  object
    val rect = { SFRect. left; top; width; height }

    method left   = rect.SFRect.left
    method top    = rect.SFRect.top
    method width  = rect.SFRect.width
    method height = rect.SFRect.height

    method contains (x, y) =
      SFRect.contains_f ~rect ~x ~y

    method intersects (rect2 : float_rect) =
      SFRect.intersects_f ~rect1:rect ~rect2:rect2#t

    method intersection (rect2 : float_rect) =
      match SFRect.intersection_f ~rect1:rect ~rect2:rect2#t with
      | None -> None
      | Some r -> Some (
          new float_rect (
            (r.SFRect.left,
             r.SFRect.top),
            (r.SFRect.width,
             r.SFRect.height)
          )
        )

    method t = rect
  end


type image_src = [
  | `FromFile of string
  | `FromMemory of bytes
  | `FromColor of (int * int * SFColor.t)
  | `FromPixels of (int * int * bytes)
  | `FromPixelsArray of (int * int * int * int) array array
  | `FromSFImage of SFImage.t
  ]

type flip_direction = [
  | `horizontally
  | `vertically
  ]

class image (src : image_src) =
  object
    val image =
      match src with
      | `FromFile filename -> SFImage.createFromFile ~filename
      | `FromMemory data -> SFImage.createFromMemory ~data
      | `FromColor (width, height, color) -> SFImage.createFromColor ~width ~height ~color
      | `FromPixels (width, height, data) -> SFImage.createFromPixels ~width ~height ~data
      | `FromPixelsArray pixels -> SFImage.createFromPixelsArray ~pixels
      | `FromSFImage img -> img

    method width = SFImage.getWidth ~image
    method height = SFImage.getHeight ~image
    method size = SFImage.getSize ~image

    method get_pixels_ba () = SFImage.getPixelsBA ~image
    method get_pixels_str () = SFImage.getPixelsStr ~image

    method get_pixel4 ~x ~y = SFImage.getPixel4 ~image ~x ~y
    method get_pixel3 ~x ~y = SFImage.getPixel3 ~image ~x ~y
    method get_pixel_rgb ~x ~y = SFImage.getPixelRGB ~image ~x ~y
    method get_pixel_rgba ~x ~y = SFImage.getPixelRGBA ~image ~x ~y

    method save_to_file ~filename = SFImage.saveToFile ~image ~filename
    method set_pixel ~x ~y ~color = SFImage.setPixel ~image ~x ~y ~color

    method flip_horizontally () = SFImage.flipHorizontally ~image
    method flip_vertically () = SFImage.flipVertically ~image

    method flip (dir:flip_direction) =
      match dir with
      | `horizontally -> SFImage.flipHorizontally ~image
      | `vertically -> SFImage.flipVertically ~image

    method t = image
  end


type texture_src = [
  | `FromDims of int * int
  | `FromFile of string
  | `FromMemory of string
  | `FromImage of image
  ]

let get_texture_max_size = SFTexture.getMaximumSize ;;

class texture (src : texture_src) ?area () =
  object
    val texture =
      match src with
      | `FromDims (width, height) -> SFTexture.create ~width ~height
      | `FromFile filename -> SFTexture.createFromFile ~filename ?area ()
      | `FromMemory data -> SFTexture.createFromMemory ~data ?area ()
      | `FromImage img -> SFTexture.createFromImage ~image:img#t ?area ()

  (* TODO
  SFTexture.copy : t -> t
  *)

    method size = SFTexture.getSize texture
    method bind () = SFTexture.bind texture
    method set_smooth ~smooth = SFTexture.setSmooth texture ~smooth
    method is_smooth = SFTexture.isSmooth texture
    method set_repeated ~repeated = SFTexture.setRepeated texture ~repeated
    method is_repeated = SFTexture.isRepeated texture
    method destroy () = SFTexture.destroy texture

    method t = texture
  end


class render_states
  ?blend_mode (* SFBlendMode.t *)
  ?transform (* SFTransform.t *)
  ?texture (* SFTexture.t *)
  ?shader (* SFShader.t *)
  () =
  object
    val states =
      let blendMode = blend_mode in
      SFRenderStates.create ?blendMode ?transform ?texture ?shader ()

    method t = states
  end


type draw_type =
  | Sprite of SFSprite.t
  | Text of SFText.t
  | Shape of SFShape.t
  | Circle of SFCircleShape.t


class virtual drawable =
  object
    method virtual draw_item : draw_type

    method virtual draw :
      SFRenderWindow.t -> ?states:render_states -> unit -> unit
  end



class sprite =
  object
    inherit drawable

    val sprite = SFSprite.create ()

    method set_position ~pos = SFSprite.setPosition ~sprite ~pos
    method set_position2 ~x ~y = SFSprite.setPosition2 ~sprite ~x ~y
    method move ~offset = SFSprite.move ~sprite ~offset
    method move2 ~offset_x:ox ~offset_y:oy = SFSprite.move2 ~sprite ~offsetX:ox ~offsetY:oy
    method scale ~factors = SFSprite.scale ~sprite ~factors
    method scale2 ~factor_x:fx ~factor_y:fy = SFSprite.scale2 ~sprite ~factorX:fx ~factorY:fy
    method rotate ~angle = SFSprite.rotate ~sprite ~angle
    method set_scale ~scale = SFSprite.setScale ~sprite ~scale
    method set_scale2 ~scale_x:sx ~scale_y:sy = SFSprite.setScale2 ~sprite ~scaleX:sx ~scaleY:sy
    method set_rotation ~rotation = SFSprite.setRotation ~sprite ~rotation
    method set_color ~color = SFSprite.setColor ~sprite ~color
    method set_origin ~origin = SFSprite.setOrigin ~sprite ~origin

    method set_texture ~texture:(tex : texture) ~resetRect =
      SFSprite.setTexture ~sprite ~texture:tex#t ~resetRect

    method get_scale_x () = SFSprite.getScaleX ~sprite
    method get_scale_y () = SFSprite.getScaleY ~sprite
    method get_scale () = SFSprite.getScale ~sprite
    method get_rotation () = SFSprite.getRotation ~sprite

    method t = sprite
    method draw_item = Sprite sprite

    method draw rw ?states:(rs : render_states option) () =
      let states = match rs with None -> None | Some st -> Some (st#t) in
      SFRenderWindow.drawSprite rw ~sprite  ?states()
  end


class shape points =
  object
    inherit drawable

    val shape = SFShape.create points

    method move ~offset = SFShape.move ~shape ~offset
    method move2 ~offset_x:ox ~offset_y:oy = SFShape.move2 ~shape ~offsetX:ox ~offsetY:oy
    method rotate ~angle = SFShape.rotate ~shape ~angle
    method scale ~factors = SFShape.scale ~shape ~factors
    method scale2 ~factor_x:fx ~factor_y:fy = SFShape.scale2 ~shape ~factorX:fx ~factorY:fy

    method set_fill_color ~color = SFShape.setFillColor ~shape ~color
    method set_outline_color ~color = SFShape.setOutlineColor ~shape ~color
    method set_outline_thickness ~thickness = SFShape.setOutlineThickness ~shape ~thickness
    method update () = SFShape.update ~shape
    method get_point_count () = SFShape.getPointCount ~shape

    method t = shape
    method draw_item = Shape shape

    method draw rw ?states:(rs : render_states option) () =
      let states = match rs with None -> None | Some st -> Some (st#t) in
      SFRenderWindow.drawShape rw ~shape ?states ()
  end



class circle_shape ?radius ?pointCount () =
  object
    inherit drawable

    val circle = SFCircleShape.create ?radius ?pointCount ()

(*
SFCircleShape.destroy
*)

    method set_point_count ~count = SFCircleShape.setPointCount ~circle ~count
    method get_point_count () = SFCircleShape.getPointCount ~circle
    method set_position ~position = SFCircleShape.setPosition ~circle ~position
    method set_fill_color ~color = SFCircleShape.setFillColor ~circle ~color
    method set_radius ~radius = SFCircleShape.setRadius ~circle ~radius

    method t = circle
    method draw_item = Circle circle

    method draw rw ?states:(rs : render_states option) () =
      let states = match rs with None -> None | Some st -> Some (st#t) in
      SFRenderWindow.drawCircleShape rw ~circle ?states ()
  end



type font_src = [
  | `FromFile of string
  | `FromMemory of string
  ]

class font (src : font_src) =
  object
    val font =
      match src with
      | `FromFile filename -> SFFont.createFromFile ~filename
      | `FromMemory data -> SFFont.createFromMemory ~data

    method t = font
  end


class text ?(font : font option)
           ?color ?charSize ?pos ?rotation ?scale ?origin str =
  object
    inherit drawable

    val text =
      let font =
        match font with Some font -> Some font#t | None -> None
      in
      SFText.make ?font ?color ?charSize ?pos ?rotation ?scale ?origin str

    method set_string ~str           = SFText.setString ~text ~str
    method set_font ~font:(f : font) = SFText.setFont ~text ~font:f#t
    method set_position ~pos         = SFText.setPosition ~text ~pos
    method set_position2 ~left ~top  = SFText.setPosition2 ~text ~left ~top
    method set_color ~color          = SFText.setColor ~text ~color
    method set_character_size ~size  = SFText.setCharacterSize ~text ~size
    method set_origin ~origin        = SFText.setOrigin ~text ~origin
    method set_rotation ~rotation    = SFText.setRotation ~text ~rotation
    method set_scale ~scale          = SFText.setScale ~text ~scale
    method set_scale2 ~scale_x ~scale_y = SFText.setScale2 ~text ~scaleX:scale_x ~scaleY:scale_y
    method move ~offset              = SFText.move ~text ~offset
    method move2 ~offset_x ~offset_y = SFText.move2 ~text ~offsetX:offset_x ~offsetY:offset_y
    method rotate ~angle             = SFText.rotate ~text ~angle
    method scale ~factors            = SFText.scale ~text ~factors
    method scale2 ~factor_x ~factor_y = SFText.scale2 ~text ~factorX:factor_x ~factorY:factor_y

    method local_bounds =
      let { SFRect.left; top; width; height } =
        SFText.getLocalBounds ~text
      in
      new float_rect ((left, top), (width, height))

    method global_bounds =
      let { SFRect.left; top; width; height } =
        SFText.getGlobalBounds ~text
      in
      new float_rect ((left, top), (width, height))

    method t = text
    method draw_item = Text text

    method draw rw ?states:(rs : render_states option) () =
      let states = match rs with None -> None | Some st -> Some (st#t) in
      SFRenderWindow.drawText rw ~text ?states ()
  end


class view ?rect () =
  object
    val view =
      match rect with
      | None -> SFView.create ()
      | Some rect -> SFView.createFromRect ~rect

    method set_center ~center = SFView.setCenter ~view ~center
    method set_center2 ~x ~y = SFView.setCenter2 ~view ~x ~y
    method move ~offset = SFView.move ~view ~offset
    method move2 ~offset_x ~offset_y = SFView.move2 ~view ~offsetX:offset_x ~offsetY:offset_y
    method zoom ~factor = SFView.zoom ~view ~factor
    method center = SFView.getCenter ~view
    method t = view
  end



class render_window
  ?style ?bpp ?settings (width, height) title =
  object
    val this =
      SFRenderWindow.make ?style ?bpp ?settings
        (width, height) title

    method is_open     = SFRenderWindow.isOpen this
    method close ()   = SFRenderWindow.close this
    method display () = SFRenderWindow.display this
    method destroy () = SFRenderWindow.destroy this

    method poll_event () = SFRenderWindow.pollEvent this
    method wait_event () = SFRenderWindow.waitEvent this

    method clear ?(color = SFColor.black) () = SFRenderWindow.clear this color
    method blank () = SFRenderWindow.blank this

    method size = SFRenderWindow.getSize this
    method width = SFRenderWindow.getWidth this
    method height = SFRenderWindow.getHeight this

    method set_size ~size = SFRenderWindow.setSize this ~size
    method set_size2 ~width ~height = SFRenderWindow.setSize2 this ~width ~height

    method set_mouse_cursor_visible () = SFRenderWindow.setMouseCursorVisible this ~show:true
    method set_mouse_cursor_invisible () = SFRenderWindow.setMouseCursorVisible this ~show:false
    method set_mouse_cursor_grabbed () = SFRenderWindow.setMouseCursorGrabbed this ~grabbed:true
    method set_mouse_cursor_ungrabbed () = SFRenderWindow.setMouseCursorGrabbed this ~grabbed:false
    method set_mouse_cursor ~cursor = SFRenderWindow.setMouseCursor this ~cursor
    method set_visible ~visible = SFRenderWindow.setVisible this ~visible
    method set_key_repeat_enabled ~enabled = SFRenderWindow.setKeyRepeatEnabled this ~enabled
    method set_active ~active = SFRenderWindow.setActive this ~active

    method draw_sprite ~sprite:(s : sprite) = SFRenderWindow.drawSprite this ~sprite:s#t
    method draw_text ~text:(t : text) = SFRenderWindow.drawText this ~text:t#t
    method draw_shape ~shape:(s : shape) = SFRenderWindow.drawShape this ~shape:s#t

    method draw : 'a. (<
      draw : SFRenderWindow.t -> ?states:render_states -> unit -> unit;
      .. > as 'a) ->
        ?states:render_states -> unit -> unit =
        fun item ?states () ->
          item#draw this ?states ()

    method set_position ~pos = SFRenderWindow.setPosition this ~pos
    method set_position2 ~left ~top = SFRenderWindow.setPosition2 this ~left ~top
    method set_framerate_limit ~limit = SFRenderWindow.setFramerateLimit this ~limit

    method set_view ~view:(v : view) = SFRenderWindow.setView this ~view:v#t
    (*
    method convert_coords ~point ~target_view:(v : view) =
      SFRenderWindow.convertCoords this ~point ~targetView:v#t
    *)
    method set_vertical_sync_enabled ~enabled = SFRenderWindow.setVerticalSyncEnabled this ~enabled
    method set_joystick_threshold ~threshold = SFRenderWindow.setJoystickThreshold this ~threshold

    method set_title ~title = SFRenderWindow.setTitle this ~title

    method push_gl_states () = SFRenderWindow.pushGLStates this
    method pop_gl_states () = SFRenderWindow.popGLStates this
    method reset_gl_states () = SFRenderWindow.resetGLStates this
  end

