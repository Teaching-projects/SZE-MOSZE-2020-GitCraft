#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <map>
#include <fstream>
#include <string>

class Parser{
public:
    static const std::map<std::string, std::string> loadInput(std::istream &jsonFile);
    static const std::map<std::string, std::string> loadInput(std::string data);
};

#endif