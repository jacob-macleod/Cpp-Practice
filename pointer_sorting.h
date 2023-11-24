//
// Created by jacob on 24/11/23.
//

#ifndef C___LEARNING_POINTER_SORTING_H
#define C___LEARNING_POINTER_SORTING_H
#include <iostream>
#include <cstring>
using namespace std;

/*Consider a company that needs to sort an array Person data[10] of structures of type
Person by name.
struct Person
{
string name;
int age;
}
In real life the Person structures may have many members and occupy a large area of
memory, making it computationally expensive to move Person objects around while
sorting. You can define an auxiliary array Person *pData[10], setting each entry of
pData[k] to point to the corresponding entry of data[k]. Write a program that sorts
the array of pointers so that when you go through pData in increasing order of index k,
the entries pData[k] point to Person objects in ascending alphabetic order of names.*/

struct Person {
    string name;
    int age;
};

// Return 1 if str1 > str2
// Return 0 if str2 > str1
// Return 2 if they are equal
int compareStr(string str1, string str2) {
    int smallStrLen;
    char * strArr1 = new char[str1.size()];
    strcpy(strArr1, str1.c_str());

    char * strArr2 = new char[str2.size()];
    strcpy(strArr2, str2.c_str());

    if (str1.size() > str2.size())
        smallStrLen = str2.size();
    else
        smallStrLen = str1.size();

    for (int i = 0; i < smallStrLen; i++) {
        if (static_cast<int>(strArr1[i]) > static_cast<int>(strArr2[i])) {
            return 1;
        } else if (static_cast<int>(strArr1[i]) < static_cast<int>(strArr2[i])) {
            return 0;
        }
        // Otherwise, the next line is reached
    }

    return 2;
}

void pointer_sorting () {
    // Set up the array
    Person data[10];
    data[0] = {"Alice", 25};
    data[1] = {"Emily", 30};
    data[2] = {"Charlie", 20};
    data[3] = {"David", 28};
    data[4] = {"Bob", 22};
    data[5] = {"Frank", 35};
    data[6] = {"Grace", 27};
    data[7] = {"Henry", 19};
    data[8] = {"Ivy", 31};
    data[9] = {"Jack", 24};
    Person *pData = new Person[10];
    Person temp;

    for (int i = 0; i < 10; i ++) {
        *(pData + i) = data[i];
    }
    // Bubble sort in ascending order
    bool swapMade = false;
    bool loop = true;
    while (loop) {
        swapMade = false;
        // For each element in pData
        for (int i = 1; i < 10; i ++) {
            // If the item is smaller than the previous one
            int res = compareStr((*(pData + i)).name, (*(pData + i - 1)).name);
            if (res == 0) {
                // Swap them
                temp = *(pData + i);
                *(pData + i) = *(pData + i - 1);
                *(pData + i - 1) = temp;
                swapMade = true;
            }
        }

        if (!swapMade) {
            loop = false;
        }
    }

    for (int i = 1; i < 10; i ++) {
        cout << "Person " << i << " name: " << (*(pData + i)).name << " age " << (*(pData + i)).age << endl;
    }

}
#endif //C___LEARNING_POINTER_SORTING_H
