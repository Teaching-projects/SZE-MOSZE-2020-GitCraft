/**
 * \class TextRenderer
 * 
 * \brief TextRenderer class
 * 
 * \note This is the TextRenderer class. This class contains the Unicode characters.
 * 
 * \author team GitCraft
 * 
 * \date 2020.12.03. 11:17:23
*/
#ifndef TEXTRENDERER_H
#define TEXTRENDERER_H
#include <iostream>
#include "Renderer.h"
class TextRenderer : public Renderer{
protected:
    std::ostream& outPutWriter;
    const std::string TOP_LEFT = "\u2554";
    const std::string TOP_RIGHT = "\u2557";
    const std::string BOTTOM_LEFT = "\u255A";
    const std::string BOTTOM_RIGHT = "\u255D";
    const std::string HORIZONTAL = "\u2550\u2550";
    const std::string VERTICAL =  "\u2551";
    const std::string FREE = "\u2591\u2591";
    const std::string WALL = "\u2588\u2588"; 
    const std::string SINGLEMONSTER = "M\u2591";
    const std::string MULTIPLEMONSTERS = "MM";
    const std::string HERO = "\u2523\u252B";
    const std::string MONSTERONE = "\u004D\u2591";
    const std::string MONSTERTWO = "\u004D\u004D";
public:
    /// This default constructor is setting up out outPutStream.
    explicit TextRenderer(std::ostream& stream=std::cout/**< [in] The output stream default: std::cout*/) : outPutWriter(stream){}
    /// This method helps to change the outputStream.
    void setOutputStream(std::ostream& stream/**< [in] The stream change outPutStream to*/){
        stream.copyfmt(outPutWriter);
    }
    /// One pure virtual method for rendering.
    virtual void render(const Game& game/**< [in] The Game to render*/) const = 0;
};
#endif