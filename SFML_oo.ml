(** OO style interface *)

class time =
  object
    method sleep ~duration = SFClock.sleep ~duration
  end

class clock =
  object
    val clock = SFClock.create ()
    method destroy () = SFClock.destroy ~clock
    method getTime () = SFClock.getTime ~clock
    method reset () = SFClock.reset ~clock
  end

class pausableClock ~paused =
  object
    val clock = SFPausableClock.create ~paused
    method destroy ()    = SFPausableClock.destroy ~clock
    method getTime ()    = SFPausableClock.getTime ~clock
    method reset ~paused = SFPausableClock.reset ~clock ~paused
    method pause ()      = SFPausableClock.pause ~clock
    method start ()      = SFPausableClock.start ~clock
  end


type image_src =
  [ `FromFile of string
  | `FromMemory of string
  | `FromColor of (int * int * SFColor.t)
  | `FromPixels of (int * int * string)
  | `FromPixelsArray of (int * int * int * int) array array
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

    method width  = SFImage.getWidth  ~image
    method height = SFImage.getHeight ~image
    method dims   = SFImage.getDims   ~image

    method getPixelsBA () = SFImage.getPixelsBA ~image
    method getPixelsStr () = SFImage.getPixelsStr ~image

    method getPixel4    ~x ~y = SFImage.getPixel4    ~image ~x ~y
    method getPixel3    ~x ~y = SFImage.getPixel3    ~image ~x ~y
    method getPixelRGB  ~x ~y = SFImage.getPixelRGB  ~image ~x ~y
    method getPixelRGBA ~x ~y = SFImage.getPixelRGBA ~image ~x ~y

    method saveToFile ~filename  = SFImage.saveToFile ~image ~filename
    method setPixel ~x ~y ~color = SFImage.setPixel ~image ~x ~y ~color
    method setSmooth ~smooth     = SFImage.setSmooth ~image ~smooth
    method isSmooth ()           = SFImage.isSmooth ~image
    method bind ()               = SFImage.bind ~image

    method t = image
  end


type draw_type =
  | Sprite of SFSprite.t
  | String of SFString.t
  | Shape of SFShape.t

class virtual drawable =
  object
    method virtual draw_item : draw_type
  end


class sprite ?(image : image option) () =
  object
    inherit drawable

    val sprite =
      match image with
      | Some img -> SFSprite.make ~image:img#t ()
      | None -> SFSprite.make ()

    method setImage ~image:(img : image) = SFSprite.setImage ~sprite ~image:img#t
    method resize ~width ~height    = SFSprite.resize ~sprite ~width ~height
    method setX ~x                  = SFSprite.setX ~sprite ~x
    method setY ~y                  = SFSprite.setY ~sprite ~y
    method setXY ~x ~y              = SFSprite.setXY ~sprite ~x ~y
    method setPosition ~x ~y        = SFSprite.setPosition ~sprite ~x ~y
    method setPosition2 ~pos        = SFSprite.setPosition2 ~sprite ~pos
    method move ~offsetX ~offsetY   = SFSprite.move ~sprite ~offsetX ~offsetY
    method move2 ~offset            = SFSprite.move2 ~sprite ~offset
    method scale ~factorX ~factorY  = SFSprite.scale ~sprite ~factorX ~factorY
    method scale2 ~factor           = SFSprite.scale2 ~sprite ~factor
    method rotate ~angle            = SFSprite.rotate ~sprite ~angle
    method flipX ~flipped           = SFSprite.flipX ~sprite ~flipped
    method flipY ~flipped           = SFSprite.flipY ~sprite ~flipped
    method setScaleX ~scale         = SFSprite.setScaleX ~sprite ~scale
    method setScaleY ~scale         = SFSprite.setScaleY ~sprite ~scale
    method setScale ~scaleX ~scaleY = SFSprite.setScale ~sprite ~scaleX ~scaleY
    method setScale2 ~scale         = SFSprite.setScale2 ~sprite ~scale
    method setRotation ~rotation    = SFSprite.setRotation ~sprite ~rotation
    method setCenter ~x ~y          = SFSprite.setCenter ~sprite ~x ~y
    method setCenter2 ~center       = SFSprite.setCenter2 ~sprite ~center
    method setColor ~color          = SFSprite.setColor ~sprite ~color
    method setBlendMode ~mode       = SFSprite.setBlendMode ~sprite ~mode

    method x        = SFSprite.getX ~sprite
    method y        = SFSprite.getY ~sprite
    method xy       = SFSprite.getXY ~sprite
    method width    = SFSprite.getWidth ~sprite
    method height   = SFSprite.getHeight ~sprite
    method dims     = SFSprite.getDims ~sprite
    method getScaleX () = SFSprite.getScaleX ~sprite
    method getScaleY () = SFSprite.getScaleY ~sprite
    method getScale () = SFSprite.getScale ~sprite
    method getRotation () = SFSprite.getRotation ~sprite
    method centerX  = SFSprite.getCenterX ~sprite
    method centerY  = SFSprite.getCenterY ~sprite
    method center   = SFSprite.getCenter ~sprite
    method getSubRect () = SFSprite.getSubRect ~sprite

    method t = sprite
    method draw_item = Sprite sprite
  end


type xy = float * float
type color = SFColor.t
type outline_color = SFColor.t
type thickness = float
type outline = float
type radius = float
type point = xy * color * outline_color

type shape_src =
  | Points of point list
  | Line of (xy * xy * thickness * color * outline * outline_color)
  | Rectangle of (xy * xy * color * outline * outline_color)
  | Circle of (xy * radius * color * outline * outline_color)

class shape src =
  object
    inherit drawable

    val shape =
      match src with
      | Points points ->
          let shape = SFShape.create () in
          List.iter (fun (pos, color, outlineCol) ->
            SFShape.addPoint ~shape ~pos ~color ~outlineCol
          ) points;
          (shape)
      | Line (p1, p2, thickness, color, outline, outlineCol) ->
          SFShape.createLine ~p1 ~p2 ~thickness ~color ~outline ~outlineCol
      | Rectangle (p1, p2, color, outline, outlineCol) ->
          SFShape.createRectangle ~p1 ~p2 ~color ~outline ~outlineCol
      | Circle (center, radius, color, outline, outlineCol) ->
          SFShape.createCircle ~center ~radius ~color ~outline ~outlineCol

    method destroy ()              = SFShape.destroy ~shape
    method move ~offsetX ~offsetY  = SFShape.move ~shape ~offsetX ~offsetY
    method move2 ~offset           = SFShape.move2 ~shape ~offset
    method rotate ~angle           = SFShape.rotate ~shape ~angle
    method scale ~factorX ~factorY = SFShape.scale ~shape ~factorX ~factorY
    method scale2 ~factor          = SFShape.scale2 ~shape ~factor
    method setBlendMode ~mode      = SFShape.setBlendMode ~shape ~mode

    method t = shape
    method draw_item = Shape shape
  end


type font_src =
  [ `Default
  | `FromFile of string
  | `FromMemory of string
  ]

class font ?charSize ?charset (src : font_src) =
  object
    val font =
      match src with
      | `Default -> SFFont.getDefaultFont ()
      | `FromFile filename -> SFFont.createFromFile ?charSize ?charset filename
      | `FromMemory buffer -> SFFont.createFromMemory ?charSize ?charset buffer

    method characterSize = SFFont.getCharacterSize ~font

    method t = font
  end


class text ?size ?(font : font option) ?color ?blend ?pos ?rotation ?scale str =
  object
    inherit drawable

    val text =
      let font =
        match font with Some font -> Some font#t | None -> None
      in
      SFString.make ?size ?font ?color ?blend ?pos ?rotation ?scale str

    method setText ~str             = SFString.setText ~text ~str
    method setSize ~size            = SFString.setSize ~text ~size
    method setFont ~font:(f : font) = SFString.setFont ~text ~font:f#t
    method setPosition ~left ~top   = SFString.setPosition ~text ~left ~top
    method setPosition2 ~pos        = SFString.setPosition2 ~text ~pos
    method setColor ~color          = SFString.setColor ~text ~color
    method setRotation ~rotation    = SFString.setRotation ~text ~rotation
    method setScale ~scaleX ~scaleY = SFString.setScale ~text ~scaleX ~scaleY
    method move ~offsetX ~offsetY   = SFString.move ~text ~offsetX ~offsetY
    method move2 ~offset            = SFString.move2 ~text ~offset
    method rotate ~angle            = SFString.rotate ~text ~angle
    method scale ~factorX ~factorY  = SFString.scale ~text ~factorX ~factorY
    method scale2 ~factor           = SFString.scale2 ~text ~factor
    method setBlendMode ~mode       = SFString.setBlendMode ~text ~mode
    method x          = SFString.getX ~text
    method y          = SFString.getY ~text
    method xy         = SFString.getXY ~text
    method getRect () = SFString.getRect ~text

    method t = text
    method draw_item = String text
  end


type music_src =
  [ `FromFile of string
  | `FromMemory of string
  ]

class music (src : music_src) =
  object
    val music =
      match src with
      | `FromFile filename -> SFMusic.createFromFile ~filename
      | `FromMemory data -> SFMusic.createFromMemory ~data

    method destroy ()        = SFMusic.destroy ~music
    method play ()           = SFMusic.play ~music
    method stop ()           = SFMusic.stop ~music
    method pause ()          = SFMusic.pause ~music
    method setLoop ~loop     = SFMusic.setLoop ~music ~loop
    method setVolume ~volume = SFMusic.setVolume ~music ~volume
    method setPitch ~pitch   = SFMusic.setPitch ~music ~pitch
    method setMinDistance ~minDistance     = SFMusic.setMinDistance ~music ~minDistance
    method setAttenuation ~attenuation     = SFMusic.setAttenuation ~music ~attenuation
    method setPosition ~x ~y ~z            = SFMusic.setPosition ~music ~x ~y ~z
    method setRelativeToListener ~relative = SFMusic.setRelativeToListener ~music ~relative
    method volume            = SFMusic.getVolume ~music
    method duration          = SFMusic.getDuration ~music
    method sampleRate        = SFMusic.getSampleRate ~music
    method channelsCount     = SFMusic.getChannelsCount ~music
    method playingOffset     = SFMusic.getPlayingOffset ~music
    method loop              = SFMusic.getLoop ~music
    method pitch             = SFMusic.getPitch ~music
    method position          = SFMusic.getPosition ~music
    method status            = SFMusic.getStatus ~music
  end


class listener =
  object
    method setGlobalVolume ~volume              = SFListener.setGlobalVolume ~volume
    method setPosition3 ~pos                    = SFListener.setPosition3 ~pos
    method setPosition ~posX ~posY ~posZ        = SFListener.setPosition ~posX ~posY ~posZ
    method setTarget3 ~target                   = SFListener.setTarget3 ~target
    method setTarget ~targetX ~targetY ~targetZ = SFListener.setTarget ~targetX ~targetY ~targetZ
    method globalVolume = SFListener.getGlobalVolume ()
    method position     = SFListener.getPosition ()
    method target       = SFListener.getTarget ()
  end


type soundBuffer_src =
  [ `FromFile of string
  | `FromMemory of string
  ]

class soundBuffer src =
  object
    val soundBuffer =
      match src with
      | `FromFile filename -> SFSoundBuffer.createFromFile ~filename
      | `FromMemory data -> SFSoundBuffer.createFromMemory ~data
      
    method saveToFile ~filename = SFSoundBuffer.saveToFile ~soundBuffer ~filename
    method samplesCount  = SFSoundBuffer.getSamplesCount ~soundBuffer
    method sampleRate    = SFSoundBuffer.getSampleRate ~soundBuffer
    method channelsCount = SFSoundBuffer.getChannelsCount ~soundBuffer
    method duration      = SFSoundBuffer.getDuration ~soundBuffer
    method t = soundBuffer
  end


type sound_status = [ `stopped | `paused | `playing ]

class sound =
  object
    val sound = SFSound.create ()

    method getStatus () =
      ((match SFSound.getStatus ~sound with
        | SFSound.Stopped -> `stopped
        | SFSound.Paused  -> `paused 
        | SFSound.Playing -> `playing) : sound_status)

    method setBuffer ~buffer:(b : soundBuffer) = SFSound.setBuffer ~sound ~buffer:b#t
    method play ()       = SFSound.play ~sound
    method pause ()      = SFSound.pause ~sound
    method stop ()       = SFSound.stop ~sound
    method setLoop ~loop = SFSound.setLoop ~sound ~loop
    method getLoop ()    = SFSound.getLoop ~sound
                                           
    method setPitch ~pitch                 = SFSound.setPitch ~sound ~pitch
    method setVolume ~volume               = SFSound.setVolume ~sound ~volume
    method setPosition ~x ~y ~z            = SFSound.setPosition ~sound ~x ~y ~z
    method setRelativeToListener ~relative = SFSound.setRelativeToListener ~sound ~relative
    method setMinDistance ~minDistance     = SFSound.setMinDistance ~sound ~minDistance
    method setAttenuation ~attenuation     = SFSound.setAttenuation ~sound ~attenuation
    method setPlayingOffset ~timeOffset    = SFSound.setPlayingOffset ~sound ~timeOffset
    method playingOffset           = SFSound.getPlayingOffset ~sound
    method pitch                   = SFSound.getPitch ~sound
    method volume                  = SFSound.getVolume ~sound
    method isRelativeToListener () = SFSound.isRelativeToListener ~sound
    method position                = SFSound.getPosition ~sound
    method minDistance             = SFSound.getMinDistance ~sound
    method attenuation             = SFSound.getAttenuation ~sound
  end


class input src =
  object
    val input = src
    method isKeyDown ~key            = SFInput.isKeyDown ~input ~key
    method isMouseButtonDown ~button = SFInput.isMouseButtonDown ~input ~button
    method mousePos                  = SFInput.getMousePos ~input
    method isJoystickButtonDown ~joyId ~button =
      SFInput.isJoystickButtonDown ~input ~joyId ~button
    method getJoystickAxis ~joyId ~axis =
      SFInput.getJoystickAxis ~input ~joyId ~axis
  end


class view ?rect () =
  object
    val view =
      match rect with
      | None -> SFView.create ()
      | Some rect -> SFView.createFromRect ~rect

    method destroy ()             = SFView.destroy ~view
    method setFromRect ~rect      = SFView.setFromRect ~view ~rect
    method setCenter ~x ~y        = SFView.setCenter ~view ~x ~y
    method move ~offsetX ~offsetY = SFView.move ~view ~offsetX ~offsetY
    method move2 ~offset          = SFView.move2 ~view ~offset
    method zoom ~factor           = SFView.zoom ~view ~factor
    method setHalfSize ~halfWidth ~halfHeight =
      SFView.setHalfSize ~view ~halfWidth ~halfHeight
    method rect     = SFView.getRect ~view
    method center   = SFView.getCenter ~view
    method halfSize = SFView.getHalfSize ~view
    method t = view
  end


class window
  ?style ?bpp ?depth ?stencil ?antialiasing (width, height) title =
  object
    val this =
      SFWindow.make ?style ?bpp ?depth ?stencil ?antialiasing
        (width, height) title

(* TODO: SFWindow.createFromHandle : handle:nativeint -> settings:window_settings -> t *)

    method isOpened   = SFWindow.isOpened this
    method close ()   = SFWindow.close this
    method display () = SFWindow.display this
    method destroy () = SFWindow.destroy this

    method getEvent () = SFWindow.getEvent this

    method width  = SFWindow.getWidth this
    method height = SFWindow.getHeight this
    method size   = SFWindow.getSize this

    method setSize ~width ~height          = SFWindow.setSize this ~width ~height

    method showMouseCursor ~show = SFWindow.showMouseCursor this ~show
    method show ~state = SFWindow.show this ~state
    method enableKeyRepeat ~enabled = SFWindow.enableKeyRepeat this ~enabled
    method setActive ~active = SFWindow.setActive this ~active

    method setCursorPosition ~left ~top    = SFWindow.setCursorPosition this ~left ~top
    method useVerticalSync ~enabled        = SFWindow.useVerticalSync this ~enabled
    method setPosition ~left ~top          = SFWindow.setPosition this ~left ~top
    method setFramerateLimit ~limit        = SFWindow.setFramerateLimit this ~limit
    method setJoystickThreshold ~threshold = SFWindow.setJoystickThreshold this ~threshold
    method frameTime                       = SFWindow.getFrameTime this
    method getInput () = new input (SFWindow.getInput this)
  end


class renderWindow
  ?style ?bpp ?depth ?stencil ?antialiasing (width, height) title =
  object
    val this =
      SFRenderWindow.make ?style ?bpp ?depth ?stencil ?antialiasing
        (width, height) title

    method isOpened   = SFRenderWindow.isOpened this
    method close ()   = SFRenderWindow.close this
    method display () = SFRenderWindow.display this
    method destroy () = SFRenderWindow.destroy this

    method getEvent () = SFRenderWindow.getEvent this
    method clear ?(color = SFColor.black) () = SFRenderWindow.clear this color
    method blank () = SFRenderWindow.blank this

    method width  = SFRenderWindow.getWidth this
    method height = SFRenderWindow.getHeight this
    method size   = SFRenderWindow.getSize this

    method setSize ~width ~height = SFRenderWindow.setSize this ~width ~height

    method showMouseCursor ~show = SFRenderWindow.showMouseCursor this ~show
    method show ~state = SFRenderWindow.show this ~state
    method enableKeyRepeat ~enabled = SFRenderWindow.enableKeyRepeat this ~enabled
    method setActive ~active = SFRenderWindow.setActive this ~active

    method drawSprite ~sprite:(s : sprite) = SFRenderWindow.drawSprite this ~sprite:s#t
    method drawText ~text:(t : text) = SFRenderWindow.drawString this ~text:t#t
    method drawShape ~shape:(s : shape) = SFRenderWindow.drawShape this ~shape:s#t

    (*
    method draw (item : < draw_item : draw_type ; .. >) =
      match (item :> drawable)#draw_item with
      | Sprite sprite -> SFRenderWindow.drawSprite this sprite
      | String text -> SFRenderWindow.drawString this text
      | Shape shape -> SFRenderWindow.drawShape this shape
    *)

    method draw (item : drawable) =
      match item#draw_item with
      | Sprite sprite -> SFRenderWindow.drawSprite this sprite
      | String text -> SFRenderWindow.drawString this text
      | Shape shape -> SFRenderWindow.drawShape this shape

    method preserveOpenGLStates ~preserve  = SFRenderWindow.preserveOpenGLStates this ~preserve
    method setCursorPosition    ~left ~top = SFRenderWindow.setCursorPosition    this ~left ~top
    method setPosition          ~left ~top = SFRenderWindow.setPosition          this ~left ~top
    method setFramerateLimit    ~limit     = SFRenderWindow.setFramerateLimit    this ~limit

    method frameTime = SFRenderWindow.getFrameTime this
    method setView ~view:(v : view) = SFRenderWindow.setView this ~view:v#t
    method convertCoords ~winX ~winY ~targetView:(v : view) =
      SFRenderWindow.convertCoords this ~winX ~winY ~targetView:v#t
    method useVerticalSync ~enabled = SFRenderWindow.useVerticalSync this ~enabled
    method setJoystickThreshold ~threshold = SFRenderWindow.setJoystickThreshold this ~threshold
    method getInput () = new input (SFRenderWindow.getInput this)
  end


type ipAddress_src =
  [ `FromString of string
  | `FromBytes of (char * char * char * char)
  | `FromInteger of int32
  | `GetLocalAddress
  | `GetPublicAddress of float
  | `LocalHost
  ]

class ipAddress src =
  object
    val address =
      let address =
        match src with
        | `FromString s -> SFIPAddress.fromString s
        | `FromBytes (b0, b1, b2, b3) -> SFIPAddress.fromBytes ~b0 ~b1 ~b2 ~b3
        | `FromInteger d -> SFIPAddress.fromInteger d
        | `GetLocalAddress -> SFIPAddress.getLocalAddress ()
        | `GetPublicAddress timeout -> SFIPAddress.getPublicAddress ~timeout
        | `LocalHost -> SFIPAddress.localHost ()
      in
      SFIPAddress.isValid_or_fail ~address;
      (address)

    method toString () = SFIPAddress.toString ~address
    method toInteger () = SFIPAddress.toInteger ~address
  end


type write_value =
  [ `Bool of bool
  | `Float of float
  | `Double of float
  | `String of string
  | `Int8 of int
  | `Uint8 of int
  | `Int16 of int
  | `Uint16 of int
  | `Int31 of int
  | `Int32 of int32
  ]

type read_value =
  [ `inBool
  | `inFloat
  | `inDouble
  | `inString
  | `inInt8
  | `inUint8
  | `inInt16
  | `inUint16
  | `inInt31
  | `inInt32
  ]

class packet =
  object
    val packet = SFPacket.create ()
    method t = packet

    method append ~data  = SFPacket.append ~packet ~data
    method clear ()      = SFPacket.clear ~packet
    method getData ()    = SFPacket.getData ~packet
    method endOfPacket   = SFPacket.endOfPacket ~packet
    method canRead       = SFPacket.canRead ~packet

    method writeBool v   = SFPacket.writeBool ~packet ~v
    method writeFloat v  = SFPacket.writeFloat ~packet ~v
    method writeDouble v = SFPacket.writeDouble ~packet ~v
    method writeString v = SFPacket.writeString ~packet ~v
    method writeInt8 v   = SFPacket.writeInt8 ~packet ~v
    method writeUint8 v  = SFPacket.writeUint8 ~packet ~v
    method writeInt16 v  = SFPacket.writeInt16 ~packet ~v
    method writeUint16 v = SFPacket.writeUint16 ~packet ~v
    method writeInt31 v  = SFPacket.writeInt31 ~packet ~v
    method writeInt32 v  = SFPacket.writeInt32 ~packet ~v

    method write (vs : write_value list) =
      List.iter (function
      | `Bool v   -> SFPacket.writeBool ~packet ~v
      | `Float v  -> SFPacket.writeFloat ~packet ~v
      | `Double v -> SFPacket.writeDouble ~packet ~v
      | `String v -> SFPacket.writeString ~packet ~v
      | `Int8 v   -> SFPacket.writeInt8 ~packet ~v
      | `Uint8 v  -> SFPacket.writeUint8 ~packet ~v
      | `Int16 v  -> SFPacket.writeInt16 ~packet ~v
      | `Uint16 v -> SFPacket.writeUint16 ~packet ~v
      | `Int31 v  -> SFPacket.writeInt31 ~packet ~v
      | `Int32 v  -> SFPacket.writeInt32 ~packet ~v
      ) vs

    method readBool   () = SFPacket.readBool ~packet
    method readFloat  () = SFPacket.readFloat ~packet
    method readDouble () = SFPacket.readDouble ~packet
    method readString () = SFPacket.readString ~packet
    method readInt8   () = SFPacket.readInt8 ~packet
    method readUint8  () = SFPacket.readUint8 ~packet
    method readInt16  () = SFPacket.readInt16 ~packet
    method readUint16 () = SFPacket.readUint16 ~packet
    method readInt31  () = SFPacket.readInt31 ~packet
    method readInt32  () = SFPacket.readInt32 ~packet

    method read (vs : read_value list) =
      (List.map (function
      | `inBool   -> `Bool   (SFPacket.readBool ~packet)
      | `inFloat  -> `Float  (SFPacket.readFloat ~packet)
      | `inDouble -> `Double (SFPacket.readDouble ~packet)
      | `inString -> `String (SFPacket.readString ~packet)
      | `inInt8   -> `Int8   (SFPacket.readInt8 ~packet)
      | `inUint8  -> `Uint8  (SFPacket.readUint8 ~packet)
      | `inInt16  -> `Int16  (SFPacket.readInt16 ~packet)
      | `inUint16 -> `Uint16 (SFPacket.readUint16 ~packet)
      | `inInt31  -> `Int31  (SFPacket.readInt31 ~packet)
      | `inInt32  -> `Int32  (SFPacket.readInt32 ~packet)
      ) vs : write_value list)
  end


class socketTCP =
  object
    val socket = SFSocketTCP.create ()
    initializer SFSocketTCP.init ()
    method t = socket

    method destroy ()                      = SFSocketTCP.destroy ~socket
    method setBlocking ~blocking           = SFSocketTCP.setBlocking ~socket ~blocking
    method connect ~port ~address ~timeout = SFSocketTCP.connect ~socket ~port ~address ~timeout
    method listen ~port                    = SFSocketTCP.listen ~socket ~port
    method accept ()                       = SFSocketTCP.accept ~socket
    method send ~data                      = SFSocketTCP.send ~socket ~data
    method send_sub ~data ~ofs ~len        = SFSocketTCP.send_sub ~socket ~data ~ofs ~len
    method receive_buf ~buf                = SFSocketTCP.receive ~socket ~data:buf
    method receive ()                      = SFSocketTCP.receive_str ~socket
    method sendPacket ~packet:(p : packet) = SFSocketTCP.sendPacket ~socket ~packet:p#t
    method receivePacket ~packet:(p : packet) = SFSocketTCP.receivePacket ~socket ~packet:p#t
    method isValid                         = SFSocketTCP.isValid ~socket
  end


class socketUDP =
  object
    val socket = SFSocketUDP.create ()
    initializer SFSocketUDP.init ()
    method t = socket

    method destroy ()                = SFSocketUDP.destroy ~socket
    method setBlocking ~blocking     = SFSocketUDP.setBlocking ~socket ~blocking
    method bind ~port                = SFSocketUDP.bind ~socket ~port
    method unbind ()                 = SFSocketUDP.unbind ~socket
    method send ~data ~address ~port = SFSocketUDP.send ~socket ~data ~address ~port
    method receive ~data             = SFSocketUDP.receive ~socket ~data
    method sendPacket ~packet:(p : packet) ~address ~port =
      SFSocketUDP.sendPacket ~socket ~packet:p#t ~address ~port
    method receivePacket ~packet:(p : packet) =
      SFSocketUDP.receivePacket  ~socket ~packet:p#t
    method isValid = SFSocketUDP.isValid ~socket
  end


class selectorTCP =
  object
    val selector = SFSelector.TCP.create ()

    method destroy ()            = SFSelector.TCP.destroy ~selector
    method add ~socket:(s : socketTCP) = SFSelector.TCP.add ~selector ~socket:s#t
    method remove ~socket:(s : socketTCP) = SFSelector.TCP.remove ~selector ~socket:s#t
    method clear ()              = SFSelector.TCP.clear ~selector
    method wait ~timeout         = SFSelector.TCP.wait ~selector ~timeout
    method getSocketReady ~index = SFSelector.TCP.getSocketReady ~selector ~index
  end


class selectorUDP =
  object
    val selector = SFSelector.UDP.create ()

    method destroy ()            = SFSelector.UDP.destroy ~selector
    method add ~socket:(s : socketUDP) = SFSelector.UDP.add ~selector ~socket:s#t
    method remove ~socket:(s : socketUDP) = SFSelector.UDP.remove ~selector ~socket:s#t
    method clear ()              = SFSelector.UDP.clear ~selector
    method wait ~timeout         = SFSelector.UDP.wait ~selector ~timeout
    method getSocketReady ~index = SFSelector.UDP.getSocketReady ~selector ~index
  end
