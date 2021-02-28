#include "TextObject.h"

TextObject::TextObject(SDL_Renderer* renderer, std::string text) : mnoptrRenderer(renderer), mText(text), mTexture(nullptr), textSurface(nullptr), mWidth(0), mHeight(0)
{
    //Load the font?
    loadFont();

}

TextObject::~TextObject()
{
    free();
}

bool TextObject::loadFont()
{
    bool success = true;

    mFont = TTF_OpenFont("LiberationSerif-Regular.ttf", 28);

    if ( mFont == nullptr )
    {
        printf("Failed to load the font %s\n", TTF_GetError());
        success = false;
    }
    else
    {
        SDL_Color textColor = { 0, 55, 0 };
        if ( !loadFromRenderedText(mnoptrRenderer, mFont, mText, textColor))
        {
            printf("Failed to render text texture!\n");
            success = false;
        }
        TTF_CloseFont(mFont);
        mFont = nullptr;
    }
    return success;
}

bool TextObject::loadFromRenderedText( SDL_Renderer* renderer, TTF_Font* font, std::string textureText, SDL_Color textColor )
{
    free();

    SDL_Surface* textSurface = TTF_RenderText_Solid( font, textureText.c_str(), textColor );

    if( textSurface == nullptr )
    {
        printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
    }
    else
    {
        //Create texture from surface Pixels
        mTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        if (mTexture == nullptr)
        {
            printf("Unable to create texture from rendered text! SDL_Error: %s\n", SDL_GetError());
        }
        else
        {
            mWidth = textSurface->w;
            mHeight = textSurface->h;
        }
        SDL_FreeSurface(textSurface);
    }
    return mTexture != nullptr;
}

// bool TextObject::loadFromRenderedText( SDL_Renderer* renderer, TTF_Font* font, int number, SDL_Color textColor )
// {
//     free();
//     //std::string numstr = std::to_string(number);
//     SDL_Surface* textSurface = TTF_RenderText_Solid( font, numstr.c_str(), textColor );

//     if( textSurface == nullptr )
//     {
//         printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
//     }
//     else
//     {
//         //Create texture from surface Pixels
//         mTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
//         if (mTexture == nullptr)
//         {
//             printf("Unable to create texture from rendered text! SDL_Error: %s\n", SDL_GetError());
//         }
//         else
//         {
//             mWidth = textSurface->w;
//             mHeight = textSurface->h;
//         }
//         SDL_FreeSurface(textSurface);
//     }
//     return mTexture != nullptr;
// }

void TextObject::free()
{
    if( mTexture != nullptr )
    {
        SDL_DestroyTexture(mTexture);
        mTexture = nullptr;
        mWidth = 0;
        mHeight = 0;
    }
}

void TextObject::render( SDL_Renderer* renderer, int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip )
{
    SDL_Rect renderQuad = { x, y, mWidth, mHeight };

    if(clip != nullptr)
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    SDL_RenderCopyEx(renderer, mTexture, clip, &renderQuad, angle, center, flip);
}