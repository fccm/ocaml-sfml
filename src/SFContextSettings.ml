type t =
  { depthBits : int;
    stencilBits : int;
    antialiasingLevel : int;
    majorVersion : int;
    minorVersion : int;
    (* TODO: attributeFlags *)
    sRgbCapable : bool
  }

let default =
  { depthBits = 0;
    stencilBits = 0;
    antialiasingLevel = 0;
    majorVersion = 1;
    minorVersion = 1;
    sRgbCapable = false
  }
