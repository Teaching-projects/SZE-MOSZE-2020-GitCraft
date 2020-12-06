#include <gtest/gtest.h>
#include "../JSON.h"
#include "../character.h"
#include "../Hero.h"
#include "../Monster.h"
#include "../Map.h"
#include "../Game.h"
#include "../MarkedMap.h"
#include "../PreparedGame.h"

//1. teszt a beolvasott karakter nevére
TEST(Character_test, getName){
	Character nametest("Hamaha", 100, 4.2, 35, 0, 0);
	std::string name = nametest.getName();
	std::string expected = "Hamaha";
	ASSERT_EQ(expected, name);
}

//2. teszt a beolvasott karakter sebzésére
TEST(Character_test, getDmg){
	Character DMGtest("Hamaha", 100, 4.2, 35, 0, 0);
	int DMG = DMGtest.getPhysicalDamage();
	int expected = 35;
	ASSERT_EQ(expected, DMG);
}
//3. teszt a beolvasott karakter élet pontjaira
TEST(Character_test, getMAXHp){
	Character HPtest("Hamaha", 100, 4.2, 35, 0, 0);
	int HP = HPtest.getHealthPoints();
	int expected = 100;
	ASSERT_EQ(expected, HP);
}
//4. teszt a beolvasott karakter ütési sebességére
TEST(Character_test, getAttackCoolDown){
	Character ACDtest("Hamaha", 100, 4.2, 35, 0, 0);
	double ACD = ACDtest.getAttackCoolDown();
	double expected = 4.2;
	ASSERT_EQ(expected, ACD);
}

//7. teszt a player karakter kezdő szintjére
TEST(Character_test, getLevel){
    Hero* player = new Hero("Hamaha", 100, 35, 0, 4.2, 15, 5, 1, 0.9, 0, 2);
	int LVL = player->getLevel();
	int expected = 1;
	ASSERT_EQ(expected, LVL);
}

// 8. teszt a player karakter kezdő xp-je.
TEST(Character_test, getXp){
    Hero* player = new Hero("Hamaha", 100,  35, 0, 4.2, 15, 5, 1, 0.9, 0, 2);
	int XP = player->getXp();
	int expected = 0;
	ASSERT_EQ(expected, XP);
}

//10. teszt az isAlive teszt
TEST(Character_test, isAlive){
	Character isAliveTest("Hamaha", 100, 4.2, 35, 0, 0);
	bool test = isAliveTest.isAlive();
	bool expected = true;
	ASSERT_EQ(expected, test);
}

//Új tesztek
//--------------------------
//1. teszt a map osztályra
TEST(Map_test, getFileName){
    Map map("map.txt");
	std::string mapname= map.getFileName();
	std::string expected = "map.txt";
	ASSERT_EQ(expected, mapname);
}

//2. teszt a map osztályra
TEST(Map_test, getHeight){
    Map map("map.txt");
	int height= map.getHeight();
	int expected = map.getVector().size();
	ASSERT_EQ(expected, height);
}

//4. teszt a map osztályra
TEST(Map_test, get){
    Map map("map.txt");
	Map::type part= map.get(2,1);
	Map::type expected = map.Free;
	ASSERT_EQ(expected, part);
}

//5. teszt Game osztály
TEST(Game_test, setMap){
    Map map("map.txt");
    Game game;
	game.setMap(map);
    bool actstatus=game.mapStatus;
	bool expected = true;
	ASSERT_EQ(expected, actstatus);
}

//6. teszt Game osztály 
TEST(Game_test, putHero){
    Map map("map.txt");
    Game game;
    Hero* hero = new Hero("Hamaha", 100, 35, 20, 5, 4.2, 18, 0.9, 1, 0, 1, 1);
	game.setMap(map);
    game.putHero(*hero,1,1);
    bool actstatus=game.heroStatus;
	bool expected = true;
	ASSERT_EQ(expected, actstatus);
}

//7. teszt Game osztály 
TEST(Game_test, putHeroOnOccupiedField){
    Map map("map.txt");
    Game game;
    Hero hero("Hamaha", 100, 35, 20, 5, 4.2, 18, 0.9, 1, 0, 1, 1);
	game.setMap(map);
	ASSERT_THROW(game.putHero(hero,2,2), OccupiedException);
}
//8. teszt Game osztály 
TEST(Game_test, putHeroAlreadyHasHeroException){
    Map map("map.txt");
    Game game;
    Hero hero("Hamaha", 100, 35, 20, 5, 4.2, 18, 0.9, 1, 0, 1, 1);
    Hero hero2("Hamaha", 100, 35, 20, 5, 4.2, 18, 0.9, 1, 0, 1, 1);
	game.setMap(map);
	game.putHero(hero,1,2);
	ASSERT_THROW(game.putHero(hero2,1,2), AlreadyHasHeroException);
}

//9. teszt Game osztály 
TEST(Game_test, NotInitializedHero){
    Map map("map.txt");
    Game game;
	game.setMap(map);
	ASSERT_THROW(game.run(), NotInitializedException);
}

//10. teszt Game osztály 
TEST(Game_test, AlreadyStarted){
    Map map("map.txt");
    Game game;
	game.setMap(map);
	game.gameStatus = true;
	ASSERT_THROW(game.setMap(map), GameAlreadyStarted);
}

// Parser osztály tesztek
// Hero name
TEST(Parser_test, read_hero){
	try{
    	Hero hero(Hero::parse("../Dark_Wanderer.json"));
		Hero expected("Prince Aidan of Khanduras", 30, 3, 3, 1.1, 20, 5, 1, 0.9, 0, 2, 2);
		ASSERT_EQ(expected.getName(), hero.getName());
	}catch(const JSON::ParseException& e){};
}
//Hero Maxhp test
TEST(Parser_test, read_hero_hp){
	try{
    	Hero hero(Hero::parse("../Dark_Wanderer.json"));
		Hero expected("Prince Aidan of Khanduras", 30, 3, 3, 1.1, 20, 5, 1, 0.9, 0, 2, 2);
		ASSERT_EQ(expected.getMaxHealthPoints(), hero.getMaxHealthPoints());
	}catch(const JSON::ParseException& e){};
}
//Hero Light radius test
TEST(Parser_test, read_hero_lightrad){
	try{
    	Hero hero(Hero::parse("../Dark_Wanderer.json"));
		Hero expected("Prince Aidan of Khanduras", 30, 3, 3, 1.1, 20, 5, 1, 0.9, 0, 2, 2);
		ASSERT_EQ(expected.getLightRadius(), hero.getLightRadius());
	}catch(const JSON::ParseException& e){};
}

// Monster name
TEST(Parser_test, read_monster_name){
	try{
    	Monster zombie(Monster::parse("../Zombie.json"));
		Monster expected("Zombie", 10, 1, 0, 2.8, 0);
		ASSERT_EQ(expected.getName(), zombie.getName());
	}catch(const JSON::ParseException& e){};
}
// Monster hp
TEST(Parser_test, read_monster_hp){
	try{
    	Monster fallen(Monster::parse("../Fallen.json"));
		Monster expected("Fallen", 4, 2, 0, 1.6, 0);
		ASSERT_EQ(expected.getHealthPoints(), fallen.getHealthPoints());
	}catch(const JSON::ParseException& e){};
}

// Monster attack_cooldown
TEST(Parser_test, read_monster_attack_cooldown){
	try{
    	Monster zombie(Monster::parse("../Zombie.json"));
		Monster expected("Zombie", 10, 1, 0, 2.8, 0);
		ASSERT_EQ(expected.getAttackCoolDown(), zombie.getAttackCoolDown());
	}catch(const JSON::ParseException& e){};
}

// Array Parser Test
TEST(Parser_test, arrayParse)
{
    ASSERT_NO_THROW(JSON::loadInputFromString("{\"monsters\": [\"zombie\", \"zombie\", \"troll\"]}"));
    ASSERT_NO_THROW(JSON::loadInputFromString("{\"monsters\": [\"zombie\", \"zombie\"    , \"troll\"]}"));
    ASSERT_NO_THROW(JSON::loadInputFromString("{\"monsters\": [\"zombie\", \"    zombie\", \"troll\"]}"));
    ASSERT_NO_THROW(JSON::loadInputFromString("{\"monsters\": [\"zombie\",     \"zombie\", \"troll\"]}"));
    ASSERT_NO_THROW(JSON::loadInputFromString("{\"monsters\": [\"Dark   Goblin\",     \"zombie\", \"troll\"]}"));
    ASSERT_NO_THROW(JSON::parseFromFile("../sc_test.json"));
    ASSERT_THROW(JSON::loadInputFromString("{\"monsters\": [\",Dark   Goblin\",     \"zombie\", \"troll\"]}"), JSON::ParseException);
    ASSERT_THROW(JSON::loadInputFromString("{\"monsters\": [\"Dark   Goblin\",     \",zombie\", \"troll\"]}"), JSON::ParseException);
}

// Standard scenario parsing
TEST(Parser_test, standard_scenario){
	ASSERT_NO_THROW(JSON::parseFromFile("../scenario1.json"));
	ASSERT_NO_THROW(JSON::parseFromFile("../scenario2.json"));
}

// MarkedMap Test
TEST(MarkedMap_test, marked_map){
	ASSERT_NO_THROW(MarkedMap markedmap("../markedmap.txt"));
}
//PreparedGame Test
TEST(PreparedGame_test, prepared_game){
	ASSERT_NO_THROW(PreparedGame("PreparedGame_test.json"));
}

int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}