#include "Hero.h"

Hero::Hero(const std::string& name, const int maxHp, const int dmg, const double attack_cooldown, const int exp_per_level, const int health_per_level, const int damage_bonus, const double cooldown_multiplier_per_level): Character(name, maxHp, dmg, attack_cooldown){
    this->exp_per_level=exp_per_level;
    this->health_per_level=health_per_level;
    this->damage_bonus=damage_bonus;
    this->cooldown_multiplier_per_level=cooldown_multiplier_per_level;
}
Hero Hero::parse(std::string& charSheetName)
{
    std::cout << charSheetName << '\n';
	JSON attributes = JSON::parseFromFile(charSheetName);
    std::vector<std::string> controlHelper {"name", "base_health_points", "base_damage", "base_attack_cooldown", "experience_per_level", "health_point_bonus_per_level", "damage_bonus_per_level", "cooldown_multiplier_per_level"};
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

void Hero::attack(Character& c)
{
	if(health_points - c.getDamage()>0)
    {
        health_points -= c.getDamage();
    }
    else
    {
        health_points = 0;
    }
}

void Hero::levelup()
{
	int level_c = getXp() / exp_per_level;
	for (int i = 0; i < level_c; i++)
	{
		level++;
		damage += damage_bonus;
		maxHp += health_per_level;
		health_points = maxHp;
		xp -= exp_per_level;
		attack_cooldown-= cooldown_multiplier_per_level;
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
					this->attack(m);
                }
				time_player = this->getAttackCoolDown();
				time_enemy = m.getAttackCoolDown();
				player_last_hit = false;
            }
            else
			{
				this->attack(m);
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
			this->attack(m);
			time_player -= time_enemy;
			time_enemy = m.getAttackCoolDown();
			player_last_hit = false;
		}
	}
}