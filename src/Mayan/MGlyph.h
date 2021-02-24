#pragma once

#include "SDL2/SDL.h"
#include "../Shapes/Line2D.h"

#include <iostream>
#include <vector>
#include <map>

using LineVec = std::vector<Line2D>;

class MGlyph
{
public:
    MGlyph();
    MGlyph(int number);
    MGlyph(int number, int xPos, int yPos);

    void draw(SDL_Renderer* renderer);

    void findPlaceValues(int base);
    void drawPlaceValue(SDL_Renderer* renderer, int digit, int placeY);
    void drawBkgd(SDL_Renderer* renderer);
    void drawZero(SDL_Renderer* renderer, int yPos);

    void makeBase(int base);


private:
    int mNumber;
    const int mNumBase = 20;

    int xOff = 50;
    int yOff = 400;

    int mTotalXWidth = 100;
    int mTotalYHeight = 360;

    std::vector<int> PlaceValues {0, 0, 0, 0};

    SDL_Renderer* mnoRenderer = nullptr;

    std::map<std::string, int> PlaceValueY
    {
        {"ONES", 270},
        {"TWENTIES", 180},
        {"FOUR_HUNDREDS", 90},
        {"EIGHT_THOUSANDS", 0}
    };
};