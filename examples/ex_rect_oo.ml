open Oo_sfml_graphics

let () =
  (* Define a rectangle, located at (0, 0) with a size of 20x5 *)
  let r1 = new int_rect ((0, 0), (20, 5)) in
 
  (* Define another rectangle, located at (4, 2) with a size of 18x10 *)
  let position = (4, 2) in
  let size = (18, 10) in
  let r2 = new int_rect (position, size) in
 
  (* Test intersections with the point (3, 1)  *)
  let b1 = r1#contains (3, 1) in  (* true *)
  let b2 = r2#contains (3, 1) in  (* false *)
  Printf.printf " r1 contains (3,1) %B\n" b1;
  Printf.printf " r2 contains (3,1) %B\n" b2;
 
  (* Test the intersection between r1 and r2 *)
  let result = r1#intersection r2 in  (* true *)
  match result with
  | None -> Printf.printf " no intersection\n"
  | Some r3 ->
      (* result: (4, 2, 16, 3) *)
      Printf.printf " %d %d %d %d\n"
        r3#left
        r3#top
        r3#width
        r3#height
