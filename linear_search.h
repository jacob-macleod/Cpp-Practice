#ifndef LINEAR_SEARCH_H
#define LINEAR_SEARCH_H
#include <iostream>
#include <string>
using namespace std;

template <class T>
string linear_search(T* arr, T item_to_find) {
	int index = 0;
	for (T item : arr) {
		if (item == item_to_find)
			return "Item found at index " + to_string(index);
		index++;
	}
	return "Item not found";
}

#endif