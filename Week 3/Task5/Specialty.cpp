#include"stdafx.h"
#include "Specialty.h"

//Constructors
Specialty::Specialty()
{
	this->students = nullptr;
	this->capacity = 8;
	this->size = 0;
}
//Methods
void Specialty::add(FMIStudent student)
{
	if (this->students == nullptr)
	{
		this->students = new FMIStudent[this->capacity];
	}
	if (this->size >= this->capacity)
	{
		this->resize();
	}
	this->students[this->size++] = student;
}
int Specialty::getSize() const
{
	return this->size;
}
bool Specialty::remove(int fn)
{
	for (size_t i = 0; i < this->size; i++)
	{
		if (this->students[i].getFN() == fn)
		{
			this->removeAt(i);
			return true;
		}
	}
	return false;
}
void Specialty::read(char* location)
{
	//Will work only in perfect condition!!!!!!
	std::ifstream stream(location, std::ios::in);
	if (!stream)
	{
		std::cout << "Error : can't load file at : " << location << " !!!" << std::endl;
		return;
	}
	while (!stream.eof())
	{
		char name[100];
		stream >> name;
		char lastName[100];
		stream >> lastName;
		char birthTown[100];
		stream >> birthTown;
		int age;
		stream >> age;
		int fn;
		stream >> fn;
		FMIStudent temp(name,lastName,birthTown,age,fn);
		this->add(temp);
	}
}
//operators
FMIStudent& Specialty::operator[](int position)
{
	return this->students[position];
}

//Private Methods
void Specialty::resize()
{
	this->capacity *= 2;
	FMIStudent* temp = new FMIStudent[this->capacity];
	for (size_t i = 0; i < this->size; i++)
	{
		temp[i] = this->students[i];
	}
	delete[] this->students;
	this->students = temp;
}
void Specialty::removeAt(int pos)
{
	FMIStudent* temp = new FMIStudent[this->capacity];
	size_t j = 0;
	for (size_t i = 0; i < this->size; i++)
	{
		if (pos != i)
		{
			temp[j++] = this->students[i];
		}
	}
	this->size--;
	delete[] this->students;
	this->students = temp;
}
//Destructor
Specialty::~Specialty()
{
	delete[] this->students;
}
