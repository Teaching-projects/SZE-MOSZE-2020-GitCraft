#ifndef MONSTER_H
#define MONSTER_H
#include <iostream>
#include <map>
#include <fstream>
#include "JSON.h"
#include "character.h"

class Monster : public Character{
public:
	Monster();
    static Monster parse(const std::string& charSheetName);
};

#endif