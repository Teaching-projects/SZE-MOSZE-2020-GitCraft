#include "Hero.h"

Hero::Hero(const std::string& name, const int maxHp, const int dmg, double attack_cooldown,int exp_per_level, int health_per_level, int damage_bonus, double cooldown_multiplier_per_level): Character(name, maxHp, dmg, attack_cooldown){
    this->exp_per_level=exp_per_level;
    this->health_per_level=health_per_level;
    this->damage_bonus=damage_bonus;
    this->cooldown_multiplier_per_level=cooldown_multiplier_per_level;
}


Hero::Hero(const Hero& hero){
    this->name=hero.name;
    this->maxHp = hero.maxHp;
    this->damage=hero.damage;
    this->attack_cooldown=hero.attack_cooldown;
}

Hero Hero::parse(std::string& charSheetName)
{
    std::cout << charSheetName << '\n';
	JSON attributes = JSON::parseFromFile(charSheetName);
    std::vector<std::string> controlHelper = {"name", "base_health_points", "base_damage", "base_attack_cooldown", "experience_per_level", "health_point_bonus_per_level", "damage_bonus_per_level", "cooldown_multiplier_per_level"};
	for(auto it=controlHelper.begin(); it!=controlHelper.end(); it++){
        if(!attributes.count(*it)){
            throw "Invalid argument";
        }
    }
    return Hero(attributes.get<std::string>("name"),
    attributes.get<int>("health_points"),
    attributes.get<int>("base_damage"),
    attributes.get<double>("base_attack_cooldown"),
    attributes.get<int>("experience_per_level"),
    attributes.get<int>("health_point_bonus_per_level"),
    attributes.get<int>("damage_bonus_per_level"),
    attributes.get<double>("cooldown_multiplier_per_level"));
}