#include <iostream>
#include <cstring>
#include "String.h"
using namespace std;

String::String(const char* t) {
	// allocate heap space that is enough to take
	// the contents of the char array + null terminator.
	//text = (char*)malloc(strlen(t) + 1);
	text = new char[strlen(t) + 1]; // Does as above.
	strcpy(text, t);
}
// Shallow copy constructor.
// Bad because text is pointed to by both original and copy here.
/*&String::String(const String& original)
: text(original.text) {}*/

// Deep copy.
// Good because new memory is allocated for text now.
&String::String(const String& original) {
	text = new char[strlen(original.text) + 1];
	strcpy(text, original.text);
}

String::~String() {
	// We have to free this or we get a memory leak!
	//free(text);
	delete [] text; //[] makes sure it deletes everything in the array (when dealing with objects).
}

void String::print() {
	cout << text;
}
// Deep assignment
String& String::operator=(const String& rhs) {
	// prevent self reassignment.
	if(this == &rhs) return *this;
	delete [] text;
	text = new char[strlen(rhs.text) + 1];
	strcpy(text, rhs.text);
	return *this;
}