#include <QApplication>
#include <QWidget>
#include <QPushButton>

class MyButton : public QWidget {

	public:
		Mybutton(QWidget *parent = 0);
};

MyButton::MyButton(QWidget *parent)
	: QWidget(parent) {
		
		QPushButton *quitBtn = new QPushButton("Quit", this);
		quitBtn->setGeometry(100, 80, 150, 60);

		connect(quitBtn, &QPushButton::clicked, qApp, &QApplication::quit);
}

int main (int argc, char *argv[]) {

	QApplication app(argc, argv);

	MyButton window;

	window.resize(500, 300);
	window.setWindowTitle("QPushButton");
	window.show();

	return app.exec();
}
