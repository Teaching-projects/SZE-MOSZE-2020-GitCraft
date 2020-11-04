#include "character.h"
#include <iostream>
#include <string>


Character::Character(const std::string& name, const int maxHp, const int dmg, double attackcooldown) : name(name), maxHp(maxHp), damage(dmg), attack_cooldown(attackcooldown)
{
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
	os << C.getName() << ": HP: " << C.getHealthPoints() << ", MaxHP:" << C.getMaxHealthPoints() << ", DMG: " << C.getDamage() << ", XP: " <<'\n';
	return os;
}