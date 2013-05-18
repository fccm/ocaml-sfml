#ifndef _SF_CAML_CONV_INC
#define _SF_CAML_CONV_INC


#define Val_none Val_int(0)
#define Some_val(v) Field(v,0)

value Val_some(value v);

#define Option_val(ml_value, Conv_val, default_value) \
    (ml_value != Val_none ? Conv_val(Some_val(ml_value)) : default_value)

#define Float_val(v) ((float)Double_val(v))

#define UInt_val(v) ((unsigned int) Long_val(v))

/*
static inline
unsigned int UInt_val(value v) {
    long d = Long_val(v);
    if (d < 0) caml_invalid_argument("unsigned int");
    return (unsigned int) d;
}
*/

#endif // _SF_CAML_CONV_INC
