#pragma once

#include <SDL2/SDL.h>
#include "../Shapes/Line2D.h"
#include <vector>
#include <array>

//Rename the sub-glyphs to 'Elements'
//I.E. if referring to one of four quadrants.

using LineVec = std::vector<Line2D>;

class CGlyph
{
public:
    CGlyph();
    CGlyph(int number);
    CGlyph(int number, int xPos, int yPos);

    void draw(SDL_Renderer* renderer);

    void drawElement(SDL_Renderer* renderer, std::vector<Line2D>& glyph);
    void drawBkgd(SDL_Renderer* renderer);

    LineVec digitToElement(int digit);
    void flipHoriz(LineVec& glyph);
    void flipVert(LineVec& glyph);

    void findPlaceValues();

private:
    int mNumber;

    //Drawing Params
    float mGlyphScalar = 100; 
    int xOff = 50;
    int yOff = 50;
    int xMidline = 100 + xOff;
    int yMidline = 150 + yOff;

    //Element Storage
    LineVec onesElement;    
    LineVec tensElement;
    LineVec hundsElement;
    LineVec thousElement;

    SDL_Renderer* mnoRenderer;//Rep with shared_ptr

    const std::array<LineVec, 10> digitToElem =
    {
        LineVec{Line2D(0, 0, 0, 0)},

        LineVec{Line2D{Coords2D{(1 * mGlyphScalar), (0 * mGlyphScalar)}, Coords2D{(2 * mGlyphScalar), (0 * mGlyphScalar)}}},

        LineVec{Line2D{Coords2D{(1 * mGlyphScalar), (1 * mGlyphScalar)}, Coords2D{(2 * mGlyphScalar), (1 * mGlyphScalar)}}},

        LineVec{Line2D{Coords2D{(1 * mGlyphScalar), (0 * mGlyphScalar)}, Coords2D{(2 * mGlyphScalar), (1 * mGlyphScalar)}}},

        LineVec{Line2D{Coords2D{(1 * mGlyphScalar), (1 * mGlyphScalar)}, Coords2D{(2 * mGlyphScalar), (0 * mGlyphScalar)}}},

        LineVec{Line2D{Coords2D{(2 * mGlyphScalar), (0 * mGlyphScalar)}, Coords2D{(1 * mGlyphScalar), (1 * mGlyphScalar)}}, 
                Line2D{Coords2D{(1 * mGlyphScalar), (0 * mGlyphScalar)}, Coords2D{(2 * mGlyphScalar), (0 * mGlyphScalar)}}},

        LineVec{Line2D{Coords2D{(2 * mGlyphScalar), (0 * mGlyphScalar)}, Coords2D{(2 * mGlyphScalar), (1 * mGlyphScalar)}}},

        LineVec{Line2D{Coords2D{(2 * mGlyphScalar), (0 * mGlyphScalar)}, Coords2D{(2 * mGlyphScalar), (1 * mGlyphScalar)}}, 
                Line2D{Coords2D{(1 * mGlyphScalar), (0 * mGlyphScalar)}, Coords2D{(2 * mGlyphScalar), (0 * mGlyphScalar)}}},

        LineVec{Line2D{Coords2D{(2 * mGlyphScalar), (0 * mGlyphScalar)}, Coords2D{(2 * mGlyphScalar), (1 * mGlyphScalar)}}, 
                 Line2D{Coords2D{(2 * mGlyphScalar), (1 * mGlyphScalar)}, Coords2D{(1 * mGlyphScalar), (1 * mGlyphScalar)}}},  

        LineVec{Line2D{Coords2D{(2 * mGlyphScalar), (0 * mGlyphScalar)}, Coords2D{(2 * mGlyphScalar), (1 * mGlyphScalar)}}, 
                 Line2D{Coords2D{(2 * mGlyphScalar), (1 * mGlyphScalar)}, Coords2D{(1 * mGlyphScalar), (1 * mGlyphScalar)}}, 
                 Line2D{Coords2D{(1 * mGlyphScalar), (0 * mGlyphScalar)}, Coords2D{(2 * mGlyphScalar), (0 * mGlyphScalar)}}}
    };
};