#ifndef MATRIXES_H
#define MATRIXES_H
/*An M * N matrix is a two-dimensional array with M rows and N columns. Write a
modular program that manipulates two matrices A and B, each of the same size. The
program should ask the user to enter values for M and N, and, using nested for loops,
populate both matrices with random numbers between 1 and 10. The program should
then use separate functions to perform the following operations:
• Display each matrix.
• Transpose the first matrix, by changing the columns into rows and the rows into
columns, and display it.
• Display the sum matrix of the two matrices, where each element in the sum
matrix is the sum of the corresponding elements in the two matrices.
Input Validation: M and N should have values of at least 2.*/
#include <iostream>
using namespace std;

class matrix {
	int m;
	int n;
	int* data;
public:
	matrix() {
		cout << "Initialising new matrix" << endl;
		cout << "Enter M and N, seperated by spaces: " << endl;
		cin >> m >> n;
		data = new int[m, n];
		int line;

		for (int y = 0; y < m; y++) {
			for (int x = 0; x < n; x++) {
				cout << "Enter the value for (" << x << ", " << y << "): ";
				cin >> line;
				cout << "Saving " << line << " to " << y << "," << x << endl;
				data[y, x] = line;
				cout << "Saved " << data[y, x] << endl;
			}
		}
	}

	int* get() {
		return data;
	}

	void display() {
		cout << data[0, 0];
		for (int y = 0; y < m; y++) {
			for (int x = 0; x < n; x++) {
				cout << "Displaying " << y << "," << x << endl;
				cout << data[y, x] << ",";
			}
			cout << endl;
		}
	}
};

void matrixes() {
	matrix a = matrix();
	//matrix b = matrix();
	cout << "Displaying a" << endl;
	a.display();
	cout << "Displaying b" << endl;
	//b.display();
}

#endif