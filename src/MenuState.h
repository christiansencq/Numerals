#pragma once

#include <memory>

#include "TextObject.h"
#include "State.h"
#include "App.h"

class MenuState : public State
{
public:
    MenuState(SDL_Renderer* renderer);
    ~MenuState();

    void init() override;
    void handleEvents() override;
    void update() override;
    void render(SDL_Renderer* renderer) override;

    bool loadFont();

private:
    int mNum;

    TTF_Font* mNumFont = nullptr;
    TextObject* mFontTexture = nullptr;


    SDL_Renderer* mnoptrrenderer;
};