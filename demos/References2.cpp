int main() {
	int x = 100;
	int& xx = x;

	int* ptr = &xx;
	int*& ptr2  = ptr;

	x++;
	xx++;
	(*ptr)++;
	(*ptr2)++;
}