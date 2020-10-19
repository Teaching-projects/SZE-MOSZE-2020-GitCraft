#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <algorithm>

class Parser{
public:
    /// Istream input method
    static const std::map<std::string, std::string> loadInput(std::istream &jsonFile/** [in] Input file name*/);
    /// String input method
    static const std::map<std::string, std::string> loadInput(std::string data/** [in] Input file name*/);
};

#endif