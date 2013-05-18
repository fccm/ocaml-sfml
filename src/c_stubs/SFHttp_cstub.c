/*
 * OCaml-SFML - OCaml bindings for the SFML library.
 * Copyright (C) 2011 Florent Monnier <monnier.florent(_)gmail.com>
 *
 * This software is provided 'as-is', without any express or implied warranty.
 * In no event will the authors be held liable for any damages arising from the
 * use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented;
 *    you must not claim that you wrote the original software.
 *    If you use this software in a product, an acknowledgment
 *    in the product documentation would be appreciated but is not required.
 *
 * 2. Altered source versions must be plainly marked as such,
 *    and must not be misrepresented as being the original software.
 *
 * 3. This notice may not be removed or altered from any source distribution.
 */

#include <SFML/Network/Http.h>

#include "sf_caml_incs_c.h"
#include "sf_caml_conv_c.h"
#include "SFTime_cstub.h"


static const sfHttpMethod table_sfHttpMethod[] = {
    sfHttpGet,
    sfHttpPost,
    sfHttpHead,
};

#define SfHttpMethod_val(m) \
    table_sfHttpMethod[Long_val(m)]

static value Val_sfHttpStatus(sfHttpStatus status)
{
    switch (status)
    {
        case sfHttpOk:                  return Val_int(0);
        case sfHttpCreated:             return Val_int(1);
        case sfHttpAccepted:            return Val_int(2);
        case sfHttpNoContent:           return Val_int(3);
        case sfHttpResetContent:        return Val_int(4);
        case sfHttpPartialContent:      return Val_int(5);
        case sfHttpMultipleChoices:     return Val_int(6);
        case sfHttpMovedPermanently:    return Val_int(7);
        case sfHttpMovedTemporarily:    return Val_int(8);
        case sfHttpNotModified:         return Val_int(9);
        case sfHttpBadRequest:          return Val_int(10);
        case sfHttpUnauthorized:        return Val_int(11);
        case sfHttpForbidden:           return Val_int(12);
        case sfHttpNotFound:            return Val_int(13);
        case sfHttpRangeNotSatisfiable: return Val_int(14);
        case sfHttpInternalServerError: return Val_int(15);
        case sfHttpNotImplemented:      return Val_int(16);
        case sfHttpBadGateway:          return Val_int(17);
        case sfHttpServiceNotAvailable: return Val_int(18);
        case sfHttpGatewayTimeout:      return Val_int(19);
        case sfHttpVersionNotSupported: return Val_int(20);
        case sfHttpInvalidResponse:     return Val_int(21);
        case sfHttpConnectionFailed:    return Val_int(22);
    }
    caml_failwith("SFHttp.status");
}

#define Val_sfHttpRequest(req) ((value)(req))
#define SfHttpRequest_val(req) ((sfHttpRequest *)(req))

#define Val_sfHttpResponse(req) ((value)(req))
#define SfHttpResponse_val(req) ((sfHttpResponse *)(req))

#define Val_sfHttp(req) ((value)(req))
#define SfHttp_val(req) ((sfHttp *)(req))

CAMLprim value
caml_sfHttpRequest_create(value unit)
{
    sfHttpRequest *req = sfHttpRequest_create();
    return Val_sfHttpRequest(req);
}

CAMLprim value
caml_sfHttpRequest_destroy(value httpRequest)
{
    sfHttpRequest_destroy(SfHttpRequest_val(httpRequest));
    return Val_unit;
}

CAMLprim value
caml_sfHttpRequest_setField(value httpRequest, value field, value val)
{
    sfHttpRequest_setField(
            SfHttpRequest_val(httpRequest), String_val(field), String_val(val));
    return Val_unit;
}

CAMLprim value
caml_sfHttpRequest_setMethod(value httpRequest, value method)
{
    sfHttpRequest_setMethod(
            SfHttpRequest_val(httpRequest), SfHttpMethod_val(method));
    return Val_unit;
}

CAMLprim value
caml_sfHttpRequest_setUri(value httpRequest, value uri)
{
    sfHttpRequest_setUri(SfHttpRequest_val(httpRequest), String_val(uri));
    return Val_unit;
}

CAMLprim value
caml_sfHttpRequest_setHttpVersion(value httpRequest, value major, value minor)
{
    sfHttpRequest_setHttpVersion(
            SfHttpRequest_val(httpRequest), UInt_val(major), UInt_val(minor));
    return Val_unit;
}

CAMLprim value
caml_sfHttpRequest_setBody(value httpRequest, value body)
{
    sfHttpRequest_setBody(SfHttpRequest_val(httpRequest), String_val(body));
    return Val_unit;
}

CAMLprim value
caml_sfHttpResponse_destroy(value httpResponse)
{
    sfHttpResponse_destroy(SfHttpResponse_val(httpResponse));
    return Val_unit;
}

CAMLprim value
caml_sfHttpResponse_getField(value httpResponse, value field)
{
    const char *resp;
    resp = sfHttpResponse_getField(
            SfHttpResponse_val(httpResponse), String_val(field));
    return caml_copy_string(resp);
}

CAMLprim value
caml_sfHttpResponse_getStatus(value httpResponse)
{
    sfHttpStatus st =
        sfHttpResponse_getStatus(SfHttpResponse_val(httpResponse));
    return Val_sfHttpStatus(st);
}

CAMLprim value
caml_sfHttpResponse_getMajorHttpVersion(value httpResponse)
{
    unsigned int ver =
        sfHttpResponse_getMajorVersion(SfHttpResponse_val(httpResponse));
    return Val_int(ver);
}

CAMLprim value
caml_sfHttpResponse_getMinorHttpVersion(value httpResponse)
{
    unsigned int ver =
        sfHttpResponse_getMinorVersion(SfHttpResponse_val(httpResponse));
    return Val_int(ver);
}

CAMLprim value
caml_sfHttpResponse_getBody(value httpResponse)
{
    const char *resp = sfHttpResponse_getBody(SfHttpResponse_val(httpResponse));
    return caml_copy_string(resp);
}

CAMLprim value
caml_sfHttp_create(value unit)
{
    sfHttp *http = sfHttp_create();
    return Val_sfHttp(http);
}

CAMLprim value
caml_sfHttp_destroy(value http)
{
    sfHttp_destroy(SfHttp_val(http));
    return Val_unit;
}

CAMLprim value
caml_sfHttp_setHost(value http, value host, value port, value unit)
{
    if (port == Val_none)
        sfHttp_setHost(SfHttp_val(http), String_val(host), 0);
    else
        sfHttp_setHost(SfHttp_val(http), String_val(host),
                Int_val(Some_val(port)));
    return Val_unit;
}

CAMLprim value
caml_sfHttp_sendRequest(value http, value request, value ml_timeout, value unit)
{
    sfTime timeout = Option_val(ml_timeout, SfTime_val, sfTime_Zero);
    sfHttpResponse *resp = sfHttp_sendRequest(
            SfHttp_val(http), SfHttpRequest_val(request), timeout);
    return Val_sfHttpResponse(resp);
}

/* vim: sw=4 sts=4 ts=4 et
 */
