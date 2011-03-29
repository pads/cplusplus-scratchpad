int main() {
	int a = 5;
	double b;
	// easier to search for casts than using ()
	b = static_cast<double>(a + 10) / 7;
}