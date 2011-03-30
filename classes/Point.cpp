#include <iostream>
using namespace std;
// Can use struct but is not the same as a C struct here.
class Point {
private:
	int x;
	int y;
public:
	Point() {
		x = 0;
		y = 0;
	}

	Point(int x0, int y0)	{
		// . takes precedence over *
		// this is implicit so don't need this anyway.
		// Just use x = x0; and y = y0;
		(*this).x = x0;
		(*this).y = y0;
	}

	// Copy constructor
	Point(const Point& copy) {

	}

	// Deconstructor
	~Point() {
		// Called just before objects are freed from memory.
		// This isn't needed if the class has no pointer variables.
	}

	void moveBy(int dx = 1, int dy = 1) {
		x+= dx;
		y+= dy;
	}

	void display() {
		// endl is a new line and a flush in one go.
		cout << "point is at: " << x << ", " << y << endl;
	}
};

int main() {
	// Created on the stack - defaults to 8k allocation, change with a compiler flag.
	// Will only live in memory until main completes.
	Point p1(100, 100), p2(400, 250), p3(200, 150);
	// p4 cannot use brackets as compiler will think it's a function call.
	Point p4;

	p1.moveBy(1, 1);
	p2.moveBy();
	p3.moveBy(1, 1);
	p4.moveBy(1, 1);

	p1.display();
	p2.display();
	p3.display();
	p4.display();

	// Created on the heap (can allocate at runtime and have full control of its life span).
	Point* ptr = new Point(22, 33);
	(*ptr).moveBy(1, 1);
	ptr->display();
	// Need to free this object from memory
	//TODO
}