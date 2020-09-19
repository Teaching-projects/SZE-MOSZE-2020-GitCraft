#include "character.h"
#include <iostream>

Character::Character(const std::string name, int hp, int dmg) : name(name)
{
	this->hp = hp;
	this->dmg = dmg;
}

std::string Character::getName() const
{
	return name;
}

int Character::getHp() const
{
	return hp;
}

int Character::getDmg() const
{
	return dmg;
}

bool Character::isAlive() const
{
	if (this->getHp() == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Character::attack(Character &c)
{
	std::cout << this->getName() << "->" << c.getName() << '\n';
	if (c.isAlive())
	{
		c.hp = (c.hp - this->getDmg()) > 0 ? c.hp - this->getDmg() : 0;
	}
}

std::ostream & operator<<(std::ostream & os, const Character &C) {
	os << C.getName() << ": HP: " << C.getHp() << ", DMG: " << C.getDmg() << '\n';
	return os;
}
