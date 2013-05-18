let example_1 () =
  let clock = SFClock.create () in
  let t0 = SFClock.getElapsedTime clock in
  let t1 = SFClock.getElapsedTime clock in
  let t2 = SFClock.getElapsedTime clock in
  let t3 = SFClock.getElapsedTime clock in
  let t4 = SFClock.getElapsedTime clock in
  let t5 = SFClock.getElapsedTime clock in
  let t6 = SFClock.getElapsedTime clock in
  let t7 = SFClock.getElapsedTime clock in
  let t8 = SFClock.getElapsedTime clock in
  let t9 = SFClock.getElapsedTime clock in
  List.iter (fun t ->
    Printf.printf "t: %f\n" (SFTime.asSeconds t)
  ) [t0; t1; t2; t3; t4; t5; t6; t7; t8; t9];
;;

let example_2 () =
  let clock = SFClock.create () in
  let t0 = SFClock.getElapsedTime clock in
  let t0s = SFTime.asSeconds (SFClock.getElapsedTime clock) in
  SFTime.sleep (SFTime.of_seconds 0.2);
  let t1 = SFClock.getElapsedTime clock in
  (*
  let t1s = SFTime.asSeconds (SFClock.getElapsedTime clock) in
  *)
  let t1s = SFClock.getElapsedTime_asSeconds clock in
  List.iter (fun (t, ts) ->
    Printf.printf "t: %f\t" ts;
    Printf.printf " %f\t" (SFTime.asSeconds t);
    Printf.printf " %Ld\t" (SFTime.asMicroseconds t);
    Printf.printf " %ld\t" (SFTime.asMilliseconds t);
    print_newline ()
  ) [t0, t0s; t1, t1s];
;;

let () =
  example_1 ();
  example_2 ();
;;
