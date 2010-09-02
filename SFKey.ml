type t =
  | A
  | B
  | C
  | D
  | E
  | F
  | G
  | H
  | I
  | J
  | K
  | L
  | M
  | N
  | O
  | P
  | Q
  | R
  | S
  | T
  | U
  | V
  | W
  | X
  | Y
  | Z
  | Num0
  | Num1
  | Num2
  | Num3
  | Num4
  | Num5
  | Num6
  | Num7
  | Num8
  | Num9
  | Escape
  | LControl
  | LShift
  | LAlt
  | LSystem  (** OS specific key (left side) : windows (Win and Linux), apple (MacOS), ... *)
  | RControl
  | RShift
  | RAlt
  | RSystem  (** OS specific key (right side) : windows (Win and Linux), apple (MacOS), ... *)
  | Menu
  | LBracket  (** [ *)
  | RBracket  (** ] *)
  | SemiColon  (** ; *)
  | Comma  (** , *)
  | Period  (** . *)
  | Quote  (** ' *)
  | Slash  (** / *)
  | BackSlash
  | Tilde     (** ~ *)
  | Equal     (** = *)
  | Dash      (** - *)
  | Space
  | Return
  | Back
  | Tab
  | PageUp
  | PageDown
  | End
  | Home
  | Insert
  | Delete
  | Add       (** + *)
  | Subtract  (** - *)
  | Multiply  (** * *)
  | Divide    (** / *)
  | Left      (** Left arrow *)
  | Right     (** Right arrow *)
  | Up        (** Up arrow *)
  | Down      (** Down arrow *)
  | Numpad0
  | Numpad1
  | Numpad2
  | Numpad3
  | Numpad4
  | Numpad5
  | Numpad6
  | Numpad7
  | Numpad8
  | Numpad9
  | F1
  | F2
  | F3
  | F4
  | F5
  | F6
  | F7
  | F8
  | F9
  | F10
  | F11
  | F12
  | F13
  | F14
  | F15
  | Pause
  | Unknown

let string_of_keyCode = function
  | A -> "a"
  | B -> "b"
  | C -> "c"
  | D -> "d"
  | E -> "e"
  | F -> "f"
  | G -> "g"
  | H -> "h"
  | I -> "i"
  | J -> "j"
  | K -> "k"
  | L -> "l"
  | M -> "m"
  | N -> "n"
  | O -> "o"
  | P -> "p"
  | Q -> "q"
  | R -> "r"
  | S -> "s"
  | T -> "t"
  | U -> "u"
  | V -> "v"
  | W -> "w"
  | X -> "x"
  | Y -> "y"
  | Z -> "z"
  | Num0 -> "0"
  | Num1 -> "1"
  | Num2 -> "2"
  | Num3 -> "3"
  | Num4 -> "4"
  | Num5 -> "5"
  | Num6 -> "6"
  | Num7 -> "7"
  | Num8 -> "8"
  | Num9 -> "9"
  | F1   -> "F1"
  | F2   -> "F2"
  | F3   -> "F3"
  | F4   -> "F4"
  | F5   -> "F5"
  | F6   -> "F6"
  | F7   -> "F7"
  | F8   -> "F8"
  | F9   -> "F9"
  | F10  -> "F10"
  | F11  -> "F11"
  | F12  -> "F12"
  | F13  -> "F13"
  | F14  -> "F14"
  | F15  -> "F15"
  | Numpad0 -> "0"
  | Numpad1 -> "1"
  | Numpad2 -> "2"
  | Numpad3 -> "3"
  | Numpad4 -> "4"
  | Numpad5 -> "5"
  | Numpad6 -> "6"
  | Numpad7 -> "7"
  | Numpad8 -> "8"
  | Numpad9 -> "9"
  | Escape    -> "escape"
  | LControl  -> "LControl"
  | LShift    -> "LShift"
  | LAlt      -> "LAlt"
  | LSystem   -> "LSystem"
  | RControl  -> "RControl"
  | RShift    -> "RShift"
  | RAlt      -> "RAlt"
  | RSystem   -> "RSystem"
  | Menu      -> "menu"
  | LBracket  -> "["
  | RBracket  -> "]"
  | SemiColon -> ";"
  | Comma     -> ","
  | Period    -> "."
  | Quote     -> "'"
  | Slash     -> "/"
  | BackSlash -> "\\"
  | Tilde     -> "~"
  | Equal     -> "="
  | Dash      -> "-"
  | Space     -> " "
  | Return    -> "\n"
  | Back      -> "back"
  | Tab       -> "\t"
  | PageUp    -> "pageUp"
  | PageDown  -> "pageDown"
  | End       -> "end"
  | Home      -> "home"
  | Insert    -> "insert"
  | Delete    -> "delete"
  | Add       -> "+"
  | Subtract  -> "-"
  | Multiply  -> "*"
  | Divide    -> "/"
  | Left      -> "left arrow"
  | Right     -> "right arrow"
  | Up        -> "up arrow"
  | Down      -> "down arrow"
  | Pause     -> "pause"
  | Unknown   -> "unknown"
