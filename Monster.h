/**
 * \class Monster
 * 
 * \brief Monster class
 * 
 * \note This class is the child of the Character class, and help manageing the fight between the monster and the hero.
 * 
 * \author davidpokorni
 * 
 * \date 2020.11.04. 11:17:23
*/
#ifndef MONSTER_H
#define MONSTER_H
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include "JSON.h"
#include "character.h"
#include "Hero.h"

class Hero;

class Monster : public Character{
public:
    /// This is the constructor of the Monster class
    Monster(const std::string& name/** [in] The name of the character.*/, const int maxHp/** [in] The healt points of the character*/, int damage/** [in] The damage of the character*/, double attack_cooldown/** [in] The attackspeed of the character*/);
    /// This method help parsing the dates of the hero from json files.
    static Monster parse(const std::string& charSheetName/** [in] String reference name*/);
    /// This function manages the healt points of the characters in a fight.
    void attack(Hero* h/** [in] This is the created character*/);
};

#endif