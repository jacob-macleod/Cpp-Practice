#ifndef WEATHER_ANALYSIS_H
#define WEATHER_ANALYIS_H

/*A weather analysis program uses the following array to store the temperature for
each hour of the day on each day of a week.
int temp[7][24];
Each row represents a day(0 = Sunday, 1 = Monday, etc.) and each column
represents a time(0 = midnight, 1 = 1 a.m., …, 12 = noon, 13 = 1 p.m., etc.).
A) Write code to find Tuesday’s average temperature.
B) Write code to find the average weekly noon temperature.*/

#include <iostream>
using namespace std;

int temp[7][24];

int getAverageTemperature(int day) {
	int sum = 0;
	for (int i = 0; i < 24; i++) {
		sum += temp[day][i];
	}

	return sum / 24;
}

int getAverageWeeklyNoonTemp() {
	int sum = 0;
	for (int i = 0; i < 7; i++) {
		sum += temp[i][12];
	}

	return sum / 7;
}
#endif