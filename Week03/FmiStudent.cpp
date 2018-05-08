#include "FmiStudent.h"

void FmiStudent::myStrCpy(char*& str1, const char* str2)
{
	if (str2)
	{
		unsigned length = 0;
		for (unsigned i = 0; str2[i] != '\0'; i++)
		{
			length++;
		}
		str1 = new char[length + 1];
		for (unsigned i = 0; str2[i] != '\0'; i++)
		{
			str1[i] = str2[i];
		}
		str1[length] = '\0';
	}
}

void FmiStudent::init()
{
	firstName = lastName = birthTown = nullptr;
	age = facultyNum = 0;
}

void FmiStudent::copy(const FmiStudent& other)
{
	myStrCpy(firstName, other.firstName);
	myStrCpy(lastName, other.lastName);
	myStrCpy(birthTown, other.birthTown);
	age = other.age;
	facultyNum = other.facultyNum;
}

void FmiStudent::destroy()
{
	delete[] firstName;
	delete[] lastName;
	delete[] birthTown;
}

FmiStudent::FmiStudent()
{
	init();
}

FmiStudent::FmiStudent(const FmiStudent& other)
{
	init();
	copy(other);
}

FmiStudent& FmiStudent::operator=(const FmiStudent& other)
{
	if (this != &other)
	{
		destroy();
		init();
		copy(other);
	}
	return *this;
}

FmiStudent::~FmiStudent()
{
	destroy();
}

FmiStudent::FmiStudent(const char* firstName, const char* lastName,const char* birthTown, const unsigned age, const unsigned facultyNum)
{
	myStrCpy(this->firstName, firstName);
	myStrCpy(this->lastName, lastName);
	myStrCpy(this->birthTown, birthTown);
	this->age = age;
	this->facultyNum = facultyNum;
}

char* FmiStudent::getFirstName()const
{
	return firstName;
}

void FmiStudent::setFirstName(const char* firstName)
{
	delete[] this->firstName;
	myStrCpy(this->firstName, firstName);
}

char* FmiStudent::getLastName()const
{
	return lastName;
}

void FmiStudent::setLastName(const char* lastName)
{
	delete[] this->lastName;
	myStrCpy(this->lastName, lastName);
}

char* FmiStudent::getBirthTown()const
{
	return birthTown;
}

void FmiStudent::setBirthTown(const char* birthTown)
{
	delete[] this->birthTown;
	myStrCpy(this->birthTown, birthTown);
}

unsigned FmiStudent::getAge()const
{
	return age;
}

void FmiStudent::setAge(const unsigned age)
{
	this->age = age;
}

unsigned FmiStudent::getFacultyNum()const
{
	return facultyNum;
}

void FmiStudent::setFacultyNum(const unsigned facultyNum)
{
	this->facultyNum = facultyNum;
}