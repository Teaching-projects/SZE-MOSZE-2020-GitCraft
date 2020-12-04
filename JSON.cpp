#include "JSON.h"

const JSON JSON::parseFromFile(const std::string &jsonFilePath){
	std::ifstream file(jsonFilePath);
    if (!file.fail())
    {
        return parseContent(file);
    }else{
		throw ParseException("Could not read content of file");
	}
}

const JSON JSON::loadInputFromString(std::string data){
	using std::regex;
	using std::string;
	using std::map;
	using std::smatch;

	static const regex jsonParseRegex("\\s*\"([a-z_]*)\"\\s*:\\s*(\\d*\\.?\\d+|\"[\\w\\s\\./]+\")?(\\[([\\S\\s]*)\\])?\\s*([,}])\\s*");

    bool lastData = false;
    string str(data);
    smatch matches;
    map<string, listedVariantValues> attributes;
    while (regex_search(str, matches, jsonParseRegex))
    {
        if (lastData)
        {
            throw JSON::ParseException("Invalid Json File structure");
        }
        if (matches.size() == 6)
        {
            if (matches[5].str() == "}")
            {
                lastData = true;
            }
            if (matches[2].str().size() > 0)
            {
                attributes[matches[1]] = variant_cast(parseValues(matches[2]));
            }
            else
            {
                attributes[matches[1]] = parseArray(matches[4]);
            }
        }
        str = matches.suffix();
	}
	if(str.length() > 0)
	{
		throw JSON::ParseException("Invalid Json File structure.");
	}

    return JSON(attributes);
}

const JSON JSON::parseContent(std::istream& file) {
    std::string line;
    std::string data = ""; 

    while (getline(file, line))
        data += line;

    return loadInputFromString(data);
}

JSON::list JSON::parseArray(const std::string& listData){
    const std::regex arrayRegex("\\s*(\\d*\\.?\\d+|\"[\\w\\s\\.\\/]+\")\\s*(,)?\\s*");

    std::smatch matches;
    std::string str(listData);
    bool hasColon = true;
    std::list<variantValues> result;
        
    while (hasColon && std::regex_search(str, matches, arrayRegex))
    {
        if (matches.prefix().str().find(',') != std::string::npos)
            {
                throw ParseException("Invalid colon position...");
            }
            if (matches.size() == 3)
            {
                result.emplace_back(parseValues(matches[1]));
                hasColon = matches[2] == ",";
            }
            str = matches.suffix();
    }    
    if (str.length() > 0 || hasColon)
    {
        throw JSON::ParseException("Invalid array format");
    }

    return result;
}

JSON::variantValues JSON::parseValues(const std::string& data){
    auto detect_quotation = [](char c){return c=='"';};
    if(data[0]=='"'){
        std::string value = data;
        value.erase(std::remove_if(value.begin(),value.end(), isspace), value.end());
        value.erase(std::remove_if(value.begin(),value.end(), detect_quotation), value.end());       
        return value;
    }
     
    if (data.find('.') != std::string::npos)
    {
        return stod(data);
    }

    return stoi(data);
}


const int JSON::count(const std::string &key){
    if (data.find(key)!=data.end()){
		return 1;
	}
	else{
		return 0;
	}
}