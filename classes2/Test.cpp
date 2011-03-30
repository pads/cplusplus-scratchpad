#include "Point.h"
using namespace abc;

int main() {
	// Created on the stack - defaults to 8k allocation, change with a compiler flag.
	// Will only live in memory until main completes.
	Point p1(100, 100), p2(400, 250), p3(200, 150);

	p1.moveBy(1, 1);
	p2.moveBy();
	p3.moveBy(1, 1);

	p1.display();
	p2.display();
	p3.display();

	// Created on the heap (can allocate at runtime and have full control of its life span).
	Point* ptr = new Point(22, 33);
	(*ptr).moveBy(1, 1);
	ptr->display();
	// Need to free this object from memory
	delete ptr;
}