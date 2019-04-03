#include "DisplayDashboard/DisplayDashboardUI/DisplayDashboardUI.h"
#include "RaceModeDisplay/RaceModeDisplayUI/RaceModeDashboardUI.h"
#include "DisplayDashboard/DisplayDashboardView/DisplayDashboardView.h"
#include "RaceModeDisplay/RaceModeDashboardView.h"
#include "Faults/BatteryFaults/BatteryFaultList.h"
#include "Faults/MotorFaults/MotorFaultList.h"
#include "../PresenterLayer/PresenterContainer.h"
#include "ViewContainer.h"
#include "DebugDisplay/BatteryPage/BatteryUi/BatteryUi.h"
#include "DebugDisplay/ControlPage/ControlUi/ControlUi.h"
#include "DebugDisplay/ControlPage/ControlView/ControlView.h"
#include "DebugDisplay/HomePage/HomePageUi/HomePageUi.h"
#include "DebugDisplay/HomePage/HomePageView/HomePageView.h"
#include "DebugDisplay/FaultPage/FaultUi/FaultUi.h"
#include "DebugDisplay/FaultPage/FaultView/FaultView.h"
#include "DebugDisplay/MotorPage/MotorUi/MotorUi.h"
#include "DebugDisplay/MotorPage/MotorView/MotorView.h"
#include "DebugDisplay/OverlordWidget/OverlordWidget.h"
#include "DebugDisplay/Tab/TabUi/TabUi.h"
#include "DebugDisplay/MPPTPage/MPPTUi/MpptUi.h"
#include "DebugDisplay/MPPTPage/MPPTView/MpptView.h"


ViewContainer::ViewContainer(PresenterContainer& presenterContainer, Mode mode, bool windowed)

{
    if (mode == Mode::DISPLAY)
    {
        MotorFaultList* motorZeroFaultList = new MotorFaultList();
        MotorFaultList* motorOneFaultList = new MotorFaultList();
        BatteryFaultList* batteryFaultList = new BatteryFaultList();
        DisplayDashboardUI_ = new DisplayDashboardUI();
        DisplayDashboardView_.reset(new DisplayDashboardView(
                                        presenterContainer.auxBmsPresenter(),
                                        presenterContainer.batteryPresenter(),
                                        presenterContainer.batteryFaultsPresenter(),
                                        presenterContainer.driverControlsPresenter(),
                                        presenterContainer.keyMotorPresenter(),
                                        presenterContainer.lightsPresenter(),
                                        presenterContainer.mpptPresenter(),
                                        presenterContainer.motorDetailsPresenter(),
                                        presenterContainer.motorFaultsPresenter(),
                                        *DisplayDashboardUI_,
                                        *motorZeroFaultList,
                                        *motorOneFaultList,
                                        *batteryFaultList));

        if(!windowed){
            DisplayDashboardUI_->setNotWindowed();
        }
    }
    else if (mode == Mode::RACE)
    {
        MotorFaultList* motorZeroFaultList = new MotorFaultList();
        MotorFaultList* motorOneFaultList = new MotorFaultList();
        BatteryFaultList* batteryFaultList = new BatteryFaultList();
        RaceModeDashboardUI_ = new RaceModeDashboardUI();
        RaceModeDashboardView_.reset(new RaceModeDashboardView(
                                         presenterContainer.batteryPresenter(),
                                         presenterContainer.batteryFaultsPresenter(),
                                         presenterContainer.auxBmsPresenter(),
                                         presenterContainer.driverControlsPresenter(),
                                         presenterContainer.keyMotorPresenter(),
                                         presenterContainer.lightsPresenter(),
                                         presenterContainer.mpptPresenter(),
                                         presenterContainer.motorDetailsPresenter(),
                                         presenterContainer.motorFaultsPresenter(),
                                         *RaceModeDashboardUI_,
                                         *motorZeroFaultList,
                                         *motorOneFaultList,
                                         *batteryFaultList));
        if(!windowed){
            RaceModeDashboardUI_->setNotWindowed();
        }
    }
    else if (mode == Mode::DEBUG)
    {
        batteryUi_ = new BatteryUi();

        ProgressBar_ = new ProgressBar();
        BatteryView_.reset(new BatteryView(presenterContainer.batteryPresenter(),
                                           *batteryUi_, *ProgressBar_, presenterContainer.auxBmsPresenter()) );

        controlUi_ = new ControlUi();
        homepageUi_ = new HomePageUi();
        faultUi_ = new FaultUi();
        motorUi_ = new MotorUi();
        mpptUi_ = new MpptUi();
        tabUi_ = new TabUi();
        MotorFaultList* motorZeroFaultList = new MotorFaultList();
        MotorFaultList* motorOneFaultList = new MotorFaultList();
        BatteryFaultList* batteryFaultList = new BatteryFaultList();
        overlordWidget_.reset(new OverlordWidget(*batteryUi_, *controlUi_,
                              *homepageUi_, *faultUi_,
                              *motorUi_, *mpptUi_, *tabUi_));

        MotorView_.reset(new MotorView( presenterContainer.keyMotorPresenter(),
                                        presenterContainer.motorDetailsPresenter(), *motorUi_));

        FaultView_.reset(new FaultView(presenterContainer.motorFaultsPresenter(),
                                       presenterContainer.batteryFaultsPresenter(),
                                       *faultUi_,
                                       *motorZeroFaultList,
                                       *motorOneFaultList,
                                       *batteryFaultList));


        MpptView_.reset(new MpptView(presenterContainer.mpptPresenter(), *mpptUi_));
        ControlView_.reset(new ControlView(presenterContainer.ccsPresenter(),
                                           presenterContainer.driverControlsPresenter(),
                                           presenterContainer.lightsPresenter(),
                                           *controlUi_));
        HomePageView_.reset(new HomePageView(*homepageUi_));

        if(!windowed){
            overlordWidget_->setNotWindowed();
        }
    }
}

ViewContainer::~ViewContainer()
{
}
