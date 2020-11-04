/**
 * \class Parser
 * 
 * \brief Parser class
 * 
 * \note This class is support the parser method.
 * 
 * \date 2020.10.29. 22:17:23
*/
#ifndef JSON_H
#define JSON_H

#include <iostream>
#include <map>
#include <fstream>
#include <algorithm>
#include <any>
#include <string>
#include <variant>
#include <cctype>

class JSON{
private:
     std::map<std::string, std::variant<int, double, std::string>> c_data;
     JSON(std::map<std::string, std::variant<int, double, std::string>> data) : c_data(data){};
public:
    class ParseException : public std::runtime_error
    {
        public:
            ParseException(const std::string &e) : std::runtime_error("Something error went wrong...\n" + e){}
    };
    /**
     * \note Istream input method option for the file.
     * \return Return with the jsonfile's datas.
    */
    static JSON loadInput(std::istream &inputStream/** [in] Input name*/);
    /**
     * \note Istream input method option for the file.
     * \return Return with the jsonfile's datas.
    */
    static JSON parseFromFile(const std::string &jsonFile/** [in] Input file name*/);
    /**
     * \note String input method option for the file.
     * \return Return with the jsonfile's datas.
    */
    static JSON loadInputFromString(std::string data/** [in] Input String*/);

    template<typename T>
    T get(const std::string &key){
    	return std::get<T>(c_data[key]);
    }

    int count(const std::string &key);
};

#endif