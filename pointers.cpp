int main() {
	int x = 100;
	int y = 200;
	int* ptr1; //, ptr2 will create an int!
	/*
	 * int* ptr1;
	 * int* ptr2;
	 * or int *ptr1, *ptr2;
	 */
	int* ptr2;

	ptr1 = &x;
	ptr2 = &y;
	// Assigns address of x to ptr2
	ptr2 = ptr1;
	// x = x
	*ptr2 = *ptr1;
}

int main() {
	int x = 100;
	int* p;
	int** q;
	
	p = &x;
	q = &p;
	// *p gets value of x
	// **q gets value of x
	// &x is address of x
	// p is address of x
	// q is address of p
	// &p is address of q

	// x = x * x
	x = *p * **q
}

#include <cstdio>
using namespace std;

int main() {
	int x = 100;
	int* p;
	int** q;

	p = &x;
	q = &p;
	
	// Cannot do this - level 1 to level 2 pointer
	// p = q;
	// Cannot do this - incompatible types
	// p = x;
	// Casting fixes compile error but usually introduces invalid address!
	// p = (int*)x;
	// Pointer arithmetic here - increments memory address by 3.
	// p = &x + 3;

	// All equivalent
	scanf("%i", &x);
	scanf("%i", p);
	scanf("%i", *q);
}