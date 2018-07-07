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
  | Semicolon  (** ; *)
  | Comma  (** , *)
  | Period  (** . *)
  | Quote  (** ' *)
  | Slash  (** / *)
  | Backslash
  | Tilde     (** ~ *)
  | Equal     (** = *)
  | Hyphen    (** - *)
  | Space
  | Enter
  | Backspace
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
  | A         -> "A"
  | B         -> "B"
  | C         -> "C"
  | D         -> "D"
  | E         -> "E"
  | F         -> "F"
  | G         -> "G"
  | H         -> "H"
  | I         -> "I"
  | J         -> "J"
  | K         -> "K"
  | L         -> "L"
  | M         -> "M"
  | N         -> "N"
  | O         -> "O"
  | P         -> "P"
  | Q         -> "Q"
  | R         -> "R"
  | S         -> "S"
  | T         -> "T"
  | U         -> "U"
  | V         -> "V"
  | W         -> "W"
  | X         -> "X"
  | Y         -> "Y"
  | Z         -> "Z"
  | Num0      -> "Num0"
  | Num1      -> "Num1"
  | Num2      -> "Num2"
  | Num3      -> "Num3"
  | Num4      -> "Num4"
  | Num5      -> "Num5"
  | Num6      -> "Num6"
  | Num7      -> "Num7"
  | Num8      -> "Num8"
  | Num9      -> "Num9"
  | F1        -> "F1"
  | F2        -> "F2"
  | F3        -> "F3"
  | F4        -> "F4"
  | F5        -> "F5"
  | F6        -> "F6"
  | F7        -> "F7"
  | F8        -> "F8"
  | F9        -> "F9"
  | F10       -> "F10"
  | F11       -> "F11"
  | F12       -> "F12"
  | F13       -> "F13"
  | F14       -> "F14"
  | F15       -> "F15"
  | Numpad0   -> "Numpad0"
  | Numpad1   -> "Numpad1"
  | Numpad2   -> "Numpad2"
  | Numpad3   -> "Numpad3"
  | Numpad4   -> "Numpad4"
  | Numpad5   -> "Numpad5"
  | Numpad6   -> "Numpad6"
  | Numpad7   -> "Numpad7"
  | Numpad8   -> "Numpad8"
  | Numpad9   -> "Numpad9"
  | Escape    -> "Escape"
  | LControl  -> "LControl"
  | LShift    -> "LShift"
  | LAlt      -> "LAlt"
  | LSystem   -> "LSystem"
  | RControl  -> "RControl"
  | RShift    -> "RShift"
  | RAlt      -> "RAlt"
  | RSystem   -> "RSystem"
  | Menu      -> "Menu"
  | LBracket  -> "LBracket"
  | RBracket  -> "RBracket"
  | Semicolon -> "Semicolon"
  | Comma     -> "Comma"
  | Period    -> "Period"
  | Quote     -> "Quote"
  | Slash     -> "Slash"
  | Backslash -> "Backslash"
  | Tilde     -> "Tilde"
  | Equal     -> "Equal"
  | Hyphen    -> "Hyphen"
  | Space     -> "Space"
  | Enter     -> "Enter"
  | Backspace -> "Backspace"
  | Tab       -> "Tab"
  | PageUp    -> "PageUp"
  | PageDown  -> "PageDown"
  | End       -> "End"
  | Home      -> "Home"
  | Insert    -> "Insert"
  | Delete    -> "Delete"
  | Add       -> "Add"
  | Subtract  -> "Subtract"
  | Multiply  -> "Multiply"
  | Divide    -> "Divide"
  | Left      -> "Left"
  | Right     -> "Right"
  | Up        -> "Up"
  | Down      -> "Down"
  | Pause     -> "Pause"
  | Unknown   -> "Unknown"

let keyCode_of_string = function
  | "A"         -> A
  | "B"         -> B
  | "C"         -> C
  | "D"         -> D
  | "E"         -> E
  | "F"         -> F
  | "G"         -> G
  | "H"         -> H
  | "I"         -> I
  | "J"         -> J
  | "K"         -> K
  | "L"         -> L
  | "M"         -> M
  | "N"         -> N
  | "O"         -> O
  | "P"         -> P
  | "Q"         -> Q
  | "R"         -> R
  | "S"         -> S
  | "T"         -> T
  | "U"         -> U
  | "V"         -> V
  | "W"         -> W
  | "X"         -> X
  | "Y"         -> Y
  | "Z"         -> Z
  | "Num0"      -> Num0
  | "Num1"      -> Num1
  | "Num2"      -> Num2
  | "Num3"      -> Num3
  | "Num4"      -> Num4
  | "Num5"      -> Num5
  | "Num6"      -> Num6
  | "Num7"      -> Num7
  | "Num8"      -> Num8
  | "Num9"      -> Num9
  | "F1"        -> F1
  | "F2"        -> F2
  | "F3"        -> F3
  | "F4"        -> F4
  | "F5"        -> F5
  | "F6"        -> F6
  | "F7"        -> F7
  | "F8"        -> F8
  | "F9"        -> F9
  | "F10"       -> F10
  | "F11"       -> F11
  | "F12"       -> F12
  | "F13"       -> F13
  | "F14"       -> F14
  | "F15"       -> F15
  | "Numpad0"   -> Numpad0
  | "Numpad1"   -> Numpad1
  | "Numpad2"   -> Numpad2
  | "Numpad3"   -> Numpad3
  | "Numpad4"   -> Numpad4
  | "Numpad5"   -> Numpad5
  | "Numpad6"   -> Numpad6
  | "Numpad7"   -> Numpad7
  | "Numpad8"   -> Numpad8
  | "Numpad9"   -> Numpad9
  | "Escape"    -> Escape
  | "LControl"  -> LControl
  | "LShift"    -> LShift
  | "LAlt"      -> LAlt
  | "LSystem"   -> LSystem
  | "RControl"  -> RControl
  | "RShift"    -> RShift
  | "RAlt"      -> RAlt
  | "RSystem"   -> RSystem
  | "Menu"      -> Menu
  | "LBracket"  -> LBracket
  | "RBracket"  -> RBracket
  | "Semicolon" -> Semicolon
  | "Comma"     -> Comma
  | "Period"    -> Period
  | "Quote"     -> Quote
  | "Slash"     -> Slash
  | "Backslash" -> Backslash
  | "Tilde"     -> Tilde
  | "Equal"     -> Equal
  | "Hyphen"    -> Hyphen
  | "Space"     -> Space
  | "Enter"     -> Enter
  | "Backspace" -> Backspace
  | "Tab"       -> Tab
  | "PageUp"    -> PageUp
  | "PageDown"  -> PageDown
  | "End"       -> End
  | "Home"      -> Home
  | "Insert"    -> Insert
  | "Delete"    -> Delete
  | "Add"       -> Add
  | "Subtract"  -> Subtract
  | "Multiply"  -> Multiply
  | "Divide"    -> Divide
  | "Left"      -> Left
  | "Right"     -> Right
  | "Up"        -> Up
  | "Down"      -> Down
  | "Pause"     -> Pause
  | "Unknown"   -> Unknown
  | _ -> failwith "keyCode_of_string"
