#ifndef SODUKU_H
#define SODUKU_H
/*The Lo Shu Magic Square is a grid with three rows and three columns that has the
following properties:
• The grid contains the numbers 1 through 9 exactly.
• The sum of each row, each column, and each diagonal all add up to the same
number. This is shown in Figure 8-18.
15
15
15 15
15 2 9 4
15 6 1 8
15 7 5 3
15
Figure 8-18
Write a program that simulates a magic square using a two-dimensional 3 × 3 array. It
should have a Boolean function isMagicSquare that accepts the array as an argument
and returns true if it determines it is a Lo Shu Magic Square and false if it is not. Test
the program with one array,*/
#include <iostream>
using namespace std;

bool isMagicSquare(int arr[3][3]) {
	// All rows, columns and diagonals add to the same number
	int rows[3] = { 0, 0, 0 };
	int columns[3] = { 0, 0, 0 };
	int diagonal = 0;

	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			columns[y] += arr[y][x];
			rows[x] += arr[y][x];

			if (x == y)
				diagonal += arr[y][x];
		}
	}
	for (int i = 0; i < 3; i++) {
		if (diagonal != rows[i] || diagonal != columns[i])
			return false;
	}

	return true;
}

void magicSquare() {
	int square[3][3] = {
		{4, 9, 2},
		{3, 5, 7},
		{8, 1, 6},
	};

	cout << "Result is " << isMagicSquare(square) << endl;
}
#endif