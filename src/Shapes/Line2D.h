#pragma once

#include "../Utils/Coords2D.h"

class Line2D
{
public:
    Line2D() : Line2D(Coords2D::Zero, Coords2D::Zero) {}
    Line2D(float x0, float y0, float x1, float y1) : mGVec0(Coords2D{x0, y0}), mGVec1(Coords2D{x1, y1}) {}
    Line2D(const Coords2D& p0, const Coords2D& p1) : mGVec0(p0), mGVec1(p1) {}

    inline const Coords2D& GetP0() const { return mGVec0; }
    inline const Coords2D& GetP1() const { return mGVec1; }

    inline void SetP0(const Coords2D& p0) { mGVec0 = p0; }
    inline void SetP1(const Coords2D& p1) { mGVec1 = p1; }

    bool operator==(const Line2D& line) const;

    float MinDistanceFrom(const Coords2D& p, bool limitToSegment = false) const;

    Coords2D Midpoint() const;
    float Slope() const;
    float Length() const;

    Line2D& horizFlip(int x0);
    Line2D& vertFlip(int y0);

private:
    Coords2D mGVec0; //Rename pt?
    Coords2D mGVec1;
};