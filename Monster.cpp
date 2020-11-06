#include "Monster.h"

Monster::Monster(const std::string& name, const int maxHp, const int dmg, double attackcooldown): Character(name, maxHp, dmg, attackcooldown)
{
}

Monster Monster::parse(const std::string& charSheetName) {
	std::vector <std::string> necessaryKeys {"name", "health_points", "damage", "attack_cooldown"};
	JSON parsedCreature = JSON::parseFromFile(charSheetName);
	bool successfullRead = true;
	for (auto key : necessaryKeys){
    	if(!parsedCreature.count(key)){
			successfullRead = false;
			break;
		}
	}

	if (successfullRead) 
	    return Monster(parsedCreature.get<std::string>("name"), 
			parsedCreature.get<int>("health_points"),
			parsedCreature.get<int>("damage"),
			parsedCreature.get<double>("attack_cooldown"));
	else throw JSON::ParseException("Incorrect attributes in " + charSheetName + "!");
}
void Monster::attack(Hero* h)
{
    if (health_points - h->getDamage() > 0) {
		h->setXp(h->getDamage());
		health_points -= h->getDamage();
	}
	else { 
		h->setXp(health_points);
		this->setToZeroHealth();
	}
    h->levelup();
}