#include <algorithm>
#include <utility>
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
    std::map<std::string, std::string> attributes;

	while(data.find('"')!=std::string::npos){
		if(data.find(":")==std::string::npos){
			throw "Couldn't read json file properly.\n";
		}
		int start = data.find('"');

		// erase unnecessary beginning
		data.erase(0, start-1);
		start = data.find('"');

		// read attribute type
		int act = data.find(':');
		int length = act - start;
		std::string actual_attr = data.substr(start+1, length-2);
		data.erase(0, length+1);

		// erase unnecessary whitespaces		
		start = data.find(':')+1;

		// only delete if there is space
		if(data[data.find(':')+1]==' '){
			act = start;
			while(data[act]==' '){
				act++;
			}
			length=act-start;
			data.erase(start-1,length-1);
		}
		
		// read attribute value
		if(data.find(',')!=std::string::npos){
			act = data.find(',');
		}else{
			act = data.find('}');
		}
		length = act - start;
		std::string actual_value = data.substr(start+1, length-1);

		// Remove " characters if necessary
		while(actual_value.find('"')!=std::string::npos){
			actual_value.erase(actual_value.find('"'), 1);
		}

		// Remove unnecessary whitespaces from the end
		int i = actual_value.length()-1;
		while(actual_value[i]==' '){
			actual_value.erase(i, 1);
			i--;
		}
		i = actual_attr.length()-1;
		while(actual_attr[i]==' ' || actual_attr[i]=='"'){
			actual_attr.erase(i, 1);
			i--;
		}

		// insert values into the map
		std::pair<std::string, std::string> actual_pair(actual_attr, actual_value);
        attributes.insert(actual_pair);
		data.erase(0, length+1);
	}
	
	return attributes;
}