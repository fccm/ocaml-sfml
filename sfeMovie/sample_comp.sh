pushd ../src
  make -j \
    LIB_SFML_BASEDIR=/temp/SFML_git \
    sfml_system.cmxa \
    sfml_window.cmxa \
    sfml_graphics.cmxa \
    sfml_audio.cmxa
popd

make \
  LIB_SFML_BASEDIR=/temp/SFML_git \
  sfeMovie.cmxa

ocamlopt bigarray.cmxa \
  -I ../src/ \
  sfml_system.cmxa \
  sfml_window.cmxa \
  sfml_graphics.cmxa \
  sfml_audio.cmxa \
  -I .  sfeMovie.cmxa \
  sample.ml $*
