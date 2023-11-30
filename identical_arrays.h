#ifndef IDENTICAL_ARRAYS_H
#define IDENTICAL_ARRAYS_H
/*Two arrays are said to be identical if they have same value in the same index for all
indices of the arrays. Create a program with a function that accepts two one-dimensional
arrays and their sizes as arguments. The function should return 1 if the two arrays are
identical, otherwise it should return 0. The main should ask the user to input the size of
the arrays and their values. It should then display whether they are identical or not.*/
#include <iostream>
#include <string>
using namespace std;

void identical_arrays() {
	int size1;
	int size2;
	cout << "Enter the size of each array, seperated by a space: ";
	cin >> size1 >> size2;
	bool identical;
	if (size1 == size2)
		identical = true;
	else
		identical = false;

	int* arr1 = new int[size1];
	int* arr2 = new int[size2];

	for (int i = 0; i < size1; i++) {
		cout << "Enter the data for index " << to_string(i) << " of array 1: ";
		cin >> arr1[i];
	}
	for (int i = 0; i < size2; i++) {
		cout << "Enter the data for index " << to_string(i) << " of array2: ";
		cin >> arr2[i];
		if (identical) {
			if (arr2[i] != arr1[i])
				identical = false;
		}
	}

	cout << ((identical) ? "Arrays are identical" : "Arrays are not identical") << endl;

}

#endif