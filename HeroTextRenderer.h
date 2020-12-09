#ifndef HEROTEXTRENDERER_H
#define HEROTEXTRENDERER_H
#include <iostream>
#include "TextRenderer.h"
#include "Game.h"
class HeroTextRenderer : public TextRenderer{
public:
    virtual void render(const Game& game) const override;
};
#endif
