#include "SDL2/SDL.h"
#include "Line2D.h"
#include "GeoVec.h"
#include <vector>

class CGlyph
{
public:
    CGlyph() : CGlyph(42) {}
    CGlyph(int number) : mNum(number) {}

    void draw(SDL_Renderer* renderer);

    std::vector<Line2D> element_add(int digit);

    std::vector<Line2D> makeOnes(std::vector<Line2D> lines);
    std::vector<Line2D> makeTens(std::vector<Line2D> lines);
    std::vector<Line2D> makeHunds(std::vector<Line2D> lines);
    std::vector<Line2D> makeThous(std::vector<Line2D> lines);

private:
    int mNum;

    int xMidline = 100;
    int yMidline = 150;

    float mGlyphScalar = 100;
    int xOff = 100;
    int yOff = 0;

    std::vector<Line2D> elements;

    std::vector<Line2D> element1 {Line2D{Coords2D{(1 * mGlyphScalar) + xOff, (0 * mGlyphScalar) + yOff}, Coords2D{(2 * mGlyphScalar) + xOff, (0 * mGlyphScalar) + yOff}}};
    std::vector<Line2D> element2 {Line2D{Coords2D{(1 * mGlyphScalar) + xOff, (1 * mGlyphScalar) + yOff}, Coords2D{(2 * mGlyphScalar) + xOff, (1 * mGlyphScalar) + yOff}}};
    std::vector<Line2D> element3 {Line2D{Coords2D{(1 * mGlyphScalar) + xOff, (0 * mGlyphScalar) + yOff}, Coords2D{(2 * mGlyphScalar) + xOff, (1 * mGlyphScalar) + yOff}}};
    std::vector<Line2D> element4 {Line2D{Coords2D{(1 * mGlyphScalar) + xOff, (1 * mGlyphScalar) + yOff}, Coords2D{(2 * mGlyphScalar) + xOff, (0 * mGlyphScalar) + yOff}}};
    std::vector<Line2D> element5 {Line2D{Coords2D{(2 * mGlyphScalar) + xOff, (0 * mGlyphScalar) + yOff}, Coords2D{(1 * mGlyphScalar) + xOff, (1 * mGlyphScalar) + yOff}}, 
                                  Line2D{Coords2D{(1 * mGlyphScalar) + xOff, (0 * mGlyphScalar) + yOff}, Coords2D{(2 * mGlyphScalar) + xOff, (0 * mGlyphScalar) + yOff}}};
    std::vector<Line2D> element6 {Line2D{Coords2D{(2 * mGlyphScalar) + xOff, (0 * mGlyphScalar) + yOff}, Coords2D{(2 * mGlyphScalar) + xOff, (1 * mGlyphScalar) + yOff}}};
    std::vector<Line2D> element7 {Line2D{Coords2D{(2 * mGlyphScalar) + xOff, (0 * mGlyphScalar) + yOff}, Coords2D{(2 * mGlyphScalar) + xOff, (1 * mGlyphScalar) + yOff}}, 
                                  Line2D{Coords2D{(1 * mGlyphScalar) + xOff, (0 * mGlyphScalar) + yOff}, Coords2D{(2 * mGlyphScalar) + xOff, (0 * mGlyphScalar) + yOff}}};
    std::vector<Line2D> element8 {Line2D{Coords2D{(2 * mGlyphScalar) + xOff, (0 * mGlyphScalar) + yOff}, Coords2D{(2 * mGlyphScalar) + xOff, (1 * mGlyphScalar) + yOff}}, 
                                  Line2D{Coords2D{(2 * mGlyphScalar) + xOff, (1 * mGlyphScalar) + yOff}, Coords2D{(1 * mGlyphScalar) + xOff, (1 * mGlyphScalar) + yOff}}};
    std::vector<Line2D> element9 {Line2D{Coords2D{(2 * mGlyphScalar) + xOff, (0 * mGlyphScalar) + yOff}, Coords2D{(2 * mGlyphScalar) + xOff, (1 * mGlyphScalar) + yOff}}, 
                                  Line2D{Coords2D{(2 * mGlyphScalar) + xOff, (1 * mGlyphScalar) + yOff}, Coords2D{(1 * mGlyphScalar) + xOff, (1 * mGlyphScalar) + yOff}}, 
                                  Line2D{Coords2D{(1 * mGlyphScalar) + xOff, (0 * mGlyphScalar) + yOff}, Coords2D{(2 * mGlyphScalar) + xOff, (0 * mGlyphScalar) + yOff}}};

    std::vector<Line2D> onesPlace;
    std::vector<Line2D> tensPlace;
    std::vector<Line2D> hundsPlace;
    std::vector<Line2D> thousPlace;

};