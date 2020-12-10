#include "Game.h"
#include "HeroTextRenderer.h"
#include "ObserverTextRenderer.h"

bool Game::test = false;

Game::~Game(){
	if (this->hero != nullptr)
		delete this->hero;
}

Hero* Game::getHero() const{
    return hero;
}

Map Game::getMap() const{
    return map;
}

std::vector<MonsterData> Game::getEnemies() const{
    return enemys;
}

std::vector<int> Game::getHeroLocation() const{
    return heroLocations;
}

void Game::setMap(Map map)
{
    if(gameStatus)
    {
        throw GameAlreadyStarted("Alredy has started");
    }
    else if(heroStatus || !enemys.empty())
    {
        throw AlreadyHasUnitsException("Alredy has Units");
    }

    this->map = map;
    mapStatus=true;
}

void Game::putHero(Hero hero, int x, int y){
    if(!mapStatus)
    {
        throw WrongIndexException("No map!");
    }
    else if(map.get(x,y)==Map::Wall)
    {
        throw OccupiedException("There is a wall!");
    }
    if(heroStatus)
    {
        throw AlreadyHasHeroException("Already has hero in the map!");
    }
    else if(gameStatus)
    {
        throw GameAlreadyStarted("Alredy has started");
    }
    else{
        this->hero=new Hero(hero);
        heroLocations.push_back(x);
        heroLocations.push_back(y);
        heroStatus=true;
    }
}

void Game::putMonster(Monster monster,int x, int y){
    if(!mapStatus)
    {
        throw WrongIndexException("No map!");
    }
    else if(map.get(x,y)==Map::Wall)
    {
        std::cout<<x<<":"<<y<<std::endl;
        throw OccupiedException("There is a wall monster!");
    }
    MonsterData nmonster = {monster,x,y};
    enemys.push_back(nmonster);
    
}

void Game::deleteHero()
{
    if(this->hero != nullptr)
    {
        delete this->hero;
    }
    this->hero=nullptr;
    heroLocations.clear();
}

void Game::fallenMonster(){
    for (long unsigned int i=0; i<=enemys.size(); i++)
    {
        if(!(enemys[i].monster.isAlive()))
        {
            enemys.erase(enemys.begin()+i);
        }
    }     
}

void Game::run()
{
    if(heroStatus && mapStatus && !enemys.empty() && !gameStatus)
    {
        gameStatus=true;
        std::cout<< "Following commands:"<<std::endl<<"\t"<<"east"<<"\t"<<"west"<<"\t"<<"north"<<"\t"<<"south"<<std::endl<<"You can only move to free space the Hero!"<<std::endl;
        printLightRadius();
        loop();
        if(enemys.empty())
        {
            std::cout<<hero->getName()<<" cleared the map!"<<std::endl;
        }
        else{
            std::cout<<"The hero died!"<<std::endl;
        }
    }
    else
    {
        throw NotInitializedException("Not initialized!");
    }
}
void Game::loop()
{
    
    std::string move="";
    std::vector<std::string> move_direction={"north", "east", "west", "south"};

     while(hero->isAlive() && !enemys.empty())
    {
        std::cout<<"Directions: ";
        if(test){
            std::ifstream inputfile("testinput.txt");
            while(getline(inputfile, move)){
                if(move == "east")
                {
                    Game::goTo(heroLocations[0],heroLocations[1]+1);
                }
                else if(move == "south")
                {
                    Game::goTo(heroLocations[0]+1,heroLocations[1]);
                }
                else if(move == "west")
                {
                    Game::goTo(heroLocations[0],heroLocations[1]-1);
                }
                else if(move == "north")
                {
                    Game::goTo(heroLocations[0]-1,heroLocations[1]);
                }
            }
            Game::test = false;
        }else{
            std::cin>>move;
            if(move == "east")
            {
                Game::goTo(heroLocations[0],heroLocations[1]+1);
            }
            else if(move == "south")
            {
                Game::goTo(heroLocations[0]+1,heroLocations[1]);
            }
            else if(move == "west")
            {
                Game::goTo(heroLocations[0],heroLocations[1]-1);
            }
            else if(move == "north")
            {
                Game::goTo(heroLocations[0]-1,heroLocations[1]);
            }
        }
        
    }
}

void Game::goTo(int x, int y){
    if(map.get(x,y) == Map::Wall){
        throw OccupiedException("There is a wall!");
    }
    for(long unsigned int i=0; i <= enemys.size(); i++)
    {
        if(hero->isAlive() && enemys[i].monster.isAlive() && (enemys[i].x==x)&& (enemys[i].y==y)){
            hero->fightTilDeath(enemys[i].monster);
            fallenMonster();
        }
    }
    heroLocations.clear();
    heroLocations.push_back(x);
    heroLocations.push_back(y);
    printLightRadius();
}

void Game::printLightRadius()
{
    HeroTextRenderer heroRender;
    heroRender.render(*this);
}

void Game::print()
{
    ObserverTextRenderer observer;
    observer.render(*this);
}

int Game::countMonsters(int x, int y) const{
    int count = 0;
    for(auto it=enemys.begin(); it!=enemys.end();it++){
        if((*it).x==x && (*it).y==y){
            count++;
        }
    }
    return count;
}