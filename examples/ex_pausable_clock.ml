let print_is_paused pc =
  Printf.printf "# is paused: %B\n%!"
    (SFPausableClock.isPaused pc)

let print_elapsed_time pc =
  Printf.printf "# elapsed time: %f\n%!"
    (SFTime.asSeconds (SFPausableClock.getElapsedTime pc))

let main () =
  let pc = SFPausableClock.create ~paused:false in
  print_elapsed_time pc;
  print_is_paused pc;
  SFTime.sleep (SFTime.of_seconds 0.2);
  print_elapsed_time pc;
  let _ = SFPausableClock.restart pc ~paused:false in
  SFTime.sleep (SFTime.of_seconds 0.2);
  SFPausableClock.pause pc;
  SFTime.sleep (SFTime.of_seconds 0.8);
  SFPausableClock.start pc;
  SFTime.sleep (SFTime.of_seconds 0.4);
  print_elapsed_time pc;
;;

let () =
  main ();
  Gc.full_major ();
;;
