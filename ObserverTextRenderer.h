#ifndef OBSERVERTEXTRENDERER_H
#define OBSERVERTEXTRENDERER_H
#include <iostream>
#include "TextRenderer.h"
class ObserverTextRenderer : public TextRenderer{
public:
    virtual void render(const Game& game) const override;
};
#endif