#include <iostream>
#include "character.h"

int main(){
    Character a("Mapple", 100, 30);
    Character b("Sally", 45, 50);
    a.print();
    b.attack(&a);
    a.print();
    std::cout << a.isAlive();
    return 0;
}
