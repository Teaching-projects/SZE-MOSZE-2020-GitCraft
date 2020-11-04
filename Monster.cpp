#include "Monster.h"

Monster::Monster(const std::string& name, const int maxHp, const int dmg, double attackcooldown): Character(name, maxHp, dmg, attackcooldown)
{
}

Monster Monster::parse(const std::string& charSheetName)
{
	JSON attributes = JSON::parseFromFile(charSheetName);
    std::vector<std::string> controlHelper {"name", "health_points", "damage", "attack_cooldown"};
	for(auto it=controlHelper.begin(); it!=controlHelper.end(); it++){
        if(!attributes.count(*it)){
            throw "Invalid argument";
        }
    }
    return Monster(attributes.get<std::string>("name"),
    attributes.get<int>("health_points"),
    attributes.get<int>("base_damage"),
    attributes.get<double>("base_attack_cooldown"));
}

void Monster::attack(Hero* h)
{
    int act_xp = 0;
	if (this->getHealthPoints() - getDamage() > 0)
	{
		this->setHealthPoints(getDamage());
		act_xp = getDamage();
	}
	else
	{
		act_xp = this->getHealthPoints();
		this->setToZeroHealth();
	}
	h->setXp(act_xp);
    h->levelup();
}