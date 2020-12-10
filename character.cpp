#include "character.h"
#include <iostream>
#include <string>

Character::Character(const std::string& name, const int maxHp, const double attackcooldown, const int physical, const int magical,const int defense) : name(name), maxHp(maxHp), defense(defense),attack_cooldown(attackcooldown)
{
	damage.physical = physical;
	damage.magical = magical;
	this->health_points = maxHp;
}
std::string Character::getName() const
{
	return name;
}

int Character::getHealthPoints() const
{
	return health_points;
}

int Character::getDefense() const
{
	return defense;
}

int Character::getPhysicalDamage() const
{
	return damage.physical;
}

int Character::getMagicalDamage() const
{
	
	return damage.magical;
}

double Character::getAttackCoolDown() const
{
	return attack_cooldown;
}

int Character::getMaxHealthPoints() const
{
	return maxHp;
}

void Character::setHealthPoints(int value){
	health_points -=value;
}
void Character::setToZeroHealth(){
	health_points=0;
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

std::ostream & operator<<(std::ostream & os, const Character &C) {
	os << C.getName() << ": HP: " << C.getHealthPoints() << ", MaxHP:" << C.getMaxHealthPoints() << ", DMG: " << C.getPhysicalDamage() << ", XP: " <<'\n';
	return os;
}