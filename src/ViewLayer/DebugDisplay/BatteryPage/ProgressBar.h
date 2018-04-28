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
    void paintEvent(QPaintEvent*);
    void setProgress(double progress);
private:
    double progress_;
};
