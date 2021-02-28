#include "MenuState.h"

MenuState::MenuState(SDL_Renderer* renderer) : mnoptrrenderer(renderer)
{

}

MenuState::~MenuState()
{

}

void MenuState::init()
{

}

void MenuState::handleEvents()
{

}

void MenuState::update()
{

}

void MenuState::render(SDL_Renderer* renderer)
{

}

bool MenuState::loadFont()
{
    bool success = true;

    mNumFont = TTF_OpenFont("LiberationSerif-Regular.ttf", 28);

    if ( mNumFont == nullptr)
    {
        printf("Failed to load the font %s\n", TTF_GetError());
        success = false;
    }
    return success;
}