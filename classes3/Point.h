#include <iostream>
using namespace std;
namespace abc {
	class Point {
	private:
		int x;
		int y;
	public:
		Point(int x0 = 0, int y0 = 0) : x(x0), y(y0) {}
		~Point() {}
		void moveBy(int dx = 1, int dy = 1) {
			x+= dx;
			y+= dy;
		}
		void display() {
			cout << "point is at: " << x << ", " << y << endl;
		}
	};
}