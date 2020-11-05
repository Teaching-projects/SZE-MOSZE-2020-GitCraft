/**
 * \class JSON
 * 
 * \brief JSON class
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
#include <string>
#include <variant>
#include <regex>

class JSON{
private:
    std::map <std::string, std::variant<std::string, int, double>> data;
public:
    class ParseException : public std::runtime_error
    {
        public:
            ParseException(const std::string &e) : std::runtime_error("Something error went wrong...\n" + e){}
    };
    JSON(std::map <std::string, std::variant<std::string, int, double>> data) : data(data){}
    /**
     * \note Istream input method option for the file.
     * \return Return with the jsonfile's datas.
    */
    static const JSON parseContent(std::istream& file);
    /**
     * \note Istream input method option for the file.
     * \return Return with the jsonfile's datas.
    */
    static const JSON parseFromFile(const std::string &json/** [in] Input file name*/);
    /**
     * \note String input method option for the file.
     * \return Return with the jsonfile's datas.
    */
    static const JSON loadInputFromString(std::string data/** [in] Input String*/);

    template<typename T> T get(const std::string& key)
    {
        if(!count(key)) throw ParseException("Perhaps the key dose not exist.");
        else return std::get<T>(data[key]);
    }
    
    const int count(const std::string &key);
};

#endif