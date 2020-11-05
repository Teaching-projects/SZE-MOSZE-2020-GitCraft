/**
 * \class Character
 * 
 * \brief Character class
 * 
 * \note This class is simulating the fight.
 * 
 * \author team GitCraft
 * 
 * \date 2020.10.8. 11:17:23
*/
#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include "JSON.h"

class Character{
protected:
    std::string name;///< This is the name of the character.
    int maxHp;///< This is the health points of the character.
    int damage;///< This is the damage of the character.
    int health_points;///< This is the actual health of the caracter.
    double attack_cooldown;/// < This is the attackspeed.
public:
    Character(const std::string& name/** [in] The name of the character.*/, const int maxHp/** [in] The healt points of the character*/, const int dmg/** [in] The damage of the character*/, double attackcooldown/** [in] The attackspeed of the character*/);
    /// This constructor is return the name of the character.
    std::string getName(/**< [in] There's no parameter here.*/) const;
    /// This constructor is return the hp of the character.
    int getHealthPoints(/**< [in] There's no parameter here.*/) const;
    /// This constructor is return the damage of the character.
    int getDamage(/**< [in] There's no parameter here.*/) const;
    /// This constructor is return the actual hp of the character.
    int getMaxHealthPoints(/**< [in] There's no parameter here.*/) const;
    /// This constructor is return the attackspeed of the character.
    double getAttackCoolDown(/**< [in] There's no parameter here.*/) const;
    /// This function is chechking the hp of the characters. If it's 0, return false, else true.
    bool isAlive(/**< [in] There's no parameter here.*/) const;
    void setHealthPoints(int value);
    void setToZeroHealth();
    /// This is the friend of the class and overload the "cout".
    friend std::ostream & operator<<(std::ostream & os/** [in] This is an ostream referenc to the output*/, const Character &C/** [in] This is what the program print out*/);
};

#endif // !CHARACTER_H