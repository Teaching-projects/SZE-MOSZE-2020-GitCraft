#include <gtest/gtest.h>
#include "../JSON.h"
#include "../character.h"
#include "../Hero.h"
#include "../Monster.h"

//1. teszt a beolvasott karakter nevére
TEST(Character_test, getName){
	Character nametest("Hamaha", 100, 35, 4.2);
	std::string name = nametest.getName();
	std::string expected = "Hamaha";
	ASSERT_EQ(expected, name);
}

//2. teszt a beolvasott karakter sebzésére
TEST(Character_test, getDmg){
	Character DMGtest("Hamaha", 100, 35, 4.2);
	int DMG = DMGtest.getDamage();
	int expected = 35;
	ASSERT_EQ(expected, DMG);
}
//3. teszt a beolvasott karakter élet pontjaira
TEST(Character_test, getMAXHp){
	Character HPtest("Hamaha", 100, 35, 4.2);
	int HP = HPtest.getHealthPoints();
	int expected = 100;
	ASSERT_EQ(expected, HP);
}
//4. teszt a beolvasott karakter ütési sebességére
TEST(Character_test, getAttackCoolDown){
	Character ACDtest("Hamaha", 100, 35, 4.2);
	double ACD = ACDtest.getAttackCoolDown();
	double expected = 4.2;
	ASSERT_EQ(expected, ACD);
}

//5. teszt a nyertes karakter megmaradt életére
TEST(TestfightHP, ResultHP)
{
    Hero* player = new Hero("Hamaha", 100, 35, 4.2, 20, 5, 18, 0.9);
    Monster* enemy = new Monster("Dumby",110,45,3.8);
    player->fightTilDeath(*enemy);
    ASSERT_EQ(player->getHealthPoints(),125);
}

//6. teszt a nyertes karakter nevére
TEST(TestfightNAME, ResultNAME)
{
    Hero* player = new Hero("Hamaha", 100, 35, 4.2, 20, 5, 18, 0.9);
    Monster* enemy = new Monster("Dumby",110,45,3.8);
    player->fightTilDeath(*enemy);
    std::string name;
    if(player->isAlive()){
        name = player->getName();
    }
    ASSERT_EQ(name,"Hamaha");
}

//7. teszt a player karakter kezdő szintjére
TEST(Character_test, getLevel){
    Hero* player = new Hero("Hamaha", 100, 35, 4.2, 20, 5, 18, 0.9);
	int LVL = player->getLevel();
	int expected = 1;
	ASSERT_EQ(expected, LVL);
}

// 8. teszt a player karakter kezdő xp-je.
TEST(Character_test, getXp){
    Hero* player = new Hero("Hamaha", 100, 35, 4.2, 20, 5, 18, 0.9);
	int XP = player->getXp();
	int expected = 0;
	ASSERT_EQ(expected, XP);
}
//9. teszt a vesztes karakter eletpontja
TEST(Fight_test, ResultHP)
{
    Hero* player = new Hero("Hamaha", 100, 35, 4.2, 20, 5, 18, 0.9);
    Monster* enemy = new Monster("Giant Bee",30,2,7.1);
    player->fightTilDeath(*enemy);
    int loserHP=enemy->getHealthPoints();
    int expected=0;
    ASSERT_EQ(expected,loserHP);
}
//10. teszt az isAlive teszt
TEST(Character_test, isAlive){
	Character isAliveTest("Hamaha", 100, 35, 4.2);
	bool test = isAliveTest.isAlive();
	bool expected = true;
	ASSERT_EQ(expected, test);
}

//11. levelUp teszt a nyertes karakterre 
TEST(Character_test, levelUp){
    Hero* player = new Hero("Hamaha", 100, 35, 4.2, 20, 5, 18, 0.9);
    Monster* enemy = new Monster("Giant Bee",30,2,7.1);
    player->fightTilDeath(*enemy);
    int levelUp;
    if(player->isAlive()){
        levelUp = player->getLevel();
    }
	int expected = 2;
	ASSERT_EQ(expected, levelUp);
}

//12 ParseUnit teszt - file
TEST(ParseUnit_test, fileParser){
    JSON parsedCreature = JSON::parseFromFile("../units/Troll.json");
    Monster troll(parsedCreature.get<std::string>("name"), 
			parsedCreature.get<int>("health"),
			parsedCreature.get<int>("dmg"),
			parsedCreature.get<double>("atc"));

    std::string expected_name="Zuli";
    int expected_hp=120;
    int expected_dmg=25;
    double expected_atc=5.2;
	ASSERT_EQ(expected_name, troll.getName());
    ASSERT_EQ(expected_hp, troll.getHealthPoints());
    ASSERT_EQ(expected_dmg, troll.getDamage());
    ASSERT_EQ(expected_atc, troll.getAttackCoolDown());
}

//13 ParseUnit teszt - string
TEST(ParseUnit_test, stringParser){
    JSON parsedCreature = JSON::loadInputFromString("{\"name\": \"Zuli\",\"health\": 120,\"dmg\": 25, \"atc\": 5.2 }");
    Monster troll(parsedCreature.get<std::string>("name"), 
			parsedCreature.get<int>("health"),
			parsedCreature.get<int>("dmg"),
			parsedCreature.get<double>("atc"));
    std::string expected_name="Zuli";
    int expected_hp=120;
    int expected_dmg=25;
    double expected_atc=5.2;
	ASSERT_EQ(expected_name, troll.getName());
    ASSERT_EQ(expected_hp, troll.getHealthPoints());
    ASSERT_EQ(expected_dmg, troll.getDamage());
    ASSERT_EQ(expected_atc, troll.getAttackCoolDown());
}

//14 ParseUnit teszt - istream
TEST(ParseUnit_test, istreamParser){
    std::fstream unitFile("../units/Orc.json");
    JSON parsedCreature = JSON::parseContent(unitFile);
    Monster troll(parsedCreature.get<std::string>("name"), 
			parsedCreature.get<int>("health"),
			parsedCreature.get<int>("dmg"),
			parsedCreature.get<double>("atc"));
    std::string expected_name="Dumby";
    int expected_hp=110;
    int expected_dmg=45;
    double expected_atc=3.8;
	ASSERT_EQ(expected_name, troll.getName());
    ASSERT_EQ(expected_hp, troll.getHealthPoints());
    ASSERT_EQ(expected_dmg, troll.getDamage());
    ASSERT_EQ(expected_atc, troll.getAttackCoolDown());
}

//15 ParseUnit teszt - invalid
TEST(ParseUnit_test, invalidParser){
    std::fstream unitFile("../units/Invalid.json");
    ASSERT_ANY_THROW(JSON parsedCreature = JSON::parseContent(unitFile);
        Monster troll(parsedCreature.get<std::string>("name"), 
	    		parsedCreature.get<int>("health"),
	    		parsedCreature.get<int>("dmg"),
	    		parsedCreature.get<double>("atc"));
        std::string expected_name="Dumby";
        int expected_hp=110;
        int expected_dmg=45;
        double expected_atc=3.8;
	    ASSERT_EQ(expected_name, troll.getName());
        ASSERT_EQ(expected_hp, troll.getHealthPoints());
        ASSERT_EQ(expected_dmg, troll.getDamage());
        ASSERT_EQ(expected_atc, troll.getAttackCoolDown());
    );
    
}


int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}