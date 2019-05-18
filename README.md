# JSONParser
A simple JSON parser utility in C++. Planning to use it to setup things in my game engine. This is just a starting version.Needs to be improved in terms of efficiency and usability.

# Sample Code to use the utility 
```C++
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
```

