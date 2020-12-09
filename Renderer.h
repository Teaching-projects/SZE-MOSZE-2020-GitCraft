#ifndef RENDERER_H
#define RENDERER_H
#include <iostream>
#include "Game.h"
#include "Map.h"
#include "Hero.h"
class Renderer{
public:
    virtual void render(const Game& game) const = 0;
};
#endif