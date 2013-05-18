
let () =
  let http = SFHttp.create () in
  let request = SFHttp.Request.create () in
  SFHttp.setHost http ~host:"sfml-dev.org" ();
  let timeout = SFTime.of_seconds 5.0 in
  let r = SFHttp.sendRequest http ~request ~timeout () in
  print_endline (SFHttp.Response.getBody r)
;;
