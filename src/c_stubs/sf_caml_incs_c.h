#ifndef _CSF_CAML_INCS
#define _CSF_CAML_INCS

#define CAML_NAME_SPACE

#include <caml/mlvalues.h>
#include <caml/alloc.h>
#include <caml/memory.h>
#include <caml/fail.h>
#include <caml/bigarray.h>
#include <caml/signals.h>
#include <caml/custom.h>
#include <caml/callback.h>

/* Turn on/off the debug messages */
#define _OCAML_CSFML_DEBUG 1

#if defined(_OCAML_CSFML_DEBUG)
  #include <stdio.h>
#endif

#endif // _CSF_CAML_INCS
