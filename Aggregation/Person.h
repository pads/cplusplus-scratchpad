#ifndef PERSON_H
#define PERSON_H

#include "String.h"

class Person {
private:
	String firstName;
	String lastName;
	int age;
public:
	Person(const char*, const char*, int);
	void print();
}

#endif