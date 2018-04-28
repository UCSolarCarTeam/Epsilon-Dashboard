#pragma once

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QProgressBar>

class ProgressBar : public QWidget
{
    Q_OBJECT
public:
    ProgressBar(QWidget* parent = 0);
    ~ProgressBar();
    double progress;
    void paintEvent(QPaintEvent*);

protected:

};

