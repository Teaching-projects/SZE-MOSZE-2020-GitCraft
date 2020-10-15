#include "character.h"

Character::Character(){
	this->name = "";
	this->hp = 0;
	this->dmg = 0;
}

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
	if (c.isAlive())
	{
		c.hp = (c.hp - this->getDmg()) > 0 ? c.hp - this->getDmg() : 0;
	}
}

std::ostream & operator<<(std::ostream & os, const Character &C) {
	os << C.getName() << ": HP: " << C.getHp() << ", DMG: " << C.getDmg() << '\n';
	return os;
}

Character* Character::parseUnit(std::string charSheetName)
{
	std::fstream charSheet(charSheetName);

	if (charSheet.fail())
	{
		std::string error("Couldn't open file");
		throw std::runtime_error(error);
	}

	std::map<std::string, std::string> attributes = Parser::loadInput(charSheet);
	

	charSheet.close();

	if(attributes.find("name")!=attributes.end() && attributes.find("hp")!=attributes.end() && attributes.find("dmg")!=attributes.end()){
		return new Character(attributes["name"], std::stoi(attributes["hp"]), std::stoi(attributes["dmg"]));
	}else{
		throw "Invalid attributes in " + charSheetName + '\n';
	}
	
}