#include "character.h"
#include <iostream>
#include <fstream>
#include <cmath>

Character::Character() {
	this->name = "";
	this->maxHp = 0;
	this->dmg = 0;
	this->health = 0;
}

Character::Character(const std::string name, const int maxHp, const int dmg) : name(name), maxHp(maxHp), dmg(dmg)
{
	health = maxHp;
}

std::string Character::getName() const
{
	return name;
}

int Character::getHp() const
{
	return health;
}

int Character::getDmg() const
{
	return dmg;
}

int Character::getMaxHp() const
{
	return maxHp;
}

int Character::getXp() const
{
	return xp;
}

int Character::getLevel() const
{
	return level;
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

void Character::fight(Character &c)
{
	if (c.isAlive())
	{
		this->attack(c);
		this->levelup();
	}
}

void Character::attack(Character &player)
{
	int act_xp = 0;
	if (player.getHp() - this->getDmg() > 0)
	{
		player.health = player.getHp() - this->getDmg();
		act_xp = this->getDmg();
	}
	else
	{
		act_xp = player.getHp();
		player.health = 0;
	}
	xp += act_xp;
}

void Character::levelup()
{
	int level_c = this->getXp() / 100;
	for (int i = 0; i < level_c; i++)
	{
		level++;
		dmg += floor(getDmg()*0.1);
		maxHp += floor(maxHp*0.1);
		health = maxHp;
		xp -= 100;
	}
}

std::ostream & operator<<(std::ostream & os, const Character &C) {
	os << C.getName() << ": HP: " << C.getHp() << ", MaxHP:" << C.getMaxHp() << ", DMG: " << C.getDmg() << ", XP: " << C.getXp() << ", Level: " << C.getLevel() << '\n';
	return os;
}

void Character::parseUnit(Character &C, std::string charSheetName)
{
	std::fstream charSheet(charSheetName);

	if (charSheet.fail())
	{
		std::string error("Couldn't open file");
		throw std::runtime_error(error);
	}

	std::string line;

	while (!charSheet.eof())
	{
		std::getline(charSheet, line);

		if ((C.getName() == "") && (line.find("name") != std::string::npos))
		{
			int end = line.rfind('"');
			int start = end;
			bool find = true;
			while (find)
			{
				start--;
				if (line[start] == '"')
				{
					find = false;
				}
			}
			int length = end - start - 1;
			C.name = line.substr(start + 1, length);
		}

		if ((C.getHp() == 0) && (line.find("hp") != std::string::npos)) 
		{
			int start = line.rfind(':');
			int end = line.rfind(',');
			int length = end - start - 2;
			C.maxHp = std::stoi(line.substr(start + 2, length));
			C.health = std::stoi(line.substr(start + 2, length));
		}


		if ((C.getDmg() == 0) && (line.find("dmg") != std::string::npos))
		{
			int start = line.rfind(':');
			int length = line.length() - start - 1;
			C.dmg = std::stoi(line.substr(start + 2, length));
		}
	}
	charSheet.close();
}