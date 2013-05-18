#include "sf_caml_incs_c.h"

/* ocaml types conversions */

value
Val_some(value v) {
    CAMLparam1(v);
    CAMLlocal1(some);
    some = caml_alloc(1, 0);
    Store_field(some, 0, v);
    CAMLreturn(some);
}

/* vim: sw=4 sts=4 ts=4 et
 */
