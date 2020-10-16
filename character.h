#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <map>
#include <fstream>
#include "parser.h"

class Character{
private:
    std::string name;
	int maxHp;
    int dmg;
	int health;
	int xp = 0;
	int level = 1;
	void attack(Character &c);
	void levelup();

public:
    Character(const std::string& name, const int maxHp, const int dmg);
    std::string getName() const;
    int getHp() const;
    int getDmg() const;
	int getMaxHp() const;
	int getXp() const;
	int getLevel() const;
    bool isAlive() const;
	void fight(Character &c);
	static Character* parseUnit(const std::string charSheetName);
    friend std::ostream & operator<<(std::ostream & os, const Character &C);
};

#endif // !CHARACTER_H
