#include <QVBoxLayout>
#include <QHBoxLayout>
#include "burning.h"

Burning::Burning(QWidget *parent)
    : QFrame(parent) {

  initUI();
}

void Burning::initUI() {

  const int MAX_VALUE = 750;
  cur_width = 0;

  slider = new QSlider(Qt::Horizontal , this);
  slider->setMaximum(MAX_VALUE);
  slider->setGeometry(50, 50, 130, 30);

  connect(slider, &QSlider::valueChanged, this, &Burning::valueChanged);

  QVBoxLayout *vbox = new QVBoxLayout(this);
  QHBoxLayout *hbox = new QHBoxLayout();

  vbox->addStretch(1);

  widget = new Widget(this);
  hbox->addWidget(widget, 0);

  vbox->addLayout(hbox);

  setLayout(vbox);
}

void Burning::valueChanged(int val) {

  cur_width = val;
  widget->repaint();
}

int Burning::getCurrentWidth() {

  return cur_width;
}
