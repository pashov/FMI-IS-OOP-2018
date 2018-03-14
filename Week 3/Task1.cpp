// ConsoleApplication12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

void stringCopy(char*& destination, char* source)
{
	int length = 0;
	while (source[length++] != '\0'); //Find length of source with terminating zero
	destination = new char[length];
	for (size_t i = 0; i < length; i++)
	{
		destination[i] = source[i];
	}
}
int main()
{
	char* string_desti = "destination";
	char* string_source = "source";

	std::cout << string_desti << " | " << string_source << std::endl;
	stringCopy(string_desti, string_source);
	std::cout << string_desti << " | " << string_source << std::endl;
    return 0;
}

