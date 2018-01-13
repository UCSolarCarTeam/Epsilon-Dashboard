#pragma once
#include "I_MotorFaultUi.h"
namespace Ui
{
    class MotorFaultUi;
}
class MotorFaultUi : public I_MotorFaultUi
{
    Q_OBJECT
public:
    explicit MotorFaultUi();
    ~MotorFaultUi();

    QWidget& motor0ContentsWidget();
    QWidget& motor1ContentsWidget();
    QWidget& batteryContentsWidget();

    QScrollArea& motor0ScrollArea();
    QScrollArea& motor1ScrollArea();
    QScrollArea& batteryScrollArea();

private:
    Ui::MotorFaultUi* ui_;
};
