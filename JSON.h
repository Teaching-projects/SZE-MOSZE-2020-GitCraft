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
    typedef std::variant<std::string, int, double> variantValues;///< The value.
    typedef std::list<variantValues> list;///< The list of the values.
    typedef std::variant<std::string, int, double, list> listedVariantValues;///< The list of the values.
    std::map <std::string, listedVariantValues> data;///< The data map.
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
            explicit ParseException(const std::string &e/** [in] This is the throwable error*/) : std::runtime_error("Something error went wrong...\n" + e){}
    };
    /// This is the constructor of the JSON class
    explicit JSON(const std::map <std::string, listedVariantValues>& data/** [in] Input data*/) : data(data){}
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
    /**
     * \note String input method for array.
     * \return Return with the datas of files in the list.
    */
    static list parseArray(const std::string& listData/** [in] Input String*/);
    /**
     * \note String input method option for the file.
     * \return Return with the jsonfile's types of values.
    */
    static variantValues parseValues(const std::string& data/** [in] Input String*/);

    /// Helps to get the value of the key.
    template<typename T> T get(const std::string& key/** [in] Input String*/)
    {
        if(!count(key)) throw ParseException("Perhaps the key dose not exist.");
        else return std::get<T>(data[key]);
    }
    /// Help to know, that the file containes the key data
    const int count(const std::string &key/** This is the key data, what the function is scanning*/);

    /// A helper for variant_cast method.
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
    /// This casting helps to decide which type of variable we need to get from parseValues.
    template <class... Args>
    static auto variant_cast(const std::variant<Args...> &v) -> variant_cast_proxy<Args...>
    {
        return {v};
    }
};

#endif