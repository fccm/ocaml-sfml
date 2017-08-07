type attribute = Default | Core | Debug

type t =
  { depthBits : int;
    stencilBits : int;
    antialiasingLevel : int;
    majorVersion : int;
    minorVersion : int;
    attributes : attribute list;
    sRgbCapable : bool
  }

let default =
  { depthBits = 0;
    stencilBits = 0;
    antialiasingLevel = 0;
    majorVersion = 1;
    minorVersion = 1;
    attributes = [Default];
    sRgbCapable = false
  }
