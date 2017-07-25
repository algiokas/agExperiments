//asciiChar.cpp : Alex Giokas
//command line utility to return the ASCII value of any valid character

#include <iostream>
#include <typeinfo>
#include <string.h>

using namespace std;

int main (int argc, char *argv[]) {
	if (argc != 2 || strlen(argv[1]) > 1) {
		cout << "usage: " << argv[0] << " <ASCII char>" << endl;
		
	}

	else {
		//DEBUG
		int val = (int)argv[1][0];
		cout << "Input: " << argv[1] << endl; 
		cout << "Length: " << strlen(argv[1]) << endl;
		cout << "Value: " << val << endl;
	}
	return 0;
}



