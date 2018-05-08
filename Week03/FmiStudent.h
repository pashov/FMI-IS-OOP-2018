#pragma once

class FmiStudent
{
private:
	char* firstName;
	char* lastName;
	char* birthTown;
	unsigned age;
	unsigned facultyNum;

private:
	void myStrCpy(char*&, const char*);
	void init();
	void copy(const FmiStudent&);
	void destroy();

public:
	FmiStudent();
	FmiStudent(const FmiStudent&);
	FmiStudent& operator=(const FmiStudent&);
	~FmiStudent();

public:
	FmiStudent(const char*, const char*, const char*, const unsigned, const unsigned);

	char* getFirstName()const;
	void setFirstName(const char*);

	char* getLastName()const;
	void setLastName(const char*);

	char*  getBirthTown()const;
	void setBirthTown(const char*);

	unsigned getAge()const;
	void setAge(const unsigned);

	unsigned getFacultyNum()const;
	void setFacultyNum(const unsigned);
};

