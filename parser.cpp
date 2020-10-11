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
		data.erase(0, start-1);
		start = data.find('"');
		int act = start;

		do{
			act++;
		}while(data[act]!=':');
		int length = act - start;
		std::string actual_attr = data.substr(start+1, length-2);

		data.erase(0, length+1);
		//std::cout << data << '\n';
		start = data.find(':')+1;
		act = start;

		do{
			act++;
		}while(data[act]!=',' && data[act]!='}');
		
		length = act - start;

		std::string actual_value = data.substr(start+1, length-1);
		std::pair<std::string, std::string> actual_pair(actual_attr, actual_value);
        attributes.insert(actual_pair);

		data.erase(0, length+1);
	}
	

	//std::pair<std::string, std::string> actual_pair(actual_attr)
	/*
	std::fstream jsonFile(fileName);

	if (jsonFile.fail())
	{
		std::string error("Couldn't open file");
		throw std::runtime_error(error);
	}
    
	std::string line;

	while (!jsonFile.eof())
	{
		std::getline(jsonFile, line);

		
		std::string s = "name";
		if (line.find(s) != std::string::npos) {
			int end = line.rfind('"');
			int start = end;
			bool find = true;
			while (find)
			{
				start--;
				if (line[start] == '"')
				{
					find = false;
				}
			}
			int length = end - start - 1;
			std::pair<std::string, std::string> name_pair("name", line.substr(start + 1, length));
            attributes.insert(name_pair);
		}
		
		s = "hp";
		if (line.find(s) != std::string::npos) {
			int start = line.rfind(':');
			int end = line.rfind(',');
			int length = end - start - 2;
			std::pair<std::string, std::string> hp_pair("hp", line.substr(start + 2, length));
            attributes.insert(hp_pair);
		}
		
		s = "dmg";
		if (line.find(s) != std::string::npos) {
			int start = line.rfind(':');
			int length = line.length() - start - 1;
            std::pair<std::string, std::string> dmg_pair("damage", line.substr(start + 2, length));
			attributes.insert(dmg_pair);
		}
		
	}
	jsonFile.close();*/
	return attributes;
}