#pragma once


#include "Glyph.h"

//Rename the sub-glyphs to 'Elements'
//I.E. if referring to one of four quadrants.

using LineVec = std::vector<Line2D>;

class Glyph;

class CGlyph : public Glyph
{
public:
    CGlyph();
    CGlyph(int number);
    CGlyph(int number, int xPos, int yPos);
    ~CGlyph() {}

    void findPlaceValues(int base) override;

    void reset(int newnum) override;

    void draw(SDL_Renderer* renderer) override;
    void drawBkgd(SDL_Renderer* renderer) override;
    void drawZero(SDL_Renderer* renderer, int PosOffset) override {} 
    void drawPlaceValueCis(SDL_Renderer* renderer, LineVec& glyph);

//    LineVec digitToElement(int digit);
    void orientPlaceValues() {}
    void flipHoriz(LineVec& glyph);
    void flipVert(LineVec& glyph);



private:
    int mNum;

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