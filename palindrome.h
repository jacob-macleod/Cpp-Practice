#ifndef PALINDROME_H
#define PALINDROME_H
/*A palindromic number is a positive integer that reads the same forward as backward.
For example, the numbers 1, 11, and 121 are palindromic. Moreover, 1 and 11 are
very special palindromic numbers: their squares are also palindromic. How many
positive integers less than 10,000 have this property? Write a program to list all such
numbers together with their squares.
The beginning part of your output should look like this:
1 has square 1
2 has square 4
3 has square 9
11 has square 121
22 has square 484*/
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(int number) {
	string strNum = to_string(number);
	char* strArr = new char[strNum.size()];
	char* reversedStr = new char[strNum.size()];
	strcpy(strArr, strNum.c_str());

	for (int i = 0; i < strNum.size(); i++) {
		if (strArr[i] != strArr[strNum.size() - i - 1])
			return false;
	}
	
	return true;

}

int square(int num) {
	return num * num;
}

void palindrome() {
	int topNum = 10000;
	for (int i = 1; i < topNum; i++) {
		if (isPalindrome(i) && isPalindrome(square(i)))
			cout << i << " has square " << square(i) << endl;
	}
}
#endif