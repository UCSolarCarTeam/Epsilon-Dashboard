#include "ProgressBar.h"

namespace
{
    const int FULL_CIRCLE = 5760;
    const int START_ANGLE = 1440;
}

ProgressBar::ProgressBar()
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
    pen.setColor(QColor(92,145,161));
    p.setPen(pen);

    p.setRenderHint(QPainter::Antialiasing);

    QRectF rectangle(27.0, 27.0, 138.0, 138.0);
    int spanAngle = progress * FULL_CIRCLE;

    p.drawArc(rectangle, START_ANGLE, spanAngle);
}
