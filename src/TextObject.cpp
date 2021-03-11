#include "TextObject.h"

TextObject::TextObject(SDL_Renderer* renderer, std::string text) : mnoptrRenderer(renderer), mText(text), mTexture(nullptr), mTextSurface(nullptr), mWidth(0), mHeight(0)
{
    mColor = new SDL_Color{ 0, 55, 0 };
    //Load the font?
    loadFont();

}

TextObject::~TextObject()
{
    free();
    delete mColor;
    mColor = nullptr;
}

bool TextObject::loadFont()
{
    bool success = true;

    mFont = TTF_OpenFont("LiberationSerif-Regular.ttf", 28);

    if ( mFont == 0 || mFont == nullptr )
    {
        printf("Failed to load the font %s\n", TTF_GetError());
        success = false;
    }
    else
    {
        if ( !loadFromRenderedText(mnoptrRenderer, mFont, mText))
        {
            printf("Failed to render text texture!\n");
            success = false;
        }//Check here for mFont?
        TTF_CloseFont(mFont);
        mFont = nullptr;
    }
    return success;
}

bool TextObject::loadFromRenderedText( SDL_Renderer* renderer, TTF_Font* font, std::string textureText )
{
    free();

    if (font)
    {
        std::cout << "Font Exists!" << std::endl;
    }
    else
    {
        std::cout << " No font found..." << std::endl;
    }

    SDL_Surface* mTextSurface = TTF_RenderText_Solid( font, textureText.c_str(), *mColor );

    if( !mTextSurface )
    {
        printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
    }
    else
    {
        //Create texture from surface Pixels
        mTexture = SDL_CreateTextureFromSurface(renderer, mTextSurface);
        if (mTexture == nullptr)
        {
            printf("Unable to create texture from rendered text! SDL_Error: %s\n", SDL_GetError());
        }
        else
        {
            mWidth = mTextSurface->w;
            mHeight = mTextSurface->h;
        }
        SDL_FreeSurface(mTextSurface);
    }
    return mTexture != nullptr;
}



void TextObject::free()
{
    if( mTexture != nullptr )
    {
        SDL_DestroyTexture(mTexture);
        mTexture = nullptr;
        //mWidth = 0;
        //mHeight = 0;
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