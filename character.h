#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>

class Character{
private:
    const std::string name;
    int hp;
    int dmg;
public:
    Character(const std::string name, int hp, int dmg);
    ~Character();
    std::string getName() const;
    int getHp() const;
    int getDmg() const;
    bool isAlive();
    void print();
    void attack(Character &c);
};

#endif // !CHARACTER_H
