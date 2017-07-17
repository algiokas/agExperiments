//strAccess.cpp : Alex Giokas

#include <QTextStream>

int main (void) {
	QTextStream out(stdout);

	QString a = "Eagle";

	out << "The first letter of Eagle is " << a[0] << endl;
	out << "The fifth letter of Eagle is " << a[4] << endl;

	out << "The third letter of Eagle is " << a.at(2) << endl;

	if (a.at(5).isNull()) {
		out << "Outside the range of the string" << endl;
	}

	return 0;

}
