/*
 * OCaml-SFML - OCaml bindings for the SFML library.
 * Copyright (C) 2012 Florent Monnier <monnier.florent(_)gmail.com>
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

#include <SFML/Network/Http.hpp>

#include "sf_caml_incs.hpp"
#include "sf_caml_conv.hpp"

#include "SFTime_stub.hpp"

static const sf::Http::Request::Method table_sfHttpMethod[] = {
    sf::Http::Request::Get,
    sf::Http::Request::Post,
    sf::Http::Request::Head,
};

#define SfHttpMethod_val(m) \
    table_sfHttpMethod[Long_val(m)]

static value Val_sfHttpStatus(sf::Http::Response::Status status)
{
    switch (status)
    {
        case sf::Http::Response::Ok:                  return Val_int(0);
        case sf::Http::Response::Created:             return Val_int(1);
        case sf::Http::Response::Accepted:            return Val_int(2);
        case sf::Http::Response::NoContent:           return Val_int(3);
        case sf::Http::Response::ResetContent:        return Val_int(4);
        case sf::Http::Response::PartialContent:      return Val_int(5);
        case sf::Http::Response::MultipleChoices:     return Val_int(6);
        case sf::Http::Response::MovedPermanently:    return Val_int(7);
        case sf::Http::Response::MovedTemporarily:    return Val_int(8);
        case sf::Http::Response::NotModified:         return Val_int(9);
        case sf::Http::Response::BadRequest:          return Val_int(10);
        case sf::Http::Response::Unauthorized:        return Val_int(11);
        case sf::Http::Response::Forbidden:           return Val_int(12);
        case sf::Http::Response::NotFound:            return Val_int(13);
        case sf::Http::Response::RangeNotSatisfiable: return Val_int(14);
        case sf::Http::Response::InternalServerError: return Val_int(15);
        case sf::Http::Response::NotImplemented:      return Val_int(16);
        case sf::Http::Response::BadGateway:          return Val_int(17);
        case sf::Http::Response::ServiceNotAvailable: return Val_int(18);
        case sf::Http::Response::GatewayTimeout:      return Val_int(19);
        case sf::Http::Response::VersionNotSupported: return Val_int(20);
        case sf::Http::Response::InvalidResponse:     return Val_int(21);
        case sf::Http::Response::ConnectionFailed:    return Val_int(22);
    }
    caml_failwith("SFHttp.status");
}

#define Val_sfHttpRequest(req) ((value)(req))
#define SfHttpRequest_val(req) ((sf::Http::Request *)(req))

#define Val_sfHttpResponse(req) ((value)(req))
#define SfHttpResponse_val(req) ((sf::Http::Response *)(req))

#define Val_sfHttp(req) ((value)(req))
#define SfHttp_val(req) ((sf::Http *)(req))

CAMLextern_C value
caml_sfHttpRequest_create(value unit)
{
    sf::Http::Request *req = new sf::Http::Request;
    return Val_sfHttpRequest(req);
}

CAMLextern_C value
caml_sfHttpRequest_destroy(value httpRequest)
{
    delete SfHttpRequest_val(httpRequest);
    return Val_unit;
}

CAMLextern_C value
caml_sfHttpRequest_setField(value httpRequest, value field, value val)
{
    SfHttpRequest_val(httpRequest)->setField(
            String_val(field), String_val(val));
    return Val_unit;
}

CAMLextern_C value
caml_sfHttpRequest_setMethod(value httpRequest, value method)
{
    SfHttpRequest_val(httpRequest)->setMethod(
            SfHttpMethod_val(method));
    return Val_unit;
}

CAMLextern_C value
caml_sfHttpRequest_setUri(value httpRequest, value uri)
{
    SfHttpRequest_val(httpRequest)->setUri(String_val(uri));
    return Val_unit;
}

CAMLextern_C value
caml_sfHttpRequest_setHttpVersion(value httpRequest, value major, value minor)
{
    SfHttpRequest_val(httpRequest)->setHttpVersion(
            UInt_val(major), UInt_val(minor));
    return Val_unit;
}

CAMLextern_C value
caml_sfHttpRequest_setBody(value httpRequest, value body)
{
    SfHttpRequest_val(httpRequest)->setBody(String_val(body));
    return Val_unit;
}

CAMLextern_C value
caml_sfHttpResponse_destroy(value httpResponse)
{
    delete SfHttpResponse_val(httpResponse);
    return Val_unit;
}

CAMLextern_C value
caml_sfHttpResponse_getField(value httpResponse, value field)
{
    const std::string& resp =
        SfHttpResponse_val(httpResponse)->getField(
            String_val(field));
    return caml_copy_string(resp.c_str());
}


CAMLextern_C value
caml_sfHttpResponse_getStatus(value httpResponse)
{
    return Val_sfHttpStatus(
        SfHttpResponse_val(httpResponse)->getStatus());
}

CAMLextern_C value
caml_sfHttpResponse_getMajorHttpVersion(value httpResponse)
{
    unsigned int ver = SfHttpResponse_val(httpResponse)->getMajorHttpVersion();
    return Val_int(ver);
}

CAMLextern_C value
caml_sfHttpResponse_getMinorHttpVersion(value httpResponse)
{
    unsigned int ver = SfHttpResponse_val(httpResponse)->getMinorHttpVersion();
    return Val_int(ver);
}

CAMLextern_C value
caml_sfHttpResponse_getBody(value httpResponse)
{
    const std::string& resp = SfHttpResponse_val(httpResponse)->getBody();
    return caml_copy_string(resp.c_str());
}

CAMLextern_C value
caml_sfHttp_create(value unit)
{
    sf::Http *http = new sf::Http;
    return Val_sfHttp(http);
}

CAMLextern_C value
caml_sfHttp_destroy(value http)
{
    delete SfHttp_val(http);
    return Val_unit;
}

CAMLextern_C value
caml_sfHttp_setHost(value http, value host, value port, value unit)
{
    if (port == Val_none)
        SfHttp_val(http)->setHost(String_val(host));
    else
        SfHttp_val(http)->setHost(String_val(host), Int_val(Some_val(port)));
    return Val_unit;
}

CAMLextern_C value
caml_sfHttp_sendRequest(value http, value request, value timeout, value unit)
{
    sf::Http::Response resp;
    if (timeout != Val_none)
        resp = SfHttp_val(http)->sendRequest(
                *SfHttpRequest_val(request), *SfTime_val_u(Some_val(timeout)));
    else
        resp = SfHttp_val(http)->sendRequest(
                *SfHttpRequest_val(request));
    sf::Http::Response *r = new sf::Http::Response;
    *r = resp;
    return Val_sfHttpResponse(r);
}

// vim: sw=4 sts=4 ts=4 et
