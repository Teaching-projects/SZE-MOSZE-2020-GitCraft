#include <gtest/gtest.h>
#include "../JSON.h"
#include "../character.h"
#include "../Hero.h"
#include "../Monster.h"

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
    Hero* player = new Hero("Hamaha", 100, 35, 0, 4.2, 15, 5, 1, 0.9, 0);
	int LVL = player->getLevel();
	int expected = 1;
	ASSERT_EQ(expected, LVL);
}

// 8. teszt a player karakter kezdő xp-je.
TEST(Character_test, getXp){
    Hero* player = new Hero("Hamaha", 100, 35, 0, 4.2, 15, 5, 1, 0.9, 0);
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

int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}