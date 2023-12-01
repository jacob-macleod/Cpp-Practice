#include <iostream>
#include <string>
#include "pointer_arrays.h"
#include "box_of_balls.h"
#include "pointer_sorting.h"
#include "binary_search.h"
#include "linear_search.h"
#include "bubble_sort.h"
#include "selection_sort.h"
#include "baseball.h"
#include "sorting_arr.h"
#include "word_parser.h"
#include "country_data.h"
#include "identical_arrays.h"
#include "meteorologist.h"
#include "matrixes.h"
#include "soduku.h"
#include "dmv.h"
#include "vending_machine.h"
#include "switch_ends.h"
using namespace std;

int main() {
    int* arr = new int[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 13, 15, 67};
    //int* arr = new int [] {1, 2, 4, 1, 2, 6, 7, 3, 8, 7, 5, 2, 8, 9, 2, 4, 5};
    //int size = 17;
    //string* arr = new string[]{ "aHello", "cMy", "bName", "fIs", "hjacob", "gand", "zI", "aLike", "Coding" };
    //string* arr2 = new string[]{ "Hello", "My", "Name", "Is", "jacob", "and", "I", "Like", "Coding" };
    //int size = 9;
    printArr(arr, 13);
    switchEnds(arr, 13);
    printArr(arr, 13);
    return 0;
}
