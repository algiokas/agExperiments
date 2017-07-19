//numFlip.cpp : Alex  Giokas
//Google C++ Class
//Takes a 3 digit number with the first digit greater than the last, reverses it, subtracts
//the reversal from the original then reverses that value and adds it to the unreversed version

#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

using namespace std;

//reverses any 3 digit integer
int reverseInt3 (int x) {
	int h = x / 100; //hundreds digit
	int t = (x - (h * 100)) / 10; //tens digit
	int o = (x - (h * 100) - (t * 10)); //ones digit
	
	int y = (o * 100) + (t * 10) + (h); //construct the reversed value
	
	//debug
	//cout << "reverse (DEBUG): " << y << endl;
	return y;
}

//Takes in two integers and a binary math operation (+, -, *, /) and prints the operation to the console 
int printOperation(int a, int b, char op) {
	int y;
	char temp = op;
	switch (temp) {
		case '+' : { y = a + b;	
			cout << "Add: ";
	  		cout << setw(3) << setfill('0') << a;
			cout << " " << op << " ";
			cout << setw(3) << setfill('0') << b;
			cout << " = ";
			cout << setw(3) << setfill('0') << y;
			break; 
		}
		case '-' : { y = a - b;	
			cout << "Subtract: ";
			cout << setw(3) << setfill('0') << a;
			cout << " " << op << " ";
			cout << setw(3) << setfill('0') << b;
			cout << " = ";
			cout << setw(3) << setfill('0') << y;
			break;
		}
		case '*' : { y = a * b;	
			cout << "Multiply: ";
			cout << setw(3) << setfill('0') << a;
			cout << " " << op << " ";
			cout << setw(3) << setfill('0') << b;
			cout << " = ";
			cout << setw(3) << setfill('0') << y;
			break;
		}
		case '/' : { y = round(a/b);	
			cout << "Divide: ";
			cout << setw(3) << setfill('0') << a;
			cout << " " << op << " ";
			cout << setw(3) << setfill('0') << b;
			cout << " = ";
			cout << setw(3) << setfill('0') << y;
			break;
		}
		default: cout << "Invalid Operator";
	}
	cout << endl;
	return y;
}




int main (void) {
	int input;
	bool valid = false;
	do {
		cout << "Input number 0-999 with the first digit greater than the last: ";
		if((cin >> input) && (input > reverseInt3(input)) && (input >= 0) && (input <= 999)) {
			valid = true;
		}
		if(!valid) {
			cout << "Invalid Input" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	} while (!valid);
	int rev = reverseInt3(input);
	cout << "reverse: ";
	cout << setw(3) << setfill('0') << rev << endl;
	int sub = printOperation(input, rev, '-');
	int revSub = reverseInt3(sub);
	cout << "reverse: ";
	cout << setw(3) << setfill('0') << revSub << endl;
	printOperation(sub, revSub, '+');

	return 0;
}
	



