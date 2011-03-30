#include <string> //C++
#include <cstring> //C
using namespace std;

void c() {
	char name[32];
	char firstName[] = "Ben";
	char lastName[] = "Paddock";
	strcpy(name, firstName);
	strcat(name, " ");
	strcat(name, lastName);
}

void cplusplus() {
	string name;
	string firstName("Ben");
	string lastName("Paddock");
	name = firstName + " " + lastName;
	
	//Convert C++ string to C char* (string)
	int size = name.size();
	char* ptr = new char[size + 1];
	strcpy(ptr, name.c_str());
}

// This is how typdefs work - string is a typedef.
void typedefs() {
	int* p1;
	int* p2;
	int x = 100;
	int y = 200;
	p1 = &x;
	p2 = &y;

	typedef int* INT_PTR;
	INT_PTR q1, q2;
	q1 = &x;
	q2 = &y;
}

int main() {
	typedefs();
	c();
	cplusplus();
}