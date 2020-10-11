#include <algorithm>
#include <utility>
#include "parser.h"

const std::map<std::string, std::string> Parser::loadInput(std::istream &jsonFile){
	std::string line;
	std::string data = "";
	while(getline(jsonFile, line)){
		data += line;
	}
	return loadInput(data);
}

const std::map<std::string, std::string> Parser::loadInput(std::string data){
    std::map<std::string, std::string> attributes;
	
	while(data.find('"')!=std::string::npos){
		int start = data.find('"');
		// erase unnecessary beginning
		data.erase(0, start-1);
		start = data.find('"');
		int act = start;

		// read attribute type
		do{
			act++;
		}while(data[act]!=':');
		int length = act - start;
		std::string actual_attr = data.substr(start+1, length-2);
		data.erase(0, length+1);

		// erase unnecessary whitespaces
		start = data.find(':')+1;
		act = start;
		while(data[act]==' '){
			act++;
		}
		length=act-start;
		data.erase(start-1,length-1);

		// read attribute value
		act=start;
		do{
			act++;
		}while(data[act]!=',' && data[act]!='}');
		length = act - start;
		std::string actual_value = data.substr(start+1, length-1);

		// Remove "" characters if necessary
		while(actual_value.find('"')!=std::string::npos){
			actual_value.erase(actual_value.find('"'), 1);
		}

		// insert values into the map
		std::pair<std::string, std::string> actual_pair(actual_attr, actual_value);
        attributes.insert(actual_pair);
		data.erase(0, length+1);
	}
	
	return attributes;
}