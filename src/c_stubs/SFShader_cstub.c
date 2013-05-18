/*
 * OCaml-SFML - OCaml bindings for the SFML library.
 * Copyright (C) 2010 Florent Monnier <monnier.florent(_)gmail.com>
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

#include <SFML/Graphics/Shader.h>

#include "sf_caml_incs_c.h"
#include "sf_caml_conv_c.h"
#include "SFShader_cstub.h"

/* sfShader */

CAMLprim value
caml_sfShader_loadFromFile(
        value vertexShaderFilename,
        value fragmentShaderFilename,
        value unit)
{
    sfShader *shader = NULL;

    if (vertexShaderFilename != Val_none &&
        fragmentShaderFilename != Val_none)
        shader = sfShader_createFromFile(
                String_val(Some_val(vertexShaderFilename)),
                String_val(Some_val(fragmentShaderFilename)));
    else if (vertexShaderFilename != Val_none)
        shader = sfShader_createFromFile(
                String_val(Some_val(vertexShaderFilename)), NULL);
    else if (fragmentShaderFilename != Val_none)
        shader = sfShader_createFromFile(
                NULL, String_val(Some_val(fragmentShaderFilename)));

    if (shader == NULL) caml_failwith("SFShader.loadFromFile");
    return Val_sfShader(shader);
}

CAMLprim value
caml_sfShader_loadFromMemory(
        value vertexShader, value fragmentShader, value unit)
{
    sfShader *shader = NULL;

    if (vertexShader != Val_none && fragmentShader != Val_none)
        shader = sfShader_createFromMemory(
                String_val(Some_val(vertexShader)),
                String_val(Some_val(fragmentShader)));
    else if (vertexShader != Val_none)
        shader = sfShader_createFromMemory(
                String_val(Some_val(vertexShader)), NULL);
    else if (fragmentShader != Val_none)
        shader = sfShader_createFromMemory(
                NULL, String_val(Some_val(fragmentShader)));

    if (shader == NULL) caml_failwith("SFShader.loadFromMemory");
    return Val_sfShader(shader);
}

CAMLprim value
caml_sfShader_destroy(value shader)
{
    sfShader_destroy(SfShader_val(shader));
    return Val_unit;
}

CAMLprim value
caml_sfShader_bind(value shader)
{
    sfShader_bind(SfShader_val(shader));
    return Val_unit;
}

/* TODO
CAMLprim value
caml_sfShader_unbind(value shader)
{
    sfShader_unbind(SfShader_val(shader));
    return Val_unit;
}
*/

CAMLprim value
caml_sfShader_isAvailable(value unit)
{
    sfBool b = sfShader_isAvailable();
    return Val_bool(b);
}

CAMLprim value
caml_sfShader_setFloatParameter(value shader, value name, value x)
{
    sfShader_setFloatParameter(
            SfShader_val(shader), String_val(name), Double_val(x));
    return Val_unit;
}

CAMLprim value
caml_sfShader_setFloat2Parameter(value shader, value name, value x, value y)
{
    sfShader_setFloat2Parameter(
            SfShader_val(shader), String_val(name),
            Double_val(x), Double_val(y));
    return Val_unit;
}

CAMLprim value
caml_sfShader_setFloat3Parameter(
        value shader, value name, value x, value y, value z)
{
    sfShader_setFloat3Parameter(
            SfShader_val(shader), String_val(name),
            Double_val(x), Double_val(y), Double_val(z));
    return Val_unit;
}

CAMLprim value
caml_sfShader_setFloat4Parameter_native(
        value shader, value name, value x, value y, value z, value w)
{
    sfShader_setFloat4Parameter(SfShader_val(shader), String_val(name),
            Double_val(x), Double_val(y), Double_val(z), Double_val(w));
    return Val_unit;
}
CAMLprim value
caml_sfShader_setFloat4Parameter_bytecode(value *argv, int argn)
{
    return caml_sfShader_setFloat4Parameter_native(
            argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

/* TODO
sfShader* sfShader_createFromStream(
        sfInputStream* vertexShaderStream, sfInputStream* fragmentShaderStream);

void sfShader_setVector2Parameter(
        sfShader* shader, const char* name, sfVector2f vector);

void sfShader_setVector3Parameter(
        sfShader* shader, const char* name, sfVector3f vector);

void sfShader_setColorParameter(
        sfShader* shader, const char* name, sfColor color);

void sfShader_setTransformParameter(
        sfShader* shader, const char* name, sfTransform transform);

void sfShader_setTextureParameter(
        sfShader* shader, const char* name, const sfTexture* texture);

void sfShader_setCurrentTextureParameter(
        sfShader* shader, const char* name);
*/

/* vim: sw=4 sts=4 ts=4 et
 */
