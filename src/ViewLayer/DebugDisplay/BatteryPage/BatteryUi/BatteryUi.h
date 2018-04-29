#pragma once
#include "I_BatteryUi.h"
namespace Ui
{
class BatteryUi;
}

class BatteryUi : public I_BatteryUi
{
    Q_OBJECT

public:
    explicit BatteryUi();
    ~BatteryUi();
    QLabel& titleLabel();
private:
    Ui::BatteryUi* ui_;
};

