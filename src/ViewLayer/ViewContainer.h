#pragma once

#include <QScopedPointer>

class I_DisplayDashboardUI;
class I_RaceModeDashboardUI;
class I_BatteryUi;
class I_ControlUi;
class I_HomePageUi;
class I_FaultUi;
class I_TabUi;
class I_MotorUi;
class I_MpptUi;
class I_AuxBmsUi;
class DisplayDashboardView;
class RaceModeDashboardView;
class ControlView;
class HomePageView;
class FaultView;
class MpptView;
class MotorView;
class BatteryView;
class FaultPopulator;
class I_MotorFaultList;
class MotorFaultsUpdater;
class I_BatteryFaultList;
class BatteryFaultsUpdater;
class OverlordWidget;
class PresenterContainer;
class ProgressBar;
class AuxBmsView;

enum class Mode { RACE, DISPLAY, DEBUG };

class ViewContainer
{
public:
    explicit ViewContainer(PresenterContainer& presenterContainer, Mode mode, bool isWindowed);
    ~ViewContainer();

private:
    QScopedPointer<I_DisplayDashboardUI> displayDashboardUI_;
    QScopedPointer<I_RaceModeDashboardUI> raceModeDashboardUI_;
    QScopedPointer<I_BatteryUi> batteryUi_;
    QScopedPointer<I_ControlUi> controlUi_;
    QScopedPointer<I_HomePageUi> homepageUi_;
    QScopedPointer<I_FaultUi> faultUi_;
    QScopedPointer<I_MotorUi> motorUi_;
    QScopedPointer<I_MpptUi> mpptUi_;
    QScopedPointer<I_TabUi> tabUi_;
    QScopedPointer<I_AuxBmsUi> auxBmsUi_;
    QScopedPointer<ProgressBar> progressBar_;
    QScopedPointer<MotorView> motorView_;
    QScopedPointer<FaultView> faultView_;
    QScopedPointer<ControlView> controlView_;
    QScopedPointer<MpptView> mpptView_;
    QScopedPointer<HomePageView> homePageView_;
    QScopedPointer<AuxBmsView> auxBmsView_;
    QScopedPointer<DisplayDashboardView> displayDashboardView_;
    QScopedPointer<RaceModeDashboardView> raceModeDashboardView_;
    QScopedPointer<OverlordWidget> overlordWidget_;
    QScopedPointer<BatteryView> batteryView_;
    QScopedPointer<I_MotorFaultList> motorZeroFaultList_;
    QScopedPointer<I_MotorFaultList> motorOneFaultList_;
    QScopedPointer<FaultPopulator> motorFaultPopulator_;
    QScopedPointer<MotorFaultsUpdater> motorFaultUpdater_;
    QScopedPointer<I_BatteryFaultList> batteryFaultList_;
    QScopedPointer<FaultPopulator> batteryFaultPopulator_;
    QScopedPointer<BatteryFaultsUpdater> batteryFaultUpdater_;
};
