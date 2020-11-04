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
    int level;
    int xp;
    int exp_per_level;/// < This is the experience the hero needs for level up variable.
    int health_per_level;/// < This is the health the character gets after level up.
    int damage_bonus;/// < This is the value of the damage bonus.
    double cooldown_multiplier_per_level;
public:
	/// This constructor is setting up the private variables.
	Hero(const std::string& name/** [in] The name of the character.*/, const int maxHp/** [in] The healt points of the character*/,
    const int dmg/** [in] The damage of the character*/, double attackcooldown/** [in] The attackspeed of the character*/,
    const int exp_per_level,const int health_per_level,const int damage_bonus, double cooldown_multiplier_per_level);
    /// It's a copy constructor for the Hero class.
    Hero(const Hero& hero);
    int getLevel() const;
    int getXp() const;
    void setXp(int mxp);
    static Hero parse(std::string& charSheetName);
    void fight(Character& c );
    void attack(Character& c);
    void levelup();
    void fightTilDeath(Monster& m);

};

#endif