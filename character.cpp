#include "character.h"
#include <iostream>
#include <fstream>
#include <string>

Character::Character(){
	this->name = "";
	this->hp = 0;
	this->dmg = 0;
	this->attackcooldown = 0.0;
}

Character::Character(const std::string name, int hp, int dmg, double attackcooldown) : name(name)
{
	this->hp = hp;
	this->dmg = dmg;
	this->attackcooldown=attackcooldown;
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
double Character::getAttackCoolDown() const
{
	return attackcooldown;
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
	if (c.isAlive())
	{
		c.hp = (c.hp - this->getDmg()) > 0 ? c.hp - this->getDmg() : 0;
	}
}
void Character::takeDamage(Character& player, Character& enemy)
{
	double t1=0.0;
	double t2=0.0;
	while(enemy.isAlive() && player.isAlive()){
		if(t1<t2){
			player.attack(enemy);
			if(!enemy.isAlive()){
				std::cout<<player.getName()<<" wins. Remaining HP: "<< player.getHp() + '\n';
			}
			t1+=player.attackcooldown;
		}
		else if(t1>t2){
			enemy.attack(player);
			if(!player.isAlive()){
				std::cout<<enemy.getName()<<" wins. Remaining HP: "<< enemy.getHp() + '\n';
			}
			t2+=enemy.attackcooldown;
		}
		else{
			player.attack(enemy);
			if (!enemy.isAlive()){
				std::cout<<player.getName()<<" wins. Remaining HP: "<< player.getHp() + '\n';
			}
			t1+=player.attackcooldown;
			enemy.attack(player);
			if(!player.isAlive()){
				std::cout<<enemy.getName()<<" wins. Remaining HP: "<< enemy.getHp() + '\n';
			}
			t2+=enemy.attackcooldown;
		}
	}
}

std::ostream & operator<<(std::ostream & os, const Character &C) {
	os << C.getName() << ": HP: " << C.getHp() << ", DMG: " << C.getDmg() << '\n';
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
			C.hp = std::stoi(line.substr(start + 2, length));
		}


		if ((C.getDmg() == 0) && (line.find("dmg") != std::string::npos))
		{
			int start = line.rfind(':');
			int length = line.length() - start - 1;
			C.dmg = std::stoi(line.substr(start + 2, length));
		}
		if ((C.getAttackCoolDown() == 0) && (line.find("atc") != std::string::npos))
		{
			int start = line.rfind(':');
			int length = line.length() - start - 1;
			C.dmg = std::stoi(line.substr(start + 2, length));
		}
	}
	charSheet.close();
}