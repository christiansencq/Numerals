#pragma once

#include "SDL2/SDL.h"
#include "../Shapes/Line2D.h"

#include <vector>
#include <map>

using LineVec = std::vector<Line2D>;

class KGlyph
{
public:
    KGlyph();
    KGlyph(int number);
    KGlyph(int number, int xPos, int yPos);

    void draw(SDL_Renderer* renderer);

    void findPlaceValues(int base);
    void drawPlaceValue(SDL_Renderer* renderer, int digit, int placeY);
    void drawBkgd(SDL_Renderer* renderer);
    void drawZero(SDL_Renderer* renderer, int xPos);

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