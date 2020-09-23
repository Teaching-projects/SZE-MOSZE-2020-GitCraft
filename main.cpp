#include <iostream>
#include <string>
#include "character.h"

int main(int argc, char* argv[]) {
	using std::stoi;
	using std::cout;
	try {
		std::string units_folder = "units/";
		Character player = Character::parseUnit(units_folder + argv[1]);
		Character enemy = Character::parseUnit(units_folder + argv[2]);

		while (enemy.isAlive() && player.isAlive()) {
			player.attack(enemy);
			// Enemy dead
			if (!enemy.isAlive()) {
				cout << player.getName() << " wins. Remaining HP: " << player.getHp();
				break;
			}
			enemy.attack(player);
			// Player dead
			if (!player.isAlive()) {
				cout << enemy.getName() << " wins. Remaining HP: " << enemy.getHp();
			}
		}
	}
	catch (std::exception &e) {
		std::cerr << e.what() << '\n';
	}
	return 0;
}