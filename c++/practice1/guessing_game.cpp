//guessing_game.cpp: Alex Giokas
//simple guessing game that generates a random number and allows the user to guess
//provides hints that indicate where the user's guess is in relation to the correct value

#include <iostream>
#include <cstdlib>
#include <limits>
#include <ctime>
using namespace std;

int main () {
	int goal;
	int guess;

	srand(time(0));
	do {
		goal = (rand() % 99) + 1;
		cout << "Guess a number between 1 and 100 (Inclusive), -1 to quit." << endl;
		do {
			cin >> guess;
			if(!guess) {
				cout << "Not a valid guess." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			} else if (guess == -1) {
				break;
			} else if (guess > goal) {
				cout << "Too high" << endl;
			} else if (guess < goal) {
				cout << "Too Low" << endl;
			}
		} while (guess != goal);
		if (guess != -1) {
			cout << "Correct!" << endl;
		}
	} while (guess != -1);
}
					
			
