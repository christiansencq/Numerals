#pragma once

#include <string>
#include <cmath>
#include <stdio.h>
#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class TextObject 
{
public:
    TextObject();
    ~TextObject();

    bool loadFont();
    bool loadFromRenderedText( SDL_Renderer* renderer, TTF_Font* font, std::string textureText, SDL_Color textColor);
    bool loadFromRenderedText( SDL_Renderer* renderer, TTF_Font* font, int number, SDL_Color textColor);
    void free();


    void render( SDL_Renderer* renderer, int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

    int getWidth() { return mWidth; }
    int getHeight() { return mHeight; }

private:
    SDL_Texture* mTexture;
    SDL_Surface* textSurface;
    int mWidth;
    int mHeight;

    //TTF_Font* font = NULL;
};