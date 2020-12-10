/**
 * \class ObserverTextRenderer
 * 
 * \brief ObserverTextRenderer class
 * 
 * \note This is the ObserverTextRenderer class. This class helps to render the whole map.
 * 
 * \author team GitCraft
 * 
 * \date 2020.12.03. 11:17:23
*/
#ifndef OBSERVERTEXTRENDERER_H
#define OBSERVERTEXTRENDERER_H
#include <iostream>
#include "TextRenderer.h"
#include "Game.h"
class ObserverTextRenderer : public TextRenderer{
public:
    /// One pure virtual method for rendering.
    virtual void render(const Game& game/**< [in] The Game to render*/) const override;
};
#endif