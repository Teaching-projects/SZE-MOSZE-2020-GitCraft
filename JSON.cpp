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
    map<string, variantValues> attributes;
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
            if(matches[2].str().size() > 0){
                string actual_value = matches[2].str();
                if (actual_value.at(0) == '"')
                {
                    actual_value.erase(actual_value.begin());
                    actual_value.erase(actual_value.end() - 1);
                    attributes[matches[1]] = actual_value;
                }
                else if (actual_value.find_first_of('.') != std::string::npos)
                {
                    attributes[matches[1]] = stod(actual_value);
                }
                else
                {
                    attributes[matches[1]] = stoi(actual_value);
                }
            }else{
                // PARSE LIST
                std::string list_values = matches[4];
                std::cout << list_values << '\n';
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

const int JSON::count(const std::string &key){
    if (data.find(key)!=data.end()){
		return 1;
	}
	else{
		return 0;
	}
}