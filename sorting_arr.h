#ifndef SORTING_ARR_H
#define SORTING_ARR_H
/*Write a program that uses two identical arrays of ten unordered strings. It should display the contents of the first array; then call a function to sort it using a
descending order bubble sort, modified to print out the array contents after each pass of the sort. Next the program should display the contents of the second array;
then call a function to sort it using a descending order selection sort, modified to print out the array contents after each pass of the sort.
*/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void printArr(string* arr, int length) {
	for (int index = 0; index < length; index++) {
		cout << arr[index] << ", ";
	}
	cout << endl;
}

int compareString(string str1, string str2) {
	// Initialise the string arrays
	char* strArr1 = new char[str1.size()];
	strcpy(strArr1, str1.c_str());

	char* strArr2 = new char[str2.size()];
	strcpy(strArr2, str2.c_str());

	// Return 0 if equal. If <0, first string is bigger. If >0, second string is bigger
	return strcmp(strArr1, strArr2);
}

void sortDescending(string* arr, int length) {
	bool swapMade = true;
	string temp;
	int res;

	while (swapMade) {
		swapMade = false;
		for (int index = 1; index < length; index++) {
			res = compareString(arr[index], arr[index - 1]);
			if (res > 0) {
				temp = arr[index];
				arr[index] = arr[index - 1];
				arr[index - 1] = temp;
				swapMade = true;
			}
		}

		cout << "Array contains: ";
		printArr(arr, length);
	}
}

void sortAscending(string* arr, int length) {
	bool swapMade = true;
	string temp;
	int res;

	while (swapMade) {
		swapMade = false;
		for (int index = 1; index < length; index++) {
			res = compareString(arr[index], arr[index - 1]);
			if (res < 0) {
				temp = arr[index];
				arr[index] = arr[index - 1];
				arr[index - 1] = temp;
				swapMade = true;
			}
		}

		cout << "Array contains: ";
		printArr(arr, length);
	}
}

#endif