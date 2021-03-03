#pragma once


#include "Glyph.h"


using LineVec = std::vector<Line2D>;

class Glyph;

class MGlyph : public Glyph
{
public:
    MGlyph();
    MGlyph(int number);
    MGlyph(int number, int xPos, int yPos);

    ~MGlyph() {}

    void findPlaceValues(int base) override;

    void draw(SDL_Renderer* renderer) override;
    void drawBkgd(SDL_Renderer* renderer) override;
    void drawZero(SDL_Renderer* renderer, int yPos) override;
    void drawPlaceValue(SDL_Renderer* renderer, int digit, int placeY);

private:
    int mNumber;
    const int mNumBase = 20;

    int xOff = 50;
    int yOff = 250;

    int mTotalXWidth = 100;
    int mTotalYHeight = 400;

    std::vector<int> PlaceValues {0, 0, 0, 0};

    SDL_Renderer* mnoRenderer = nullptr;

    std::map<std::string, int> PlaceValueY
    {
        {"ONES", 300},
        {"TWENTIES", 200},
        {"FOUR_HUNDREDS", 100},
        {"EIGHT_THOUSANDS", 0}
    };
};