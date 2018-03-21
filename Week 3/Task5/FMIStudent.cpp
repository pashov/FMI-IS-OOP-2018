#include "stdafx.h"
#include "FMIStudent.h"

//Constructors
FMIStudent::FMIStudent()
{
	this->age = 0;
	this->fn = 0;
	this->birthTown = nullptr;
	this->lastName = nullptr;
	this->name = nullptr;
}
FMIStudent::FMIStudent(char* name, char* lastName, char* birthTown, int age, int fn)
{
	this->init(name,lastName,birthTown,age,fn);
}
FMIStudent::FMIStudent(const FMIStudent& student)
{
	this->copyFunc(student);
}

//operators
FMIStudent& FMIStudent::operator=(const FMIStudent& student)
{
	if (this != &student)
	{
		delete[] this->birthTown;
		delete[] this->lastName;
		delete[] this->name;
		this->copyFunc(student);
	}
	return *this;
}
//Setters
void FMIStudent::setAge(int age)
{
	this->age = age;
}
void FMIStudent::setFN(int fn)
{
	this->fn = fn;
}
void FMIStudent::setName(char* name)
{
	if (this->name != nullptr)
	{
		delete[] this->name;
	}
	int length = 0;
	while (name[length++] != '\0');
	this->name = new char[length];
	for (size_t i = 0; i < length; i++)
	{
		this->name[i] = name[i];
	}
}
void FMIStudent::setLastName(char* lastName)
{
	if (this->lastName != nullptr)
	{
		delete[] this->lastName;
	}
	int length = 0;
	while (lastName[length++] != '\0');
	this->lastName = new char[length];
	for (size_t i = 0; i < length; i++)
	{
		this->lastName[i] = lastName[i];
	}
}
void FMIStudent::setBirthTown(char* birthTown)
{
	if (this->birthTown != nullptr)
	{
		delete[] this->birthTown;
	}
	int length = 0;
	while (birthTown[length++] != '\0');
	this->birthTown = new char[length];
	for (size_t i = 0; i < length; i++)
	{
		this->birthTown[i] = birthTown[i];
	}
}
//Getters
int FMIStudent::getAge() const
{
	return this->age;
}
int FMIStudent::getFN() const
{
	return this->fn;
}
char* FMIStudent::getName() const
{
	return this->name;
}
char* FMIStudent::getLastName() const
{
	return this->lastName;
}
char* FMIStudent::getBirthTown() const
{
	return this->birthTown;
}

//Methods
void FMIStudent::load(char* name, char* lastName, char* birthTown, int age, int fn)
{
	if (this->name != nullptr)
	{
		delete[] this->name;
	}
	if (this->lastName != nullptr)
	{
		delete[] this->lastName;
	}
	if (this->birthTown != nullptr)
	{
		delete[] this->birthTown;
	}
	this->init(name,lastName,birthTown,age,fn);

}

//Private Methods
void FMIStudent::init(char* name, char* lastName, char* birthTown, int age, int fn)
{
	int length = 0;
	while (name[length++] != '\0');
	this->name = new char[length];
	for (size_t i = 0; i < length; i++)
	{
		this->name[i] = name[i];
	}

	length = 0;
	while (lastName[length++] != '\0');
	this->lastName = new char[length];
	for (size_t i = 0; i < length; i++)
	{
		this->lastName[i] = lastName[i];
	}

	length = 0;
	while (birthTown[length++] != '\0');
	this->birthTown = new char[length];
	for (size_t i = 0; i < length; i++)
	{
		this->birthTown[i] = birthTown[i];
	}

	this->age = age;
	this->fn = fn;
}
void FMIStudent::copyFunc(const FMIStudent& student)
{
	int length = 0;
	while (student.name[length++] != '\0');
	this->name = new char[length];
	for (size_t i = 0; i < length; i++)
	{
		this->name[i] = student.name[i];
	}

	length = 0;
	while (student.lastName[length++] != '\0');
	this->lastName = new char[length];
	for (size_t i = 0; i < length; i++)
	{
		this->lastName[i] = student.lastName[i];
	}

	length = 0;
	while (student.birthTown[length++] != '\0');
	this->birthTown = new char[length];
	for (size_t i = 0; i < length; i++)
	{
		this->birthTown[i] = student.birthTown[i];
	}

	this->age = student.age;
	this->fn = student.fn;
}
//Destructor
FMIStudent::~FMIStudent()
{
	delete[] this->birthTown;
	delete[] this->name;
	delete[] this->lastName;
}