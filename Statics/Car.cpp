#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Car {
private:
	static int count;
	string make;
	int cc;
	int cost;
	// Cannot create a car unless the static createCar is called.
	Car(string make, int cc, int cost) : make(make), cc(cc), cost(cost) { 
		count++;		
	}
	Car(Car& original) {}
public:
	// Turned this class into a factory.
	static Car* createCar(string make, int cc, int cost) {
		if(Car::howMany() < 3) {
			return new Car(make, cc, cost);
		} else {
			// Should throw an exception here really.
			return 0;
		}
	}
	~Car() { count--; }
	static int howMany() { return count; }
	int getCost() { return cost; }
};

// Allocate static memory at compile time - Java allocates when classes are loaded into memory.
int Car::count = 0;

vector<Car*> list;

void allocateCars() {
	list.push_back(Car::createCar("Porche", 3845, 32000));
	list.push_back(Car::createCar("Morgan", 1997, 17000));
	list.push_back(Car::createCar("Jaguar", 2800, 46000));
	// will work - just adds 0 (the null pointer).
	list.push_back(Car::createCar("Lada", 998, 100));

	cout << "[Allocate] Number of cars: " << Car::howMany() << endl;
	cout << "[Allocate] List size: " << list.size() << endl;
}

void useCars() {
	int n = Car::howMany();
	int cost = list[0]->getCost();
	cost = list[1]->getCost();
	cost = list[2]->getCost();
}

void deallocateCars() {
	while(!list.empty()) {
		// Cannot go forward in list when modifying it.
		delete list.back();
		// Without this the list size will not return to 0.
		list.pop_back();
	}
	cout << "[Deallocate] Number of cars: " << Car::howMany() << endl;
	cout << "[Deallocate] List size: " << list.size() << endl;
}

int main() {
	allocateCars();
	useCars();
	deallocateCars();
}