#include "../parser.h"
#include <gtest/gtest.h>
#include "../character.h"
TEST(test_parser, test_filename){
    
    std::map<std::string, std::string> expected{
        {"name", "Zuli"},
        {"health", "120"},
        {"dmg", "25"},
        {"atc", "5.2"}
    };

    std::string fileName = "../units/Troll.json";
    std::map<std::string, std::string> output = Parser::loadInput(fileName);

    for(auto a : output){
        ASSERT_EQ(expected[a.first], a.second);
    }
}

TEST(test_parser, test_istream){
    std::map<std::string, std::string> output;
    std::map<std::string, std::string> expected{
        {"name", "Hamaha"},
        {"health", "100"},
        {"dmg", "35"},
        {"atc", "4.2"}
    };

    std::fstream unitFile("../units/Elf.json");
    output = Parser::loadInput(unitFile);
    unitFile.close();

    for(auto a : output){
        ASSERT_EQ(expected[a.first], a.second);
    }
}

TEST(test_parser, test_string){
    std::map<std::string, std::string> output;
    std::map<std::string, std::string> expected{
        {"name", "Dumby"},
        {"health", "110"},
        {"dmg", "45"},
        {"atc", "3.8"}
    };

    std::string fileName = "../units/Orc.json";
    std::fstream file(fileName);
    std::string jsonContent = "";

    std::string line;
    while(getline(file, line)){
        jsonContent += line;
    }
    
    file.close();
    output = Parser::loadInput(jsonContent);

    for(auto a : output){
        ASSERT_EQ(expected[a.first], a.second);
    }
}

TEST(test_parser, test_invalid){
    std::string expected = "Couldn't read json file properly.\n";
    std::fstream unitFile("../units/Invalid.json");
    try{
        Parser::loadInput(unitFile);   
    }catch(char const* c){
		ASSERT_EQ(c, expected);
	}
    catch(std::string s){
        ASSERT_EQ(s, expected);
    }

    unitFile.close();
}
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
	int DMG = DMGtest.getDmg();
	int expected = 35;
	ASSERT_EQ(expected, DMG);
}
//3. teszt a beolvasott karakter élet pontjaira
TEST(Character_test, getMAXHp){
	Character HPtest("Hamaha", 100, 35, 4.2);
	int HP = HPtest.getMaxHp();
	int expected = 100;
	ASSERT_EQ(expected, HP);
}
//4. teszt a beolvasott karakter ütési sebességére
TEST(Character_test, getAttackCoolDown){
	Character ACDtest("Hamaha", 100, 35, 4.2);
	double ACD = ACDtest.getMaxHp();
	double expected = 4.2;
	ASSERT_EQ(expected, ACD);
}
//5. teszt a nyertes karakter megmaradt életére
TEST(TestfightHP, ResultHP)
{
    Character* player = Character::parseUnit("../units/Elf.json");
    Character* enemy = Character::parseUnit("../units/Orc.json");
    Character* out;
    out=player->takeDamage(*player,*enemy);
    ASSERT_EQ(out->getHp(),131);
}
//6. teszt a nyertes karakter nevére
TEST(TestfightNAME, ResultNAME)
{
    Character* player = Character::parseUnit("../units/Elf.json");
    Character* enemy = Character::parseUnit("../units/Orc.json");
    Character* out;
    out=player->takeDamage(*player,*enemy);
    ASSERT_EQ(out->getName(),"Dumby");
}
//7. teszt a player karakter kezdő szintjére
TEST(Character_test, getLevel){
    Character* player = Character::parseUnit("../units/Troll.json");
	int LVL = player->getLevel();
	int expected = 1;
	ASSERT_EQ(expected, LVL);
}
// 8. teszt a player karakter kezdő xp-je.
TEST(Character_test, getXp){
    Character* player = Character::parseUnit("../units/Troll.json");
	int XP = player->getXp();
	int expected = 75;
	ASSERT_EQ(expected, XP);
}
//9. teszt a vesztes karakter eletpontja
TEST(Fight_test, ResultHP)
{
    Character* player = Character::parseUnit("../units/Troll.json");
    Character* enemy = Character::parseUnit("../units/Elf.json");
    Character* out;
    out=player->takeDamage(*player,*enemy);
    int loserHP=player->getHp();
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
    Character* player = Character::parseUnit("../units/Troll.json");
    Character* enemy = Character::parseUnit("../units/Elf.json");
    Character* out;
    out=player->takeDamage(*player,*enemy);
	int levelUp = out->getLevel();
	int expected = 2;
	ASSERT_EQ(expected, levelUp);
}
//12 ParseUnit teszt
TEST(ParseUnit_test, parseUnit){
    Character* player = Character::parseUnit("../units/Troll.json");
    std::string name=player->getName();
    int hp=player->getMaxHp();
    int dmg=player->getDmg();
    double atc=player->getAttackCoolDown();
    std::string expected_name="Zuli";
    int expected_hp=120;
    int expected_dmg=25;
    double expected_atc=5.2;
	ASSERT_EQ(expected_name, name);
    ASSERT_EQ(expected_hp, hp);
    ASSERT_EQ(expected_dmg, dmg);
    ASSERT_EQ(expected_atc, atc);
}
int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}