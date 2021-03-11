#pragma once

#include "Glyph.h"

using LineVec = std::vector<Line2D>;

class Glyph;

class KGlyph : public Glyph
{
public:
    KGlyph();
    KGlyph(int number);
    KGlyph(int number, int xPos, int yPos);
    ~KGlyph() {}

    void reset(int newnum) override;

    void findPlaceValues(int base) override;

    void draw(SDL_Renderer* renderer) override;
    void drawBkgd(SDL_Renderer* renderer) override;
    void drawZero(SDL_Renderer* renderer, int xPos) override;

    void drawPlaceValue(SDL_Renderer* renderer, int digit, int placeY);


private:
    int mNumber;
    const int mNumBase = 20;

    int xOff = 50;
    int yOff = 50;

    int mTotalXwidth = 475;
    int mTotalYheight = 225;

    std::vector<int> PlaceValues {0, 0, 0, 0};

    SDL_Renderer* mnoRenderer = nullptr;//Shared Ptr change

    std::map<std::string, int> PlaceValueX
    {
        {"ONES", 375},
        {"TWENTIES", 250},
        {"FOUR_HUNDREDS", 125},
        {"EIGHT_THOUSANDS", 0}
    };
};