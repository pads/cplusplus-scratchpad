#include <iostream>
#include <vector>
using namespace std;

class Shape {
public:
	// compiler introduces an extra pointer to enable polymorphism.
	virtual void show() { cout << "Showing Shape" << endl; };
	virtual void draw() { cout << "Drawing Shape" << endl; };
	//abstract
	virtual void hide() = 0;
};

class Ellipse : public Shape {
public:
	// virtual is implicitly provided by shape.
	void show() { cout << "Showing Ellipse" << endl; }
	void draw() { cout << "Drawing Ellipse" << endl; }
	void hide() { cout << "Hiding Ellipse" << endl; }
};

class Triangle : public Shape  {
public:
	void show() { cout << "Showing Triangle" << endl; }
	void draw() { cout << "Drawing Triangle" << endl; }
	void hide() { cout << "Hiding Triangle" << endl; }
};

class Polygon : public Shape  {
public:
	void show() { cout << "Showing Polygon" << endl; }
	void draw() { cout << "Drawing Polygon" << endl; }
	void hide() { cout << "Hiding Polygon" << endl; }
};

void showEverything(vector<Shape*>& shapes) {
	vector<Shape*>::iterator i;
	for(i = shapes.begin(); i != shapes.end(); ++i) {
		Shape& theShape = **i;
		theShape.show();
	}
}

// Copy constructor will cause unexpected results here
// if shape is passed by value ;)
void drawAnything(Shape& s) {
	s.draw(); // runtime/early/dynamic binding, opposite below.
	s.Shape::draw(); //force the shape implementation to run.
}

int main() {
	Ellipse e1, e2;
	Triangle t1, t2;
	Polygon p1, p2;

	drawAnything(e1);
	drawAnything(p2);

	// Must be pointers - sub-classed objects can be different sizes.
	vector<Shape*> shapes;
	shapes.push_back(&e1);
	shapes.push_back(&e2);
	shapes.push_back(&t1);
	shapes.push_back(&t2);
	shapes.push_back(&p1);
	shapes.push_back(&p2);

	showEverything(shapes);
}