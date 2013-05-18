#include <sfeMovie/Movie.hpp>

#include "SFRenderWindow_stub.hpp"

extern "C" {
#define CAML_NAME_SPACE

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

#define Val_sfeMovie(emv) ((value)(emv))
#define SfeMovie_val(emv) ((sfe::Movie *)(emv))

static value
Val_sfeStatus(sfe::Movie::Status status)
{
    switch (status)
    {
        case sfe::Movie::Stopped: return Val_int(0);
        case sfe::Movie::Paused:  return Val_int(1);
        case sfe::Movie::Playing: return Val_int(2);
        default: caml_failwith("SFEMovie.status");
    }
    caml_failwith("SFEMovie.status");
}

CAMLextern_C value
caml_sfeMovie_create(value unit)
{
    sfe::Movie *movie = new sfe::Movie;
    return Val_sfeMovie(movie);
}

CAMLextern_C value
caml_sfeMovie_openFromFile(value movie, value filename)
{
    if (!SfeMovie_val(movie)->openFromFile(String_val(filename)))
        caml_failwith("SFEMovie.openFromFile");

    return Val_unit;
}

CAMLextern_C value
caml_sfeMovie_play(value movie)
{
    SfeMovie_val(movie)->play();
    return Val_unit;
}

CAMLextern_C value
caml_sfeMovie_pause(value movie)
{
    SfeMovie_val(movie)->pause();
    return Val_unit;
}

CAMLextern_C value
caml_sfeMovie_stop(value movie)
{
    SfeMovie_val(movie)->stop();
    return Val_unit;
}

CAMLextern_C value
caml_sfeMovie_draw(value window, value movie)
{
    SfRenderWindow_val(window)->draw(*SfeMovie_val(movie));
    return Val_unit;
}

CAMLextern_C value
caml_sfeMovie_resizeToFrame_native(
        value movie, value x, value y, value width, value height, value unit)
{
    SfeMovie_val(movie)->resizeToFrame(
            Int_val(x), Int_val(y), Int_val(width), Int_val(height));
    return Val_unit;
}
CAMLextern_C value
caml_sfeMovie_resizeToFrame_bytecode(value *argv, int argn)
{
    return caml_sfeMovie_resizeToFrame_native(
            argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}
// TODO
//  void resizeToFrame(int x, int y, int width, int height, bool preserveRatio = true);
//  void resizeToFrame(sf::IntRect frame, bool preserveRatio = true);

CAMLextern_C value
caml_sfeMovie_getStatus(value movie)
{
    sfe::Movie::Status st = SfeMovie_val(movie)->getStatus();
    return Val_sfeStatus(st);
}

/*
CAMLextern_C value
caml_sfeMovie_(value movie)
{
    SfeMovie_val(movie)->
    return Val_;
}
*/

/* TODO

    bool hasVideoTrack(void) const;
    bool hasAudioTrack(void) const;
    void setVolume(float volume);
    float getVolume(void) const;
    sf::Time getDuration(void) const;
    sf::Vector2i getSize(void) const;
    float getFramerate(void) const;
    unsigned int getSampleRate(void) const;
    unsigned int getChannelCount(void) const;
    //void SetPlayingOffset(sf::Uint32 position);
    sf::Time getPlayingOffset(void) const;
    const sf::Texture& getCurrentFrame(void) const;
    //void SetLoop(bool Loop);
    //bool GetLoop() const;
    static void useDebugMessages(bool flag = true);
    static bool usesDebugMessages(void);
*/

// vim: sw=4 sts=4 ts=4 et
