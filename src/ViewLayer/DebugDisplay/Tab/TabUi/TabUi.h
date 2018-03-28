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
    explicit TabUi(QWidget *parent = 0);
    ~TabUi();
    QPushButton& homepageButton();
    QPushButton& batteryButton();
    QPushButton& controlButton();
    QPushButton& faultButton();
    QPushButton& motorButton();
    QPushButton& mpptButton();
private slots:
    void showTime();
private:
    Ui::TabUi* ui_;
};
