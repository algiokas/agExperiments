//compensation.cpp : Alex Giokas
//exercise for google code class - c++
//determine which compensation is the best for an employee based on weekly sales

#include <iostream>

using namespace std;

#define SHOE_PRICE 225.00
#define WEEKLY_SALARY 600.00
#define HOURLY_SALARY 7.00
#define PCT_COMMISION_LOW 0.1
#define PCT_COMMISION_HIGH 0.2
#define COMMISION 20.00
#define HOURSPERWEEK 40

int main() {
	int weekly_sales;
	cout << "Input number of shoes sold in 1 week" << endl;
	cin >> weekly_sales;
	double m1 = CalcMethod1();
	double m2 = CalcMethod2(weekly_sales);
	double m3 = CalcMethod3(weekly_sales);
	

}

double CalcMethod1 () {
	return WEEKLY_SALARY;
}

double CalcMethod2 (int sales) {
	return (HOURSPERWEEK * HOURLY_SALARY) + (sales * SHOE_PRICE * PCT_COMMISION_LOW);
}

double CalcMethod3 (int sales) {
	return (sales * ((SHOE_PRICE * PCT_COMMISION_HIGH) + COMMISION));
}
	
