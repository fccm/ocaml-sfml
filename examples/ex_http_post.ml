
let () =
  let http = SFHttp.create () in
  let request = SFHttp.Request.create () in
  SFHttp.Request.setMethod request SFHttp.Post;
  SFHttp.Request.setUri request "/w/index.php?title=Special:Export&action=submit";
  SFHttp.Request.setBody request "OCaml";
  SFHttp.setHost http ~host:"en.wikipedia.org" ~port:0 ();
  let timeout = SFTime.of_seconds 5.0 in
  let r = SFHttp.sendRequest http ~request ~timeout () in
  print_endline (SFHttp.Response.getBody r)
;;
