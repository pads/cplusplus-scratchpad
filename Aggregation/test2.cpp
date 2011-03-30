#include "String.h"

// Pass by value -> copy constructor called.
void f(String t) {}

String g() {
	String green("Green");
	// Return by value -> copy constructor called.
	return green;
}

int main() {
	String s("Blue");
	String t(s); // explicit copy constructor call.
	f(s);
	//Operator is overloaded by String class to perform deep copy.
	s = g();

	String a("aaa");
	String b("bbb");
	String c("ccc");

	// c.operator=(b.operator=(a))
	c = b = a;
	a = a;
}