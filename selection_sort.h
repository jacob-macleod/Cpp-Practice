#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

template <class T>
void selection_sort(T* arr, T size) {
	// Find the smallest. Swap with first
	// FInd second smallest, swap with second
	// And so on till the end of file
	int smallestItem;
	int smallestIndex;
	// For each element
	for (int index = 0; index < size; index++) {
		// Find the smallest item
		smallestItem = *(arr + index);
		smallestIndex = index;
		for (int item = index; item < size; item++) {
			if (*(arr + item) < smallestItem) {
				smallestItem = *(arr + item);
				smallestIndex = item;
			}
		}

		// Swap the item ad index and the item at smallest index
		*(arr + smallestIndex) = *(arr + index);
		*(arr + index) = smallestItem;
	}
}

#endif