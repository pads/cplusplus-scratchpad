int main() {
	int x, y, z;
	y = 100;
	z = 200;
	// y++ will not work - assignment before increment.
	if (++y > 100) {
		x = 99;
	}
	x = y++ + z++;
	/* Above is same as:
	 * x = y + z;
	 * y++;
	 * z++; 
	 */
}