#include "game.h"
#include "character.h"

Game::Game(){}

Game::~Game(){}

void Game::start()
{
    this->running = true;
    this->run();
}

void Game::end()
{
    this->running = false;
}

void Game::run()
{
    // Initializing characters
    Character* player = new Character("Mapple", 150, 10);
	Character* enemy = new Character("Sally", 45, 30);
    std::cout << player->getName() << ' ' << player->getHp() << ' ' << player->getDmg() << ' ' ;
    std::cout << enemy->getName() << ' ' << enemy->getHp() << ' ' << enemy->getDmg() << '\n';
    player->print();
    enemy->print();
    while(running){
        player->attack(enemy);
        player->print();
        enemy->print();
        //Player dead
        if(!enemy->isAlive()){
            this->end();
            std::cout << enemy->getName() << " died. " << player->getName() << " wins.\n";
            break;      // Otherwise segmentation fault...
        }
        enemy->attack(player);
        player->print();
        enemy->print();
        //Enemy dead
        if(!player->isAlive()){
            this->end();
            std::cout << player->getName() << " died. " << enemy->getName() << " wins.\n";
        }
    } 
    delete player;
    delete enemy;
}
