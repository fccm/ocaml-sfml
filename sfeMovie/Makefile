include ../src/Makefile

SFML_LINK_LIBS := \
  $(CXX_SYSTEM_LIB) \
  $(CXX_WINDOW_LIB) \
  $(CXX_GRAPHICS_LIB) \
  $(CXX_AUDIO_LIB) \
  #End

SFEMOVIE_LINK_LIBS := -lswscale -lsfeMovie -lavformat -lavcodec

SFEMOVIE_BASEDIR := /temp/sfeMovie
SFEMOVIE_LIB_DIR := $(SFEMOVIE_BASEDIR)/lib
SFEMOVIE_LD_PATH := -L$(SFEMOVIE_LIB_DIR)

SFEMOVIE_INC_DIR := $(SFEMOVIE_BASEDIR)/include
SFEMOVIE_INC_PATH := -I$(SFEMOVIE_INC_DIR)

.PHONY: sfe sfe_byte sfe_opt sfe_cmxs
sfe: sfe_byte sfe_opt sfe_cmxs
sfe_byte: sfeMovie.cma
sfe_opt: sfeMovie.cmxa
sfe_cmxs: sfeMovie.cmxs

%.mli: %.ml
	cat SFEMovie_mli.txt > $@
	$(OCAMLC) -i -I ../src $< >> $@

%.cmi: %.mli
	$(OCAMLC) -c -o $@ -I ../src $<

%.cmo: %.ml %.cmi
	$(OCAMLC) -c -o $@ -I ../src $<

%.cmx: %.ml %.cmi
	$(OCAMLOPT) -c -o $@ -I ../src $<

DOC_DIR := doc
.PHONY: sfe_doc
sfe_doc: SFEMovie.mli SFEMovie.cmi
	mkdir -p $(DOC_DIR)
	$(OCAMLDOC) -I ../src $< \
	  -colorize-code -html \
	  -d $(DOC_DIR)

sfeMovie.cma: SFEMovie.cmo SFEMovie.cmi dllsfeMovie_stubs.so
	$(OCAMLC) -a -o $@ $< \
	  -dllib -lsfeMovie_stubs \
	  -cclib -lsfeMovie_stubs \
	  -ccopt "$(CXX_LD_PATH)  $(SFEMOVIE_LD_PATH)" \
	  -cclib "$(SFML_LINK_LIBS)  $(SFEMOVIE_LINK_LIBS)"

sfeMovie.cmxa: SFEMovie.cmx dllsfeMovie_stubs.so
	$(OCAMLOPT) -a -o $@ $< \
	  -cclib -lsfeMovie_stubs \
	  -ccopt "$(CXX_LD_PATH)  $(SFEMOVIE_LD_PATH)" \
	  -cclib "$(SFML_LINK_LIBS)  $(SFEMOVIE_LINK_LIBS)"

dllsfeMovie_stubs.so: SFEMovie_stub.o
	$(OCAMLMKLIB) -oc sfeMovie_stubs \
	  $< \
	  $(CXX_LD_PATH)  $(SFEMOVIE_LD_PATH) \
	  $(SFML_LINK_LIBS)  $(SFEMOVIE_LINK_LIBS)

SFEMovie_stub.o: SFEMovie_stub.cpp
	$(CXX) -c -I$(OCAML_DIR) $(CXX_INC_PATH) \
	  -I../src/cxx_stubs/ \
	  $(SFEMOVIE_INC_PATH) $<
