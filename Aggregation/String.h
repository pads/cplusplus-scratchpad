#ifndef STRING_H
#define STRING_H

#include <cstdlib>
#include <cstring>
using namespace std;

class String {
private:
	char* text;
	// This would ban object assignment all together - good for locks etc...
	//String& operator=(const String&)
public:
	String(const char* t);
	String(const String&);
	~String();
	void print();
	String& operator=(const String&);
};

#endif