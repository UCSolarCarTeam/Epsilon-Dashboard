#pragma once
#include "I_TabUi.h"
namespace Ui
{
    class TabUi;
}
class TabUi : public I_TabUi
{
    Q_OBJECT
public:
    explicit TabUi();
    ~TabUi();
    QPushButton& homepageButton();
    QPushButton& batteryButton();
    QPushButton& controlButton();
    QPushButton& faultsButton();
    QPushButton& motorButton();
    QPushButton& mpptButton();
private:
    Ui::TabUi* ui_;
};
