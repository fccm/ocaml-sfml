type 'a t = {
  left   : 'a;
  top    : 'a;
  width  : 'a;
  height : 'a;
}

external contains_f: rect:float t -> x:float -> y:float -> bool
  = "caml_sfFloatRect_contains"

external contains_i: rect:int t -> x:int -> y:int -> bool
  = "caml_sfIntRect_contains"

external intersects_i: rect1:int t -> rect2:int t -> bool
  = "caml_sfFloatRect_intersects"

external intersection_i: rect1:int t -> rect2:int t -> int t option
  = "caml_sfFloatRect_intersection"

external intersects_f: rect1:float t -> rect2:float t -> bool
  = "caml_sfIntRect_intersects"

external intersection_f: rect1:float t -> rect2:float t -> float t option
  = "caml_sfIntRect_intersection"
