#include "Line2D.h"


bool Line2D::operator==(const Line2D& line) const 
{
    return line.GetP0() == mGVec0 && line.GetP1() == mGVec1;
}

float Line2D::MinDistanceFrom(const Coords2D& p, bool limitToSegment) const { return 0.0f; }

Coords2D Line2D::Midpoint() const { return Coords2D::Zero; }
float Line2D::Slope() const { return 0.0f; }
float Line2D::Length() const { return 0.0f;}

Line2D& Line2D::horizFlip(int x0)
{
    mGVec0.SetX(-mGVec0.GetX() + (2*x0));
    mGVec1.SetX(-mGVec1.GetX() + (2*x0));

    return *this;
}

Line2D& Line2D::vertFlip(int y0)
{
    mGVec0.SetY(-mGVec0.GetY() + (2*y0));
    mGVec1.SetY(-mGVec1.GetY() + (2*y0));

    return *this;
}