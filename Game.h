/**
 * \class Game
 * 
 * \brief Game class
 * 
 * \note This class manageing the game in a new map, where we can put our hero and some monsters to fight, then we fight. The result depends on our strength.
 * 
 * \author team GitCraft
 * 
 * \date 2020.12.03. 11:17:23
*/
#ifndef GAME_H
#define GAME_H
#include "Map.h"
#include "Hero.h"
#include "character.h"
#include "Monster.h"
#include <fstream>

/**
 * \struct Monster
 * \brief MonsterData struct
 * \note This structure for the Monsters. Contains the monster class instantiation and the coordinates where we put them.
*/
struct MonsterData{
    Monster monster;///< This is the monster class instantiation
    int x;///< This is the x coordinate, where we put the monster in the map.
    int y;///< This is the y coordinate, where we put the monster in the map.
};

class Game
{
private:
    Map map;///< This is the map class instantiation
    Hero* hero;/// < This is the hero class instantiation
    std::vector<MonsterData> enemys; /// < This vector contain the struct of monsters.
    std::vector<int> heroLocations;///< This vector is containes the coordinates, which means the current location of the hero.
    /// This method is manageing or moves on the map.
    void loop(/**< [in] There's no parameter here*/);
    ///This method is makeing the position changes of the hero on the map.
    void goTo(int x/**< [in] The x coordinate for the move*/, int y/**< [in] The y coordinate for the move*/);
    ///This method is cleaning the dead monsters on the map, after every figth.
    void fallenMonster(/**< [in] There's no parameter here*/);
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
    /// This default constructor is setting up the necessary variables for the game.
    Game(/**< [in] There's no parameter here*/): map(Map()), hero{nullptr},gameStatus(false),heroStatus(false),mapStatus(false){}
    /// This constructor is setting up the necessary variables for the game.
    explicit Game(const std::string& mapfilename/**< [in] The name of the map*/): map(mapfilename), hero{nullptr} ,gameStatus(false),heroStatus(false),mapStatus(false){}
    /// Simple destructor
    ~Game(/**< [in] There's no parameter here*/);
    /// This method is setting up the map, and checking the status of the game.
    void setMap(const Map& map/**< [in] Map class type*/);
    /// This method is put the hero to the map.
    void putHero(Hero hero/**< [in] Hero class type*/, int x/**< [in] The first coordinate where we put the hero*/, int y/**< [in] The second coordinate where we put the hero*/);
    void putMonster(Monster monster/**< [in] Monster class type*/,int x/**< [in] The first coordinate where we put a moster*/, int y/**< [in] The second coordinate where we put a moster*/);
    /// This method is running the game, in here we can add the destruction for the move.
    void run(/**< [in] There's no parameter here*/);
    ///This method is print out the current map, with the hero and the monsters.
    void print(/**< [in] There's no parameter here*/);
    /// This method is counting the monsters and support the print method.
    int countMonsters(int x/**< [in] The x coordinate of the monster*/, int y/**< [in] The y coordinate of the monster*/);
    ///This method is print out the current map, with the light radius hero and the monsters.
    void printLightRadius(/**< [in] There's no parameter here*/);
    static bool test;///< Simple static variable for the io test.
    bool gameStatus;/// < With this variable check the status of game.
    bool heroStatus;/// < With this variable check the status of hero.
    bool mapStatus;/// < With this variable check the status of map.
};

class OccupiedException : public std::runtime_error{ 
    public:
    explicit OccupiedException(const std::string& message) : std::runtime_error(message){}
};

class AlreadyHasHeroException : public std::runtime_error{
    public:
    explicit AlreadyHasHeroException(const std::string& message) : std::runtime_error(message){}
};

class AlreadyHasUnitsException : public std::runtime_error{
    public:
    explicit AlreadyHasUnitsException(const std::string& message) : std::runtime_error(message){}
};

class GameAlreadyStarted : public std::runtime_error{
    public:
    explicit GameAlreadyStarted(const std::string& message) : std::runtime_error(message){}
};

class NotInitializedException : public std::runtime_error{
    public:
    explicit NotInitializedException(const std::string& message) : std::runtime_error(message){}
};
#endif