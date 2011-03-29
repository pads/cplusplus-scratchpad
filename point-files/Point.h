namespace abc {
	class Point {
	private:
		int x;
		int y;
	public:
		Point(int x0 = 0, int y0 = 0);
		~Point();
		void moveBy(int dx = 1, int dy = 1);
		void display();
	};
}