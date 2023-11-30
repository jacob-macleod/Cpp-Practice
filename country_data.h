#ifndef COUNTRY_DATA_H
#define COUNTRY_DATA_H
/*In a program you need to store the names and populations of 12 countries. Create
an appropriate array to store this information and then write the code needed to
read the information into the array from a file named pop.dat*/
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class country_data {
	struct country {
		string name;
		int population;
	};

	int numOfCountries = 12;
	country data[12];
	string fileName = "pop.dat";

public:
	void inputData() {
		for (int i = 0; i < numOfCountries; i++) {
			cout << "Enter the name and population for country " << to_string(i + 1) << " seperated by a space: ";
			cin >> data[i].name >> data[i].population;
		}
	}

	void writeData() {
		ofstream fileIn;
		fileIn.open("pop.dat");
		for (country item : data)
			fileIn << item.name << " has a population of " << to_string(item.population) << endl;

	}
};

#endif