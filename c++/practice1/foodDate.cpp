//foodDate.cpp : Alex Giokas
//Google C++ class
//encodes and decodes dates as 4 letter codes

#include <iostream>
#include <string>

std::string months[] = {"January", "February", "March", "April", "May", "June", 
			"July", "August", "September", "October", "November", "December"};

using namespace std; 

bool validCode(string code) {
	if (code.length() != 4) {
		return false;
	}
	
	int charVals[4];
	for (int i = 0; i < 4; i++) {
		charVals[i] = (int) code.at(i);
	}

	if (charVals[0] > 76 || charVals[0] < 65) { return false; } //ASCII chars A-L
	if (charVals[1] > 84 || charVals[1] < 81) { return false; } //ASCII chars Q-S
	if (charVals[2] > 90 || charVals[2] < 81) { return false; } //ASCII chars Q-Z
	if (charVals[3] > 90 || charVals[3] < 65) { return false; } //ASCII chars A-Z
	if (charVals[1] == 81 && charVals[2] == 81) { return false; } //00 is not a valid day
	if (charVals[1] == 84 && charVals[2] > 82) {return false; } //excludes days 32-39

	return true;
}



int main (void) {
	string code;
	do {
		cout << "Enter a valid 4 letter date code (q to quit): ";
		cin >> code;

		if (code == "q" || code == "Q") {break;} 
	
		int charVals[4];
		for (int i = 0; i < 4; i++) {
			charVals[i] = (int) code.at(i);
		}
		if (!validCode(code)) {
			cout << "Invalid code, terminating" << endl;
		} else {
			int mo = charVals[0] - 65;
			int day = ((charVals[1] - 81) * 10) + (charVals[2] - 81);
			int year = 1995 + charVals[3] - 64;

			cout << "Expiration Date: " << months[mo] << " " << day << ", " << year << endl;
		}
	} while (!validCode(code));
	return 0;
}
