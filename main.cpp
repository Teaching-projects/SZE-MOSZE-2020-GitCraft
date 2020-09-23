#include <iostream>
#include <string>
#include "character.h"

int main(int argc, char* argv[]) {
	using std::stoi;
	using std::cout;
	try {
		Character player = Character::parseUnit("units/Orc.json");
		Character enemy = Character::parseUnit("units/Troll.json");

		while (enemy.isAlive() && player.isAlive()) {
			player.attack(enemy);
			// Enemy dead
			if (!enemy.isAlive()) {
				cout << player.getName() << " wins. Remaining HP: " << player.getHp() << std::endl;
				break;
			}
			enemy.attack(player);
			// Player dead
			if (!player.isAlive()) {
				cout << enemy.getName() << " wins. Remaining HP: " << enemy.getHp() << std::endl;
			}
		}
	}
	catch (std::exception &e) {
		std::cerr << e.what() << '\n';
	}
	return 0;
}