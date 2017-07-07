type t =
  | Titlebar
  | Resize
  | Close
  | Fullscreen

let none = []
let default = [Titlebar; Resize; Close]
