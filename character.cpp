#include "character.h"

Character::Character(string name, int hp, int dmg)
{
    this->name = name;
    this->hp = hp;
    this->dmg = dmg;
}

Character::~Character(){
}

string Character::getName() const
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

void Character::setHp(int dmg)
{
    hp += dmg;
    if (hp<=0)
    {
        hp = 0;
    }
}

bool Character::isAlive()
{
    if(this->getHp()==0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void Character::attack(Character *c)
{
    std::cout << this->getName() << "->" << c->getName() << '\n';
    if (c->isAlive())
    {
        c->setHp(0-this->getDmg());
    }
}

void Character::print()
{
    std::cout << getName() << ": HP: " << getHp() << ", DMG: " << getDmg() << '\n';
}
