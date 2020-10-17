#include "parser.h"

const std::map<std::string, std::string> Parser::loadInput(std::istream &jsonFile){
	std::string line;
	std::string data = "";
	while(getline(jsonFile, line)){
		data += line;
	}

	if(data.substr(0, 1)!="{")
		throw "No '{' at the beginning of the input.\n";

	if(data.substr(data.length()-1, 1)!="}")
		throw "No '}' at the end of the input.\n";
	
	return loadInput(data);
}

const std::map<std::string, std::string> Parser::loadInput(std::string data){
	using std::remove_if;
	using std::string;
	using std::pair;

    std::map<string, string> attributes;
	auto detect_quotation = [](char c){return c=='"';};

	data.erase(remove_if(data.begin(), data.end(), isspace), data.end());

	while(data.find('"')!=string::npos){
		if(data.find(":")==string::npos){
			throw "Couldn't read json file properly.\n";
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
		}else{
			act = data.find('}');
		}

		length = act - start;
		string actual_value = data.substr(start+1, length-1);
		data.erase(0, length);

		// Remove '"' characters if necessary
		actual_value.erase(remove_if(actual_value.begin(),actual_value.end(), detect_quotation), actual_value.end());

		// insert values into the map
		pair<string, string> actual_pair(actual_attr, actual_value);
        attributes.insert(actual_pair);
	}
	
	return attributes;
}