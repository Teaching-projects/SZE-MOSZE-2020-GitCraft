/**
 * \class HeroTextRenderer
 * 
 * \brief HeroTextRenderer class
 * 
 * \note This is the HeroTextRenderer class. This class helps to render from the point of the Hero.
 * 
 * \author team GitCraft
 * 
 * \date 2020.12.03. 11:17:23
*/
#ifndef HEROTEXTRENDERER_H
#define HEROTEXTRENDERER_H
#include <iostream>
#include "TextRenderer.h"
#include "Game.h"
class HeroTextRenderer : public TextRenderer{
public:
    /// One virtual render method to override.
    virtual void render(const Game& game/**< [in] The Game to render*/) const override;
};
#endif
