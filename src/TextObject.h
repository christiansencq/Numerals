#pragma once

#include <sstream>
#include <string>
#include <cmath>
#include <stdio.h>
#include <memory>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class TextObject
{
public:
    TextObject(SDL_Renderer* renderer, std::string text);
    ~TextObject();

    bool loadFont();
    bool loadFromRenderedText( SDL_Renderer* renderer, TTF_Font* font, std::string textureText);

    void free();

    void render( SDL_Renderer* renderer, int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

    int getWidth() { return mWidth; }
    int getHeight() { return mHeight; }

    //Set color
    void setText(std::string text) { mText = text; }
    //void setText(std::stringstream text) { mText = text; }

private:
    SDL_Renderer* mnoptrRenderer;

    std::string mText; //Actual words/characters that will be displayed.

    SDL_Texture* mTexture;//Texture to render
    SDL_Surface* mTextSurface;//Surface to render on
    
    //std::stringstream mText;    
    
    int mWidth;
    int mHeight;

    SDL_Color* mColor;
    TTF_Font* mFont;
};