#include "KGlyph.h"

KGlyph::KGlyph() : KGlyph(10)
{

}

KGlyph::KGlyph(int number, int xPos, int yPos) : mNumber(number), xOff(xPos), yOff(yPos)
{
    findPlaceValues(mNumBase);
}

KGlyph::KGlyph(int number) : KGlyph(number, 100, 100)
{

}


void KGlyph::reset(int newnum)
{
    mNumber = newnum;
    findPlaceValues(mNumBase);    
}

void KGlyph::draw(SDL_Renderer* renderer) 
{
    mnoRenderer = renderer;

    drawBkgd(mnoRenderer);
    drawPlaceValue(mnoRenderer, PlaceValues[0], PlaceValueX["ONES"]);
    drawPlaceValue(mnoRenderer, PlaceValues[1], PlaceValueX["TWENTIES"]);
    drawPlaceValue(mnoRenderer, PlaceValues[2], PlaceValueX["FOUR_HUNDREDS"]);
    drawPlaceValue(mnoRenderer, PlaceValues[3], PlaceValueX["EIGHT_THOUSANDS"]);
}

void KGlyph::findPlaceValues(int base)
{
    PlaceValues[0] = mNumber % base;
    PlaceValues[1] = (mNumber % (base*base)) / base; 
    PlaceValues[2] = (mNumber % (base*base*base)) / (base*base);
    PlaceValues[3] = mNumber / (base*base*base);
}

void KGlyph::drawBkgd(SDL_Renderer* renderer)
{
    SDL_Rect fillRect {xOff, yOff, xOff + mTotalXwidth, yOff + mTotalYheight};
    SDL_SetRenderDrawColor(mnoRenderer, 0xEE, 0x11, 0xEE, 0xFF);
    SDL_RenderFillRect(mnoRenderer, &fillRect);
}

void KGlyph::drawPlaceValue(SDL_Renderer* renderer, int digit, int placeX) 
{
    int xPlacePos = placeX;

    int fives = digit / 5;
    int ones = digit % 5;

    if (fives == 0 && ones == 0)
    {
        drawZero(renderer, xPlacePos);
    }
    else 
    {
        for (int i = 0; i < fives; i++)
        {
            SDL_SetRenderDrawColor(mnoRenderer, 0xBB, 0xBB, 0xBB, 0xFF);
            SDL_RenderDrawLine(mnoRenderer, (i % 2) * 100 + xPlacePos + xOff, 100 - (i * 25) + yOff, 
                                        ((i+1) % 2) * 100 + xPlacePos + xOff, 100 - ((i+1) * 25) + yOff);
        }

        for (int i = 0; i < ones; i++)
        {
            SDL_SetRenderDrawColor(mnoRenderer, 0xBB, 0xBB, 0xBB, 0xFF);
            SDL_RenderDrawLine(mnoRenderer, (i *25) + xPlacePos + xOff, 100 + ((i % 2) * 100) + yOff, 
                                        ((i+1) * 25) + xPlacePos + xOff, 100 + (((i+1) % 2) * 100) + yOff);
        }
    }
}

void KGlyph::drawZero(SDL_Renderer* renderer, int xPos)
{
    SDL_SetRenderDrawColor(mnoRenderer, 0x33, 0x1B, 0xEE, 0xFF);
    SDL_RenderDrawLine(mnoRenderer,  25 + xPos + xOff, 50 + yOff, 
                                     100 + xPos + xOff, 50 + yOff);
    SDL_RenderDrawLine(mnoRenderer, 100 + xPos + xOff, 50 + yOff, 
                                    25 + xPos + xOff, 200 + yOff);
    SDL_RenderDrawLine(mnoRenderer,  25 + xPos + xOff, 50 + yOff, 
                                     100 + xPos + xOff, 200 + yOff);
}
