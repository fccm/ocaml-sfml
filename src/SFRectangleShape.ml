type u

external create: ?size:(float * float) -> unit -> u
  = "caml_sfRectangleShape_create"

external destroy: u -> unit = "caml_sfRectangleShape_destroy"

(* ================ *)

type t = { u:u }

let debug = true

let destroy rectangle =
  if debug
  then Printf.eprintf "# finalising rectangle...\n%!";
  destroy rectangle.u

let create ?size () =
  let u = create ?size () in
  let t = { u=u } in
  Gc.finalise destroy t;
  (t)
