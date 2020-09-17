#include <iostream>
#include <string>
#include "character.h"

int main(int argc, char* argv[]){
    using std::stoi;
    using std::cout;
    try{
        Character player(argv[1], stoi(argv[2]), stoi(argv[3]));
        Character enemy(argv[4], stoi(argv[5]), stoi(argv[6]));
        player.print();
        enemy.print();
        while(enemy.isAlive() && player.isAlive()){
            player.attack(enemy);
            player.print();
            enemy.print();
            // Enemy dead
            if(!enemy.isAlive()){
                cout << enemy.getName() << " died. " << player.getName() << " wins.\n";
                break;
            }
            enemy.attack(player);
            player.print();
            enemy.print();
            // Player dead
            if(!player.isAlive()){
                cout << player.getName() << " died. " << enemy.getName() << " wins.\n";
            }
        }
    }catch(std::invalid_argument &ia){
        std::cerr << "Invalid argument\n";
    }
    return 0;
}
