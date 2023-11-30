#ifndef BASEBALL_H
#define BASEBALL_H
/*Write a program that creates and displays a report of 12 Little League baseball players and their batting averages, listed in order of batting average from
highest to lowest. The program should use an array of structures or class objects to store the data, where each structure or object holds the name of a player
and their batting average. Make the program modular by having main call on different functions to input the data, sort the data, perform swaps, and display the report.
*/
#include <iostream>
using namespace std;
#include <string>

struct playerData {
	string name;
	float battingAvg;
};

class players {
	int numOfPlayers = 4;
	playerData data[4];
public:
	players() {
		for (int player = 0; player < numOfPlayers; player++) {
			string name;
			float battingAvg;
			cout << "Enter the name for player " << to_string(player + 1) << ": ";
			cin >> data[player].name;
			cout << "Enter the batting average for player " << to_string(player + 1) << ": ";
			cin >> data[player].battingAvg;
		}
	}

	void displayData() {
		for (int player = 0; player < numOfPlayers; player++) {
			cout << "Player " << data[player].name << " - " << to_string(player + 1) << " has a batting average of " << to_string(data[player].battingAvg) << endl;
		}
	}

	void swapPlayers() {
		int p1;
		int p2;
		cout << "Enter the numbers of the two players you want to swap, seperated by a space: ";
		cin >> p1 >> p2;
		// The user sees the indexing as starting from when when it really starts from 0
		p1--;
		p2--;

		playerData temp = data[p1];
		data[p1] = data[p2];
		data[p2] = temp;
		cout << "Swapped players " << to_string(p1 + 1) << " and " << to_string(p2 + 1) << endl;
	}

	void sortByBattingAvg() {
		// Bubble sort by batting average
		bool swapMade = true;
		playerData temp;

		while (swapMade) {
			swapMade = false;

			for (int player = 1; player < numOfPlayers; player++) {
				if (data[player].battingAvg < data[player - 1].battingAvg) {
					temp = data[player];
					data[player] = data[player - 1];
					data[player - 1] = temp;
					swapMade = true;
				}
			}
		}
	}
};

#endif