#include <QApplication>
#include <blend_slider.h>
#include <burning.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Burning window;

    window.setWindowTitle("Blend Slider v1.0");
    window.showMaximized();

    return a.exec();
}
