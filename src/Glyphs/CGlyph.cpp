#include "CGlyph.h"
#include <iostream>

//enum for the place values.

CGlyph::CGlyph() : CGlyph(2475) 
{
    std::cout << "number (NOT CALLED?) : " << mNum << std::endl;
}

CGlyph::CGlyph(int number, int xPos, int yPos) : mNum(number), xOff(xPos), yOff(yPos)
{
    findPlaceValues(10);
    std::cout << "number : " << mNum << std::endl;
}

CGlyph::CGlyph(int number) : CGlyph(number, 50, 50)
{
    std::cout << "number (NOT CALLED?) : " << mNum << std::endl;
}

void CGlyph::reset(int newnum)
{
    mNum = newnum;
    findPlaceValues(10);
}

void CGlyph::draw(SDL_Renderer* renderer)
{
    drawBkgd(renderer);

    drawPlaceValueCis(renderer, onesElement);
    drawPlaceValueCis(renderer, tensElement);
    drawPlaceValueCis(renderer, hundsElement);
    drawPlaceValueCis(renderer, thousElement);
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

void CGlyph::drawPlaceValueCis(SDL_Renderer* renderer, LineVec& glyph)
{
    SDL_SetRenderDrawColor(renderer, 0x00, 0xAA, 0xFF, 0xFF);

    for (size_t i = 0; i < glyph.size(); i++)
    {
        SDL_RenderDrawLine(renderer, glyph[i].GetP0().GetX() + xOff, glyph[i].GetP0().GetY() + yOff, glyph[i].GetP1().GetX() + xOff, glyph[i].GetP1().GetY() + yOff);
    }
}



void CGlyph::findPlaceValues(int base)
{
    std::cout << "mNum in find place values: " << mNum << std::endl;

    int thou = mNum / (base*base*base);    
    int hund = (mNum / (base * base)) % base;
    int tens = (mNum / base) % base;
    int ones = mNum % base;

    thousElement = digitToElem[thou];
    hundsElement = digitToElem[hund];
    tensElement = digitToElem[tens];
    onesElement = digitToElem[ones];

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