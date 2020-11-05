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
	using std::variant;
	using std::string;
	using std::map;
	using std::smatch;

	static const regex jsonParseRegex("\\s*\"([a-z_]*)\"\\s*:\\s*([0-9]*\\.?[0-9]+|\"[\\w\\s\\./]+\")\\s*([,}])\\s*");

    bool lastData = false;
    string str(data);
    smatch matches;
    map<string, variant<string, int, double>> attributes;
    while (regex_search(str, matches, jsonParseRegex))
    {
        if (lastData)
        {
            throw JSON::ParseException("Invalid Json File structure");
        }
        if (matches.size() == 4)
        {
            if (matches[3].str() == "}")
            {
                lastData = true;
            }

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