/**
 * \class Character
 * 
 * \brief Character class
 * 
 * \note This class is simulating the fight.
 * 
 * \author davidpokorni
 * 
 * \date 2020.10.8. 11:17:23
*/
#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <map>
#include <fstream>
#include "parser.h"

class Character{
private:
    std::string name;///< This is the name of the character.
    int maxHp;///< This is the health points of the character.
    int dmg;///< This is the damage of the character.
    int health;///< This is the actual health of the caracter.
    int xp = 0;///< This is the experience of the character.
	int level = 1;///< This is the level of the character.
    double attackcooldown;/// < This is the attackspeed.
    /// This function manage the level ups of the characters.
    void levelup(/**< [in] There's no parameter here.*/);
    /// This function manages the healt points of the characters in a fight.
    void attack(Character &c/** [in] This is the created character*/);
    /// This function is the fight method.
    void fight(Character &c/** [in] This is the created character*/);
public:
    /// This constructor is setting up the private variables.
    Character(const std::string& name/** [in] The name of the character.*/, const int hp/** [in] The healt points of the character*/, const int dmg/** [in] The damage of the character*/, double attackcooldown/** [in] The attackspeed of the character*/);
    /// This constructor is return the name of the character.
    std::string getName(/**< [in] There's no parameter here.*/) const;
    /// This constructor is return the hp of the character.
    int getHp(/**< [in] There's no parameter here.*/) const;
    /// This constructor is return the damage of the character.
    int getDmg(/**< [in] There's no parameter here.*/) const;
    /// This constructor is return the actual hp of the character.
    int getMaxHp(/**< [in] There's no parameter here.*/) const;
    /// This constructor is return with the experience of the character.
    int getXp(/**< [in] There's no parameter here.*/) const;
    /// This contructor return the level of the character.
	int getLevel(/**< [in] There's no parameter here.*/) const;
    /// This constructor is return the attackspeed of the character.
    double getAttackCoolDown(/**< [in] There's no parameter here.*/) const;
    /// This function is chechking the hp of the characters. If it's 0, return false, else true.
    bool isAlive(/**< [in] There's no parameter here.*/) const;
    /// This function is making the fights, using in main.
    Character* takeDamage(Character& player/** [in] This character is the first fighter*/, Character& enemy/** [in] This character is the second fighter*/);
	///This function manages the input datas from the .json file.
    static Character* parseUnit(const std::string charSheetName/** [in] This is the name of the file*/);
    /// This is the friend of the class and overload the "cout".
    friend std::ostream & operator<<(std::ostream & os/** [in] This is an ostream referenc to the output*/, const Character &C/** [in] This is what the program print out*/);
};

#endif // !CHARACTER_H
