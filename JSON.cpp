#include "JSON.h"

JSON JSON::parseFromFile(const std::string &jsonFilePath){
	std::fstream file(jsonFilePath);
	std::string line;
	std::string data = "";
	while(getline(file, line)){
		data += line;
	}
	
	data.erase(remove_if(data.begin(), data.end(), isspace), data.end());

	if(data[0]!='{')
		throw ParseException("No '{' at the beginning of the input.\n");

	if(*(data.end()-1)!='}')
		throw ParseException("No '}' at the end of the input.\n");
	
	return loadInputFromString(data);
}

JSON JSON::loadInputFromString(std::string data){
	using std::remove_if;
	using std::string;
	using std::pair;
    using std::variant;

    std::map<string, variant<int, double, std::string>> attributes;
	auto detect_quotation = [](char c){return c=='"';};

	data.erase(remove_if(data.begin(), data.end(), isspace), data.end());
	while(data.find('"')!=string::npos){
		if(data.find(":")==string::npos){
			throw ParseException("Couldn't read json file properly.\n");
		}
		int start = data.find('"');
		// erase unnecessary beginning
		if(start!=0){
			data.erase(0, start-1);
			start = data.find('"');
		}
		
		// read attribute type
		int act = data.find(':');
		int length = act - start;
		string actual_attr = data.substr(start+1, length-2);
		data.erase(0, length+1);
		
		start = data.find(':');		
		
		// read attribute value
		if(data.find(',')!=string::npos){
			act = data.find(',');
		}else if(data.find('}')!=string::npos){
			act = data.find('}');
		}else{
			act = data.length();
		}

		length = act - start;
		string actual_value = data.substr(start+1, length-1);
		data.erase(0, length);

		// Remove '"' characters if necessary
		actual_value.erase(remove_if(actual_value.begin(),actual_value.end(), detect_quotation), actual_value.end());

		// insert values into the map
		pair<string, variant<int, double, std::string>> actual_pair(actual_attr, actual_value);
        attributes.insert(actual_pair);
	}
	
	return JSON(attributes);
}

JSON JSON::loadInput(const std::string &inputString){
	std::fstream charFile(inputString);
	if(charFile.fail()){
		return loadInputFromString(inputString);
	}
	else{
		return parseFromFile(inputString);
	}
}

int JSON::count(const std::string &key){
    return c_data.count(key);
}