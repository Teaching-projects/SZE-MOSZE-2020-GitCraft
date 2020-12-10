/**
 * \class Renderer
 * 
 * \brief Renderer class
 * 
 * \note This is the Renderer class. This class is abstract and will help to render the game.
 * 
 * \author team GitCraft
 * 
 * \date 2020.12.03. 11:17:23
*/
#ifndef RENDERER_H
#define RENDERER_H
#include <iostream>
#include "Game.h"
#include "Map.h"
#include "Hero.h"
class Renderer{
public:
    /// One pure virtual method for rendering.
    virtual void render(const Game& game/**< [in] The Game to render*/) const = 0;
};
#endif