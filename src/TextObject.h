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
    TextObject(SDL_Renderer* renderer, std::string text);
    ~TextObject();

    bool loadFont();
    bool loadFromRenderedText( SDL_Renderer* renderer, TTF_Font* font, std::string textureText, SDL_Color textColor);
    //bool loadFromRenderedText( SDL_Renderer* renderer, TTF_Font* font, int number, SDL_Color textColor);
    void free();

    void render( SDL_Renderer* renderer, int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

    int getWidth() { return mWidth; }
    int getHeight() { return mHeight; }

private:
    SDL_Texture* mTexture;//Texture to render
    SDL_Surface* textSurface;//Surface to render on
    
    std::string mText; //Actual words/characters that will be displayed.
    
    int mWidth;
    int mHeight;

    TTF_Font* mFont;
    SDL_Renderer* mnoptrRenderer;
    //TTF_Font* font = NULL;
};