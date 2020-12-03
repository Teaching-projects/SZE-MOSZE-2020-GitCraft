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
#include <list>

class JSON{
public:
    typedef std::variant<std::string, int, double> variantValues;
    typedef std::list<variantValues> list;
    typedef std::variant<std::string, int, double, list> listedVariantValues;
    std::map <std::string, listedVariantValues> data;
private:
    
public:
/**
 * \class ParseExeption
 * 
 * \brief ParseExeption class
 * 
 * \note This class managing the exeptions of the class.
 * 
 * \date 2020.11.05. 22:17:23
*/
    class ParseException : public std::runtime_error
    {
        public:
            /// This is the constructor of the ParseExeption class
            ParseException(const std::string &e/** [in] This is the throwable error*/) : std::runtime_error("Something error went wrong...\n" + e){}
    };
    /// This is the constructor of the JSON class
    JSON(std::map <std::string, listedVariantValues> data/** [in] Input data*/) : data(data){}
    /**
     * \note Istream input method option for the file.
     * \return Return with the jsonfile's datas.
    */
    static const JSON parseContent(std::istream& file/** [in] Input istream file*/);
    /**
     * \note Istream input method option for the file.
     * \return Return with the jsonfile's datas.
    */
    static const JSON parseFromFile(const std::string &jsonFilePath/** [in] Input file name*/);
    /**
     * \note String input method option for the file.
     * \return Return with the jsonfile's datas.
    */
    static const JSON loadInputFromString(std::string data/** [in] Input String*/);

    static list parseArray(const std::string& listData);
    static variantValues parseValues(const std::string& data);

    template<typename T> T get(const std::string& key)
    {
        if(!count(key)) throw ParseException("Perhaps the key dose not exist.");
        else return std::get<T>(data[key]);
    }
    /// Help to know, that the file containes the key data
    const int count(const std::string &key/** This is the key data, what the function is scanning*/);



    template <class... Args>
    struct variant_cast_proxy
    {
        std::variant<Args...> v;

        template <class... ToArgs>
        operator std::variant<ToArgs...>() const
        {
            return std::visit(
                [](auto &&arg) -> std::variant<ToArgs...> { return arg; },
                v);
        }
    };

    template <class... Args>
    static auto variant_cast(const std::variant<Args...> &v) -> variant_cast_proxy<Args...>
    {
        return {v};
    }
};

#endif