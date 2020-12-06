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
	int actDmg = h->getPhysicalDamage() - defense;
	if(actDmg > 0)
    {
		if(health_points - actDmg > 0)
		{
			actDmg += h->getMagicalDamage();
			h->setXp(actDmg);
			if(health_points - actDmg > 0)
			{
				setHealthPoints(actDmg);
			}
			else
			{
				h->setXp(health_points);
				setToZeroHealth();
			}
		}
		else
    	{
			h->setXp(health_points);
        	setToZeroHealth();
    	}
    }
    h->levelup();
}