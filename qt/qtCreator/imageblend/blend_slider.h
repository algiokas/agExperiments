#ifndef BLEND_SLIDER_H
#define BLEND_SLIDER_H

#include <QWidget>
#include <QLabel>
#include <QSlider>

class Blend_Slider : public QWidget {
    Q_OBJECT

public:
    Blend_Slider(QWidget *parent = 0);



private:
    QSlider *slider;
    QLabel *leftLabel;
    QLabel *rightLabel;
};


#endif // BLEND_SLIDER_H
