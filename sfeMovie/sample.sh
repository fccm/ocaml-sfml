pushd ../src
  make -j \
    sfml_system.cma \
    sfml_window.cma \
    sfml_graphics.cma \
    sfml_audio.cma
popd

make sfeMovie.cma

echo ocaml bigarray.cma \
  -I ../src/ \
  sfml_system.cma \
  sfml_window.cma \
  sfml_graphics.cma \
  sfml_audio.cma \
  -I .  sfeMovie.cma \
  sample.ml $*

\ocaml bigarray.cma \
  -I ../src/ \
  sfml_system.cma \
  sfml_window.cma \
  sfml_graphics.cma \
  sfml_audio.cma \
  -I .  sfeMovie.cma \
  sample.ml $*
