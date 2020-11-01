#include "Monster.h"

Monster::Monster(const std::string& name, const int maxHp, const int dmg, double attackcooldown,int exp_per_level, int healt_per_level, int damage_bonus): Character(name, maxHp, dmg, attackcooldown),exp_per_level(exp_per_level), healt_per_level(healt_per_level),damage_bonus(damage_bonus){}

Monster::Monster(){
    std::cout << "Monster done.\n";
}

Monster Monster::parse(const std::string& charSheetName)
{
	JSON attributes = JSON::loadInput(charSheetName);
    std::vector<std::string> controlHelper = {"name", "maxHp", "dmg", "attackcooldown", "exp_per_level", "healt_per_level", "damage_bonus"};
	for(auto it=controlHelper.begin(); it!=controlHelper.end(); it++){
        if(!attributes.count(*it)){
            throw "Invalid argument";
        }
    }
    return Monster(attributes.get<std::string>("name"),
    attributes.get<int>("maxHp"),
    attributes.get<int>("dmg"),
    attributes.get<double>("attackcooldown"),
    attributes.get<int>("exp_per_level"),
    attributes.get<int>("healt_per_level"),
    attributes.get<int>("damage_bonus"));
}