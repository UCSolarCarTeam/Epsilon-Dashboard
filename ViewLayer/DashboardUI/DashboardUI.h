#pragma once

#include "I_DashboardUI.h"
#include "../I_SolarCarWindow/I_SolarCarWindow.h"

namespace Ui {
    class DashboardUI;
}
class DashboardUI : public I_SolarCarWindow, public I_DashboardUI
{
    Q_OBJECT

public:
    explicit DashboardUI();
    ~DashboardUI();

private:
    Ui::DashboardUI *ui;
};
