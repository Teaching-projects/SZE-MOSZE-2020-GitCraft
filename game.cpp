#include "game.h"
#include "character.h"

Game::Game(){

}

Game::~Game(){}

void Game::start(){
    this->running = true;
    this->run();
}

void Game::end(){
    this->running = false;
}

void Game::run(){
    Character* player = new Character("Mapple", 150, 10);
	Character* enemy = new Character("Sally", 45, 30);
    std::cout << player->getName() << ' ' << player->getHp() << ' ' << player->getDmg() << ' ' ;
    std::cout << enemy->getName() << ' ' << enemy->getHp() << ' ' << enemy->getDmg() << '\n';
    player->print();
    enemy->print();
    
    delete player;
    delete enemy;
}
