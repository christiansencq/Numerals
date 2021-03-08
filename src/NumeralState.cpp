#include "NumeralState.h"


NumeralState::NumeralState(SDL_Renderer* renderer) : mnoptrrenderer(renderer), mCisGlyph(nullptr), mKakGlyph(nullptr), mMayGlyph(nullptr)
{
    //mFontTexture = std::make_unique<FontText>();
    srand(time(0));
    mNum = rand() % 9999;
    mNumStr = std::to_string(mNum);

    mFontTexture = std::make_unique<TextObject>(renderer, mNumStr);

    mCisGlyph = std::make_unique<CGlyph>(mNum, 500, 100);
    mKakGlyph = std::make_unique<KGlyph>(mNum, 10, 10);
    mMayGlyph = std::make_unique<MGlyph>(mNum, 100, 500);
}

NumeralState::~NumeralState()
{
    mFontTexture->free();
    delete mTextColor;
    mTextColor = nullptr;
}

void NumeralState::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);//Assigns to event the value of the top event.

    switch (event.type)
    {
        case SDL_QUIT:
            App::Singleton().QuitApp();
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
                case SDLK_ESCAPE:
                    App::Singleton().QuitApp();
                    break;
                case SDLK_SPACE:
                    newRandomNumber();
                    break;
                case SDLK_a:
                    increment();
                    break;
                case SDLK_s:
                    decrement();
                    break;
                default:
                    break;
            }
        default:
            break;
    }
}

void NumeralState::increment()
{
    if (mNum < 9999 )
    {
        mNum += 1;
        refreshNum();
    }
}

void NumeralState::decrement()
{
    if (mNum > 0)
    {
        mNum -= 1;
        refreshNum();
    }
}

void NumeralState::newRandomNumber()
{
    //Randomly generate a new number.
    mNum = rand() % 9999;
    refreshNum();
}

void NumeralState::refreshNum()
{
    //Update all the graphical displays.
    mNumStr = std::to_string(mNum);

    //Update the TextDisplay.
    mFontTexture->setText(mNumStr);
    mFontTexture->loadFont();

    //Update the CGlyph, KGlyph, MGlyph displays
    mCisGlyph->reset(mNum);
    mKakGlyph->reset(mNum);
    mMayGlyph->reset(mNum);
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