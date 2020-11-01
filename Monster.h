#ifndef MONSTER_H
#define MONSTER_H
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include "JSON.h"
#include "character.h"

class Monster : public Character{
public:
	Monster();
    Monster(const std::string& name, const int maxHp, const int dmg, double attackcooldown,int exp_per_level, int healt_per_level, int damage_bonus): Character(name, maxHp, dmg, attackcooldown),exp_per_level(exp_per_level), healt_per_level(healt_per_level),damage_bonus(damage_bonus){}
    static Monster parse(const std::string& charSheetName);
};

#endif