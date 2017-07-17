//get_input.cpp: Alex Giokas
//Google C++ Code Class
//simple program that takes input from command line

#include <iostream>
using namespace std;

int main() {
	int input_var = 0;

	do {
		cout << "Enter a number (-1 = quit): ";
		if (!(cin >> input_var)) {
			cout << "You entered a non-numeric. Exiting..." << endl;
			break;
		}
		if (input_var != -1) {
			cout << "You Entered " << input_var <<endl;
		}
	} while (input_var != -1);
	cout << "All done." << endl;
	return 0;
}
