#pragma once
#include "I_MotorUi.h"

namespace Ui
{
    class MotorUi;
}
class MotorUi : public I_MotorUi
{
    Q_OBJECT
public:
    explicit MotorUi();
    ~MotorUi();
    QLabel& titleLabel();

private:
    Ui::MotorUi* ui_;
};

