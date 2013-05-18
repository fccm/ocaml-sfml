
let () =
  let p = SFPacket.create () in

  let s1 = "Hello" in
  let s2 = "World" in
  (*
  let s3 = "Hello\000 This will be ignored!" in
  *)
  let s3 = "Hello, this one is not weird" in

  SFPacket.writeString p s1;
  SFPacket.writeString p s2;
  SFPacket.writeString p s3;

  let eop p =
    Printf.printf "EOP: %B\n%!" (SFPacket.endOfPacket p)
  in
  let test p orig_s =
    eop p;
    let r = SFPacket.readString p in
    Printf.printf " got-str(%S) got-len(%d) :: orig-str(%S) orig-len(%d)\n%!"
      r (String.length r)
      orig_s (String.length orig_s)
  in

  test p s1;
  test p s2;
  test p s3;

  eop p;
;;
