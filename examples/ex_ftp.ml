let ftp_server = "ftp://ftp.myserver.com"
let temp_dir = "temp_dir"
let local_file = "./local_path/file.txt"
let login = "laurent"
let password = "dF6Zm89D"

let () =
  (* Create a new FTP client *)
  let ftp = SFFtp.create () in
 
  (* Connect to the server *)
  let timeout = SFTime.of_seconds 1.0 in
  let server = SFIpAddress.fromString ftp_server in
  let response = SFFtp.connect ftp ~server ~port:21 ~timeout () in

  if SFFtp.Response.isOk response then
    print_endline "Connected";
 
  (* Log in *)
  let response = SFFtp.login ftp login password in
  if SFFtp.Response.isOk response then
    print_endline "Logged in";
 
  (* Print the working directory *)
  let directory = SFFtp.getWorkingDirectory ftp in
  if SFFtp.DirectoryResponse.isOk directory then
    Printf.eprintf "Working directory: %s\n%!"
      (SFFtp.DirectoryResponse.getDirectory directory);
 
  (* Create a new directory *)
  let response = SFFtp.createDirectory ftp temp_dir in
  if SFFtp.Response.isOk response then
    print_endline "Created new directory";
 
  (* Upload a file to this new directory *)
  let response = SFFtp.upload ftp local_file temp_dir SFFtp.Ascii in
  if SFFtp.Response.isOk response then
    print_endline "File uploaded";
 
  (* Disconnect from the server (optional) *)
  let response = SFFtp.disconnect ftp in
  if SFFtp.Response.isOk response then
    print_endline "Disconnected";
;;
