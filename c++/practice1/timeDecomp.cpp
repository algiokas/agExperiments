//timeDecomp.cpp : Alex Giokas
//Google C++ class
//takes as input a number of seconds and prints the value decomposed into hours, minutes and seconds

#include <iostream>
#include <limits>

using namespace std;

int64_t mph = 60; //minutes per hour
int64_t spm = 60; //seconds per minute

//print64_ts the number of hours in a given number of seconds and returns the remainder
int64_t hours (int64_t seconds) {
	int64_t numHours = seconds / (spm * mph);
	int64_t rem = seconds % (spm * mph);

	cout << "Hours: " << numHours << endl;

	return rem;
}

int64_t minutes (int64_t seconds) {
	int64_t numMinutes = seconds / spm;
	int64_t rem = seconds % spm;

	cout << "Minutes: " << numMinutes << endl;

	return rem;
}

int main (void) {
	int64_t s;
	cout << "Number of Seconds: ";
	if (!(cin >> s) || (s < 0)) {
		cout << "Invalid input" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	int64_t remSecs = minutes(hours(s));
	cout << "Seconds: " << remSecs << endl;

	return 0;
}
