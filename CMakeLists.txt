cmake_minimum_required(VERSION 3.26)
project(C___Learning)

set(CMAKE_CXX_STANDARD 20)

add_executable(C___Learning main.cpp
        pointer_arrays.h
        box_of_balls.h
        pointer_sorting.h "binary_search.h" "linear_search.h" "bubble_sort.h" "selection_sort.h" "baseball.h" "sorting_arr.h" "word_parser.h" "country_data.h" "wheather_analysis.h" "identical_arrays.h" "meteorologist.h" "matrixes.h")
