#pragma once

#include <memory>
#include <string>

#include "State.h"
#include "App.h"
#include "TextObject.h"
#include "Glyphs/Glyph.h"
#include "Glyphs/CGlyph.h"
#include "Glyphs/KGlyph.h"
#include "Glyphs/MGlyph.h"


class NumeralState : public State
{
public:
    NumeralState(SDL_Renderer* renderer);
    ~NumeralState();

    void init() override {}
    void handleEvents() override;
    void update() override;
    void render(SDL_Renderer* renderer) override;

    void increment();
    void decrement();
    void newRandomNumber();
    void refreshNum();
    //Scaling vars  CHECK TO SEE IF CAN REMOVE
    static const int CGlyphscalar = 100;

private:
    int mNum;

    std::string mNumStr;
    std::unique_ptr<Glyph> mCisGlyph;
    std::unique_ptr<Glyph> mKakGlyph;
    std::unique_ptr<Glyph> mMayGlyph;

    //Text & Font
    std::unique_ptr<TextObject> mFontTexture = nullptr;

    SDL_Renderer* mnoptrrenderer;//Not owned, the renderer is from App; its passed in!
};