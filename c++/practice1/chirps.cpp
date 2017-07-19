//chirps.cpp : Alex Giokas
//for google c++ class
//Assuming that crickets chirp in direct proportion to the temperature
//get temperature from an input of cricket chirps per minute

#include <iostream>

using namespace std;

int main (void) {
	int baseChirps = 40;
	double chirpsPerDegree = 4.0;
	int chirps;

	cout << "Number of Chirps: ";
	cin >> chirps;

	int temp = ((chirps + baseChirps) / chirpsPerDegree);
	cout << "The temperature is: " << temp << " degrees." << endl;	
	
	return 0;
}
