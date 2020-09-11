#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>

using std::string;

class Character{
private:
    string name;
    int hp;
    int dmg;
public:
    Character(string name, int hp, int dmg);
    ~Character();
    string getName() const;
    int getHp() const;
    int getDmg() const;
    void setHp(int dmg);
    bool isAlive();
    void print();
    void attack(Character* c);
};

#endif // !CHARACTER_H
