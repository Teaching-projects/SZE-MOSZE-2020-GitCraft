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
    struct Damage{
        int physical;///< This is the physical damage of the character.
        int magical;///< This is the magical damage of the character.
    };
    std::string name;///< This is the name of the character.
    int maxHp;///< This is the health points of the character.
    Damage damage;///< This is the damage of the character.
    int health_points;///< This is the actual health of the caracter.
    int defense;///<This is the defens points of the character
    double attack_cooldown;/// < This is the attackspeed.
public:
    Character(const std::string& name/**< [in] The name of the character.*/, const int maxHp/**< [in] The healt points of the character*/, const double attackcooldown=0/**< [in] The attackspeed of the character*/, const int physical=0/**< [in] The magical damage of the character*/,
    const int magical=0/**< [in] The magical damage of the character*/, const int defense=0/**< [in] The defense points of the character*/);
    /// This constructor is return the name of the character.
    std::string getName(/**< [in] There's no parameter here.*/) const;
    /// This getter is return the hp of the character.
    int getHealthPoints(/**< [in] There's no parameter here.*/) const;
    /// This getter is return the defense points of the character.
    int getDefense(/**< [in] There's no parameter here.*/) const;
    /// This getter is return the physical damage of the character.
    int getPhysicalDamage(/**< [in] There's no parameter here.*/) const;
    /// This getter is return the magical damage of the character.
    int getMagicalDamage(/**< [in] There's no parameter here.*/) const;
    /// This getter is return the actual hp of the character.
    int getMaxHealthPoints(/**< [in] There's no parameter here.*/) const;
    /// This getter is return the attackspeed of the character.
    double getAttackCoolDown(/**< [in] There's no parameter here.*/) const;
    /// This function is chechking the hp of the characters. If it's 0, return false, else true.
    bool isAlive(/**< [in] There's no parameter here.*/) const;
    /// This is a setter for the health points of the characters in the fights.
    void setHealthPoints(int value/** [in] Value of the hp reduce*/);
    /// This setter is set the healt to zero.
    void setToZeroHealth(/**< [in] There's no parameter here.*/);
    /// This is the friend of the class and overload the "cout".
    friend std::ostream & operator<<(std::ostream & os/** [in] This is an ostream referenc to the output*/, const Character &C/** [in] This is what the program print out*/);
};

#endif // !CHARACTER_H