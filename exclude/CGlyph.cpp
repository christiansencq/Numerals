#include "CGlyph.h"

//enum for the place values.

void CGlyph::draw(SDL_Renderer* renderer)
{

    SDL_Rect fillRect {0, 0, 200, 300};
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
    SDL_RenderFillRect(renderer, &fillRect);
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
    SDL_RenderDrawLine(renderer, 100, 0, 100, 300);

    int thousands = mNum / 1000;
    int hundreds = mNum / 100;
    int tens = mNum / 10;
    int ones = mNum % 10;
    
    std::vector<Line2D>::iterator it;

    if (thousands >= 1)
    {
        std::vector<Line2D> thouelem {element_add(thousands)};
        for (it = thouelem.begin(); it != thouelem.end(); it++)
        {
            elements.push_back(*it);
        }
    }

    if (hundreds >= 1)
    {
        std::vector<Line2D> hundelem {element_add(hundreds)};
        for (it = hundelem.begin(); it != hundelem.end(); it++)
        {
            elements.push_back(*it);
        }
    }

    if (tens >= 1)
    {
        std::vector<Line2D> tenselem {element_add(tens)};
        for (it = tenselem.begin(); it != tenselem.end(); it++)
        {
            elements.push_back(*it);
        }
    }

}

std::vector<Line2D> CGlyph::makeTens(std::vector<Line2D> lines)
{
    //Flips the lines' X axis.
    std::vector<Line2D> tensVec;
    std::vector<Line2D>::iterator it;

    for (it = lines.begin(); it != lines.end(); it++)
    {
        *it.horizFlip(xMidline);
    }

    return lines;
}

std::vector<Line2D> CGlyph::makeHunds(std::vector<Line2D> lines)
{
    //Flips the lines' X axis.
    std::vector<Line2D> hundsVec;
    std::vector<Line2D>::iterator it;


    for (it = lines.begin(); it != lines.end(); it++)
    {
        *it.vertFlip(yMidline);
        *it.horizFlip(xMidline);
    }

    return lines;
}

std::vector<Line2D> CGlyph::makeThous(std::vector<Line2D> lines)
{
    //Flips the lines' X axis.
    std::vector<Line2D> thousVec;
    std::vector<Line2D>::iterator it;

    for (it = lines.begin(); it != lines.end(); it++)
    {
        *it.vertFlip(yMidline);
    }

    return lines;
}


std::vector<Line2D> CGlyph::element_add(int digit)
{
    switch(digit)
    {
        case 1:
            return element1;
        case 2:
            return element2;
        case 3:
            return element3;
        case 4:
            return element4;
        case 5:
            return element5;
        case 6:
            return element6;
        case 7:
            return element7;
        case 8:
            return element8;
        case 9:
            return element9;
        default:
            return std::vector<Line2D> {Line2D(0, 0, 0, 0)};
    };
}