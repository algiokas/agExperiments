//artilleryGame.cpp : Alex Giokas
//Created for Google online C++ class
//game that generates a random target distance and allows the player to fire at a given angle

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <math.h>
#include <limits>

#define _USE_MATH_DEFINES //gives access to common math constants such as pi

int ammo = 10; //amount of ammo available for each round
int min_distance = 50; //feet
int max_distance = 1000; //feet
double velocity = 200.0; //feet per second
double blast_radius = 10.0; //feet
double gravity = 32.2; //feet per second


using namespace std;

//Displays the starting text
void start() {
	cout << "Welcome to Artillery" << endl;
	cout << "You control an artillery emplacement which can shoot at any angle" << endl;
	cout << "The enemy is charging your lines and you only have " << ammo << " shells" << endl;
	cout << "Let's begin..." << endl;
	cout << endl;
}

//Randomly generates a distance to an enemy, displays it, and returns it
int rand_distance() {
	int dist;

	srand(time(NULL));

	dist = (rand() % (max_distance - min_distance)) + min_distance; 

	cout << "The enemy is " << dist << " feet away!" << endl;

	return dist;
}


//prompts user for an angle and returns the value 
double input_angle () {
	double angle;
	cout << "Input Angle: ";

	if (!(cin >> angle)) {
		throw invalid_argument("Non-numeric argument, Exiting");
	}
	return angle;
}

//converts an angle in degrees to a radian value between 0 and 2*pi
double convert_angle(double rawAngle) {
	return (2 * M_PI) * ((fmod(rawAngle, 360)) / 360);
}

int calculate_dist(double angle) {
	double rAngle = convert_angle(angle); //get angle in radians to use with sin() and cos()

	//velocity * sin(rAngle) = vertical velocity
	//divide by gravity to determine time to decelerate to 0
	//then multiply by 2 to account for the upward and downward portion of the ballistic trajectory
	double airtime = ((velocity * sin(rAngle)) / gravity) * 2.0; 
	
	//velocity * cos(rAngle) = horizontal velocity
	int distance = round((velocity * cos(rAngle)) * airtime); 

	return distance;
}

//prints the outcomes for each individual shot and returns true on a hit
bool fire(int distance, int shot) {
	int prox = shot - distance;
	
	//overshot
	if (prox > 0 && prox > blast_radius) {
		cout << "You over shot by " << prox << endl;
		return false;
	} else if (prox < 0 && prox < blast_radius) {
		cout << "You under shot by " << (-1 * prox) << endl;
		return false;
	} else {
		cout << "Hit!" << endl;
		return true;
	}
}



//main loop for a single round (1 distance, [ammo] tries)
bool round() {
	int spent; //spent ammo
	int distance = rand_distance(); 
	int impact, proximity;
	

	for (spent = 0; spent < ammo; spent++) {
		impact = calculate_dist(input_angle());	
		if (fire(distance, impact)) {
			cout << "It took you " << spent << " shots" << endl;
			return true;
		}
	}

	cout << "You ran out of ammo" << endl << "R.I.P." << endl;
}
		

int main () {
	start();
	string done;
	int killed = 0;

	do {
		if (round()) {
			killed++;
		}
		cout << "Play Again? (Y/N) " << endl;
		cin >> done;
	} while (done != "n");
	cout << "You killed " << killed << " enemies." << endl;

	return 0;
}




