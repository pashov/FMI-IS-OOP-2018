// Tasks.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int MAX_LINE_LENGTH = 300;

//task1
void readWrite(char* source, char* destination)
{
	ifstream readStr(source);
	ofstream writeStr(destination);
	if (readStr.is_open())
	{
		char buf;
		while (!readStr.eof())
		{
			buf = (char)readStr.get();

			//Check if we read an ASCII char. 
			//We need to check, because of * while (!readStr.eof()) * - it will read 1 char after eof
			if (buf >= 0 && buf <= 127)
			{
				if (buf >= 'a' && buf <= 'z')
				{
					//lowercase to uppercase
					buf = buf - 'a' + 'A';
				}
				writeStr << buf;
			}
		}
		readStr.close();
		writeStr.close();
	}
}


//task2
void printDifferentLines(char* f1, char* f2)
{
	ifstream firstFile(f1);
	ifstream secondFile(f2);
	if (firstFile.is_open() && secondFile.is_open())
	{
		char firstFileLine[MAX_LINE_LENGTH] = { '\0' };
		char secondFileLine[MAX_LINE_LENGTH] = { '\0' };
		//different lines from first file
		while(!firstFile.eof())
		{
			firstFile.getline(firstFileLine, MAX_LINE_LENGTH);
			bool different = true;
			secondFile.seekg(ios::beg);
			while (!secondFile.eof())
			{
				secondFile.getline(secondFileLine, MAX_LINE_LENGTH);
				if (strcmp(firstFileLine, secondFileLine) == 0)
				{
					different = false;
				}
			}
			if (different)
			{
				cout << "< " <<  firstFileLine << '\n';
			}
		}

		secondFile.seekg(ios::beg);
		//different lines from second file
		while (!secondFile.eof())
		{
			secondFile.getline(secondFileLine, MAX_LINE_LENGTH);
			bool different = true;
			firstFile.seekg(ios::beg);
			while (!firstFile.eof())
			{
				firstFile.getline(firstFileLine, MAX_LINE_LENGTH);
				if (strcmp(secondFileLine, firstFileLine) == 0)
				{
					different = false;
				}
			}
			if (different)
			{
				cout << "> " << secondFileLine << '\n';
			}
		}
		firstFile.close();
		secondFile.close();
	}
}


//task3
void printLastLines(int numLastLines, char* filename)
{
	ifstream readStr(filename);
	if (readStr.is_open())
	{
		int countLines = 0;
		char line[MAX_LINE_LENGTH];
		// Get count of lines
		while (!readStr.eof())
		{
			readStr.getline(line, MAX_LINE_LENGTH);
			countLines++;
		}
		readStr.seekg(ios::beg);
		// read until remaining *numLastLines*, then read and print
		while (!readStr.eof())
		{
			readStr.getline(line, MAX_LINE_LENGTH);
			if (countLines <= numLastLines)
			{
				cout << line << '\n';
			}
			countLines--;
		}
		readStr.close();
	}
}

int main()
{
	readWrite("fmi_oop.txt", "FMI_OOP1.txt");
	printDifferentLines("fmi_oop.txt", "FMI_OOP1.txt");
	printLastLines(3, "fmi_oop.txt");
    return 0;
}

