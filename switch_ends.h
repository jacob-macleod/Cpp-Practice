#ifndef SWITCH_ENDS_H
#define SWITCH_ENDS_H
/*Write a function
void switchEnds(int *array, int size);
that is passed the address of the beginning of an array and the size of the array. The
function swaps the values in the first and last entries of the array.*/

void switchEnds (int *array, int size) {
	int last;
	last = *(array + size - 1);
	*(array + size - 1) = *array;
	*array = last;
}
#endif