#include "Hero.h"

Hero::Hero(const std::string& name, const int maxHp, int physical, int magical, const double attack_cooldown,
const int exp_per_level, const int health_per_level, const int physical_damage_bonus_per_level, const double cooldown_multiplier_per_level,
const int defense, const int light_radius, const int light_radius_per_level):
Character(name, maxHp, attack_cooldown, physical, magical,  defense)
{   
    this->exp_per_level=exp_per_level;
    this->health_per_level=health_per_level;
    this->physical_damage_bonus_per_level=physical_damage_bonus_per_level;
    this->cooldown_multiplier_per_level=cooldown_multiplier_per_level;
    this->light_radius=light_radius;
    this->light_radius_per_level=light_radius_per_level;
}

Hero Hero::parse(const std::string& charSheetName) {
	std::vector <std::string> necessaryKeys {"experience_per_level","health_point_bonus_per_level", "physical_damage_bonus_per_level",
							 "cooldown_multiplier_per_level","name", "base_health_points", "physical", "magical", "base_attack_cooldown", "defense",
							 "light_radius", "light_radius_per_level"};
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
			parsedCreature.get<int>("defense"),
			parsedCreature.get<int>("light_radius"),
			parsedCreature.get<int>("light_radius_per_level"));
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

int Hero::getLightRadius() const
{
    return light_radius;
}

void Hero::setXp(int mxp)
{
    xp += mxp;
}

void Hero::attack(Character* c)
{
	int actDmg = c->getPhysicalDamage()-defense;
	if(actDmg > 0)
    {
		if(health_points - actDmg > 0)
		{
			actDmg += c->getMagicalDamage();
			if(health_points - actDmg > 0)
			{
				setHealthPoints(actDmg);
			}
			else
			{
				setToZeroHealth();
			}
		}
		else
    	{
        	setToZeroHealth();
    	}
    }
    this->levelup();
}

void Hero::levelup()
{
    while (xp >= exp_per_level)
	{
		level++;
		this->damage.physical += physical_damage_bonus_per_level;
		this->damage.magical  += magical_damage_bonus_per_level;
		this->maxHp += health_per_level;
		this->health_points = maxHp;
		this->xp -= exp_per_level;
		this->attack_cooldown *= cooldown_multiplier_per_level;
		this->defense += defense_bonus_per_level;
		this->light_radius += light_radius_per_level;
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