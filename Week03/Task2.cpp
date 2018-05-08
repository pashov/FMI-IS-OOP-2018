// ConsoleApplication13.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

char* stringConcat(char* str1, char* str2)
{
	int length_str1 = 0;
	while (str1[length_str1++] != '\0'); //Find length of str1 with terminating zero

	int length_str2 = 0;
	while (str1[length_str2++] != '\0'); //Find length of str2 with terminating zero

	char* string = new char[length_str1 + length_str2 - 1];

	int newStrCounter = 0;

	for (size_t i = 0; i < length_str1 - 1; i++) // -1 because lenght_str1 is including '\0'
	{
		string[newStrCounter++] = str1[i];
	}
	for (size_t i = 0; i < length_str2; i++)
	{
		string[newStrCounter++] = str2[i];
	}
	return string;

}

int main()
{
	char* string_desti = "destination";
	char* string_source = "source";

	std::cout << string_desti << " | " << string_source << std::endl;
	char* string = stringConcat(string_desti, string_source);
	std::cout << string << std::endl;
	std::cout << string_desti << " | " << string_source << std::endl;
	return 0;
    return 0;
}

