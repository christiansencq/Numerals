#pragma once

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

class State
{
public:
    virtual ~State() {}
    virtual void init() = 0;
    virtual void handleEvents() = 0;
    virtual void update() = 0;
    virtual void render(SDL_Renderer* renderer) = 0;

private:

};