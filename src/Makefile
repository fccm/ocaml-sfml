# Makefile for ocaml-sfml
# Copyright (C) 2012 Florent Monnier (monnier dot florent on gmail)
# Code provided under MIT license:
# See the file COPYING.txt or this URL:
# https://secure.wikimedia.org/wikipedia/en/wiki/MIT_License
# This software is provided "AS IS", without warranty of any kind.

OCAML := ocaml
OCAMLC := ocamlc -g
CC_PARAMS := -Wall -Werror -Wno-deprecated-declarations
OCAMLOPT_PARAMS := -g -w A -warn-error A -ccopt "$(CC_PARAMS)"
OCAMLOPT := ocamlopt $(OCAMLOPT_PARAMS)
OCAMLDOC := ocamldoc
OCAMLMKLIB := ocamlmklib
OCAMLDEP := ocamldep
OCAMLFIND := ocamlfind
OCAML_DIR := $(shell ocamlc -where)
CXX := g++ -g $(CC_PARAMS) -fPIC
BINDING_DIR := sfml
PREFIX := $(OCAML_DIR)/$(BINDING_DIR)
#DLL_PREFIX := $(OCAML_DIR)/stublibs
DLL_PREFIX := $(PREFIX)
DOC_DIR := doc

VERSION := $(shell date --iso)

LIB_SFML_BASEDIR := /usr
LIB_CSFML_BASEDIR := /usr

CXX_INC_DIR := $(LIB_SFML_BASEDIR)/include/
C_INC_DIR := $(LIB_CSFML_BASEDIR)/include/

CXX_INC_PATH := -I$(CXX_INC_DIR)
C_INC_PATH := -I$(C_INC_DIR)

LIBDIRSUFFIX :=
#LIBDIRSUFFIX := 64
LIBDIR := lib$(LIBDIRSUFFIX)

CXX_LD_DIR := $(LIB_SFML_BASEDIR)/$(LIBDIR)/
C_LD_DIR := $(LIB_CSFML_BASEDIR)/$(LIBDIR)/

CXX_LD_PATH := -L$(CXX_LD_DIR)
C_LD_PATH := -L$(C_LD_DIR)
LD_PATH := $(CXX_LD_PATH) $(C_LD_PATH)


CXX_LIB_SYSTEM   := -lsfml-system
CXX_LIB_WINDOW   := -lsfml-window
CXX_LIB_GRAPHICS := -lsfml-graphics
CXX_LIB_AUDIO    := -lsfml-audio
CXX_LIB_NETWORK  := -lsfml-network

C_LIB_SYSTEM   := -lcsfml-system
C_LIB_WINDOW   := -lcsfml-window
C_LIB_GRAPHICS := -lcsfml-graphics
C_LIB_AUDIO    := -lcsfml-audio
C_LIB_NETWORK  := -lcsfml-network

LIBS_SYSTEM   := $(CXX_LIB_SYSTEM)   $(C_LIB_SYSTEM)
LIBS_WINDOW   := $(CXX_LIB_WINDOW)   $(C_LIB_WINDOW)
LIBS_GRAPHICS := $(CXX_LIB_GRAPHICS) $(C_LIB_GRAPHICS)
LIBS_AUDIO    := $(CXX_LIB_AUDIO)    $(C_LIB_AUDIO)
LIBS_NETWORK  := $(CXX_LIB_NETWORK)  $(C_LIB_NETWORK)

CXX_LIBS := $(CXX_LIB_SYSTEM) $(CXX_LIB_WINDOW) $(CXX_LIB_GRAPHICS) $(CXX_LIB_AUDIO) $(CXX_LIB_NETWORK)
C_LIBS   := $(C_LIB_SYSTEM)   $(C_LIB_WINDOW)   $(C_LIB_GRAPHICS)   $(C_LIB_AUDIO)   $(C_LIB_NETWORK)
LIBS := $(CXX_LIBS) $(C_LIBS)


vpath %.c ./c_stubs/
vpath %.h ./c_stubs/

vpath %.cpp ./cxx_stubs/
vpath %.hpp ./cxx_stubs/


# Bindings to the C++ API:
cxx: cxx_byte cxx_opt
cxx_all: cxx_byte cxx_opt cxx_cmxs cxx_oo_byte cxx_oo_opt cxx_oo_cmxs
cxx_byte: \
  sfml_system.cma \
  sfml_window.cma \
  sfml_graphics.cma \
  sfml_audio.cma \
  sfml_network.cma
cxx_opt: \
  sfml_system.cmxa \
  sfml_window.cmxa \
  sfml_graphics.cmxa \
  sfml_audio.cmxa \
  sfml_network.cmxa
cxx_cmxs: \
  sfml_system.cmxs \
  sfml_window.cmxs \
  sfml_graphics.cmxs \
  sfml_audio.cmxs \
  sfml_network.cmxs
cxx_oo_byte: \
  sfml_system_oo.cma \
  sfml_window_oo.cma \
  sfml_graphics_oo.cma \
  sfml_audio_oo.cma \
  sfml_network_oo.cma
cxx_oo_opt: \
  sfml_system_oo.cmxa \
  sfml_window_oo.cmxa \
  sfml_graphics_oo.cmxa \
  sfml_audio_oo.cmxa \
  sfml_network_oo.cmxa
cxx_oo_cmxs: \
  sfml_system_oo.cmxs \
  sfml_window_oo.cmxs \
  sfml_graphics_oo.cmxs \
  sfml_audio_oo.cmxs \
  sfml_network_oo.cmxs
.PHONY: cxx cxx_all cxx_byte cxx_opt cxx_cmxs cxx_oo_byte cxx_oo_opt cxx_oo_cmxs



# Bindings to the C API:
c: c_byte c_opt
c_all: c_byte c_opt c_cmxs c_oo_byte c_oo_opt c_oo_cmxs
c_byte: \
  csfml_system.cma \
  csfml_window.cma \
  csfml_graphics.cma \
  csfml_audio.cma \
  csfml_network.cma
c_opt: \
  csfml_system.cmxa \
  csfml_window.cmxa \
  csfml_graphics.cmxa \
  csfml_audio.cmxa \
  csfml_network.cmxa
c_cmxs: \
  csfml_system.cmxs \
  csfml_window.cmxs \
  csfml_graphics.cmxs \
  csfml_audio.cmxs \
  csfml_network.cmxs
c_oo_byte: \
  csfml_system_oo.cma \
  csfml_window_oo.cma \
  csfml_graphics_oo.cma \
  csfml_audio_oo.cma \
  csfml_network_oo.cma
c_oo_opt: \
  csfml_system_oo.cmxa \
  csfml_window_oo.cmxa \
  csfml_graphics_oo.cmxa \
  csfml_audio_oo.cmxa \
  csfml_network_oo.cmxa
c_oo_cmxs: \
  csfml_system_oo.cmxs \
  csfml_window_oo.cmxs \
  csfml_graphics_oo.cmxs \
  csfml_audio_oo.cmxs \
  csfml_network_oo.cmxs
.PHONY: c c_all c_byte c_opt c_cmxs c_oo_byte c_oo_opt c_oo_cmxs



%.mli: %.ml
	$(OCAML) doc_link.ml $< > $@
	$(OCAMLC) -i $< >> $@
%.cmi: %.mli
	$(OCAMLC) -c -o $@ $<
%.cmo: %.ml %.cmi
	$(OCAMLC) -c -o $@ $<
%.cmx: %.ml %.cmi
	$(OCAMLOPT) -c -o $@ $<

%.cmxs: %.cmxa
	$(OCAMLOPT) -shared -linkall -o $@ -ccopt -L. $<


%.o: %.c sf_caml_incs_c.h
	$(OCAMLOPT) -c -ccopt "$(C_INC_PATH)" $<

%.o: %.cpp sf_caml_incs.hpp
	$(CXX) -c -I$(OCAML_DIR) $(CXX_INC_PATH) $<



# non-generated .mli files:

SFTime.mli:
	:
SFPausableClock.mli:
	:
SFBlendMode.mli:
	:
SFText.mli:
	:
SFFont.mli:
	:
SFSprite.mli:
	:
SFShape.mli:
	:
SFCircleShape.mli:
	:
SFRectangleShape.mli:
	:
SFImage.mli:
	:
SFSound.mli:
	:
SFSoundBuffer.mli:
	:
SFPacket.mli:
	:
SFRenderStates.mli:
	:
SFEvent.mli:
	:
SFSensor.mli:
	:


# clean generated .mli files:
GENERATED_MLI := \
      SFConfig.mli \
      SFClock.mli SFClipboard.mli SFCursor.mli \
      SFRect.mli SFColor.mli \
      SFMusic.mli SFListener.mli SFSoundRecorder.mli \
      SFKey.mli SFMouse.mli SFKeyboard.mli SFJoystick.mli \
      SFView.mli SFWindow.mli SFVideoMode.mli SFStyle.mli \
      SFTexture.mli SFShader.mli SFTransform.mli \
      SFRenderWindow.mli SFContext.mli SFContextSettings.mli \
      SFIpAddress.mli \
      SFTcpSocket.mli SFUdpSocket.mli \
      SFTcpListener.mli \
      SFSocketSelector.mli \
      SFHttp.mli \
      SFFtp.mli

.PHONY: clean_mli
clean_mli:
	$(RM) $(GENERATED_MLI)


# Modules dependencies:

SFClock.mli: SFClock.ml SFTime.cmi
SFMusic.mli: SFMusic.ml SFTime.cmi
SFImage.cmi: SFColor.cmi
#SFTexture.cmi: SFImage.cmi SFRect.cmi
SFTexture.mli: SFImage.cmi SFRect.cmi
SFPausableClock.mli: SFPausableClock.ml SFTime.cmi
SFKeyboard.mli: SFKeyboard.ml SFKey.cmi
SFShape.mli: SFShape.ml SFColor.cmi SFBlendMode.cmi SFCircleShape.cmi SFRectangleShape.cmi
SFView.mli: SFView.ml SFRect.cmi
SFSound.cmi: SFSoundBuffer.cmi SFTime.cmi
SFSoundBuffer.cmi: SFTime.cmi
SFSprite.cmi: SFTexture.cmi SFColor.cmi SFRect.cmi
SFText.cmi: SFFont.cmi SFColor.cmi SFRect.cmi
SFFont.cmi: SFRect.cmi
SFWindow.mli: SFWindow.ml \
  SFView.cmi SFKey.cmi SFEvent.cmi SFColor.cmi SFStyle.cmi SFContextSettings.cmi
SFRenderStates.cmi: SFRenderStates.mli \
  SFBlendMode.cmi SFTransform.cmi SFTexture.cmi SFShader.cmi
SFRenderWindow.mli: SFRenderWindow.ml \
  SFView.cmi SFKey.cmi SFEvent.cmi SFColor.cmi SFStyle.cmi \
  SFShape.cmi SFSprite.cmi SFText.cmi SFContextSettings.cmi \
  SFRenderStates.cmi

SFIpAddress.mli: SFIpAddress.ml SFTime.cmi
SFTcpSocket.mli: SFIpAddress.cmi SFPacket.cmi SFTime.cmi
SFUdpSocket.mli: SFIpAddress.cmi SFPacket.cmi
SFTcpListener.mli: SFTcpSocket.cmi
SFSocketSelector.mli: SFTcpSocket.cmi SFUdpSocket.cmi SFTcpListener.cmi SFTime.cmi
SFHttp.mli: SFTime.cmi
SFFtp.mli: SFIpAddress.cmi SFTime.cmi
SFEvent.mli: SFMouse.cmi SFJoystick.cmi SFSensor.cmi


# files generated by 'make' in each directory
-include c_stubs/c_depend.mk
-include cxx_stubs/cxx_depend.mk

# generated with 'make ml_depend.mk'
-include ml_depend.mk


# ==== C API ==== #

CSTUBS_FILES_SYSTEM := \
  sf_caml_conv_c.c \
  sf_conv_vectors_c.c \
  SFConfig_cstub.c \
  SFTime_cstub.c \
  SFClock_cstub.c \
  SFPausableClock_cstub.c \
  #END
CSTUBS_FILES_WINDOW := \
  sf_context_settings_c.c \
  SFKey_cstub.c \
  SFMouse_cstub.c \
  SFKeyboard_cstub.c \
  SFJoystick_cstub.c \
  SFEvent_cstub.c \
  SFWindow_cstub.c \
  SFContext_cstub.c \
  SFVideoMode_cstub.c \
  #END
CSTUBS_FILES_GRAPHICS := \
  SFColor_cstub.c \
  SFRect_cstub.c \
  SFBlendMode_cstub.c \
  SFImage_cstub.c \
  SFTexture_cstub.c \
  SFTransform_cstub.c \
  SFRenderStates_cstub.c \
  SFFont_cstub.c \
  SFText_cstub.c \
  SFShape_cstub.c \
  SFRectangleShape_cstub.c \
  SFCircleShape_cstub.c \
  SFSprite_cstub.c \
  SFShader_cstub.c \
  SFView_cstub.c \
  #END
CSTUBS_FILES_AUDIO := \
  sf_sound_status.c \
  SFMusic_cstub.c \
  SFSoundBuffer_cstub.c \
  SFSound_cstub.c \
  SFListener_cstub.c \
  SFSoundBufferRecorder_cstub.c \
  SFSoundRecorder_cstub.c \
  #END
CSTUBS_FILES_NETWORK := \
  SFHttp_cstub.c \
  SFFtp_cstub.c \
  SFIpAddress_cstub.c \
  SFPacket_cstub.c \
  SFUdpSocket_cstub.c \
  SFTcpSocket_cstub.c \
  SFTcpListener_cstub.c \
  SFSocketSelector_cstub.c \
  #END

CSTUBS_OBJS_SYSTEM   := $(patsubst %.c, %.o, $(CSTUBS_FILES_SYSTEM))
CSTUBS_OBJS_WINDOW   := $(patsubst %.c, %.o, $(CSTUBS_FILES_WINDOW))
CSTUBS_OBJS_GRAPHICS := $(patsubst %.c, %.o, $(CSTUBS_FILES_GRAPHICS))
CSTUBS_OBJS_AUDIO    := $(patsubst %.c, %.o, $(CSTUBS_FILES_AUDIO))
CSTUBS_OBJS_NETWORK  := $(patsubst %.c, %.o, $(CSTUBS_FILES_NETWORK))


# ==== C++ API ==== #

STUBS_FILES_SYSTEM := \
  sf_caml_conv.cpp \
  sf_conv_vectors.cpp \
  SFConfig_stub.cpp \
  SFTime_stub.cpp \
  SFClock_stub.cpp \
  #END
STUBS_FILES_WINDOW := \
  sf_context_settings.cpp \
  sf_conv_style.cpp \
  SFClipboard_stub.cpp \
  SFCursor_stub.cpp \
  SFKey_stub.cpp \
  SFMouse_stub.cpp \
  SFKeyboard_stub.cpp \
  SFJoystick_stub.cpp \
  SFEvent_stub.cpp \
  SFWindow_stub.cpp \
  SFContext_stub.cpp \
  SFVideoMode_stub.cpp \
  #END
STUBS_FILES_GRAPHICS := \
  SFColor_stub.cpp \
  SFRect_stub.cpp \
  SFBlendMode_stub.cpp \
  SFImage_stub.cpp \
  SFTexture_stub.cpp \
  SFFont_stub.cpp \
  SFText_stub.cpp \
  SFShape_stub.cpp \
  SFCircleShape_stub.cpp \
  SFRectangleShape_stub.cpp \
  SFSprite_stub.cpp \
  SFShader_stub.cpp \
  SFTransform_stub.cpp \
  SFView_stub.cpp \
  SFRenderStates_stub.cpp \
  SFRenderWindow_stub.cpp \
  #END
STUBS_FILES_AUDIO := \
  SFMusic_stub.cpp \
  SFSoundBuffer_stub.cpp \
  SFSound_stub.cpp \
  SFListener_stub.cpp \
  SFSoundBufferRecorder_stub.cpp \
  SFSoundRecorder_stub.cpp \
  #END
STUBS_FILES_NETWORK := \
  SFHttp_stub.cpp \
  SFFtp_stub.cpp \
  SFIpAddress_stub.cpp \
  SFPacket_stub.cpp \
  SFUdpSocket_stub.cpp \
  SFTcpSocket_stub.cpp \
  SFTcpListener_stub.cpp \
  SFSocketSelector_stub.cpp \
  #END

STUBS_OBJS_SYSTEM   := $(patsubst %.cpp, %.o, $(STUBS_FILES_SYSTEM))
STUBS_OBJS_WINDOW   := $(patsubst %.cpp, %.o, $(STUBS_FILES_WINDOW))
STUBS_OBJS_GRAPHICS := $(patsubst %.cpp, %.o, $(STUBS_FILES_GRAPHICS))
STUBS_OBJS_AUDIO    := $(patsubst %.cpp, %.o, $(STUBS_FILES_AUDIO))
STUBS_OBJS_NETWORK  := $(patsubst %.cpp, %.o, $(STUBS_FILES_NETWORK))


SYSTEM_MODULES := \
  SFConfig.ml \
  SFTime.ml \
  SFClock.ml \
  SFPausableClock.ml \
  #END
WINDOW_MODULES := \
  SFClipboard.ml \
  SFCursor.ml \
  SFKey.ml \
  SFMouse.ml \
  SFKeyboard.ml \
  SFJoystick.ml \
  SFEvent.ml \
  SFVideoMode.ml \
  SFStyle.ml \
  SFContextSettings.ml \
  SFWindow.ml \
  SFContext.ml \
  #END
GRAPHICS_MODULES := \
  SFColor.ml \
  SFRect.ml \
  SFBlendMode.ml \
  SFImage.ml \
  SFTexture.ml \
  SFFont.ml \
  SFText.ml \
  SFShape.ml \
  SFCircleShape.ml \
  SFRectangleShape.ml \
  SFSprite.ml \
  SFShader.ml \
  SFTransform.ml \
  SFView.ml \
  SFRenderStates.ml \
  SFRenderWindow.ml \
  #END
AUDIO_MODULES := \
  SFMusic.ml \
  SFSoundBuffer.ml \
  SFSound.ml \
  SFListener.ml \
  SFSoundBufferRecorder.ml \
  SFSoundRecorder.ml \
  #END
NETWORK_MODULES := \
  SFHttp.ml \
  SFFtp.ml \
  SFIpAddress.ml \
  SFPacket.ml \
  SFUdpSocket.ml \
  SFTcpSocket.ml \
  SFTcpListener.ml \
  SFSocketSelector.ml \
  #END


################

SRC_FILES := \
  $(SYSTEM_MODULES) \
  $(WINDOW_MODULES) \
  $(GRAPHICS_MODULES) \
  $(AUDIO_MODULES) \
  $(NETWORK_MODULES) \
  #End

MLI_FILES := $(patsubst %.ml, %.mli, $(SRC_FILES))
CMI_INTRF := $(patsubst %.ml, %.cmi, $(SRC_FILES))

ml_depend.mk: $(SRC_FILES)
	$(OCAMLDEP) SF*.ml SF*.mli oo_*.ml oo_*.mli > $@


################

SYSTEM_MOD_CMO := $(patsubst %.ml, %.cmo, $(SYSTEM_MODULES))
SYSTEM_MOD_CMX := $(patsubst %.ml, %.cmx, $(SYSTEM_MODULES))
SYSTEM_MOD_CMI := $(patsubst %.ml, %.cmi, $(SYSTEM_MODULES))

WINDOW_MOD_CMO := $(patsubst %.ml, %.cmo, $(WINDOW_MODULES))
WINDOW_MOD_CMX := $(patsubst %.ml, %.cmx, $(WINDOW_MODULES))
WINDOW_MOD_CMI := $(patsubst %.ml, %.cmi, $(WINDOW_MODULES))

GRAPHICS_MOD_CMO := $(patsubst %.ml, %.cmo, $(GRAPHICS_MODULES))
GRAPHICS_MOD_CMX := $(patsubst %.ml, %.cmx, $(GRAPHICS_MODULES))
GRAPHICS_MOD_CMI := $(patsubst %.ml, %.cmi, $(GRAPHICS_MODULES))

AUDIO_MOD_CMO := $(patsubst %.ml, %.cmo, $(AUDIO_MODULES))
AUDIO_MOD_CMX := $(patsubst %.ml, %.cmx, $(AUDIO_MODULES))
AUDIO_MOD_CMI := $(patsubst %.ml, %.cmi, $(AUDIO_MODULES))

NETWORK_MOD_CMO := $(patsubst %.ml, %.cmo, $(NETWORK_MODULES))
NETWORK_MOD_CMX := $(patsubst %.ml, %.cmx, $(NETWORK_MODULES))
NETWORK_MOD_CMI := $(patsubst %.ml, %.cmi, $(NETWORK_MODULES))

################

SFML_LIBS := system window graphics audio network

SFML_STUBS := $(patsubst %, dllsfml_%_stubs.so, $(SFML_LIBS))
CSFML_STUBS := $(patsubst %, dllcsfml_%_stubs.so, $(SFML_LIBS))


dllsfml_system_stubs.so: $(STUBS_OBJS_SYSTEM)
	$(OCAMLMKLIB) -oc sfml_system_stubs \
	  $(STUBS_OBJS_SYSTEM) \
	  $(CXX_LD_PATH) \
	  $(CXX_LIB_SYSTEM)

dllsfml_window_stubs.so: $(STUBS_OBJS_WINDOW)
	$(OCAMLMKLIB) -oc sfml_window_stubs \
	  $(STUBS_OBJS_WINDOW) \
	  $(CXX_LD_PATH) \
	  $(CXX_LIB_WINDOW)

dllsfml_graphics_stubs.so: $(STUBS_OBJS_GRAPHICS)
	$(OCAMLMKLIB) -oc sfml_graphics_stubs \
	  $(STUBS_OBJS_GRAPHICS) \
	  $(CXX_LD_PATH) \
	  $(CXX_LIB_GRAPHICS)

dllsfml_audio_stubs.so: $(STUBS_OBJS_AUDIO)
	$(OCAMLMKLIB) -oc sfml_audio_stubs \
	  $(STUBS_OBJS_AUDIO) \
	  $(CXX_LD_PATH) \
	  $(CXX_LIB_AUDIO)

dllsfml_network_stubs.so: $(STUBS_OBJS_NETWORK)
	$(OCAMLMKLIB) -oc sfml_network_stubs \
	  $(STUBS_OBJS_NETWORK) \
	  $(CXX_LD_PATH) \
	  $(CXX_LIB_NETWORK)

################

dllcsfml_system_stubs.so: $(CSTUBS_OBJS_SYSTEM)
	$(OCAMLMKLIB) -oc csfml_system_stubs \
	  $(CSTUBS_OBJS_SYSTEM) \
	  $(LD_PATH) \
	  $(LIBS_SYSTEM)

dllcsfml_window_stubs.so: $(CSTUBS_OBJS_WINDOW)
	$(OCAMLMKLIB) -oc csfml_window_stubs \
	  $(CSTUBS_OBJS_WINDOW) \
	  $(LD_PATH) \
	  $(LIBS_WINDOW)

dllcsfml_graphics_stubs.so: $(CSTUBS_OBJS_GRAPHICS)
	$(OCAMLMKLIB) -oc csfml_graphics_stubs \
	  $(CSTUBS_OBJS_GRAPHICS) \
	  $(LD_PATH) \
	  $(LIBS_GRAPHICS)

dllcsfml_audio_stubs.so: $(CSTUBS_OBJS_AUDIO)
	$(OCAMLMKLIB) -oc csfml_audio_stubs \
	  $(CSTUBS_OBJS_AUDIO) \
	  $(LD_PATH) \
	  $(LIBS_AUDIO)

dllcsfml_network_stubs.so: $(CSTUBS_OBJS_NETWORK)
	$(OCAMLMKLIB) -oc csfml_network_stubs \
	  $(CSTUBS_OBJS_NETWORK) \
	  $(LD_PATH) \
	  $(LIBS_NETWORK)

################

sfml_system.cma: dllsfml_system_stubs.so $(SYSTEM_MOD_CMO)
	$(OCAMLC) -g -a -o $@ \
	  $(SYSTEM_MOD_CMO) \
	  -dllib -lsfml_system_stubs \
	  -cclib -lsfml_system_stubs \
	  -ccopt "$(CXX_LD_PATH)" \
	  -cclib "$(CXX_LIB_SYSTEM)"

sfml_window.cma: dllsfml_window_stubs.so $(WINDOW_MOD_CMO)
	$(OCAMLC) -g -a -o $@ \
	  $(WINDOW_MOD_CMO) \
	  -dllib -lsfml_window_stubs \
	  -cclib -lsfml_window_stubs \
	  -ccopt "$(CXX_LD_PATH)" \
	  -cclib "$(CXX_LIB_WINDOW)"

sfml_graphics.cma: dllsfml_graphics_stubs.so $(GRAPHICS_MOD_CMO)
	$(OCAMLC) -g -a -o $@ \
	  $(GRAPHICS_MOD_CMO) \
	  -dllib -lsfml_graphics_stubs \
	  -cclib -lsfml_graphics_stubs \
	  -ccopt "$(CXX_LD_PATH)" \
	  -cclib "$(CXX_LIB_GRAPHICS)"

sfml_audio.cma: dllsfml_audio_stubs.so $(AUDIO_MOD_CMO)
	$(OCAMLC) -g -a -o $@ \
	  $(AUDIO_MOD_CMO) \
	  -dllib -lsfml_audio_stubs \
	  -cclib -lsfml_audio_stubs \
	  -ccopt "$(CXX_LD_PATH)" \
	  -cclib "$(CXX_LIB_AUDIO)"

sfml_network.cma: dllsfml_network_stubs.so $(NETWORK_MOD_CMO)
	$(OCAMLC) -g -a -o $@ \
	  $(NETWORK_MOD_CMO) \
	  -dllib -lsfml_network_stubs \
	  -cclib -lsfml_network_stubs \
	  -ccopt "$(CXX_LD_PATH)" \
	  -cclib "$(CXX_LIB_NETWORK)"


################

sfml_system.cmxa: dllsfml_system_stubs.so $(SYSTEM_MOD_CMX)
	$(OCAMLOPT) -a -o $@ \
	  $(SYSTEM_MOD_CMX) \
	  -cclib -lsfml_system_stubs \
	  -ccopt "$(CXX_LD_PATH)" \
	  -cclib "$(CXX_LIB_SYSTEM)"

sfml_window.cmxa: dllsfml_window_stubs.so $(WINDOW_MOD_CMX)
	$(OCAMLOPT) -a -o $@ \
	  $(WINDOW_MOD_CMX) \
	  -cclib -lsfml_window_stubs \
	  -ccopt "$(CXX_LD_PATH)" \
	  -cclib "$(CXX_LIB_WINDOW)"

sfml_graphics.cmxa: dllsfml_graphics_stubs.so $(GRAPHICS_MOD_CMX)
	$(OCAMLOPT) -a -o $@ \
	  $(GRAPHICS_MOD_CMX) \
	  -cclib -lsfml_graphics_stubs \
	  -ccopt "$(CXX_LD_PATH)" \
	  -cclib "$(CXX_LIB_GRAPHICS)"

sfml_audio.cmxa: dllsfml_audio_stubs.so $(AUDIO_MOD_CMX)
	$(OCAMLOPT) -a -o $@ \
	  $(AUDIO_MOD_CMX) \
	  -cclib -lsfml_audio_stubs \
	  -ccopt "$(CXX_LD_PATH)" \
	  -cclib "$(CXX_LIB_AUDIO)"

sfml_network.cmxa: dllsfml_network_stubs.so $(NETWORK_MOD_CMX)
	$(OCAMLOPT) -a -o $@ \
	  $(NETWORK_MOD_CMX) \
	  -cclib -lsfml_network_stubs \
	  -ccopt "$(CXX_LD_PATH)" \
	  -cclib "$(CXX_LIB_NETWORK)"



# ==== CSFML ==== #

csfml_system.cma: dllcsfml_system_stubs.so $(SYSTEM_MOD_CMO)
	$(OCAMLC) -g -a -o $@ \
	  $(SYSTEM_MOD_CMO) \
	  -dllib -lcsfml_system_stubs \
	  -cclib -lcsfml_system_stubs \
	  -ccopt "$(LD_PATH)" \
	  -cclib "$(LIBS_SYSTEM)"

csfml_window.cma: dllcsfml_window_stubs.so $(WINDOW_MOD_CMO)
	$(OCAMLC) -g -a -o $@ \
	  $(WINDOW_MOD_CMO) \
	  -dllib -lcsfml_window_stubs \
	  -cclib -lcsfml_window_stubs \
	  -ccopt "$(LD_PATH)" \
	  -cclib "$(LIBS_WINDOW)"

csfml_graphics.cma: dllcsfml_graphics_stubs.so $(GRAPHICS_MOD_CMO)
	$(OCAMLC) -g -a -o $@ \
	  $(GRAPHICS_MOD_CMO) \
	  -dllib -lcsfml_graphics_stubs \
	  -cclib -lcsfml_graphics_stubs \
	  -ccopt "$(LD_PATH)" \
	  -cclib "$(LIBS_GRAPHICS)"

csfml_audio.cma: dllcsfml_audio_stubs.so $(AUDIO_MOD_CMO)
	$(OCAMLC) -g -a -o $@ \
	  $(AUDIO_MOD_CMO) \
	  -dllib -lcsfml_audio_stubs \
	  -cclib -lcsfml_audio_stubs \
	  -ccopt "$(LD_PATH)" \
	  -cclib "$(LIBS_AUDIO)"

csfml_network.cma: dllcsfml_network_stubs.so $(NETWORK_MOD_CMO)
	$(OCAMLC) -g -a -o $@ \
	  $(NETWORK_MOD_CMO) \
	  -dllib -lcsfml_network_stubs \
	  -cclib -lcsfml_network_stubs \
	  -ccopt "$(LD_PATH)" \
	  -cclib "$(LIBS_NETWORK)"


################

csfml_system.cmxa: dllcsfml_system_stubs.so $(SYSTEM_MOD_CMX)
	$(OCAMLOPT) -a -o $@ \
	  $(SYSTEM_MOD_CMX) \
	  -cclib -lcsfml_system_stubs \
	  -ccopt "$(LD_PATH)" \
	  -cclib "$(LIBS_SYSTEM)"

csfml_window.cmxa: dllcsfml_window_stubs.so $(WINDOW_MOD_CMX)
	$(OCAMLOPT) -a -o $@ \
	  $(WINDOW_MOD_CMX) \
	  -cclib -lcsfml_window_stubs \
	  -ccopt "$(LD_PATH)" \
	  -cclib "$(LIBS_WINDOW)"

csfml_graphics.cmxa: dllcsfml_graphics_stubs.so $(GRAPHICS_MOD_CMX)
	$(OCAMLOPT) -a -o $@ \
	  $(GRAPHICS_MOD_CMX) \
	  -cclib -lcsfml_graphics_stubs \
	  -ccopt "$(LD_PATH)" \
	  -cclib "$(LIBS_GRAPHICS)"

csfml_audio.cmxa: dllcsfml_audio_stubs.so $(AUDIO_MOD_CMX)
	$(OCAMLOPT) -a -o $@ \
	  $(AUDIO_MOD_CMX) \
	  -cclib -lcsfml_audio_stubs \
	  -ccopt "$(LD_PATH)" \
	  -cclib "$(LIBS_AUDIO)"

csfml_network.cmxa: dllcsfml_network_stubs.so $(NETWORK_MOD_CMX)
	$(OCAMLOPT) -a -o $@ \
	  $(NETWORK_MOD_CMX) \
	  -cclib -lcsfml_network_stubs \
	  -ccopt "$(LD_PATH)" \
	  -cclib "$(LIBS_NETWORK)"



# ==== OO ==== #

### SFML OO:

sfml_%_oo.cma: oo_sfml_%.ml oo_sfml_%.cmi sfml_%.cma
	$(OCAMLC) -a -o $@ $<

sfml_%_oo.cmxa: oo_sfml_%.ml oo_sfml_%.cmi sfml_%.cmxa
	$(OCAMLOPT) -a -o $@ $<


### CSFML OO:

csfml_%_oo.cma: oo_sfml_%.ml oo_sfml_%.cmi csfml_%.cma
	$(OCAMLC) -a -o $@ $<

csfml_%_oo.cmxa: oo_sfml_%.ml oo_sfml_%.cmi csfml_%.cmxa
	$(OCAMLOPT) -a -o $@ $<



# ==== Edit ==== #

EDITOR := vim
edit_sys:
	cd cxx_stubs &&	$(EDITOR) $(STUBS_FILES_SYSTEM)
edit_win:
	cd cxx_stubs &&	$(EDITOR) $(STUBS_FILES_WINDOW)
edit_audio:
	cd cxx_stubs &&	$(EDITOR) $(STUBS_FILES_AUDIO)
edit_network:
	cd cxx_stubs &&	$(EDITOR) $(STUBS_FILES_NETWORK)
.PHONY: edit_sys edit_win edit_audio edit_network



# ==== META ==== #

META_cxx/META: META_cxx/META.in
	cat $< | sed -e 's/@VERSION@/$(VERSION)/' > $@

META_c/META: META_c/META.in
	cat $< | sed -e 's/@VERSION@/$(VERSION)/' > $@

.PHONY: clean_meta
clean_meta:
	$(RM)  META_cxx/META  META_c/META



# ==== Install commands ==== #

INSTALL := install
INSTALL_FILE := $(INSTALL) -m 0644
INSTALL_DIR := $(INSTALL) -d -m 0755
INSTALL_EXE := $(INSTALL) -m 0755

install: install_cxx
.PHONY: install


# ==== Install C++ bindings ==== #

.PHONY: install_cxx
install_cxx: $(CMI_INTRF) $(SFML_STUBS) META_cxx/META
	$(INSTALL_DIR)  $(PREFIX)
	$(INSTALL_DIR)  $(DLL_PREFIX)
	$(INSTALL_FILE) META_cxx/META $(PREFIX)
	$(INSTALL_FILE) *.mli $(PREFIX)
	$(INSTALL_FILE) libsfml_*_stubs.a sfml_*.a $(PREFIX)
	$(INSTALL_FILE) *.cmi sfml_*.cma sfml_*.cmxa $(PREFIX)
	if [ "`ls sfml_*.cmxs 2> /dev/null`" != "" ]; then\
	 $(INSTALL_EXE) sfml_*.cmxs $(PREFIX); fi
	$(INSTALL_EXE) dllsfml_*_stubs.so $(DLL_PREFIX)


# ==== Install C bindings ==== #

.PHONY: install_c
install_c: $(CMI_INTRF) $(CSFML_STUBS) META_c/META
	$(INSTALL_DIR)  $(PREFIX)
	$(INSTALL_DIR)  $(DLL_PREFIX)
	$(INSTALL_FILE) META_c/META $(PREFIX)
	$(INSTALL_FILE) *.mli $(PREFIX)
	$(INSTALL_FILE) libcsfml_*_stubs.a csfml_*.a $(PREFIX)
	$(INSTALL_FILE) *.cmi csfml_*.cma csfml_*.cmxa $(PREFIX)
	if [ "`ls csfml_*.cmxs 2> /dev/null`" != "" ]; then\
	 $(INSTALL_EXE) csfml_*.cmxs $(PREFIX); fi
	$(INSTALL_EXE) dllcsfml_*_stubs.so $(DLL_PREFIX)



# ==== find-install ==== #

.PHONY: findinstall findinstall_c findinstall_cxx
findinstall: findinstall_cxx
findinstall_cxx: META_cxx/META
	$(OCAMLFIND) install sfml $< *.cma *.cmxa *.cmxs *.cmi *.mli *.so *.a

findinstall_c: META_c/META
	$(OCAMLFIND) install sfml $< *.cma *.cmxa *.cmxs *.cmi *.mli *.so *.a



# ==== doc ==== #

.PHONY: doc
doc: $(MLI_FILES) $(CMI_INTRF) \
  oo_sfml_system.mli \
  oo_sfml_system.cmi \
  oo_sfml_window.mli \
  oo_sfml_window.cmi \
  oo_sfml_graphics.mli \
  oo_sfml_graphics.cmi \
  oo_sfml_audio.mli \
  oo_sfml_audio.cmi \
  oo_sfml_network.mli \
  oo_sfml_network.cmi
	mkdir -p $(DOC_DIR)
	$(OCAMLDOC) $(MLI_FILES) \
	  oo_sfml_system.mli \
	  oo_sfml_window.mli \
	  oo_sfml_graphics.mli \
	  oo_sfml_audio.mli \
	  oo_sfml_network.mli \
	  -colorize-code -html \
	  -d $(DOC_DIR)


# ==== clean ==== #

clean_doc:
	$(RM) $(DOC_DIR)/*
	$(RM) -r $(DOC_DIR)

clean:
	$(RM) *.[oa] *.cm[ixoa] *.cmx[as] *.so *.opt *.byte

clean_obj:
	$(RM) *.o

clean_baks:
	$(RM) *~ */*~

clean_all: clean clean_mli clean_doc clean_obj clean_baks clean_meta

.PHONY: clean clean_all clean_baks clean_obj clean_doc
