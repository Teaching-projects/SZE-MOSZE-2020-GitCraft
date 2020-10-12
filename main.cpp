#include <iostream>
#include <string>
#include <map>
#include "character.h"
#include "parser.h"

int main(int argc, char* argv[]) {
	using std::stoi;
	using std::cout;
	try {
		std::string units_folder = "units/";
		Character player;
		Character::parseUnit(player, units_folder + argv[1]);
		Character enemy;
		Character::parseUnit(enemy, units_folder + argv[2]);
		Parser p;
		std::string s = "units/Orc.json";
		std::map<std::string, std::string> test = p.loadInput(s);
		while (enemy.isAlive() && player.isAlive()) {
			player.attack(enemy);
			// Enemy dead
			if (!enemy.isAlive()) {
				cout << player.getName() << " wins. Remaining HP: " << player.getHp() << '\n';
				break;
			}
			enemy.attack(player);
			// Player dead
			if (!player.isAlive()) {
				cout << enemy.getName() << " wins. Remaining HP: " << enemy.getHp() << '\n';
			}
		}
	}
	catch (std::exception &e) {
		std::cerr << e.what() << '\n';
		return 1;
	}
	return 0;
}