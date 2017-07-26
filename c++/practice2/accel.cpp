// accel.cpp : Alex Giokas
// some practice passing by reference
#include <iostream>

using namespace std;

void accelerate(int *speed, int increase) {
	*speed = *speed + increase;
	cout << "Accelerate!!!" << endl;
}

int main() {
	int *v = new int;
	*v = 25;

	cout << "Start Speed: " << (*v) << endl;

	int step = 10;
	accelerate(v, step);

	cout << "End Speed: " << (*v) << endl;

	return 0;

}
