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

#include <SFML/Graphics/Shader.hpp>

#include "sf_caml_incs.hpp"
#include "sf_caml_conv.hpp"
#include "SFShader_stub.hpp"

value Val_sfShader(sf::Shader * p)
{
    return caml_copy_nativeint((intnat) p);
}

sf::Shader * SfShader_val(value v)
{
    return (sf::Shader *) Nativeint_val(v);
}

/* sf::Shader */

CAMLextern_C value
caml_sfShader_loadFromFile(
        value vertexShaderFilename, value fragmentShaderFilename, value unit)
{
    bool success = false;
    sf::Shader *shader = new sf::Shader;

    if (vertexShaderFilename != Val_none ||
        fragmentShaderFilename != Val_none)
    {
        if (vertexShaderFilename == Val_none)
        {
            // fragment shader only
            success = shader->loadFromFile(
                    String_val(fragmentShaderFilename),
                    sf::Shader::Fragment);
        }
        else if (fragmentShaderFilename == Val_none)
        {
            // vertex shader only
            success = shader->loadFromFile(
                    String_val(vertexShaderFilename),
                    sf::Shader::Vertex);
        }
        else
        {
            // vertex + fragment shaders
            success = shader->loadFromFile(
                    String_val(vertexShaderFilename),
                    String_val(fragmentShaderFilename));
        }
    }

    if (!success)
    {
        delete shader;
        caml_failwith("SFShader.loadFromFile");
    }

    return Val_sfShader(shader);
}

CAMLextern_C value
caml_sfShader_loadFromMemory(
        value vertexShader, value fragmentShader, value unit)
{
    bool success = false;
    sf::Shader* shader = new sf::Shader;

    if (vertexShader != Val_none ||
        fragmentShader != Val_none)
    {
        if (vertexShader == Val_none)
        {
            // fragment shader only
            success = shader->loadFromMemory(
                    String_val(fragmentShader),
                    sf::Shader::Fragment);
        }
        else if (fragmentShader == Val_none)
        {
            // vertex shader only
            success = shader->loadFromMemory(
                    String_val(vertexShader),
                    sf::Shader::Vertex);
        }
        else
        {
            // vertex + fragment shaders
            success = shader->loadFromMemory(
                    String_val(vertexShader),
                    String_val(fragmentShader));
        }
    }

    if (!success)
    {
        delete shader;
        caml_failwith("SFShader.loadFromMemory");
    }

    return Val_sfShader(shader);
}

CAMLextern_C value
caml_sfShader_destroy(value shader)
{
    delete SfShader_val(shader);
    return Val_unit;
}

CAMLextern_C value
caml_sfShader_bind(value shader)
{
    sf::Shader::bind(SfShader_val(shader));
    return Val_unit;
}

/* TODO
CAMLextern_C value
caml_sfShader_unbind(value shader)
{
    SfShader_val(shader)->unbind();
    return Val_unit;
}
*/

CAMLextern_C value
caml_sfShader_isAvailable(value unit)
{
    bool b = sf::Shader::isAvailable();
    return Val_bool(b);
}

CAMLextern_C value
caml_sfShader_setFloatParameter(value shader, value name, value x)
{
    SfShader_val(shader)->setParameter(String_val(name), Float_val(x));
    return Val_unit;
}

CAMLextern_C value
caml_sfShader_setFloat2Parameter(value shader, value name, value x, value y)
{
    SfShader_val(shader)->setParameter(String_val(name),
            Float_val(x), Float_val(y));
    return Val_unit;
}

CAMLextern_C value
caml_sfShader_setFloat3Parameter(
        value shader, value name, value x, value y, value z)
{
    SfShader_val(shader)->setParameter(String_val(name),
            Float_val(x), Float_val(y), Float_val(z));
    return Val_unit;
}

CAMLextern_C value
caml_sfShader_setFloat4Parameter_native(
        value shader, value name, value x, value y, value z, value w)
{
    SfShader_val(shader)->setParameter(String_val(name),
            Float_val(x), Float_val(y), Float_val(z), Float_val(w));
    return Val_unit;
}
CAMLextern_C value
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

/* TODO
enum Type
{
Vertex,  ///< Vertex shader
Fragment ///< Fragment (pixel) shader
};
Shader();
~Shader();
bool loadFromFile(const std::string& filename, Type type);
bool loadFromFile(const std::string& vertexShaderFilename, const std::string& fragmentShaderFilename);
bool loadFromMemory(const std::string& shader, Type type);
bool loadFromMemory(const std::string& vertexShader, const std::string& fragmentShader);
bool loadFromStream(InputStream& stream, Type type);
bool loadFromStream(InputStream& vertexShaderStream, InputStream& fragmentShaderStream);
void setParameter(const std::string& name, float x);
void setParameter(const std::string& name, float x, float y);
void setParameter(const std::string& name, float x, float y, float z);
void setParameter(const std::string& name, float x, float y, float z, float w);
void setParameter(const std::string& name, const Vector2f& vector);
void setParameter(const std::string& name, const Vector3f& vector);
void setParameter(const std::string& name, const Color& color);
void setParameter(const std::string& name, const sf::Transform& transform);
void setParameter(const std::string& name, const Texture& texture);
void setParameter(const std::string& name, CurrentTextureType);
static void bind(const Shader* shader);
static bool isAvailable();
*/

// vim: sw=4 sts=4 ts=4 et
