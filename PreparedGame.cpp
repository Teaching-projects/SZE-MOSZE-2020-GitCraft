#include "PreparedGame.h"

PreparedGame::PreparedGame(const std::string &inputFile)
{
    using std::vector;
    using std::string;
    using std::to_string;
    JSON parsedAttr = JSON::parseFromFile(inputFile);
    bool successfullRead = true;
    vector<string> necessaryKeys{"map", "hero"};

    for (auto key : necessaryKeys)
    {
        if(!parsedAttr.count(key)){
			successfullRead = false;
			break;
		}
    }

    if(successfullRead){
        MarkedMap markedMap(parsedAttr.get<string>("map"));
        setMap(markedMap);
        mapStatus=true;

        Hero hero = Hero::parse(parsedAttr.get<string>("hero"));
        vector<int> hero_location = markedMap.getHeroPosition();
        putHero(hero, hero_location[0], hero_location[1]);
        heroStatus=true;

        for (int i = 1; i < 10; i++)
        {
            string monsterName = "monster-" + to_string(i);
            if (parsedAttr.count(monsterName))
            {
                vector<MonsterPos> mlocations = markedMap.getMonsterPositions('0'+i);
                for (auto location : mlocations)
                {
                    //std::cout << location.x <<":"<<location.y<< '\n';
                    Monster m = Monster::parse(parsedAttr.get<string>(monsterName));
                    putMonster(m, location.x, location.y);
                }
            }
        }
    }
}

void PreparedGame::run()
{
    Game::run();
}