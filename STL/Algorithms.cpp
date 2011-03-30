#include <map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

typedef const pair<string, int> PAIR;
typedef map<string, int> MAP;

// This is a functor - object impersonating a function
class Query {
private:
	int salary;
public:
	Query(int salary) : salary(salary) {}
	bool operator()(PAIR &item) {
		if(item.second < salary) {
			return true;
		} else {
			return false;
		}
	}
};

int main() {
	MAP salaries;
	MAP::iterator i;
	salaries["John"] = 45000;
	salaries["Mary"] = 23000;
	salaries["Zoe"] = 31000;
	salaries["Sue"] = 17000;
	salaries["Bill"] = 44000;

	Query q(40000);
	i = find_if(salaries.begin(), salaries.end(), q);
	while(i != salaries.end()) {
		cout << i->first << "," << i->second << endl;
		i++;
	}
}