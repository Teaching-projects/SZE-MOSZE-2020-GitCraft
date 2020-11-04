#include "JSON.h"

JSON JSON::parseFromFile(const std::string &jsonFilePath){
    std::ifstream jsonFile(jsonFilePath);
	if(jsonFilePath.find(".json")!=std::string::npos && jsonFile.is_open()){
    	if (jsonFile.fail()) throw ParseException(jsonFilePath + " could not be opened!");
    	else
    	{
    	    std::map<std::string, std::variant<int, double, std::string>> toReturn = loadInput(jsonFile).c_data;
    	    jsonFile.close();
    	    return JSON(toReturn);
    	}
	}
    else return loadInputFromString(jsonFilePath);
}

JSON JSON::loadInputFromString(std::string data){
	using std::remove_if;
	using std::string;
	using std::pair;
    using std::variant;

    std::map<string, variant<int, double, std::string>> attributes;
	auto detect_quotation = [](char c){return c=='"';};
	auto detect_int = [](char c){return std::isdigit(c);};
	auto detect_double = [](char c){return std::isdigit(c) || c == '.' ? true : false;};
	bool seen_space = false;

    auto end{ std::remove_if(data.begin(), data.end(),
                             [&seen_space](unsigned ch) {
                                 bool is_space = std::isspace(ch);
                                 std::swap(seen_space, is_space);
                                 return seen_space && is_space;
                             }
              )
    };

    if (end != data.begin() && std::isspace(static_cast<unsigned>(end[-1])))
        --end;

    data.erase(end, data.end());
	std::cout << data << '\n';

	//data.erase(remove_if(data.begin(), data.end(), isspace), data.end());
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
		
		if (!actual_value.empty() && std::all_of(actual_value.begin(), actual_value.end(), detect_int)){
			actual_value = std::stoi(actual_value);
		}
        else if (!actual_value.empty() && std::all_of(actual_value.begin(), actual_value.end(), detect_double)){
			actual_value  = std::stod(actual_value);
		}
		else {actual_value = actual_value;}
		std::cout << actual_attr << ' ' << actual_value << '\n';

		// insert values into the map
	    attributes.insert(std::make_pair(actual_attr,actual_value));
	}
	
	return JSON(attributes);
}

JSON JSON::loadInput(std::istream &inputStream){
    std::string line;
    std::string data = ""; 

    while (getline(inputStream, line)){
        data += line;
	}

    return loadInputFromString(data);
}

int JSON::count(const std::string &key){
    return c_data.count(key);
}