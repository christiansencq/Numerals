#include "MGlyph.h"

//Update PlaceValue vals.  Draw Zero, Draw Place Values
MGlyph::MGlyph() : MGlyph(10)
{
}

MGlyph::MGlyph(int number) : MGlyph(number, 100, 100)
{
}

MGlyph::MGlyph(int number, int xPos, int yPos) : mNumber(number), xOff(xPos), yOff(yPos)
{
    findPlaceValues(mNumBase);
}

void MGlyph::draw(SDL_Renderer* renderer) 
{
    mnoRenderer = renderer;

    //drawBkgd(mnoRenderer);
    drawPlaceValue(mnoRenderer, PlaceValues[0], PlaceValueY["ONES"]);
    drawPlaceValue(mnoRenderer, PlaceValues[1], PlaceValueY["TWENTIES"]);
    drawPlaceValue(mnoRenderer, PlaceValues[2], PlaceValueY["FOUR_HUNDREDS"]);
    drawPlaceValue(mnoRenderer, PlaceValues[3], PlaceValueY["EIGHT_THOUSANDS"]);
}

void MGlyph::findPlaceValues(int base)
{
    //Get the first four digits from breaking down the number by the base.
    //Determine a formula to calculate this?
    PlaceValues[0] = mNumber % base;
    PlaceValues[1] = (mNumber % (base*base)) / base; 
    PlaceValues[2] = (mNumber % (base*base*base)) / (base*base);
    PlaceValues[3] = mNumber / (base*base*base);
}

void MGlyph::drawBkgd(SDL_Renderer* renderer)
{

}

void MGlyph::drawPlaceValue(SDL_Renderer* renderer, int digit, int placeY) 
{
    int yPlacePos = placeY;
    int fives = digit / 5;
    int ones = digit % 5;

    if (fives == 0 && ones == 0)
    {
        drawZero(renderer, yPlacePos);
    }
    else 
    {
        for (int i = 1; i <= fives; i++)
        {
            //xOff is just center it within the element, y is to skip over the Ones.
            SDL_Rect fillRect {xOff + 10, yOff + yPlacePos + (i * 20) + 40, 80, 15};
            SDL_SetRenderDrawColor(mnoRenderer, 0xBB, 0xBB, 0xBB, 0xFF);
            SDL_RenderFillRect(mnoRenderer, &fillRect);
        }

        for (int i = 1; i <= ones; i++)
        {
            SDL_Rect fillRect {xOff + (20 * i), yOff + yPlacePos, 10, 10};
            SDL_SetRenderDrawColor(mnoRenderer, 0xBB, 0xFF, 0x33, 0xFF);
            SDL_RenderFillRect(mnoRenderer, &fillRect);
        }
    }
}

void MGlyph::drawZero(SDL_Renderer* renderer, int yPos)
{
    SDL_SetRenderDrawColor(mnoRenderer, 0x33, 0x1B, 0xEE, 0xFF);
    SDL_RenderDrawLine(mnoRenderer, 25 + xOff, 25 + yOff + yPos, 
                                    75 + xOff, 75 + yOff + yPos);
    SDL_RenderDrawLine(mnoRenderer,  25 + xOff, 75 + yOff + yPos, 
                                     75 + xOff, 25 + yOff + yPos);
}
