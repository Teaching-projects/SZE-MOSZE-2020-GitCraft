#include "../parser.h"
#include <gtest/gtest.h>

TEST(test_parser, test_filename){
    
    std::map<std::string, std::string> expected{
        {"name", "Zuli"},
        {"health", "200"},
        {"dmg", "15"}
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
        {"health", "160"},
        {"dmg", "25"}
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
        {"health", "120"},
        {"dmg", "35"}
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

int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}