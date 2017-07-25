//cardTrick.cpp : Alex Giokas
//Google online C++ class
//Simulates a card trick with a 3 digit number the trick is as follows:
//	- Let A, B, and C be the digits of a 3 digit number
//	- recombine the digits into ABC, BCA and CAB and divide each by 11
//	- let the remainder of each division be X, Y, and Z respectively
//	- Add together X+Y, Y+Z and Z+X,
//	- If any of these sums are odd, add or subtract 11 so that the result is in (0, 20)
//	- divide each sum in half to then get A, B and C again

#include <iostream>
#include <limits>

using namespace std;

typedef struct {
	int a;
	int b;
	int c;
} triple;

//prompts the user for input and checks for validity before returning the input as a triple struct
triple getCards() {
	int input;
	triple x;		
	bool valid = false;
	do {
		cout << "Enter a 3 digit number (-1 = Quit): ";
		//check input for validity
		if (!(cin >> input)) {
			cout << "Invalid Input" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} else if (input == -1) {
			break;
		} else if (input < 0 || input > 999) {
			cout << "Input out of range, Enter a number between 0 and 999" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} else {
			cout << "test1" << endl;
			valid = true;

			x.a = input / 100;
			x.b = (input - (x.a * 100)) / 10;
			x.c = input - (x.a * 100) - (x.b * 10);
		}

	} while (valid = false);

	return x;
}

triple remSum (triple cards) {
	int x = ((cards.a * 100) + (cards.b * 10) + cards.c) % 11;
	int y = ((cards.b * 100) + (cards.c * 10) + cards.a) % 11;
	int z = ((cards.c * 100) + (cards.a * 10) + cards.b) % 11;
	
	

	triple remSums;

	remSums.a = x + y;
	remSums.b = y + z;
	remSums.c = z + x;

	return remSums;
}

//checks if any remainders are 9
bool checkNine(triple sums) {
	if (sums.a == 9) {return true;}
	if (sums.b == 9) {return true;}
	if (sums.c == 9) {return true;}
	return false;
}

triple upOrDown (triple sums) {
	triple output;

	if ((sums.a % 2) != 0) {
		if (sums.a < 8) {output.a = sums.a + 11;}
		else { output.a = sums.a - 11;}
	} else {
		output.a = sums.a;
	}

	if ((sums.b % 2) != 0) {
		if (sums.b < 8) {output.b = sums.b + 11;}
		else { output.b = sums.b - 11;}
	} else {
		output.b = sums.b;
	}

	if ((sums.c % 2) != 0) {
		if (sums.c < 8) {output.c = sums.c + 11;}
		else { output.c = sums.c - 11;}
	} else {
		output.c = sums.c;
	}

	return output;
}

int main (void) {
	triple cards;
	cards = getCards();

	cout << "DEBUG 1: " << cards.a << cards.b << cards.c << endl;
	
	triple sums = remSum(cards);
	cout << "DEBUG 2: " << sums.a << sums.b << sums.c << endl;

	if (checkNine(sums)) {
		cout << "9 detected, exiting" << endl;
		return 0;
	}	
	
	triple aSums = upOrDown(sums);
	cout << "DEBUG 3: " << aSums.a << aSums.b << aSums.c << endl;
	
	cout << "Your number was: " << aSums.a / 2 << aSums.b / 2 << aSums.c / 2 << endl; 
	return 0;
}
