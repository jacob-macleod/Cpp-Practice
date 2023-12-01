#ifndef LENGTH_H
#define LENGTH_H
/*Design a Length class having two member variables: centimeters and millimeters.
The class should have constructors and member functions to input and return member
variables. It should also overload the operators ==, + and *.
Design another class Rectangle that should comprise two Length objects, representing
the two adjacent sides of a rectangle. The class should have the following member
functions:
setSides: This member function should ask the user to input the values of the sides of
the rectangle and accordingly set the value of the lengths by calling the set function of
the Length class.
getSides: This member function should call the get function of the Length class to
display the sides of the rectangle.
isSquare: This function should return a Boolean value True if the rectangle is a square,
that is, if. its sides are equal; otherwise it should return False.
getArea : This should return the area of the rectangle, which is. the product of its two
adjacent sides.
getPerimeter: This should return the perimeter of the rectangle, which is. the sum of
all its four sides.
Demonstrate the classes in a program that creates a Rectangle object and calls all its
member functions.*/


/*Design a Length class having two member variables: centimeters and millimeters.
The class should have constructors and member functions to input and return member
variables. It should also overload the operators ==, + and *.*/
#include <iostream>
using namespace std;

class Length {
public:
	int centimeters;
	int millimeters;
	float length;
	Length(int centimeters, int millimeters) : centimeters(centimeters), millimeters(millimeters) {
		length = centimeters + (millimeters / 10);
	}
	Length() {
		inputValues();
	}

	void operator+(Length otherLength) {
		centimeters += otherLength.centimeters;
		millimeters += otherLength.millimeters;
		length += otherLength.length;
	}

	int operator*(Length otherLength) {
		return length * otherLength.length;
	}

	bool operator==(Length l) {
		return (centimeters == l.centimeters) && (millimeters == l.millimeters) && (length == l.length);
	}

	void inputValues() {
		cout << "Enter the centimeters and millimeters seperated by a space: ";
		cin >> centimeters >> millimeters;
	}
};
/*Design another class Rectangle that should comprise two Length objects, representing
the two adjacent sides of a rectangle. The class should have the following member
functions:
setSides: This member function should ask the user to input the values of the sides of
the rectangle and accordingly set the value of the lengths by calling the set function of
the Length class.
getSides: This member function should call the get function of the Length class to
display the sides of the rectangle.
isSquare: This function should return a Boolean value True if the rectangle is a square,
that is, if. its sides are equal; otherwise it should return False.
getArea : This should return the area of the rectangle, which is. the product of its two
adjacent sides.
getPerimeter: This should return the perimeter of the rectangle, which is. the sum of
all its four sides.*/
class Rectangle {
	Length leftSide;
	Length rightSide;

public:
	void setSides() {
		leftSide = Length();
		rightSide = Length();
	}

	void getSides() {
		cout << "Left side is " << leftSide.centimeters << " centimeters and " << leftSide.millimeters << " long" << endl;
		cout << "Right side is " << rightSide.centimeters << " centimeters and " << rightSide.millimeters << " long" << endl;
	}

	bool isSquare() {
		return leftSide == rightSide;
	}

	int getArea() {
		return leftSide * rightSide;
	}
};

void length() {
	Rectangle r = Rectangle();
	r.setSides();
	r.getSides();
	cout << r.isSquare() << endl;
	cout << r.getArea();
}
#endif