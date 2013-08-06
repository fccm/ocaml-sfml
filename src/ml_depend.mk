SFBlendMode.cmo :
SFBlendMode.cmx :
SFCircleShape.cmo : SFColor.cmo SFCircleShape.cmi
SFCircleShape.cmx : SFColor.cmx SFCircleShape.cmi
SFClock.cmo : SFTime.cmi
SFClock.cmx : SFTime.cmx
SFColor.cmo :
SFColor.cmx :
SFConfig.cmo :
SFConfig.cmx :
SFContext.cmo :
SFContext.cmx :
SFEvent.cmo : SFMouse.cmo SFKey.cmo
SFEvent.cmx : SFMouse.cmx SFKey.cmx
SFFont.cmo : SFRect.cmo SFFont.cmi
SFFont.cmx : SFRect.cmx SFFont.cmi
SFFtp.cmo : SFTime.cmi SFIpAddress.cmo SFFtp.cmi
SFFtp.cmx : SFTime.cmx SFIpAddress.cmx SFFtp.cmi
SFHttp.cmo : SFTime.cmi
SFHttp.cmx : SFTime.cmx
SFImage.cmo : SFColor.cmo SFImage.cmi
SFImage.cmx : SFColor.cmx SFImage.cmi
SFIpAddress.cmo : SFTime.cmi
SFIpAddress.cmx : SFTime.cmx
SFJoystick.cmo :
SFJoystick.cmx :
SFKeyboard.cmo : SFKey.cmo
SFKeyboard.cmx : SFKey.cmx
SFKey.cmo :
SFKey.cmx :
SFListener.cmo :
SFListener.cmx :
SFMouse.cmo :
SFMouse.cmx :
SFMusic.cmo : SFTime.cmi
SFMusic.cmx : SFTime.cmx
SFPacket.cmo : SFPacket.cmi
SFPacket.cmx : SFPacket.cmi
SFPausableClock.cmo : SFTime.cmi
SFPausableClock.cmx : SFTime.cmx
SFRectangleShape.cmo : SFRectangleShape.cmi
SFRectangleShape.cmx : SFRectangleShape.cmi
SFRect.cmo :
SFRect.cmx :
SFRenderStates.cmo : SFTransform.cmo SFTexture.cmo SFShader.cmo \
    SFBlendMode.cmo SFRenderStates.cmi
SFRenderStates.cmx : SFTransform.cmx SFTexture.cmx SFShader.cmx \
    SFBlendMode.cmx SFRenderStates.cmi
SFRenderWindow.cmo : SFView.cmo SFText.cmi SFSprite.cmi SFShape.cmi \
    SFRenderStates.cmi SFImage.cmi SFEvent.cmo SFColor.cmo SFCircleShape.cmi
SFRenderWindow.cmx : SFView.cmx SFText.cmx SFSprite.cmx SFShape.cmx \
    SFRenderStates.cmx SFImage.cmx SFEvent.cmx SFColor.cmx SFCircleShape.cmx
SFRoundedRectangleShape.cmo :
SFRoundedRectangleShape.cmx :
SFShader.cmo :
SFShader.cmx :
SFShape.cmo : SFRectangleShape.cmi SFColor.cmo SFCircleShape.cmi SFShape.cmi
SFShape.cmx : SFRectangleShape.cmx SFColor.cmx SFCircleShape.cmx SFShape.cmi
SFSocketSelector.cmo : SFUdpSocket.cmo SFTime.cmi SFTcpSocket.cmo \
    SFTcpListener.cmo
SFSocketSelector.cmx : SFUdpSocket.cmx SFTime.cmx SFTcpSocket.cmx \
    SFTcpListener.cmx
SFSoundBuffer.cmo : SFTime.cmi SFSoundBuffer.cmi
SFSoundBuffer.cmx : SFTime.cmx SFSoundBuffer.cmi
SFSoundBufferRecorder.cmo : SFSoundBufferRecorder.cmi
SFSoundBufferRecorder.cmx : SFSoundBufferRecorder.cmi
SFSound.cmo : SFTime.cmi SFSoundBuffer.cmi SFSound.cmi
SFSound.cmx : SFTime.cmx SFSoundBuffer.cmx SFSound.cmi
SFSoundRecorder.cmo :
SFSoundRecorder.cmx :
SFSprite.cmo : SFTexture.cmo SFColor.cmo SFSprite.cmi
SFSprite.cmx : SFTexture.cmx SFColor.cmx SFSprite.cmi
SFTcpListener.cmo : SFTcpSocket.cmo
SFTcpListener.cmx : SFTcpSocket.cmx
SFTcpSocket.cmo : SFTime.cmi SFPacket.cmi SFIpAddress.cmo
SFTcpSocket.cmx : SFTime.cmx SFPacket.cmx SFIpAddress.cmx
SFText.cmo : SFRect.cmo SFFont.cmi SFColor.cmo SFText.cmi
SFText.cmx : SFRect.cmx SFFont.cmx SFColor.cmx SFText.cmi
SFTexture.cmo : SFRect.cmo SFImage.cmi
SFTexture.cmx : SFRect.cmx SFImage.cmx
SFTime.cmo : SFTime.cmi
SFTime.cmx : SFTime.cmi
SFTransform.cmo :
SFTransform.cmx :
SFUdpSocket.cmo : SFPacket.cmi SFIpAddress.cmo
SFUdpSocket.cmx : SFPacket.cmx SFIpAddress.cmx
SFVideoMode.cmo : SFVideoMode.cmi
SFVideoMode.cmx : SFVideoMode.cmi
SFView.cmo : SFRect.cmo
SFView.cmx : SFRect.cmx
SFWindow.cmo : SFEvent.cmo
SFWindow.cmx : SFEvent.cmx
SFCircleShape.cmi : SFColor.cmo
SFFont.cmi : SFRect.cmo
SFFtp.cmi : SFTime.cmi SFIpAddress.cmo
SFImage.cmi : SFColor.cmo
SFPacket.cmi :
SFRectangleShape.cmi :
SFRenderStates.cmi : SFTransform.cmo SFTexture.cmo SFShader.cmo \
    SFBlendMode.cmo
SFShape.cmi : SFRectangleShape.cmi SFColor.cmo SFCircleShape.cmi
SFSoundBuffer.cmi : SFTime.cmi
SFSoundBufferRecorder.cmi :
SFSound.cmi : SFTime.cmi SFSoundBuffer.cmi
SFSprite.cmi : SFTexture.cmo SFColor.cmo
SFText.cmi : SFRect.cmo SFFont.cmi SFColor.cmo
SFTime.cmi :
SFVideoMode.cmi :
oo_sfml_audio.cmo : SFSoundBuffer.cmi SFSound.cmi SFMusic.cmo SFListener.cmo \
    oo_sfml_audio.cmi
oo_sfml_audio.cmx : SFSoundBuffer.cmx SFSound.cmx SFMusic.cmx SFListener.cmx \
    oo_sfml_audio.cmi
oo_sfml_graphics.cmo : SFView.cmo SFTexture.cmo SFText.cmi SFSprite.cmi \
    SFShape.cmi SFRenderWindow.cmo SFRenderStates.cmi SFRect.cmo SFImage.cmi \
    SFFont.cmi SFColor.cmo SFCircleShape.cmi oo_sfml_graphics.cmi
oo_sfml_graphics.cmx : SFView.cmx SFTexture.cmx SFText.cmx SFSprite.cmx \
    SFShape.cmx SFRenderWindow.cmx SFRenderStates.cmx SFRect.cmx SFImage.cmx \
    SFFont.cmx SFColor.cmx SFCircleShape.cmx oo_sfml_graphics.cmi
oo_sfml_network.cmo : SFUdpSocket.cmo SFTcpSocket.cmo SFPacket.cmi \
    SFIpAddress.cmo SFHttp.cmo SFFtp.cmi oo_sfml_system.cmi \
    oo_sfml_network.cmi
oo_sfml_network.cmx : SFUdpSocket.cmx SFTcpSocket.cmx SFPacket.cmx \
    SFIpAddress.cmx SFHttp.cmx SFFtp.cmx oo_sfml_system.cmx \
    oo_sfml_network.cmi
oo_sfml_system.cmo : SFTime.cmi SFPausableClock.cmo SFConfig.cmo SFClock.cmo \
    oo_sfml_system.cmi
oo_sfml_system.cmx : SFTime.cmx SFPausableClock.cmx SFConfig.cmx SFClock.cmx \
    oo_sfml_system.cmi
oo_sfml_window.cmo : SFWindow.cmo oo_sfml_window.cmi
oo_sfml_window.cmx : SFWindow.cmx oo_sfml_window.cmi
oo_sfml_audio.cmi : SFTime.cmi SFSoundBuffer.cmi SFSound.cmi SFMusic.cmo
oo_sfml_graphics.cmi : SFView.cmo SFTransform.cmo SFTexture.cmo SFText.cmi \
    SFSprite.cmi SFShape.cmi SFShader.cmo SFRenderWindow.cmo \
    SFRenderStates.cmi SFRect.cmo SFImage.cmi SFFont.cmi SFEvent.cmo \
    SFColor.cmo SFCircleShape.cmi SFBlendMode.cmo
oo_sfml_network.cmi : SFUdpSocket.cmo SFTime.cmi SFTcpSocket.cmo \
    SFPacket.cmi SFIpAddress.cmo SFHttp.cmo SFFtp.cmi oo_sfml_system.cmi
oo_sfml_system.cmi : SFTime.cmi SFPausableClock.cmo SFClock.cmo
oo_sfml_window.cmi : SFWindow.cmo SFEvent.cmo
