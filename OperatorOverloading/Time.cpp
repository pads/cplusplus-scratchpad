#include <iostream>
using namespace std;

class Time {
// The function implementation can live outside of the class
// but access private variables - the best of both worlds!
friend Time operator+(const Time& time1, const Time& time2);
private:
	int hours;
	int minutes;
public:
	// Also a cast from int to Time.
	Time(int mins) : hours(mins / 60), minutes(mins % 60) {} 
	Time() : hours(0), minutes(0) {}
	Time(int hrs, int mins) : hours(hrs), minutes(mins) {}
	// Explicit copy constructor - bypassed when Time objects are passed by reference.
	Time(const Time& original) : hours(original.hours), minutes(original.minutes) {
		cout << "copy constructor called." << endl;
	}
	~Time() {
		cout << "Destructor called." << endl;
	}
	// Reverse cast - not allowed a return type - it is already implied here as int.
	operator int() {
		return hours * 60 + minutes;
	}
};

// Outside of the class, both parameters required as 'this' doesn't exist.
// By living here - it can be made into a template function
// If the return type is a reference - it will refer to the short-lived result object, argh!
Time operator+(const Time& time1, const Time& time2) {
	Time result;
	result.hours = time1.hours + time2.hours;
	result.minutes = time1.minutes + time2.minutes;
	if(result.minutes >= 60) {
		result.minutes -= 60;
		result.hours++;
	}
	return result;
}
// Don't have to return anything as we are using references.
// However, this could be called as t = t1 += t2;
// We can return a reference this time as it is simply referring
// to an existing reference created outside the scope.
Time& operator+=(Time& time1, const Time& time2) {
	// Calls the operator above, so we don't need to be a friend function here.
	time1 = time1 + time2;
	return time1;
}

int main() {
	Time t;

	int x = 125;
	t = (Time)x; // Same as below.
	t = Time(x); // We can overload the cast using a single parameter constructor.
	int y = (int)t; // y = t.operator int()
	y = -t; // y = t.operator-()

	Time t1(4, 45);
	Time t2(3, 25);

	t = t1 + t2; // this can work without the overloaded + by using implicit casts as below:
	// Time(t) = (int)t1 + (int)t2
	// compiler calls our single parameter constructor and operator int() functions.
	// Block this using the explicit keyword against the above.

	//t = operator+(t1, t2);
	//t = t1.operator+(t2);

	//t1.operator+(8) - could be a way to add 8 minutes to a time object.
	//8.operator+(t1) - does not work, 8 is not an object.

	t1 += t2;
}