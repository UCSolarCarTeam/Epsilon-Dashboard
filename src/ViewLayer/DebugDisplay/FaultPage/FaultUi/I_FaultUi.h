#pragma once

#include <QLabel>
#include <QScrollArea>

class I_FaultUi: public QWidget
{
    Q_OBJECT
public:
    virtual ~I_FaultUi() {}


    virtual QWidget& motor0ContentsWidget() = 0;
    virtual QWidget& motor1ContentsWidget() = 0;
    virtual QWidget& batteryContentsWidget() = 0;

    virtual QScrollArea& motor0ScrollArea() = 0;
    virtual QScrollArea& motor1ScrollArea() = 0;
    virtual QScrollArea& batteryScrollArea() = 0;

    virtual QLabel& showHistoryLabel() = 0;

};
