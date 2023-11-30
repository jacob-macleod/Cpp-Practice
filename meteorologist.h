#ifndef METEOROLOGIST_H
#define METEOROLOGIST_H
/*An amateur meteorologist wants to keep track of weather conditions during the past
year’s three-month summer season and has designated each day as either rainy (‘R’),
cloudy (‘C’), or sunny (‘S’). Write a modular program that stores this information in
a 3 × 30 array of characters, where the row indicates the month (0 = June, 1 = July,
2 = August) and the column indicates the day of the month. Note that data is not
being collected for the 31st of any month. The program should begin by calling a
function to read the weather data in from a file. Then it should create a report that
displays for each month and for the whole three-month period, how many days were
rainy, how many were cloudy, and how many were sunny. To help it do this, it
should use a value-returning function that is passed the array, the number of the
month to examine, and the character to look for (‘R’, ‘C’, or ‘S’). This function
should return the number of days the indicated month had the requested weather.
Data for the program can be found in the RainOrShine.dat file located in the
Chapter 8 programs folder on this book’s companion website.*/
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;

void readFile(string file, char data[3][30]) {
	ifstream fileIn;
	fileIn.open(file);
	char* fileArr = new char[3];
	string str;
	int line = 0;

	if (fileIn.fail())
		cout << "Failed to open the file" << endl;
	while (getline(fileIn, str)) {
		strcpy(fileArr, str.c_str());
		data[0][line] = fileArr[0];
		data[1][line] = fileArr[1];
		data[2][line] = fileArr[2];
		line++;
	}
}

int numOfDays(char data[3][30], int month, char item) {
	int count = 0;
	for (int i = 0; i < 30; i++) {
		if (data[month][i] == item) {
			count++;
		}
	}
	
	return count;
}

void printArr(char data[3][30]) {
	for (int y = 0; y < 30; y++) {
		for (int x = 0; x < 3; x++) {
			cout << data[x][y];
		}
		cout << endl;
	}
	cout << endl;
}

void report(char data[3][30]) {
	int rDaysInJune = numOfDays(data, 0, 'R');
	int sDaysInJune = numOfDays(data, 0, 'S');
	int cDaysInJune = numOfDays(data, 0, 'C');

	int rDaysInJuly = numOfDays(data, 1, 'R');
	int sDaysInJuly = numOfDays(data, 1, 'S');
	int cDaysInJuly = numOfDays(data, 1, 'C');

	int rDaysInAug = numOfDays(data, 2, 'R');
	int sDaysInAug = numOfDays(data, 2, 'S');
	int cDaysInAug = numOfDays(data, 2, 'C');

	int rDays = rDaysInAug + rDaysInJune + rDaysInJuly;
	int cDays = cDaysInAug + cDaysInJuly + cDaysInJune;
	int sDays = sDaysInAug + sDaysInJuly + cDaysInJune;

	cout << "In June there were " << to_string(rDaysInJune) << " rainy days, " << to_string(cDaysInJune) << " cloudy days and " << to_string(sDaysInJune) << " sunny days" << endl;
	cout << "In July there were " << to_string(rDaysInJuly) << " rainy days, " << to_string(cDaysInJuly) << " cloudy days and " << to_string(sDaysInJuly) << " sunny days" << endl;
	cout << "In August there were " << to_string(rDaysInAug) << " rainy days, " << to_string(cDaysInAug) << " cloudy days and " << to_string(sDaysInAug) << " sunny days" << endl;
	cout << "Overall there were " << to_string(rDays) << " rainy days, " << to_string(cDays) << " cloudy days and " << to_string(sDays) << " sunny days" << endl;

}

void meteorologist() {
	char data[3][30];
	readFile("../../../data.txt", data);
	report(data);
};
#endif