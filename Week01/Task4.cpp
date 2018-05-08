// ConsoleApplication9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>

int main()
{
	const char file[] = "file.txt";
	std::ifstream stream(file, std::ios::in | std::ios::ate); //using flag ate because he will set get pointer to last position
	if (!stream) //if stream isn't open then display error and quit from program
	{
		std::cout << "Error file : " << file << " didn't laod!" << std::endl;
		return 0;
	}
	std::cout <<"Lenght of file in bytes : " << stream.tellg() << std::endl; //get current position of get pointer, int txt files every symbol is char. 1 char = 1 byte
	stream.close();

    return 0;
}

