/*void f(int p[]) {
	// will be 4 bytes
	// p is a pointer to first element only.
	int size = sizeof(p);
}*/

void f(int* p) {
	int size = sizeof(p);
}

int main() {
	// read-only
	int a[5] = {2, 3, 5, 7, 11};
	// will be 20 bytes
	int size = sizeof(a);
	f(a);
	
	// All do the same thing!
	int y;
	y = a[4];
	y = *(a + 3);
	y = *(2 + a);
	y = 1[a];

	// writable
	int* p;
	p = a;
	//*p = 2;
	// p[0] = 2;
	// traverse up and down the array
	p++;
	p++;
	p[-1] = 99;
	// Will access memory out of the array!
	// p[4] = 88;
	p--;
	p--;
}