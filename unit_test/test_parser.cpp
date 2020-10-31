#include "../parser.h"
#include <gtest/gtest.h>

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
    output = Parser::loadInputFromFile(unitFile);
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
        Parser::loadInputFromFile(unitFile);   
    }catch(char const* c){
		ASSERT_EQ(c, expected);
	}
    catch(std::string s){
        ASSERT_EQ(s, expected);
    }

    unitFile.close();
}

int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
