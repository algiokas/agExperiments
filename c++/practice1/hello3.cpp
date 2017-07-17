//hello3.cpp: Alex Giokas
//Modified Hello World program that prints 6 lines of 4 "Hello World!"'s with spacing
//differs from hello2 in that the text is left justified in each column
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			cout << setw(17) << left << "Hello World!";
		}
		cout << endl;
	}
	return 0;
}

