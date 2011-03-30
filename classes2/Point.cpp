// quotes denotes a user library
#include <iostream>
#include "Point.h"
using namespace std;
namespace abc {
	Point::Point(int x0, int y0)	{
		// . takes precedence over *
		// this is implicit so don't need this anyway.
		// Just use x = x0; and y = y0;
		(*this).x = x0;
		(*this).y = y0;
	}

	// Deconstructor
	Point::~Point() {
		// Called just before objects are freed from memory.
		// This isn't needed if the class has no pointer variables.
	}

	// Default values live in the header file.
	void Point::moveBy(int dx, int dy) {
		x+= dx;
		y+= dy;
	}

	void Point::display() {
		// endl is a new line and a flush in one go.
		cout << "point is at: " << x << ", " << y << endl;
	}
}