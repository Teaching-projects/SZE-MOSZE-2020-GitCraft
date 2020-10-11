
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

const std::map<std::string, std::string> Parser::loadInput(std::string fileName){
    std::fstream jsonFile(fileName);

    std::map<std::string, std::string> attributes;
    
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
	jsonFile.close();
	return attributes;
}