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
    Monster(const std::string& name, const int maxHp, const int dmg, const double attackcooldown, const int exp_per_level, const int healt_per_level, const int damage_bonus);
    static Monster parse(const std::string& charSheetName);
};

#endif