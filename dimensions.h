#ifndef DIMENSIONS_H
#define DIMENSIONS_H
#include <iostream>
using namespace std;

// A 2d point
class point {
public:
	int x;
	int y;

	// If you want to enter x and y as parameters
	point(int x, int y) : x(x), y(y) {};
	point() {
		cout << "Enter x: ";
		cin >> x;
		cout << "Enter y: ";
		cin >> y;
	}

	// Overloads + operator. When you do p1 + p2, p2 is passed as an argument to the p1 object
	point operator+(point otherP) {
		return point(x + otherP.x, y + otherP.y);
	}

	bool operator==(point otherP) {
		return (x == otherP.x && y == otherP.y);
	}

	void operator=(point otherP) {
		x = otherP.x;
		y = otherP.y;
	}

	void print() {
		cout << "(" << x << ", " << y << ")" << endl;
	}
};

void dimension() {
	point p1 = point(5, 7);
	point p2 = point(4, 8);

	(p1 + p2).print();
	cout << (p1 == p2) << endl;
	p1.print();
	p1 = p2;
	p1.print();
}
#endif