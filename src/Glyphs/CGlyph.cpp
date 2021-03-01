#include "CGlyph.h"
#include <iostream>

//enum for the place values.

CGlyph::CGlyph() : CGlyph(2475) 
{
    std::cout << "number (NOT CALLED?) : " << mNum << std::endl;
}

CGlyph::CGlyph(int number, int xPos, int yPos) : mNum(number), xOff(xPos), yOff(yPos)
{
    findPlaceValues(mNum);
    std::cout << "number : " << mNum << std::endl;
}

CGlyph::CGlyph(int number) : CGlyph(number, 50, 50)
{
    std::cout << "number (NOT CALLED?) : " << mNum << std::endl;
}

void CGlyph::draw(SDL_Renderer* renderer)
{
    drawBkgd(renderer);

    drawPlaceValue(renderer, onesElement);
    drawPlaceValue(renderer, tensElement);
    drawPlaceValue(renderer, hundsElement);
    drawPlaceValue(renderer, thousElement);
}

void CGlyph::drawBkgd(SDL_Renderer* renderer)
{
    //Background Square
    SDL_Rect fillRect {0 + xOff, 0 + yOff, 200, 300};
    SDL_SetRenderDrawColor(renderer, 0xEE, 0xEE, 0xEE, 0xFF);
    SDL_RenderFillRect(renderer, &fillRect);

    //Midline.
    SDL_SetRenderDrawColor(renderer, 0x44, 0x44, 0x44, 0xFF);
    SDL_RenderDrawLine(renderer, 100 + xOff, 0 + yOff, 100 + xOff, 300 + yOff);
}

void CGlyph::drawPlaceValue(SDL_Renderer* renderer, LineVec& glyph)
{
    SDL_SetRenderDrawColor(renderer, 0x00, 0xAA, 0xFF, 0xFF);

    for (int i = 0; i < glyph.size(); i++)
    {
        SDL_RenderDrawLine(renderer, glyph[i].GetP0().GetX() + xOff, glyph[i].GetP0().GetY() + yOff, glyph[i].GetP1().GetX() + xOff, glyph[i].GetP1().GetY() + yOff);
    }
}

void CGlyph::findPlaceValues(int base)
{
    thousElement = digitToElem[mNum / base*base*base];
    hundsElement = digitToElem[(mNum / base*base) % base];
    tensElement = digitToElem[(mNum / base) % base];
    onesElement = digitToElem[mNum % base];

    flipHoriz(tensElement);
    flipVert(hundsElement);
    flipVert(thousElement);
    flipHoriz(thousElement); 
}

void CGlyph::flipHoriz(LineVec& glyph)
{
    LineVec newvec;

    for (auto& line : glyph)
    {
        newvec.push_back( Line2D{Coords2D{line.GetP0().GetX() - 2 * (line.GetP0().GetX() - 100), line.GetP0().GetY()}, 
                                 Coords2D{line.GetP1().GetX() - 2 * (line.GetP1().GetX() - 100), line.GetP1().GetY()}});
    }

    glyph.swap(newvec);
}

void CGlyph::flipVert(LineVec& glyph)
{
    LineVec newvec;

    for (auto& line : glyph)
    {
        newvec.push_back( Line2D{Coords2D{line.GetP0().GetX(), line.GetP0().GetY() - 2 * (line.GetP0().GetY() - 150)}, 
                                 Coords2D{line.GetP1().GetX(), line.GetP1().GetY() - 2 * (line.GetP1().GetY() - 150)}});
    }

    glyph.swap(newvec);
}