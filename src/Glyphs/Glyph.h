#pragma once

#include "SDL2/SDL.h"
#include "../Shapes/Line2D.h"
#include <vector>
#include <array>

using LineVec = std::vector<Line2D>;

class Glyph
{
public:
    virtual ~Glyph();

    virtual void draw(SDL_Renderer* renderer);
    virtual void findPlaceValues(int base);


private:
    int mNumber;

    int xOff; //Rename to position for clarity?
    int yOff;

    LineVec FirstElement;
    LineVec SecondElement;
    LineVec ThirdElement;
    LineVec FourthElement;

    const std::array<int, 4> PlaceValues {0, 0, 0, 0};
};