#include "HeroTextRenderer.h"

void HeroTextRenderer::render(const Game& game) const{
    Map map = game.getMap();
    Hero* hero = game.getHero();
    int maxwidth = 0;             
    int maxheight=map.getHeight();                                     
    int x=game.getHeroLocation()[0];
    int y=game.getHeroLocation()[1];
    int x_min=x-hero->getLightRadius();
    int x_max=x+hero->getLightRadius();
    int y_min=y-hero->getLightRadius();
    int y_max=y+hero->getLightRadius();
    int width;
    for(int i = 0;i < map.getHeight();i++)
        if(maxwidth < map.getRowLength(i)) maxwidth = map.getRowLength(i);
    if(x_min<0)
    {
        x_min=0;
        width=x+hero->getLightRadius()+1;
    }
    else
    {
        width=x_max-x_min+1;
    }
    if(x_max>maxwidth) x_max=maxwidth;
    if(y_min<0)
    {
        y_min=0;
    }
    if(y_max>maxheight) y_max=maxheight;
    std::cout << TOP_LEFT;
    int w = 0;
    while(w < width && w  <= map.getRowLength(0))
    {
        std::cout << HORIZONTAL;
        w++;
    }
    
    std::cout << TOP_RIGHT << "\n";

    int monsterNumber;
    int i=y_min; 
    while(i <= y_max && i < map.getHeight())
    {
        std::cout << VERTICAL;
        int j=x_min;
        while(j <= x_max && j < map.getRowLength(i))
        {
            monsterNumber = game.countMonsters(i,j);
            if(map.get(i,j)==Map::Wall){
                std::cout << WALL;
            }else if(monsterNumber>0){
                if(monsterNumber>1){
                    std::cout << MULTIPLEMONSTERS;
                }else{
                    std::cout << SINGLEMONSTER;
                }
            }
            else if(!game.getHeroLocation().empty() && game.getHeroLocation()[0]==i && game.getHeroLocation()[1]==j){
                std::cout << HERO;
            }
            else{
                std::cout << FREE;
            }
            j++;
        }
        for(int m = map.getRowLength(i);m<=x_max;m++)
            std::cout << WALL;
        std::cout << VERTICAL << "\n";
        i++;
    }

    std::cout << BOTTOM_LEFT;
    
    for(int i = 0;i<w;i++)
        std::cout << HORIZONTAL;
    
    std::cout << BOTTOM_RIGHT << "\n";
}