type u

external create: ?size:(float * float) -> unit -> u
  = "caml_sfRectangleShape_create"

external destroy: u -> unit = "caml_sfRectangleShape_destroy"

(* ================ *)

type t = { u:u; s:string }

let destroy rectangle =
  Printf.printf "# destroying rectangle (%s)...\n%!" rectangle.s;
  destroy rectangle.u

let create ?size () =
  let u = create ?size () in
  let t = {u=u; s=" "} in
  Gc.finalise destroy t;
  (t)
