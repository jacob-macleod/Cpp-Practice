//
// Created by jacob on 21/11/23.
//

#ifndef C___LEARNING_POINTER_ARRAYS_H
#define C___LEARNING_POINTER_ARRAYS_H
#include <iostream>
#include <memory>
using namespace std;
/*Write a program that asks the user to input the number of elements of an array, the size,
and creates a dynamic array, numArray, of integers having size number of elements. It
        should then create two arrays, positiveArray containing the positive numbers and
negativeArray containing the negative numbers of numArray. You may use smart
pointers to the arrays.*/

void pointer_arrays () {
    int size;
    cout << "How many elements do you want to be in the array? ";
    cin >> size;
    //int arr[size];
    unique_ptr<int[]> numArray = make_unique<int[]>(size);
    unique_ptr<int[]> positiveArray = make_unique<int[]>(size / 2);
    int posIndex = 0;
    unique_ptr<int[]> negativeArray = make_unique<int[]>(size / 2);
    int negIndex = 0;

    shared_ptr<int> a = make_shared<int>();
    *a = 7;


    for (int i = 0; i < size; i++) {
        numArray[i] = i;
        cout << "numArray[" << i << "] is " << i << endl;
        // If the number is positive
        if ((i % 2) == 0) {
            positiveArray[posIndex] = i;
            cout << "positiveArray[" << posIndex << "] is " << i << endl;
            posIndex ++;
        } else {
            negativeArray[negIndex] = i;
            cout << "negativeArray[" << negIndex << "] is " << i << endl;
            negIndex ++;
        }
    }
}

#endif //C___LEARNING_POINTER_ARRAYS_H
