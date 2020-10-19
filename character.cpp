#include "character.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

Character::Character(const std::string& name, const int maxHp, const int dmg, double attackcooldown) : name(name), maxHp(maxHp), dmg(dmg), attackcooldown(attackcooldown)
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
double Character::getAttackCoolDown() const
{
	return attackcooldown;
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
	if (player.getHp() - getDmg() > 0)
	{
		player.health -= getDmg();
		act_xp = getDmg();
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
	int level_c = getXp() / 100;
	for (int i = 0; i < level_c; i++)
	{
		level++;
		dmg += round(getDmg()*0.1);
		maxHp += round(getMaxHp()*0.1);
		health = maxHp;
		xp -= 100;
		attackcooldown-= round(getAttackCoolDown()*0.1);
	}
}
Character* Character::takeDamage(Character& player, Character& enemy)
{
	double t1=0.0;
	double t2=0.0;
	while(enemy.isAlive() && player.isAlive()){
		if(t1<t2){
			player.fight(enemy);
			if(!enemy.isAlive()){
				return &player;
			}
			t1+=player.attackcooldown;
		}
		else if(t1>t2){
			enemy.fight(player);
			if(!player.isAlive()){
				return &enemy;
			}
			t2+=enemy.attackcooldown;
		}
		else{
			player.fight(enemy);
			if (!enemy.isAlive()){
				return &player;
			}
			t1+=player.attackcooldown;
			enemy.fight(player);
			if(!player.isAlive()){
				return &enemy;
			}
			t2+=enemy.attackcooldown;
		}
	}
	return nullptr;
}

std::ostream & operator<<(std::ostream & os, const Character &C) {
	os << C.getName() << ": HP: " << C.getHp() << ", MaxHP:" << C.getMaxHp() << ", DMG: " << C.getDmg() << ", XP: " << C.getXp() << ", Level: " << C.getLevel() << '\n';
	return os;
}

Character* Character::parseUnit(const std::string charSheetName)
{
	std::fstream charSheet(charSheetName);
	std::map<std::string, std::string> attributes;
	if (charSheet.fail())
	{
		attributes = Parser::loadInput(charSheetName);
	}else{
		attributes = Parser::loadInput(charSheet);
		charSheet.close();
	}

	if(attributes.find("name")!=attributes.end() && attributes.find("health")!=attributes.end() && attributes.find("dmg")!=attributes.end()){
			return new Character(attributes["name"], std::stoi(attributes["health"]), std::stoi(attributes["dmg"]), std::stoi(attributes["atc"]));
	}
	else{
			throw "Invalid attributes in " + charSheetName + '\n';
	}
}