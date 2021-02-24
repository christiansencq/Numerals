#include "NumeralState.h"

NumeralState::NumeralState(SDL_Renderer* renderer) : mnoptrrenderer(renderer)
{
    //mFontTexture = std::make_unique<FontText>();
    srand(time(0));
    int randnum = rand() % 9999 + 1;
    mNum = 340;
    randnum = 340;
    mFontTexture = new TextObject();

    mCisGlyph = std::make_unique<CGlyph>(randnum, 500, 100);

    mKakGlyph = std::make_unique<KGlyph>(randnum, 10, 10);

    mMayGlyph = std::make_unique<MGlyph>(randnum, 100, 500);

    if (!loadFont())
    {
        printf("Failed to load media!\n");
    }
}

NumeralState::~NumeralState()
{
    mFontTexture->free();
    delete mFontTexture;
    mFontTexture = nullptr;
}

bool NumeralState::loadFont()
{
    bool success = true;

    mNumFont = TTF_OpenFont("LiberationSerif-Regular.ttf", 28);

    if ( mNumFont == nullptr )
    {
        printf("Failed to load the font %s\n", TTF_GetError());
        success = false;
    }
    else
    {
        SDL_Color textColor = { 0, 55, 0 };
        if ( !mFontTexture->loadFromRenderedText(mnoptrrenderer, mNumFont, mNum, textColor))
        {
            printf("Failed to render text texture!\n");
            success = false;
        }
    }
    return success;
}

void NumeralState::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);//Assigns to event the value of the top event.

    switch (event.type)
    {
        case SDL_QUIT:
            App::Singleton().QuitApp();
    }
}

void NumeralState::update()
{
    
}

void NumeralState::render(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    SDL_RenderClear(renderer);

    mCisGlyph->draw(renderer);
    mKakGlyph->draw(renderer);
    mMayGlyph->draw(renderer);
    mFontTexture->render( renderer, (SCREEN_WIDTH - mFontTexture->getWidth()) * 3/4, (SCREEN_HEIGHT - mFontTexture->getHeight()) / 10);

    SDL_RenderPresent(renderer);

}