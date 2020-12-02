#include "Monster.h"

Monster::Monster(const std::string& name, const int maxHp, const int physical, const int magical, const double attack_cooldown, const int defense) : Character(name, maxHp, physical, magical, attack_cooldown, defense){}

Monster Monster::parse(const std::string& charSheetName) {
	std::vector <std::string> necessaryKeys {"name", "health_points", "physical", "magical", "attack_cooldown", "defense"};
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
			parsedCreature.get<int>("physical"),
			parsedCreature.get<int>("magical"),
			parsedCreature.get<double>("attack_cooldown"),
			parsedCreature.get<int>("defense"));
	else throw JSON::ParseException("Incorrect attributes in " + charSheetName + "!");
}
void Monster::attack(Hero* h)
{
    if (health_points - h->getPhysicalDamage() > 0) {
		h->setXp(h->getPhysicalDamage());
		health_points -= h->getPhysicalDamage();
	}
	else { 
		h->setXp(health_points);
		this->setToZeroHealth();
	}
    h->levelup();
}