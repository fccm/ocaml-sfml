
(* Play a sound *)
let playSound () =
  (* Load a sound buffer from a wav file *)
  let buffer = SFSoundBuffer.loadFromFile "./data/test.wav" in

  (* Display sound informations *)
  print_endline "test.wav :";
  let s = SFTime.asSeconds in
  Printf.printf " %g sec\n" (s (SFSoundBuffer.getDuration buffer));
  Printf.printf " %d samples / sec\n" (SFSoundBuffer.getSampleRate buffer);
  Printf.printf " %d channels\n" (SFSoundBuffer.getChannelCount buffer);

  (* Create a sound instance and play it *)
  let sound = SFSound.create () in
  SFSound.setBuffer sound buffer;
  SFSound.play sound;

  (* Loop while the sound is playing *)
  while (SFSound.getStatus sound) = SFSound.Playing
  do
    (* Leave some CPU time for other processes *)
    SFTime.sleep (SFTime.of_seconds 0.1);

    (* Display the playing position *)
    Printf.printf "\rPlaying... %8g sec   %!"
      (s (SFSound.getPlayingOffset sound));
  done;
  print_newline ()


(* Play a music *)
let playMusic () =
  (* Load an ogg music file *)
  let music = SFMusic.openFromFile "./data/nice_music.ogg" in

  (* Display music informations *)
  print_endline "nice_music.ogg :";
  let s = SFTime.asSeconds in
  Printf.printf " %g sec\n"        (s (SFMusic.getDuration music));
  Printf.printf " %d samples / sec\n" (SFMusic.getSampleRate music);
  Printf.printf " %d channels\n"      (SFMusic.getChannelCount music);

  (* Play it *)
  SFMusic.play music;

  (* Loop while the music is playing *)
  while (SFMusic.getStatus music) = SFMusic.Playing
  do
    (* Leave some CPU time for other processes *)
    SFTime.sleep (SFTime.of_seconds 0.1);

    (* Display the playing position *)
    Printf.printf "\rPlaying... %8g sec   %!"
      (s (SFMusic.getPlayingOffset music));
  done;
  print_newline ()


(* Entry point of application *)
let () =
  (* Play a sound *)
  (*playSound ();*)

  (* Play a music *)
  playMusic ();
;;

