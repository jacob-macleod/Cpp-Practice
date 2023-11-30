#include <iostream>
#include <string>
#include "pointer_arrays.h"
#include "box_of_balls.h"
#include "pointer_sorting.h"
#include "binary_search.h"
#include "linear_search.h"
using namespace std;

int main() {
    int* arr = new int[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 13, 15, 67};
    int size = 14;
    cout << linear_search(arr, 47) << endl;
    return 0;
}
