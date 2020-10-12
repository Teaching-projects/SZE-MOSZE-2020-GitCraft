#include "../parser.h"
#include <gtest/gtest.h>

TEST(test_parser, test_filename){
    Parser p;
    std::map<std::string, std::string> output;
    std::map<std::string, std::string> expected{
        {"name", "Zuli"},
        {"hp", "200"},
        {"dmg", "15"}
    };

    std::string fileName("../units/Troll.json");
    output = p.loadInput(fileName);

    for(auto a : output){
        ASSERT_EQ(expected[a.first], a.second);
    }
}

TEST(test_parser, test_istream){
    Parser p;
    std::map<std::string, std::string> output;
    std::map<std::string, std::string> expected{
        {"name", "Hamaha"},
        {"hp", "160"},
        {"dmg", "25"}
    };

    std::fstream unitFile("../units/Elf.json");
    output = p.loadInput(unitFile);
    unitFile.close();

    for(auto a : output){
        ASSERT_EQ(expected[a.first], a.second);
    }
}

TEST(test_parser, test_string){
    Parser p;
    std::map<std::string, std::string> output;
    std::map<std::string, std::string> expected{
        {"name", "Dumby"},
        {"hp", "120"},
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
    output = p.loadInput(jsonContent);

    for(auto a : output){
        ASSERT_EQ(expected[a.first], a.second);
    }
}

int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}