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
    virtual ~Glyph() {}

    virtual void findPlaceValues(int base) = 0;

    virtual void draw(SDL_Renderer* renderer) = 0;
    virtual void drawBkgd(SDL_Renderer* renderer) = 0;
    virtual void drawZero(SDL_Renderer* renderer, int PosOffset) = 0;
    virtual void drawPlaceValue(SDL_Renderer* renderer, int digit, int PosOffset) {}
    virtual void drawPlaceValue(SDL_Renderer* renderer, LineVec& glyph) {}

// private:
//     int mNum;

//     int xOff; //Rename to position for clarity?
//     int yOff;

//     LineVec onesElement;
//     LineVec tensElement;
//     LineVec hundsElement;
//     LineVec thousElement;

//     const std::array<int, 4> PlaceValues {0, 0, 0, 0};
};