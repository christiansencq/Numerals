#pragma once

#include <cmath>
#include <vector>

#include "../Utils/Utilities.h"
#include "../Utils/Coords2D.h"
#include "Line2D.h"
#include "../Constants.h"

class Circle
{
public:
    Circle(int center, int radius);
    ~Circle();

    void draw();

private:
    const unsigned int CIRCLE_SEGMENTS = 24;

    float centerPoint;
    float radius;

    std::vector<Coords2D> circlePoints;
    std::vector<Line2D> circleLines;
};