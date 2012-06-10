OCAMLC := ocamlc.opt -g
OCAMLOPT := ocamlopt.opt -g
OCAMLDOC := ocamldoc.opt
OCAMLMKLIB := ocamlmklib
OCAML_DIR := $(shell ocamlc -where)
BINDING_DIR := sfml
PREFIX := $(OCAML_DIR)/$(BINDING_DIR)
#DLL_PREFIX := $(OCAML_DIR)/stublibs
DLL_PREFIX := $(PREFIX)

CXXLIBS := -lsfml-graphics -lsfml-system -lsfml-window -lsfml-audio
CLIBS := -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio
LIBS := $(CXXLIBS) $(CLIBS)

LIB_SFML_BASEDIR := ../SFML-1.6

INC_PATH := -I$(LIB_SFML_BASEDIR)/CSFML/include/
CXXLD_PATH := -L$(LIB_SFML_BASEDIR)/lib/
CLD_PATH := -L$(LIB_SFML_BASEDIR)/CSFML/lib/
LD_PATH := $(CXXLD_PATH) $(CLD_PATH)

DOC_DIR := doc
SRC_FILES := \
      SFClock.ml SFPausableClock.ml \
      SFRect.ml SFColor.ml SFBlendMode.ml \
      SFImage.ml SFSprite.ml SFShape.ml \
      SFFont.ml SFString.ml \
      SFMusic.ml SFListener.ml \
      SFSoundBuffer.ml SFSound.ml \
      SFKey.ml SFEvent.ml SFInput.ml \
      SFView.ml SFWindow.ml SFRenderWindow.ml

BYTE_OBJ := $(patsubst %.ml, %.cmo, $(SRC_FILES))
NAT_OBJ := $(patsubst %.ml, %.cmx, $(SRC_FILES))
MLI_FILES := $(patsubst %.ml, %.mli, $(SRC_FILES))
CMI_INTRF := $(patsubst %.ml, %.cmi, $(SRC_FILES))

all: byte opt cmxs
byte: SFML.cma
opt: SFML.cmxa
cmxs: SFML.cmxs

sfml_stubs.o: sfml_stubs.c
	$(OCAMLC) -c -ccopt $(INC_PATH) $<

dllsfml_stubs.so: sfml_stubs.o
	$(OCAMLMKLIB) -oc sfml_stubs $< $(LD_PATH) $(LIBS)

%.mli: %.ml
	$(OCAMLC) -i $< > $@
%.cmi: %.mli
	$(OCAMLC) -c $<
%.cmo: %.ml %.cmi
	$(OCAMLC) -c $<
%.cmx: %.ml %.cmi
	$(OCAMLOPT) -c $<

# non-generated .mli files:

SFString.mli:
	:
SFFont.mli:
	:
SFSprite.mli:
	:
SFImage.mli:
	:
SFSound.mli:
	:
SFSoundBuffer.mli:
	:

# clean generated .mli files:
GENERATED_MLI := \
      SFClock.mli SFPausableClock.mli \
      SFRect.mli SFColor.mli SFBlendMode.mli \
      SFShape.mli \
      SFMusic.mli SFListener.mli \
      SFKey.mli SFEvent.mli SFInput.mli \
      SFView.mli SFWindow.mli SFRenderWindow.mli

clean_mli:
	rm -f $(GENERATED_MLI)

SFInput.mli: SFInput.ml SFKey.cmi SFEvent.cmi
SFEvent.mli: SFEvent.ml SFKey.cmi
SFShape.mli: SFShape.ml SFColor.cmi SFBlendMode.cmi
SFView.mli: SFView.ml SFRect.cmi
SFSound.cmi: SFSoundBuffer.cmi
SFSprite.cmi: SFImage.cmi SFBlendMode.cmi SFColor.cmi SFRect.cmi
SFString.cmi: SFFont.cmi SFColor.cmi SFBlendMode.cmi SFRect.cmi
SFWindow.mli: SFWindow.ml \
  SFView.cmi SFKey.cmi SFEvent.cmi SFInput.cmi SFColor.cmi
SFRenderWindow.mli: SFRenderWindow.ml \
  SFView.cmi SFKey.cmi SFEvent.cmi SFInput.cmi SFColor.cmi \
  SFShape.cmi SFSprite.cmi SFString.cmi

SFML.cma: $(BYTE_OBJ) $(CMI_INTRF) dllsfml_stubs.so
	$(OCAMLC) -a -o $@ $(BYTE_OBJ) -dllib -lsfml_stubs -cclib -lsfml_stubs \
	  -ccopt "$(LD_PATH)" -cclib "$(LIBS)"

SFML.cmxa: $(NAT_OBJ) $(CMI_INTRF) dllsfml_stubs.so
	$(OCAMLOPT) -a -o $@ $(NAT_OBJ) -cclib -lsfml_stubs \
	  -ccopt "$(LD_PATH)" -cclib "$(LIBS)"

SFML.cmxs: SFML.cmxa
	$(OCAMLOPT) -shared -linkall -o $@ -ccopt -L. $<

install: $(CMI_INTRF) dllsfml_stubs.so
	install -d -m 0755 $(PREFIX)
	install -m 0644 *.mli META $(PREFIX)
	install -m 0644 *.a *.cmi *.cma *.cmxa $(PREFIX)
	install -m 0755 *.cmxs $(PREFIX)
	install -m 0755 *.so $(DLL_PREFIX)

doc: $(MLI_FILES) $(CMI_INTRF)
	mkdir -p $(DOC_DIR)
	$(OCAMLDOC) $(MLI_FILES) \
	    -colorize-code -html \
	    -d $(DOC_DIR)

test: SFML.cma
	@echo "may require to run this before:"
	@echo "(with the appropriate path)"
	@echo "export LD_LIBRARY_PATH=\"$(LIB_SFML_BASEDIR)/lib:$(LIB_SFML_BASEDIR)/CSFML/lib\""
	ocaml bigarray.cma $< test.ml
test.opt: SFML.cmxa
	$(OCAMLOPT) -g -cclib -L. bigarray.cmxa SFML.cmxa test.ml -o test.opt
test_opt: test.opt
	./$<

clean:
	rm -f *.[oa] *.cm[ixoa] *.so *.cmxa *.cmxs *.opt

.PHONY: clean clean_mli all opt byte cmxs doc test test_opt install
