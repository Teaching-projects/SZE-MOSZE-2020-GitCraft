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
    explicit Monster(const std::string& name, const int maxHp, int damage, double attack_cooldown);
    static Monster parse(const std::string& charSheetName);
};

#endif