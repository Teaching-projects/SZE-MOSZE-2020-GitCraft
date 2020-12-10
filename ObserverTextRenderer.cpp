#include "ObserverTextRenderer.h"

void ObserverTextRenderer::render(const Game& game) const{
    Map map = game.getMap();
    Hero* hero = game.getHero();
    using std::cout;
    int monsterNumber;
    cout << TOP_LEFT;

    for(int i=0; i < map.getMaxLength(); i++){
        cout << HORIZONTAL;
    }

    cout << TOP_RIGHT<<'\n';

    for(int i=0; i<map.getHeight(); i++){
        cout << VERTICAL;
        for(int j=0; j<map.getRowLength(i); j++){
            monsterNumber = game.countMonsters(i,j);
            if(map.get(i,j)==Map::Wall){
                cout << WALL;
            }else if(monsterNumber>0){
                if(monsterNumber>1){
                    cout << MULTIPLEMONSTERS;
                }else{
                    cout << SINGLEMONSTER;
                }
            }
            else if(!game.getHeroLocation().empty() && game.getHeroLocation()[0]==i && game.getHeroLocation()[1]==j){
                cout << HERO;
            }
            else{
                cout << FREE;
            }
            
        }
        cout<<VERTICAL<<'\n';
    }

    cout << BOTTOM_LEFT;

    for (int i = 0; i < map.getMaxLength(); i++){
        cout << HORIZONTAL;
    }

    cout << BOTTOM_RIGHT<<'\n';
}