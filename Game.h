#ifndef GAME_H
#define GAME_H
#include "Map.h"
#include "Hero.h"
#include "character.h"
#include "Monster.h"


struct MonsterData{
    Monster monster;
    int x;
    int y;
};

class Game
{
private:
    Map map;
    Hero* hero;
    std::vector<MonsterData> enemys;
    std::vector<int> heroLocations;
    bool gameStatus;
    bool heroStatus;
    bool mapStatus;
    void loop();
    void goTo(int x, int y);
    void deleteHero();
    void fallenMonster();
    /*
    const std::string TOP_LEFT = "*";
    const std::string TOP_RIGHT = "*";
    const std::string BOTTOM_LEFT = "*";
    const std::string BOTTOM_RIGHT = "*";
    const std::string HORIZONTAL = "_";
    const std::string VERTICAL =  "|";
    const std::string FREE = " ";
    const std::string WALL = "[]"; 
    const std::string SINGLEMONSTER = "M";
    const std::string MULTIPLEMONSTERS = "MM";
    const std::string HERO = "H";
    const std::string MONSTERONE = "M";
    const std::string MONSTERTWO = "MM";
*/
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
    Game(): map(Map()), hero{nullptr},gameStatus(false),heroStatus(false),mapStatus(false){}
    Game(const std::string& mapfilename): map(mapfilename), hero{nullptr} ,gameStatus(false),heroStatus(false),mapStatus(false){}
    ~Game();
    void setMap(Map map);
    void putHero(Hero hero, int x, int y);
    void putMonster(Monster monster,int x, int y);
    void run();
    void print();
    int countMonsters(int x, int y);
};

class OccupiedException : public std::runtime_error{ 
    public:
    OccupiedException(const std::string& message) : std::runtime_error(message){}
};

class AlreadyHasHeroException : public std::runtime_error{
    public:
    AlreadyHasHeroException(const std::string& message) : std::runtime_error(message){}
};

class AlreadyHasUnitsException : public std::runtime_error{
    public:
    AlreadyHasUnitsException(const std::string& message) : std::runtime_error(message){}
};

class GameAlreadyStarted : public std::runtime_error{
    public:
    GameAlreadyStarted(const std::string& message) : std::runtime_error(message){}
};

class NotInitializedException : public std::runtime_error{
    public:
    NotInitializedException(const std::string& message) : std::runtime_error(message){}
};
#endif