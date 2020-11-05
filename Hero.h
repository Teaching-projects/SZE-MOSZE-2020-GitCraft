/**
 * \class Hero
 * 
 * \brief Hero class
 * 
 * \note This class is the child of the Character class, and help manageing the fight between the monster and the hero
 * 
 * \author davidpokorni
 * 
 * \date 2020.11.04. 11:17:23
*/
#ifndef HERO_H
#define HERO_H
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include "JSON.h"
#include "character.h"
#include "Monster.h"

class Monster;

class Hero : public Character{
private:
    int level = 1;/// < This is the basic level of the hero
    int xp = 0;/// < This is the actual experience points variable of hero
    int exp_per_level;/// < This is the experience the hero needs for level up variable.
    int health_per_level;/// < This is the health the character gets after level up.
    int damage_bonus;/// < This is the value of the damage bonus.
    double cooldown_multiplier_per_level;/// < This is the attackspeed of the hero, in the levels.
public:
	/// This constructor is setting up the private variables.
	Hero(const std::string& name/** [in] The name of the character.*/, const int maxHp/** [in] The healt points of the character*/,
    const int dmg/** [in] The damage of the character*/, double attackcooldown/** [in] The attackspeed of the character*/,
    const int exp_per_level,const int health_per_level,const int damage_bonus, double cooldown_multiplier_per_level);
    /// It's a copy constructor for the Hero class.
    Hero(const Hero& hero);
    /// This constructor is return the evel of the hero.
    int getLevel(/**< [in] There's no parameter here.*/) const;
    /// This constructor is return the experience points of the hero.
    int getXp(/**< [in] There's no parameter here.*/) const;
    /// This constructor is set the experience points of the hero.
    void setXp(int mxp/** [in] It helps to set the experience.*/);
    /// This method help parsing the dates of the hero from json files
    static Hero parse(const std::string& fname/** [in] String reference name*/);
    /// This function manages the healt points of the characters in a fight.
    void attack(Character* c/** [in] This is the created character*/);
    /// This function manage the level ups of the characters.
    void levelup(/**< [in] There's no parameter here.*/);
    /// This method is makeing the fights between the characters. Using the attack function.
    void fightTilDeath(Monster& m/** [in] This is the character who is fighting*/);

};

#endif