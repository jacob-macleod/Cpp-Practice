#ifndef VENDING_MACHINE_H
#define VENDING_MACHINE_H
/*Create a class that simulates and manages a soft drink machine. Information on each
drink type should be stored in a structure that has data members to hold the drink
name, the drink price, and the number of drinks of that type currently in the machine.
The class should have an array of five of these structures, initialized with the following data.
Drink Name Cost Number in Machine
Cola 1.00 20
Root beer 1.00 20
Orange soda 1.00 20
Grape soda 1.00 20
Bottled water 1.50 20
The class should have two public member functions, displayChoices (which displays
a menu of drink names and prices) and buyDrink (which handles a sale). The class
should also have at least two private member functions, inputMoney, which is called by
buyDrink to accept, validate, and return (to buyDrink) the amount of money input,
and dailyReport, which is called by the destructor to report how many of each drink
type remain in the machine at the end of the day and how much money was collected.
You may want to use additional functions to make the program more modular.
The client program that uses the class should have a main processing loop that calls the
displayChoices class member function and allows the patron to either pick a drink or
quit the program. If the patron selects a drink, the buyDrink class member function is
called to handle the actual sale. This function should be passed the patron’s drink
choice. Here is what the buyDrink function should do:
• Call the inputMoney function, passing it the patron’s drink choice.
• If the patron no longer wishes to make the purchase, return all input money.
• If the machine is out of the requested soda, display an appropriate “sold out”
message and return all input money.
• If the machine has the soda and enough money was entered, complete the sale by
updating the quantity on hand and money collected information, calculating any
change due to be returned to the patron, and delivering the soda. This last action
can be simulated by printing an appropriate “here is your beverage” message.*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class VendingMachine {
	struct item {
		string name;
		float cost;
		int number;
	};

	float money = 0;

	/* DRINK DATA
	Cola 1.00 20
	Root beer 1.00 20
	Orange soda 1.00 20
	Grape soda 1.00 20
	Bottled water 1.50 20*/
	item drinks[5] = {
		{"Cola", 1.0, 20},
		{"Root beer", 1.0, 20},
		{"Orange soda", 1.0, 20},
		{"Grape soda", 1.0, 20},
		{"Bottled water", 1.5, 20}
	};
	int drinkTypes = 5;

public:
	// displays a menu of drink names and prices
	void displayChoices() {
		for (int drink = 0; drink < drinkTypes; drink++) {
			cout << "Drink " << to_string(drink + 1) << " " << drinks[drink].name;
			cout << " costs " << setprecision(2) << fixed << drinks[drink].cost;
			cout << ". There are " << to_string(drinks[drink].number) << " left" << endl;
		}
	}

	// called by buyDrink to accept, validate, and return
	bool inputMoney(item drink) {
		float pricePaid = 0;
		bool proceed = true;
		char input;
		cout << "Press y if you want to proceed with the sale: " << endl;
		cin >> input;

		if (input == 'y') {
			while (pricePaid < drink.cost) {
				cout << "Please enter the amount you will pay for the $" << setprecision(2) << fixed << drink.cost << " drink: ";
				cin >> pricePaid;

				if (pricePaid < drink.cost)
					cout << "Sorry, you need to pay $" << setprecision(2) << fixed << (drink.cost - pricePaid) << " more" << endl;
			}

			if (pricePaid > drink.cost)
				cout << "You overpaid by " << setprecision(2) << fixed << (pricePaid - drink.cost) << ". The money is being returned" << endl;

			return true;
		}
		else
			cout << "Sale cancelled" << endl;

		return false;
		
	}

	/*buyDrink (which handles a sale)
		If the patron selects a drink, the buyDrink class member function is
		called to handle the actual sale. This function should be passed the patron’s drink
		choice. Here is what the buyDrink function should do:
		• Call the inputMoney function, passing it the patron’s drink choice.
		• If the patron no longer wishes to make the purchase, return all input money.
		 If the machine has the soda and enough money was entered, complete the sale by
		updating the quantity on hand and money collected information, calculating any
		change due to be returned to the patron, and delivering the soda. This last action
		can be simulated by printing an appropriate “here is your beverage” message.
	*/
	void buyDrink(int drink) {
		// For the user, the indexing starts at 1, but 0 for the computer
		drink--;
		if (drink <= 5 && drink >= 0) {
			cout << "Buying drink number " << to_string(drink + 1) << " " << drinks[drink].name << endl;
			if (drinks[drink].number > 0) {
				if (inputMoney(drinks[drink])) {
					money += drinks[drink].cost;
					drinks[drink].number--;
					cout << "Here is your beverage!" << endl;
				}
			}
			else
				cout << "Sorry, there are not enough drinks avaliable" << endl;
		}
		else
			cout << "Sorry, that number is wrong" << endl;
	}

	// called by the destructor to report how many of each drink type remain in the machine at the end of the day and how much money was collected
	void dailyReport (){
		for (int drink = 0; drink < drinkTypes; drink++) {
			cout << "Drink " << to_string(drink + 1) << " " << drinks[drink].name;
			cout << " has " << to_string(drinks[drink].number) << " left" << endl;
		}
		cout << "$" << setprecision(2) << fixed << money << " was collected" << endl;
	}

	~VendingMachine () {
		dailyReport();
	}
};

void vendingMachine() {
	/*The client program that uses the class should have a main processing loop that calls the
	displayChoices class member function and allows the patron to either pick a drink or
	quit the program. If the patron selects a drink, the buyDrink class member function is
	called to handle the actual sale. This function should be passed the patron’s drink
	choice.*/
	VendingMachine machine = VendingMachine();
	char response = 'y';
	int number;

	while (response not_eq 'q') {
		machine.displayChoices();
		cout << "If you want a drink, enter y(es), otherwise, enter q(uit)" << endl;
		cin >> response;
		if (response == 'y') {
			cout << "Which number would you like? ";
			cin >> number;
			machine.buyDrink(number);
		}

		cout << endl << endl;
	}
}
#endif