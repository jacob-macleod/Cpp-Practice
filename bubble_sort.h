#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H
#include <iostream>
using namespace std;

template <class T>
void printArr(T* arr, T size) {
	for (int i = 0; i < size; i++) {
		cout << to_string(*(arr + i)) << ", ";
	}
	cout << endl;
}

template <class T>
void bubble_sort(T* arr, T size) {
	bool swapMade = true;
	T temp;
	while (swapMade) {
		swapMade = false;
		for (int i = 1; i < size; i++) {
			if (*(arr + i) < *(arr + i - 1)) {
				temp = *(arr + i);
				*(arr + i) = *(arr + i - 1);
				*(arr + i - 1) = temp;
				swapMade = true;
			}
		}
	}
}

#endif