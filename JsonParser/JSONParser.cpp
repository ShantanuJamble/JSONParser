#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <stdlib.h>

#include "JsonParser.h"

JSONParser::JSONParser(const char* file_path)
{
	std::vector<std::string> fileData;
	std::string line;
	std::ifstream jsonFile(file_path);
	std::string delimeter = ":";
	if (jsonFile.is_open())
	{
		while (getline(jsonFile, line))
		{
			// trimming spaces
			line = std::regex_replace(line, std::regex("^ +| +$|( ) +"), "$1");

			fileData.emplace_back(line);
		}
	}

	

	LoadData(fileData,0);
}

size_t JSONParser::LoadData(std::vector<std::string> &fileData , size_t index, const char * keyPrefix)
{
	
	if (fileData[0].find("{") != 0)
	{
		std::cout << "JSON format curropted.";
		return index;
	}
	else
	{
		for (; index < fileData.size(); index++)
		{
			if (fileData[index][0] == '}')
				return index;
		
			if(fileData[index][0] == '{')
				continue;
			else
			{
				int delimeterIndex = fileData[index].find(':');
				if (delimeterIndex == std::string::npos)
				{
					std::cout << "JSON format curropted.";
					return index;
				}
				char key[50] = "\0";
				std::string val;
				
				//key = std::strcat(keyPrefix, fileData[index].substr(delimeterIndex, fileData[index].size()).c_str());
				if (keyPrefix != NULL)
				{
					strcat_s(key, 50, keyPrefix);
					strcat_s(key, 50, ",");
				}
				std::string keysub = fileData[index].substr(0, delimeterIndex);
				keysub.erase(0, 1);
				keysub.erase(keysub.size() - 1);
				strcat_s(key,50, keysub.c_str());
				
				val = fileData[index].substr(delimeterIndex+1, fileData[index].size());
				val = std::regex_replace(val, std::regex("^ +| +$|( ) +"), "$1");
				if (val[0] == '{')
				{
					index = LoadData(fileData, index + 1, key);
				}
				else {
					val.erase(0, 1);
					if (val[val.size() - 1] == ',')
						val.erase(val.size() - 2, val.size() - 1);
					else
						val.erase(val.size() - 1);

					std::cout << "key " << key << "  Val " << val << std::endl;
					jsonData[key] = val;
				}
			}	
			
		}
	}
	return index;
}



JSONParser::~JSONParser()
{
}



std::string JSONParser::operator[](std::string key)
{
	try {
		return jsonData[key];
	}
	catch (const std::exception & e)
	{
		return "";
	}
}


