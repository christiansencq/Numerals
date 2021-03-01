#pragma once

#include <memory>
#include <string>

#include "Glyphs/CGlyph.h"
#include "Glyphs/KGlyph.h"
#include "Glyphs/MGlyph.h"
#include "State.h"
#include "App.h"
#include "TextObject.h"

class NumeralState : public State
{
public:
    NumeralState(SDL_Renderer* renderer);
    ~NumeralState();

    void init() override {}
    void handleEvents() override;
    void update() override;
    void render(SDL_Renderer* renderer) override;

    bool loadFont();

    //Scaling vars
    static const int CGlyphscalar = 100;

private:
    int mNum;
    std::string mNumStr;
    std::unique_ptr<CGlyph> mCisGlyph;
    std::unique_ptr<KGlyph> mKakGlyph;
    std::unique_ptr<MGlyph> mMayGlyph;

    //Text & Font
    TTF_Font* mNumFont = nullptr;
//    TextObject* mFontTexture = nullptr;
    std::unique_ptr<TextObject> mFontTexture = nullptr;

    //Positional vars.?? IDK what this is.
    int xPos;
    int yPos;

    SDL_Renderer* mnoptrrenderer;//Not owned, the renderer is from App
};