#include "ProgressBar.h"

namespace
{
    const int FULL_CIRCLE = 5760;
    const int START_ANGLE = 1440;
    const int FONT_SIZE = 18;
    const double RECT_X_LOCATION = 10.0;
    const double RECT_Y_LOCATION = 30.0;
    const double RECT_HEIGHT = 100.0;
    const double RECT_WIDTH = 100.0;
    const int PEN_WIDTH = 7;
    const QColor TEXT_COLOR = QColor(250, 187, 28);

}


ProgressBar::ProgressBar(QWidget* parent) : QWidget(parent)
{

}


ProgressBar::~ProgressBar()
{
}

void ProgressBar::setProgress(double progress)
{
    progress_ = progress;
}


void ProgressBar::paintEvent(QPaintEvent*)
{
    QPainter p(this);

    QPen pen;
    pen.setWidth(PEN_WIDTH);
    pen.setColor(TEXT_COLOR);
    p.setPen(pen);

    p.setRenderHint(QPainter::Antialiasing);

    QRectF rectangle(RECT_X_LOCATION, RECT_Y_LOCATION, RECT_WIDTH, RECT_HEIGHT);
    int spanAngle = progress_ * FULL_CIRCLE;

    p.drawArc(rectangle, START_ANGLE, spanAngle);

    QFont font = p.font();
    font.setPointSize(FONT_SIZE);
    p.setFont(font);
    p.drawText(rectangle, Qt::AlignCenter, QString::number(progress_ * 100) + "%");
}
