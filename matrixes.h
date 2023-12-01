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
Input Validation: M and N should have values of at least 2.*/
#include <iostream>
using namespace std;

class matrix {
	int m;
	int n;
	int** data;
public:
	matrix() {
		cout << "Initialising new matrix" << endl;
		int valid = false;
		while (!valid) {
			cout << "Enter M and N, seperated by spaces: " << endl;
			cin >> m >> n;
			if (m >= 2 && n >= 2) {
				valid = true;
				cout << "M and N must be greater or equal to 2" << endl;
			}
		}
		int line;

		data = new int* [m];
		for (int i = 0; i < m; i++) {
			data[i] = new int [n];
		}

		for (int y = 0; y < m; y++) {
			for (int x = 0; x < n; x++) {
				data[y][x] = rand() % 10;
			}
		}
	}

	void display() {
		for (int y = 0; y < m; y++) {
			for (int x = 0; x < n; x++) {
				cout << data[y][x] << ",";
			}
			cout << endl;
		}
	}

	void transpose() {
		// Switch round the rows and columns
		/* m = 3, n = 2 in this case
		* 1 2 3  SO indexes (0, 0), (0, 1), (0, 2)
		* 4 5 6              (1,0)  (1, 1),  (1, 2)
		* BECOMES
		* 1 4      (0,2) (1,2)
		* 2 5		(0, 1) (1, 1)
		* 3 6       (0, 0) (1, 0)
		*/

		// Make a new array of the right size - with m and n switched round
		cout << "Transposing..." << endl;
		int** oldArr;
		oldArr = data;

		data = new int* [n];
		for (int i = 0; i < n; i++) {
			data[i] = new int[m];
		}

		// Populate the new data arr
		for (int y = 0; y < m; y++) {
			for (int x = 0; x < n; x++) 
				data[x][y] = oldArr[y][x];
		}

		// Switch m and n
		int temp = n;
		n = m;
		m = temp;
	}

	~matrix () {
		for (int i = 0; i < m; i++) {
			delete[] data[i];
		}

		delete[] data;
	}
};

void matrixes() {
	matrix a = matrix();
	matrix b = matrix();
	cout << "Displaying a" << endl;
	a.display();
	a.transpose();
	a.display();
	cout << "Displaying b" << endl;
	b.display();
}

#endif