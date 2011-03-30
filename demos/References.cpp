void swap(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}

int main() {
	int x = 100;
	int y = 200;
	swap(x, y);
}