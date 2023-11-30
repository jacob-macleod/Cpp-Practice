#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H
#include <iostream>
#include <string>
using namespace std;

string binary_search(int *arr, int length, int item_to_find) {
	// Define variables
	int bottom = 0;
	int top = length - 1;
	int midpoint;
	int iterations = 0;

	// While looping
	while (iterations < length) {
		midpoint = (top + bottom) / 2;
		if (*(arr + midpoint) > item_to_find)
			top = midpoint - 1;
		else if (*(arr + midpoint) < item_to_find)
			bottom = midpoint + 1;
		else
			return "Item found at index " + to_string(midpoint);
		iterations++;
	}

	// If the item is not found
	return "Item not found";
}

#endif