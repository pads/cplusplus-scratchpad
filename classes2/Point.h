// Makes sure this header file is not compiled more than once 
// if referenced from multiple location.
#ifndef POINT_H
#define POINT_H

namespace abc {
	class Point {
	private:
		int x;
		int y;
	public:
		Point(int x0 = 0, int y0 = 0);
		~Point();
		void moveBy(int dx = 1, int dy = 1);
		void display();
	};
}

#endif