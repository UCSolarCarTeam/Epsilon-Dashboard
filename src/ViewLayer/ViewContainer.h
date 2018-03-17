#pragma once

#include "DebugDisplay/BatteryPage/ProgressBar.h"
#include <QScopedPointer>

#include "DebugDisplay/BatteryPage/BatteryUi/BatteryUi.h"
#include "DebugDisplay/BatteryPage/BatteryView/BatteryView.h"
#include "../PresenterLayer/PresenterContainer.h"


class DisplayDashboardView;
class RaceModeDashboardView;
class I_DisplayDashboardUI;
class I_RaceModeDashboardUI;
class BatteryUi;
class ControlUi;
class ControlView;
class HomePageUi;
class FaultUi;
class FaultView;
class MotorUi;
class MpptUi;
class MpptView;
class OverlordWidget;
class TabUi;
class PresenterContainer;
class ProgressBar;

class BatteryView;

enum class Mode { RACE, DISPLAY, DEBUG };

class ViewContainer
{
public:
    explicit ViewContainer(PresenterContainer& presenterContainer, Mode mode);
    ~ViewContainer();

private:
    I_DisplayDashboardUI* DisplayDashboardUI_;
    I_RaceModeDashboardUI* RaceModeDashboardUI_;
    BatteryUi* batteryUi_;
    ControlUi* controlUi_;
    HomePageUi* homepageUi_;
    FaultUi* faultUi_;
    MotorUi* motorUi_;
    MpptUi* mpptUi_;
    TabUi* tabUi_;
    ProgressBar* ProgressBar_;

    QScopedPointer<FaultView> FaultView_;

    QScopedPointer<ControlView> ControlView_;
    QScopedPointer<MpptView> MpptView_;

    QScopedPointer<DisplayDashboardView> DisplayDashboardView_;
    QScopedPointer<RaceModeDashboardView> RaceModeDashboardView_;
    QScopedPointer<OverlordWidget> overlordWidget_;

    QScopedPointer<BatteryView> BatteryView_;
};
