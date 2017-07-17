//get_input2.cpp: Alex Giokas
//Google C++ Code Class
//simple program to take input from the console
//modified to handle non-numeric inputs without exiting

#include <iostream>
#include <limits>
using namespace std;

int main() {
	int input_var = 0;

	do {
		cout << "Enter a number (-1 = quit): ";
		if (!(cin >> input_var)) {
			cout << "You entered a non-numeric." << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
		}
		else if (input_var != -1) {
			cout << "You Entered " << input_var <<endl;
		}
	} while (input_var != -1);
	cout << "All done." << endl;
	return 0;
}
