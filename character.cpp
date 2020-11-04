#include "character.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>


Character::Character(const std::string& name, const int maxHp, const int dmg, double attackcooldown) : name(name), maxHp(maxHp), damage(dmg), attack_cooldown(attackcooldown)
{
	health_points = maxHp;
}
std::string Character::getName() const
{
	return name;
}

int Character::getHealthPoints() const
{
	return health_points;
}

int Character::getDamage() const
{
	return damage;
}
double Character::getAttackCoolDown() const
{
	return attack_cooldown;
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
		player.health_points -= getDamage();
		act_xp = getDamage();
	}
	else
	{
		act_xp = player.getHealthPoints();
		player.health_points = 0;
	}
	xp += act_xp;
}

void Character::levelup()
{
	int level_c = getXp() / 100;
	for (int i = 0; i < level_c; i++)
	{
		level++;
		damage += round(getDamage()*0.1);
		maxHp += round(getMaxHealthPoints()*0.1);
		health_points = maxHp;
		xp -= 100;
		attack_cooldown-= round(getAttackCoolDown()*0.1);
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
			t1+=player.attack_cooldown;
		}
		else if(t1>t2){
			enemy.fightTilDeath(player);
			if(!player.isAlive()){
				return &enemy;
			}
			t2+=enemy.attack_cooldown;
		}
		else{
			player.fightTilDeath(enemy);
			if (!enemy.isAlive()){
				return &player;
			}
			t1+=player.attack_cooldown;
			enemy.fightTilDeath(player);
			if(!player.isAlive()){
				return &enemy;
			}
			t2+=enemy.attack_cooldown;
		}
	}
	return nullptr;
}

std::ostream & operator<<(std::ostream & os, const Character &C) {
	os << C.getName() << ": HP: " << C.getHealthPoints() << ", MaxHP:" << C.getMaxHealthPoints() << ", DMG: " << C.getDamage() << ", XP: " << C.getXp() << ", Level: " << C.getLevel() << '\n';
	return os;
}