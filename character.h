#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <map>
#include <fstream>
#include "parser.h"

class Character{
private:
    std::string name;
    int hp;
    int dmg;
public:
    Character();
    Character(std::string name, int hp, int dmg);
    std::string getName() const;
    int getHp() const;
    int getDmg() const;
    bool isAlive() const;
    void attack(Character &c);
	static Character* parseUnit(std::string charSheetName);
    friend std::ostream & operator<<(std::ostream & os, const Character &C);
};

#endif // !CHARACTER_H
