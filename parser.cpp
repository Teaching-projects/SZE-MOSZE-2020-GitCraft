#include "parser.h"

const std::map<std::string, std::string> Parser::loadInputFromFile(std::fstream &jsonFile){
	std::string line;
	std::string data = "";
	while(getline(jsonFile, line)){
		data += line;
	}
	
	data.erase(remove_if(data.begin(), data.end(), isspace), data.end());

	if(data[0]!='{')
		throw "No '{' at the beginning of the input.\n";

	if(*(data.end()-1)!='}')
		throw "No '}' at the end of the input.\n";
	
	return loadInputFromString(data);
}

const std::map<std::string, std::string> Parser::loadInputFromString(std::string data){
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
		pair<string, string> actual_pair(actual_attr, actual_value);
        attributes.insert(actual_pair);
	}
	
	return attributes;
}

const std::map<std::string, std::string> Parser::loadInput(const std::string& inputStream){
	std::fstream charFile(inputStream);
	if(charFile.fail()){
		return loadInputFromString(inputStream);
	}
	else{
		return loadInputFromFile(charFile);
	}
}