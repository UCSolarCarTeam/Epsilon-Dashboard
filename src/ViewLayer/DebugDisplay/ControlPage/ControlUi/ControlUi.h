#pragma once
#include "I_ControlUi.h"
namespace Ui
{
    class ControlUi;
}

class ControlUi : public I_ControlUi
{
    Q_OBJECT
public:
    explicit ControlUi();
    ~ControlUi();
    QLabel& titleLabel();
private:
    Ui::ControlUi* ui_;
};

