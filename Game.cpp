#include "Game.h"

Game::~Game(){
	if (this->hero != nullptr)
		delete this->hero;
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
        throw OccupiedException("There is a wall!");
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
    for (int i=0; i<=enemys.size(); i++)
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
        std::cin>>move;
        if(move == "east")
        {
            Game::goTo(heroLocations[0]+1,heroLocations[1]);
        }
        else if(move == "south")
        {
            Game::goTo(heroLocations[0],heroLocations[1]+1);
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

void Game::goTo(int x, int y){
    if(map.get(x,y) == Map::Wall){
        throw OccupiedException("There is a wall!");
    }
    for(int i=0; i <= enemys.size(); i++)
    {
        if(hero->isAlive() && enemys[i].monster.isAlive() && (enemys[i].x==x)&& (enemys[i].y==y)){
            hero->fightTilDeath(enemys[i].monster);
            fallenMonster();
        }
    }
    heroLocations.clear();
    heroLocations.push_back(x);
    heroLocations.push_back(y);
    print();
}

void Game::print()
{
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
            monsterNumber = countMonsters(i,j);
            if(map.get(i,j)==Map::Wall){
                cout << WALL;
            }else if(monsterNumber>0){
                if(monsterNumber>1){
                    cout << MULTIPLEMONSTERS;
                }else{
                    cout << SINGLEMONSTER;
                }
            }
            else if(!heroLocations.empty() && heroLocations[0]==i && heroLocations[1]==j){
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

int Game::countMonsters(int x, int y){
    int count = 0;
    for(auto it=enemys.begin(); it!=enemys.end();it++){
        if((*it).x==x && (*it).y==y){
            count++;
        }
    }
    return count;
}