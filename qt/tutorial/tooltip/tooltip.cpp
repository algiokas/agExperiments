//tooltip.cpp : Alex Giokas

#include <QApplication>
#include <QWidget>

int main (int argc, char *argv[]) {

	QApplication app(argc, argv);

	QWidget window;

	window.resize(500, 300);
	window.move(300, 300);
	window.setWindowTitle("ToolTip demo");
	window.setToolTip("QWidget");

	window.show();

	return app.exec();
}
