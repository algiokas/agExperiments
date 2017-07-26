#ifndef ARTILLERY_GAME_H
#define ARTILLERY_GAME_H

//Displays the starting text in the console
void start();

//Randomly generates a distance to an enemy and returns it
int rand_distance();

//prompts user for an angle and returns the value
double input_angle();

//converts an angle in degrees to a radian value between 0 and 2*pi
double convert_angle(double rawAngle);

//calculates the ballistic distance travelled by a projectile given its angle,
//initial height is assumed to be 0 and initial velocity is determined by the global variable velocity
int calculate_dist(double angle);

//prints the outcomes for each individual shot and returns true on a hit
bool fire(int distance, int shot);

//main loop for a single round (1 distance, [ammo] tries)
bool play_round();

#endif // ARTILLERY_GAME_H
