type rgb = int * int * int
type rgba = int * int * int * int
type t = RGB of rgb | RGBA of rgba

let black = RGB(0, 0, 0)
let white = RGB(255, 255, 255)
let red = RGB(255, 0, 0)
let green = RGB(0, 255, 0)
let blue = RGB(0, 0, 255)
let yellow = RGB(255, 255, 0)
let magenta = RGB(255, 0, 255)
let cyan = RGB(0, 255, 255)
let transparent = RGBA(0, 0, 0, 0)
