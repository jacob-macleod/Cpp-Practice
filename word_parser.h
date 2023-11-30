#ifndef WORD_PARSER_H
#define WORD_PARSER_H
/*Write a program that accepts as input a sentence in which all of the words are run together, but the first character of each word is uppercase. Convert the sentence
to a string in which the words are separated by spaces and only the first word starts with an uppercase letter. For example the string "StopAndSmellTheRoses." would
be converted to "Stop and smell the roses."*/
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

// Return true if the character is uppercase, otherwise return false
bool upper(char c) {
	char upperChars[27] = "QWERTYUIOPASDFGHJKLZXCVBNM";

	for (char l : upperChars) {
		if (l == c)
			return true;
	}

	return false;
}

string word_parser(string str) {
	char* strArr = new char[str.size()];
	strcpy(strArr, str.c_str());
	string parsedText = "";

	for (int i = 0; i < str.size(); i ++) {
		if (upper(strArr[i]))
			parsedText += " ";

		// Make the first letter a capital
		if (i == 0)
			parsedText = 'S';
		else
			// All other letters are lowercase
			parsedText += static_cast<char>(tolower(strArr[i]));
	}
	
	return parsedText;
}

#endif