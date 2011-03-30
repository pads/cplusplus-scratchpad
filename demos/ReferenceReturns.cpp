#include <iostream>
using namespace std;

int& modify(int* arr, int index) {
	if(index < 0) throw "too small";
	if(index >= 5) throw "too large";
	return arr[index];
}

int main() {
	int x[5] = {2, 4, 6, 10, 20};
	/* Modify returns a reference
	 * therefore modify is the reference itself.
	 * Here it represents arr[3] from modify.
	 */
	modify(x, 3) = 99;
	try {
		modify(x, 33) = 99;
	} catch (const char* exception) {
		cout << exception << endl;
	}
}