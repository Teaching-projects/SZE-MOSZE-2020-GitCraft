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

class Character{
private:
    std::string name;///< This is the name of the character.
    int hp;///< This is the health points of the character.
    int dmg;///< This is the damage of the character.
    double attackcooldown;/// < This is the attackspeed.
    /// This function manages the healt points of the characters in a fight.
    void attack(Character &c/** [in] This is the created character*/);
public:
    /// This is a basic constructor and reset the variables.
    Character(/**< [in] There's no parameter here.*/);
    /// This constructor is setting up the private variables.
    Character(std::string name/** [in] The name of the character.*/, int hp/** [in] The healt points of the character*/, int dmg/** [in] The damage of the character*/, double attackcooldown/** [in] The attackspeed of the character*/);
    /// This constructor is return the name of the character.
    std::string getName(/**< [in] There's no parameter here.*/) const;
    /// This constructor is return the hp of the character.
    int getHp(/**< [in] There's no parameter here.*/) const;
    /// This constructor is return the damage of the character.
    int getDmg(/**< [in] There's no parameter here.*/) const;
    /// This constructor is return the attackspeed of the character.
    double getAttackCoolDown(/**< [in] There's no parameter here.*/) const;
    /// This function is chechking the hp of the characters. If it's 0, return false, else true.
    bool isAlive(/**< [in] There's no parameter here.*/) const;
    /// This function is making the fights, using in main.
    void takeDamage(Character& player/** [in] This character is the first fighter*/, Character& enemy/** [in] This character is the second fighter*/);
	///This function manages the input datas from the .json file.
    static void parseUnit(Character &C/** [in] This is the cerated character*/, std::string charSheetName/** [i] This is a string for the .json file name*/);
    /// This is the friend of the class and overload the "cout".
    friend std::ostream & operator<<(std::ostream & os/** [in] This is an ostream referenc to the output*/, const Character &C/** [in] This is what the program print out*/);
};

#endif // !CHARACTER_H
