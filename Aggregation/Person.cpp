#include <iostream>
#include "Person.h"
using namespace std;

Person::Person(const char* firstName, const char* lastName, int age) 
: firstName(firstName), lastName(lastName), age(age) {

}

void Person::print() {
	firstName.print(); cout << ",";
	lastName.print(); cout << ",";
	cout << age << endl;
}