#include <QHBoxLayout>
#include <blend_slider.h>

Blend_Slider::Blend_Slider(QWidget *parent):QWidget(parent){

    QHBoxLayout *hbox = new QHBoxLayout(this);

    slider = new  QSlider(Qt::Horizontal, this);
    hbox->addWidget(slider);

    leftLabel = new QLabel("0", this);
    rightLabel = new QLabel("0", this);
    hbox->addWidget(leftLabel);
    hbox->addWidget(rightLabel);

    connect(slider, &QSlider::valueChanged,
            leftLabel, static_cast<void (QLabel::*)(int)>(&QLabel::setNum));
    connect(slider, &QSlider::valueChanged,
            rightLabel, static_cast<void (QLabel::*)(int)>(&QLabel::setNum));

}
