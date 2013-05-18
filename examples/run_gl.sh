sh run.sh "\
  sfml_system.cma \
  sfml_window.cma \
  sfml_graphics.cma \
  " "-I +glMLite GL.cma Glu.cma \
  $*"
