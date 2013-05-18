#ifndef _SF_CAML_INCS
#define _SF_CAML_INCS

#define CAML_NAME_SPACE

extern "C" {
#include <caml/mlvalues.h>
#include <caml/alloc.h>
#include <caml/memory.h>
#include <caml/fail.h>
#include <caml/bigarray.h>
#include <caml/signals.h>
#include <caml/custom.h>
#include <caml/callback.h>
}

#define CAMLextern_C extern "C"

/* Turn on/off the debug messages */
#define _OCAML_SFML_DEBUG 1

#if defined(_OCAML_SFML_DEBUG)
  #include <iostream>
#endif

#endif // _SF_CAML_INCS
