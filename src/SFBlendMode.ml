type factor =
  | Zero
  | One
  | SrcColor
  | OneMinusSrcColor
  | DstColor
  | OneMinusDstColor
  | SrcAlpha
  | OneMinusSrcAlpha
  | DstAlpha
  | OneMinusDstAlpha

type equation =
  | Add
  | Subtract
  | ReverseSubtract

type t = {
  color_src_factor : factor;
  color_dst_factor : factor;
  color_equation : equation;
  alpha_src_factor : factor;
  alpha_dst_factor : factor;
  alpha_equation : equation;
}

let make ?(equation = Add) src_factor dst_factor = {
    color_src_factor = src_factor;
    color_dst_factor = dst_factor;
    color_equation = equation;
    alpha_src_factor = src_factor;
    alpha_dst_factor = dst_factor;
    alpha_equation = equation
  }

let alpha = { (make One OneMinusSrcAlpha) with color_src_factor = SrcAlpha }
let add = { (make One One) with color_src_factor = SrcAlpha }
let multiply = make DstColor Zero
let none = make One Zero
