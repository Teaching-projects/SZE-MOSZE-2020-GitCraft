/**
 * \class Parser
 * 
 * \brief Parser class
 * 
 * \note This class is support the parser method.
 * 
 * \date 2020.10.29. 22:17:23
*/
#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <algorithm>

class Parser{
public:
    /**
     * \note Istream input method option for the file.
     * \return Return with the jsonfile's datas.
    */
    static const std::map<std::string, std::string> loadInput(const std::string& inputStream/** [in] Input name*/);
    /**
     * \note Istream input method option for the file.
     * \return Return with the jsonfile's datas.
    */
    static const std::map<std::string, std::string> loadInputFromFile(std::fstream &jsonFile/** [in] Input file name*/);
    /**
     * \note String input method option for the file.
     * \return Return with the jsonfile's datas.
    */
    static const std::map<std::string, std::string> loadInputFromString(std::string data/** [in] Input String*/);
};

#endif