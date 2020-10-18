#include <iostream>
#include <string>
#include <map>
#include <exception>
#include "character.h"
#include "parser.h"

int main(int argc, char* argv[]) {
	using std::stoi;
	using std::cout;
	try {
		std::string units_folder = "units/";
		Character *player = Character::parseUnit(units_folder + argv[1]);
		Character *enemy = Character::parseUnit(units_folder + argv[2]);
		Character* out;

		out=player->takeDamage(*player,*enemy);
		std::cout<<out->getName()<<" wins. Remaining HP: "<< out->getHp() + '\n';
		
		delete player;
		delete enemy;
	}
	catch(char const* c){
		std::cerr << "Couldn't read json file properly.\n";
		return -2;
	}
	catch(std::string s){
		std::cerr << "Couldn't read json file properly.\n";
		return -2;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << "\n";
		return 1;
	}
	return 0;
}