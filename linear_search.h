#ifndef LINEAR_SEARCH_H
#define LINEAR_SEARCH_H
#include <iostream>
#include <string>
using namespace std;

template <class T>
string linear_search(T arr[], int size, T item_to_find) {
	for (int index = 0; index < size; index++) {
		if (*(arr+index) == item_to_find)
			return "Item found at index " + to_string(index);
	}
	return "Item not found";
}

#endif