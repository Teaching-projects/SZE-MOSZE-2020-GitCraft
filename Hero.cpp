#include "Hero.h"

Hero::Hero(const std::string& name, const int maxHp, int physical, int magical, const double attack_cooldown,
const int exp_per_level, const int health_per_level, const int physical_damage_bonus_per_level, const double cooldown_multiplier_per_level,
const int defense):
Character(name, maxHp, physical, magical, attack_cooldown, defense)
{   
    this->exp_per_level=exp_per_level;
    this->health_per_level=health_per_level;
    this->physical_damage_bonus_per_level=physical_damage_bonus_per_level;
    this->cooldown_multiplier_per_level=cooldown_multiplier_per_level;
}

Hero Hero::parse(const std::string& charSheetName) {
	std::vector <std::string> necessaryKeys {"experience_per_level","health_point_bonus_per_level", "physical_damage_bonus_per_level",
							 "cooldown_multiplier_per_level","name", "base_health_points", "physical", "magical", "base_attack_cooldown", "defense"};
	JSON parsedCreature = JSON::parseFromFile(charSheetName);
	bool successfullRead = true;
	for (auto key : necessaryKeys){
    	if(!parsedCreature.count(key)){
			successfullRead = false;
			break;
		}
	}
    
	if (successfullRead) 
	     return Hero(parsedCreature.get<std::string>("name"), 
			parsedCreature.get<int>("base_health_points"),
			parsedCreature.get<int>("physical"),
			parsedCreature.get<int>("magical"),
			parsedCreature.get<double>("base_attack_cooldown"),
			parsedCreature.get<int>("experience_per_level"),
			parsedCreature.get<int>("health_point_bonus_per_level"),
			parsedCreature.get<int>("physical_damage_bonus_per_level"),
			parsedCreature.get<double>("cooldown_multiplier_per_level"),
			parsedCreature.get<int>("defense"));
	else throw JSON::ParseException("Incorrect attributes in " + charSheetName + "!");
}
int Hero::getLevel() const
{
    return level;
}

int Hero::getXp() const
{
    return xp;
}

void Hero::setXp(int mxp)
{
    xp += mxp;
}

void Hero::attack(Character* c)
{
	if(health_points - c->getPhysicalDamage()> 0)
    {
        setHealthPoints(c->getPhysicalDamage());
    }
    else
    {
        setToZeroHealth();
    }
    this->levelup();
}

void Hero::levelup()
{
    while (xp >= exp_per_level)
	{
		level++;
		damage.physical += physical_damage_bonus_per_level;
		maxHp += health_per_level;
		health_points = maxHp;
		xp -= exp_per_level;
		attack_cooldown *= cooldown_multiplier_per_level;
	}
}

void Hero::fightTilDeath(Monster& m)
{
    bool player_last_hit=false;
    double time_player=this->getAttackCoolDown();
    double time_enemy=m.getAttackCoolDown();
	while(this->isAlive() && m.isAlive()){
		if(time_player==time_enemy){
            if(player_last_hit){
                m.attack(this);
				if(m.isAlive()){
					this->attack(&m);
                }
				time_player = this->getAttackCoolDown();
				time_enemy = m.getAttackCoolDown();
				player_last_hit = false;
            }
            else
			{
				this->attack(&m);
				if(this->isAlive()){
					m.attack(this);
                }
				time_player = this->getAttackCoolDown();
				time_enemy = m.getAttackCoolDown();
				player_last_hit = true;
			}
		}
        //time_player>time_enemy
        else if((time_player - time_enemy) < 0)
		{
			m.attack(this);
			time_enemy -= time_player;
			time_player = this->getAttackCoolDown();
		    player_last_hit = true;
		}
        else 
		{
			this->attack(&m);
			time_player -= time_enemy;
			time_enemy = m.getAttackCoolDown();
			player_last_hit = false;
		}
	}
}