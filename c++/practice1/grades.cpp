//grades.cpp : Alex Giokas
//Google C++ class
//Prompts the user for assignment and exam scores then outputs a final grade based on a weighting scale

#include <iostream>
#include <limits>

using namespace std;

double ASSIGNMENTS = 0.4;
double MIDTERM = 0.15;
double FINAL = 0.35;
double PARTICIPATION = 0.1;

string grades[] = {"Assignment", "Midterm Exam", "Final Exam", "Participation"};

int displayScale(void) {
	cout << "Final grades will use the following scale:" << endl;
	cout << (ASSIGNMENTS * 100) << "% Assignments	" << (MIDTERM * 100) << "% Midterm Exam" << endl;
	cout << (FINAL * 100) << "% Final Exam     " << (PARTICIPATION * 100) << "% Participation" << endl;
}

int getAssignments (void) {
	double mean;
	int sum = 0;
	int a[4];
	for (int i = 0; i < 4; i++) {
		bool valid = false;
		do {
			cout << "Enter the score for assignment " << (i + 1) << ": ";
			if (cin >> a[i] && a[i] >= 0 && a[i] <= 100) {
				valid = true;
			}
	
			if (!valid) {
				cout << "invalid input" << endl;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		} while (!valid);
		sum = sum + a[i];
	}
	mean = sum / 4.0;
	return mean;
}

int getOtherGrades (int otherGrade) {
	int grade;
	bool valid = false;
	do {
		cout << "Enter your " << grades[otherGrade] << " grade: ";
		if (cin >> grade && grade >= 0 && grade <= 100) {
			valid = true;
		}

		if (!valid) {
			cout << "invalid input" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (!valid);
	return grade;
}


int main (void) {
	displayScale();	
	int assignments, midterm, final_g, participation;
	assignments = getAssignments();
	midterm = getOtherGrades(1);
	final_g = getOtherGrades(2);
	participation = getOtherGrades(3);
	double total = (assignments * ASSIGNMENTS) + (midterm * MIDTERM) + (final_g * FINAL) + (participation * PARTICIPATION);
	cout << "Your total grade is: " << total << endl;
	return 0;
}
