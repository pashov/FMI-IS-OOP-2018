// ConsoleApplication10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>

struct Point
{
	char name[50];
	double x;
	double y;
};

void ReadFile(const char* file, Point* points, int& pointsLenght)
{
	std::ifstream stream(file, std::ios::in);
	if (!stream)
	{
		std::cout << "Error file " << file << " can't load!" << std::endl;
		return;
	}
	while (!stream.eof())
	{
		stream >> points[pointsLenght].name;
		stream >> points[pointsLenght].x;
		stream >> points[pointsLenght].y;
		pointsLenght++;
	}
	stream.close();
}
void WriteToFile(const char* file, Point* points, int sizeOfPoints)
{
	std::ofstream stream(file, std::ios::out);
	if (!stream)
	{
		std::cout << "Error file " << file << " can't load!" << std::endl;
		return;
	}
	for (size_t i = 0; i < sizeOfPoints; i++)
	{
		stream << points[i].name << ' ';
		stream << points[i].x << ' ';
		stream << points[i].y << ' ';
		stream << '\n';
	}
	stream.close();
}
void Print(Point* points, int sizeOfPoints)
{
	for (size_t i = 0; i < sizeOfPoints; i++)
	{
		std::cout << points[i].name << " " << points[i].x << " " << points[i].y << std::endl;
	}
}

int main()
{
	Point points[100];
	int pointsLength = 0;
	ReadFile("read.txt", points, pointsLength);
	Print(points, pointsLength);
	WriteToFile("write.txt", points, pointsLength);

    return 0;
}

