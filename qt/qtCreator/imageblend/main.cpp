#include <QApplication>
#include <blend_slider.h>
#include <burning.h>
#include <QIcon>
#include <QSize>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Burning window;

    window.setWindowTitle("Blend Slider v1.0");
    QSize size = QSize(10, 10);

    return a.exec();
}
