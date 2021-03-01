#pragma once

#include "SDL2/SDL.h"
#include "../Shapes/Line2D.h"
#include <vector>
#include <array>
#include <map>
#include <iostream>

using LineVec = std::vector<Line2D>;

class Glyph
{
public:
    virtual ~Glyph();

    virtual void findPlaceValues(int base);

    virtual void draw(SDL_Renderer* renderer);
    virtual void drawBkgd(SDL_Renderer* renderer);
    virtual void drawZero(SDL_Renderer* renderer, int PosOffset);
    virtual void drawPlaceValue(SDL_Renderer* renderer, int digit, int PosOffset);

private:
    int mNumber;

    int xOff; //Rename to position for clarity?
    int yOff;

    LineVec onesElement;
    LineVec tensElement;
    LineVec hundsElement;
    LineVec thousElement;

    const std::array<int, 4> PlaceValues {0, 0, 0, 0};
};