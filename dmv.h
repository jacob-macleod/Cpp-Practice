#ifndef DMV_H
#define DMV_H
/*The State Department of Motor Vehicles (DMV) has asked you to write a program
that grades the written portion of the driver’s license exam, which has 20 multiple-
choice questions. Here are the correct answers:
1.B 5.C 9.C 13.D 17.C
2.D 6.A 10.D 14.A 18.B
3.A 7.B 11.B 15.D 19.D
4.A 8.A 12.C 16.C 20.A
To do this, you should create a TestGrader class. The class will have an answers array
of 20 characters, which holds the correct test answers. It will have two public member
functions that enable user programs to interact with the class: setKey and grade. The
setKey function receives a 20-character string holding the correct answers and copies
this information into its answers array. The grade function receives a 20-character
array holding the test taker’s answers and compares each of their answers to the correct
one. An applicant must correctly answer 15 or more of the 20 questions to pass the
exam. After “grading” the exam, the grade function should create and return to the
user a string that includes the following information:
• A message indicating whether the applicant passed or failed the exam
• The number of right answers and the number of wrong answers
• A list of the question numbers for all incorrectly answered questions
The client program that creates and uses a TestGrader object should first make a single call
to setKey, passing it a string containing the 20 correct answers. Once this is done, it should
allow atest taker’s 20answersto beentered, making sure only answersof A–D are accepted,
and store them in a 20-character array. Then it should call the grade function to grade the
exam and should display the string the function returns. The program should loop to allow
additional tests to be entered and graded until the user indicates a desire to quit.*/
#include <iostream>
using namespace std;

class TestGrader {
	char* answers = new char[20];
	char responses[20];
public:
	void setKey(string key) {
		bool inputValid;
		char response;
		strcpy(answers, key.c_str());

		for (int question = 0; question < 20; question++) {
			inputValid = false;
			while (!inputValid) {
				cout << "Enter the answer for question " << (question + 1) << ": ";
				cin >> response;
				responses[question] = toupper(response);
				inputValid = (responses[question] == 'A' || responses[question] == 'B' || responses[question] == 'C' || responses[question] == 'D');
				if (!inputValid)
					cout << "You can only enter A, B, C or D" << endl;
			}
		}
	}

	string grade() {
		int wrongAnswers = 0;
		string wrongQuestions = "";
		for (int question = 0; question < 20; question++) {
			if (responses[question] != *(answers + question)) {
				wrongAnswers++;
				cout << wrongQuestions << endl;
			}
		}

		string passMessage = (wrongAnswers <= 5) ? "You passed the exam! " : "You did not pass the exam ";
		return passMessage + "You had " + to_string(20 - wrongAnswers) + " right answers and " + to_string(wrongAnswers) + " wrong answers. You answered questions " + wrongQuestions + "wrong";
	}
};


void dmv() {
	string answers = "BDAACABACDBCDADCCBDA";
	cout << "Starting" << endl;
	// n - or any other character except q - means n(ot quit), and q means q(uit)
	char quit = 'n';
	while (quit != 'q') {
		TestGrader t = TestGrader();
		t.setKey(answers);
		cout << t.grade() << endl;

		cout << "Type in q if you want to quit - otherwise, press enter n: ";
		cin >> quit;
	}
}
#endif