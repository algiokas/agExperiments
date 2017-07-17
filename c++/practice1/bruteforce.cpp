//bruteforce.cpp : Alex Giokas
//Brute force approach to the following problem from google code class:
//"Horses cost $10, pigs cost $3, and rabbits are only $0.50. A farmer buys 100 animals for $100
//How many of each animal did he buy?"

#include <iostream>
using namespace std;

int main () {
	int cost;
	int BUDGET = 10000;
	int HORSE_COST = 1000;
	int PIG_COST = 300;
	int RABBIT_COST = 50; 
	for (int h = 0; h < 10; h++) {
		for (int p = 0; p < 33; p++) {
			for (int r = 0; r < 200; r++) {
				cost = (h * HORSE_COST) + (p * PIG_COST) + (r * RABBIT_COST);
				if (cost == BUDGET && (h + p + r) == 100) {
					cout << h << " Horses, " << p << " pigs, and " << r << " rabbits." << endl;
					return(0);
				} else if (cost > BUDGET) {
					break;
				}
			}
		}
	}
}
