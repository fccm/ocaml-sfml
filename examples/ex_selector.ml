let () =
  (* Create a socket to listen to new connections *)
  let listener = SFTcpListener.create () in
  SFTcpListener.listen listener 55001;
 
  (* Create a list to store the future clients *)
  let clients = ref [] in
 
  (* Create a selector *)
  let selector = SFSocketSelector.create () in
 
  (* Add the listener to the selector *)
  SFSocketSelector.addTcpListener selector listener;
 
  (* Endless loop that waits for new connections *)
  while true do
    (* Make the selector wait for data on any socket *)
    if SFSocketSelector.wait selector () then
    begin
      (* Test the listener *)
      if SFSocketSelector.isTcpListenerReady selector listener then
      begin
        (* The listener is ready: there is a pending connection *)
        let client = SFTcpListener.accept listener in
          (* Add the new client to the clients list *)
          clients := client :: !clients;
 
          (* Add the new client to the selector so that we will
             be notified when he sends something *)
          SFSocketSelector.addTcpSocket selector client;

      end else begin
        (* The listener socket is not ready, test all other sockets
           (the clients) *)
        List.iter (fun client ->
          if SFSocketSelector.isTcpSocketReady selector client then
          begin
            (* The client has sent some data, we can receive it *)
            let packet = SFPacket.create () in
            SFTcpSocket.receivePacket client packet;
            let data = SFPacket.getData packet in
            Printf.printf "Data: (%S)\n%!" data
          end
        ) !clients;
      end
    end
  done
