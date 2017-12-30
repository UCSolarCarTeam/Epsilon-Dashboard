#pragma once

#include "I_RaceModeDashboardUI.h"

namespace Ui
{
    class RaceModeDashboardUI;
}
class RaceModeDashboardUI : public I_RaceModeDashboardUI
{
    Q_OBJECT

public:
    explicit RaceModeDashboardUI();
    ~RaceModeDashboardUI();

private:
    Ui::RaceModeDashboardUI* ui_;
};
