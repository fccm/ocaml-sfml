let print res should =
  Printf.printf "# res: %.3f (should: %.3f)\n" (SFTime.asSeconds res) should

let test1 () =
  let t1 = SFTime.of_seconds 2.0 in
  let t2 = SFTime.of_milliseconds 400l in
  let res = SFTime.add t1 t2 in
  let should = 2.4 in
  print res should

let test2 () =
  let t = SFTime.of_seconds 2.0 in
  let res = SFTime.mul t 3.0 in
  let should = 6.0 in
  print res should

let () =
  test1 ();
  test2 ();
  Gc.full_major ()
