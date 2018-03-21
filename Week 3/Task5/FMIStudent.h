#pragma once

class FMIStudent
{
public:
	FMIStudent();
	~FMIStudent();
	FMIStudent(const FMIStudent& student);
	FMIStudent& operator=(const FMIStudent& student);
	FMIStudent(char* name, char* lastName, char* birthTown, int age, int fn);

	void setAge(int age);
	void setFN(int fn);
	void setName(char* name);
	void setLastName(char* lastName);
	void setBirthTown(char* birthTown);

	int getAge() const;
	int getFN() const;
	char* getName() const;
	char* getLastName() const;
	char* getBirthTown() const;

	void load(char* name, char* lastName, char* birthTown, int age, int fn);
private:

	void copyFunc(const FMIStudent& student);
	void init(char* name, char* lastName, char* birthTown, int age, int fn);

	int fn;
	int age;
	char* name;
	char* lastName;
	char* birthTown;
};
