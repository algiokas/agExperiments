// squareSum.cpp : Alex Giokas
// for google C++ class
// attempts to find numbers that are both perfect squares and the sum of integers 1...n

#include <iostream>
#include <math.h>

using namespace std;

int64_t search_max = 1000000;

int main () {
	cout << "Start" << endl;
	int64_t sum = 0;
	double root;
	for (int64_t i = 1; i < search_max; i++) {
		sum = sum + i;
		root = sqrt(sum);
		if (root == round(root)) {
			cout << sum << " = 1 ... " << i << " = " << root << "^2" << endl;
		}
	}
	cout << "Search max reached" << endl;

	return 0;
}

