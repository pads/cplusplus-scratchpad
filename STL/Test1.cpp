#include <iostream>
#include <string>
#include <list>
using namespace std;

int main() {
	list<string> myList;
	list<string>::iterator i;
	myList.push_back("London");
	myList.push_back("Paris");
	myList.push_back("Madrid");
	myList.push_back("Copenhagen");
	myList.push_back("Athens");

	for(i = myList.begin(); i != myList.end(); i++) {
		cout << *i << endl;
	}
}