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

int Character::getHealthPoints() const
{
	return health;
}

int Character::getDamage() const
{
	return dmg;
}
double Character::getAttackCoolDown() const
{
	return attackcooldown;
}

int Character::getMaxHealthPoints() const
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

int Character::getExpPerLevel() const
{
	return exp_per_level;
}

int Character::getHealthPerLevel() const
{
	return health_per_level;
}

int Character::getDamageBonus() const
{
	return damage_bonus;
}


bool Character::isAlive() const
{
	if (this->getHealthPoints() == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Character::fightTilDeath(Character &c)
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
	if (player.getHealthPoints() - getDamage() > 0)
	{
		player.health -= getDamage();
		act_xp = getDamage();
	}
	else
	{
		act_xp = player.getHealthPoints();
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
		dmg += round(getDamage()*0.1);
		maxHp += round(getMaxHealthPoints()*0.1);
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
			player.fightTilDeath(enemy);
			if(!enemy.isAlive()){
				return &player;
			}
			t1+=player.attackcooldown;
		}
		else if(t1>t2){
			enemy.fightTilDeath(player);
			if(!player.isAlive()){
				return &enemy;
			}
			t2+=enemy.attackcooldown;
		}
		else{
			player.fightTilDeath(enemy);
			if (!enemy.isAlive()){
				return &player;
			}
			t1+=player.attackcooldown;
			enemy.fightTilDeath(player);
			if(!player.isAlive()){
				return &enemy;
			}
			t2+=enemy.attackcooldown;
		}
	}
	return nullptr;
}

std::ostream & operator<<(std::ostream & os, const Character &C) {
	os << C.getName() << ": HP: " << C.getHealthPoints() << ", MaxHP:" << C.getMaxHealthPoints() << ", DMG: " << C.getDamage() << ", XP: " << C.getXp() << ", Level: " << C.getLevel() << '\n';
	return os;
}