#include <iostream>
#include "JSONParser.h"
int main()
{
	std::cout << "I work" << std::endl;
	int a;
	JSONParser parser = JSONParser("test.json");
	//Test Valid Case
	std::cout << parser["cars,car1"].c_str() << std::endl;

	//Test case for invalid key..fails gracefully
	std::cout << parser["cars,ca"].c_str() << std::endl;
	std::cin >> a;
}