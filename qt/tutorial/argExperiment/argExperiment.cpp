// argExperiment.cpp : Alex Giokas
// playing around with QStrings and the .arg() function for QStrings

#include <QTextStream>

int main (void) {
	QTextStream out(stdout);

	int hoursPerDay = 24;
	int daysPerWeek = 7;
	//int daysPerYear = 365;
	//int minutesPerHour = 60;
	//int secondsPerMinute = 60;

	QString str1 = "There are %1 hours in a day and %2 hours in a week";
	out << str1.arg(hoursPerDay).arg(hoursPerDay * daysPerWeek) << endl;

	QString str2 = "There are %1 frogs and %1 birds and %2 fish in the pond";
	out << str2.arg(hoursPerDay).arg(daysPerWeek) << endl;
	
	return 0;
}
