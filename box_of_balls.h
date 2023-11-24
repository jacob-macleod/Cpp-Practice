//
// Created by jacob on 23/11/23.
//

#ifndef C___LEARNING_BOX_OF_BALLS_H
#define C___LEARNING_BOX_OF_BALLS_H
#include <iostream>
using namespace std;
/*Design a class representing a box of balls of varied sizes. The class should have two data
members, one for storing the number of balls and the other declaring a dynamic array for
diameter of each ball. The class should have a parameterized constructor to initialize the
number of balls and the diameter of each ball and a destructor to deallocate memory when
the objects are destroyed. It should also have member functions to input data members
and to display the volume of each ball. Demonstrate the class in a program.*/

class box {
    int number;
    float *diameters;
    float pi = 3.14159;
    float volume;

public:
    box(int number) : number(number) {
        diameters = new float[number];
    }

    ~box() {
        delete[] diameters;
    }

    void inputData() {
        for (int i = 0; i < number; i ++) {
            cout << "Enter the diameter for ball " << i + 1 << ": ";
            cin >> diameters[i];
        }
    }

    void displayVolumes () {
        // Volume = PI * r^2 = PI * (d/2)^2
        for (int i = 0; i < number; i ++) {
            volume = (4.0/3.0) * pi * ((diameters[i] / 2) * (diameters[i] / 2) * (diameters[i] / 2));
            cout << "Ball " << i + 1 << " has a diameter of " << volume << endl;
        }
    }


};

struct ball {
    int diameter;
    int volume;
};

void box_of_balls() {
    cout << "How many balls are in your box? ";
    int balls;
    cin >> balls;
    box myBox(balls);
    myBox.inputData();
    myBox.displayVolumes();
}
#endif //C___LEARNING_BOX_OF_BALLS_H
