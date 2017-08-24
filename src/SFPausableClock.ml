type t = {
    clock: SFClock.t;
    mutable time: SFTime.t;
    mutable paused: bool
  }

let create ~paused = {
    clock = SFClock.create ();
    time = SFTime.zero;
    paused
  }

let isPaused clock = clock.paused

let getElapsedTime clock =
  if clock.paused then
    clock.time
  else
    SFTime.add clock.time (SFClock.getElapsedTime clock.clock)

let restart clock ~paused =
  let ret = match clock.paused, paused with
    | true, _ -> clock.time
    | false, false -> SFTime.add clock.time (SFClock.restart clock.clock)
    | false, true -> SFTime.add clock.time (SFClock.getElapsedTime clock.clock)
  in
  clock.time <- SFTime.zero;
  clock.paused <- paused;
  ret

let pause clock =
  if not clock.paused then (
    clock.time <- SFTime.add clock.time (SFClock.getElapsedTime clock.clock);
    clock.paused <- true
  )

let start clock =
  if clock.paused then (
    ignore (SFClock.restart clock.clock);
    clock.paused <- false
  )
