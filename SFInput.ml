type t

external isKeyDown: input:t -> key:SFKey.t -> bool = "caml_sfInput_IsKeyDown"
external isMouseButtonDown: input:t -> button:SFEvent.mouse_button -> bool = "caml_sfInput_IsMouseButtonDown"
external getMousePos: input:t -> int * int = "caml_sfInput_GetMousePos"
external isJoystickButtonDown: input:t -> joyId:int -> button:int -> bool = "caml_sfInput_IsJoystickButtonDown"
external getJoystickAxis: input:t -> joyId:int -> axis:SFEvent.joy_axis -> float = "caml_sfInput_GetJoystickAxis"
