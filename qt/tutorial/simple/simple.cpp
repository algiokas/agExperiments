//simple.cpp

#include <QApplication>
#include <QWidget>

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
	QWidget window;
	window.resize(250, 150);
	window.setWindowTitle("Simple example 123");
	window.show();

	return app.exec();
}
