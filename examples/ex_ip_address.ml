let print_id_addr a =
  print_endline (SFIpAddress.toString a)

let () =
  print_id_addr (SFIpAddress.localHost ());
  print_id_addr (SFIpAddress.getLocalAddress ());
  print_id_addr (SFIpAddress.getPublicAddress (SFTime.of_seconds 4.0));
;;
