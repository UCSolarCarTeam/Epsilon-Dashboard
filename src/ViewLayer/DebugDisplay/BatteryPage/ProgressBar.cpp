#include "ProgressBar.h"

namespace
{
    const int FULL_CIRCLE = 5760;
    const int START_ANGLE = 1440;
}

ProgressBar::ProgressBar(QWidget *parent) : QWidget(parent)
{

}


ProgressBar::~ProgressBar()
{
}

void ProgressBar::paintEvent(QPaintEvent *)
{
    QPainter p(this);

    QPen pen;
    pen.setWidth(7);
    pen.setColor(QColor(250, 187, 28));
    p.setPen(pen);

    p.setRenderHint(QPainter::Antialiasing);

    QRectF rectangle(10.0, 20.0, 100.0, 100.0);
    int spanAngle = progress * FULL_CIRCLE;

    p.drawArc(rectangle, START_ANGLE, spanAngle);

    QFont font = p.font();
    font.setPointSize(17);
    p.setFont(font);
    p.drawText(rectangle, Qt::AlignCenter, QString::number(progress * 100) + "%");
}

