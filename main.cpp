#include <iostream>
#include <string>
#include "character.h"

int main(int argc, char* argv[]) {
	using std::stoi;
	using std::cout;
	try {
		std::string units_folder = "units/";
		Character player;
		Character::parseUnit(player, units_folder + argv[1]);
		Character enemy;
		Character::parseUnit(enemy, units_folder + argv[2]);

		player.takeDamage(player,enemy);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << '\n';
		return 1;
	}
	return 0;
}