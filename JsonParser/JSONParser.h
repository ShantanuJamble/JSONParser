#pragma once
#include <map>
#include <vector>
class JSONParser
{
private:
	std::map<std::string, std::string> jsonData;

public:
	JSONParser(const char* file_path);
	size_t LoadData(std::vector<std::string> &line,size_t index, const char * keyPrefix=nullptr);
	~JSONParser();
	std::string operator [] (std::string key);
};