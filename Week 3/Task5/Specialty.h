#pragma once
#include "FMIStudent.h"
#include <iostream>
#include <fstream>

class Specialty
{
public:
	Specialty();
	~Specialty();
	void read(char* location);
	void add(FMIStudent student);
	int getSize() const;
	bool remove(int fn);
	FMIStudent& operator[](int position);
private:
	void removeAt(int pos);
	void resize();
	FMIStudent* students;
	size_t size;
	size_t capacity;
};
