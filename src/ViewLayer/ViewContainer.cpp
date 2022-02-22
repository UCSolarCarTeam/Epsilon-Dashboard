#include "ViewContainer.h"

#include "Faults/MotorFaults/MotorFaultList.h"
#include "Faults/MotorFaults/MotorFaultPopulator.h"
#include "Faults/MotorFaults/MotorFaultsUpdater.h"
#include "Faults/BatteryFaults/BatteryFaultList.h"
#include "Faults/BatteryFaults/BatteryFaultPopulator.h"
#include "Faults/BatteryFaults/BatteryFaultsUpdater.h"
#include "DisplayDashboard/DisplayDashboardUI/DisplayDashboardUI.h"
#include "DisplayDashboard/DisplayDashboardView/DisplayDashboardView.h"
#include "../PresenterLayer/PresenterContainer.h"
#include "RaceModeDisplay/RaceModeDashboardView.h"
#include "RaceModeDisplay/RaceModeDisplayUI/RaceModeDashboardUI.h"
#include "DebugDisplay/BatteryPage/BatteryUi/BatteryUi.h"
#include "DebugDisplay/BatteryPage/ProgressBar.h"
#include "DebugDisplay/BatteryPage/BatteryView/BatteryView.h"
#include "DebugDisplay/ControlPage/ControlUi/ControlUi.h"
#include "DebugDisplay/HomePage/HomePageUi/HomePageUi.h"
#include "DebugDisplay/FaultPage/FaultUi/FaultUi.h"
#include "DebugDisplay/MotorPage/MotorUi/MotorUi.h"
#include "DebugDisplay/MPPTPage/MPPTUi/MpptUi.h"
#include "DebugDisplay/Tab/TabUi/TabUi.h"
#include "DebugDisplay/AuxBmsPage/AuxBmsUi/AuxBmsUi.h"
#include "DebugDisplay/OverlordWidget/OverlordWidget.h"
#include "DebugDisplay/MotorPage/MotorView/MotorView.h"
#include "DebugDisplay/FaultPage/FaultView/FaultView.h"
#include "DebugDisplay/MPPTPage/MPPTView/MpptView.h"
#include "DebugDisplay/ControlPage/ControlView/ControlView.h"
#include "DebugDisplay/HomePage/HomePageView/HomePageView.h"

#include "DebugDisplay/AuxBmsPage/AuxBmsView/AuxBmsView.h"

ViewContainer::ViewContainer(PresenterContainer& presenterContainer, Mode mode, bool isWindowed)
    :  motorZeroFaultList_(new MotorFaultList)
    ,  motorOneFaultList_(new MotorFaultList)
    ,  motorFaultPopulator_(new MotorFaultPopulator(*motorZeroFaultList_, *motorOneFaultList_))
    ,  motorFaultUpdater_(new MotorFaultsUpdater(presenterContainer.motorFaultsPresenter(), *motorZeroFaultList_, *motorOneFaultList_))
    ,  batteryFaultList_(new BatteryFaultList)
    ,  batteryFaultPopulator_(new BatteryFaultPopulator(*batteryFaultList_))
    ,  batteryFaultUpdater_(new BatteryFaultsUpdater(presenterContainer.batteryFaultsPresenter(), *batteryFaultList_))
{
    Q_INIT_RESOURCE(fontresources);

    if (mode == Mode::DISPLAY)
    {
        motorFaultPopulator_->populateFaults();
        batteryFaultPopulator_->populateFaults();
        displayDashboardUI_.reset(new DisplayDashboardUI(isWindowed));
        displayDashboardView_.reset(new DisplayDashboardView(
                                        presenterContainer.auxBmsPresenter(),
                                        presenterContainer.batteryPresenter(),
                                        presenterContainer.driverControlsPresenter(),
                                        presenterContainer.keyMotorPresenter(),
                                        presenterContainer.lightsPresenter(),
                                        presenterContainer.mpptPresenter(),
                                        presenterContainer.motorDetailsPresenter(),
                                        *displayDashboardUI_,
                                        *motorZeroFaultList_,
                                        *motorOneFaultList_,
                                        *batteryFaultList_));
    }
    else if (mode == Mode::RACE)
    {
        motorFaultPopulator_->populateRaceFaults();
        batteryFaultPopulator_->populateRaceFaults();
        raceModeDashboardUI_.reset(new RaceModeDashboardUI(isWindowed));
        raceModeDashboardView_.reset(new RaceModeDashboardView(
                                         presenterContainer.batteryPresenter(),
                                         presenterContainer.auxBmsPresenter(),
                                         presenterContainer.driverControlsPresenter(),
                                         presenterContainer.keyMotorPresenter(),
                                         presenterContainer.lightsPresenter(),
                                         presenterContainer.mpptPresenter(),
                                         presenterContainer.motorDetailsPresenter(),
                                         *raceModeDashboardUI_,
                                         *motorZeroFaultList_,
                                         *motorOneFaultList_,
                                         *batteryFaultList_));
    }
    else if (mode == Mode::DEBUG)
    {
        motorFaultPopulator_->populateFaults();
        batteryFaultPopulator_->populateFaults();
        batteryUi_.reset(new BatteryUi);
        controlUi_.reset(new ControlUi);
        homepageUi_.reset(new HomePageUi);
        faultUi_.reset(new FaultUi);
        motorUi_.reset(new MotorUi);
        mpptUi_.reset(new MpptUi);
        tabUi_.reset(new TabUi);
        auxBmsUi_.reset(new AuxBmsUi);
        progressBar_.reset(new ProgressBar);

        overlordWidget_.reset(new OverlordWidget
                              (
                                  *batteryUi_,
                                  *controlUi_,
                                  *homepageUi_,
                                  *faultUi_,
                                  *motorUi_,
                                  *mpptUi_,
                                  *tabUi_,
                                  *auxBmsUi_,
                                  isWindowed
                              ));

        batteryView_.reset(new BatteryView(presenterContainer.batteryPresenter(),
                                           *batteryUi_,
                                           *progressBar_) );
        motorView_.reset(new MotorView( presenterContainer.keyMotorPresenter(),
                                        presenterContainer.motorDetailsPresenter(), *motorUi_));

        faultView_.reset(new FaultView(*faultUi_,
                                       *motorZeroFaultList_,
                                       *motorOneFaultList_,
                                       *batteryFaultList_));

        auxBmsView_.reset(new AuxBmsView(presenterContainer.auxBmsPresenter(),
                                         *auxBmsUi_));
        mpptView_.reset(new MpptView(presenterContainer.mpptPresenter(), *mpptUi_));
        controlView_.reset(new ControlView(presenterContainer.ccsPresenter(),
                                           presenterContainer.driverControlsPresenter(),
                                           presenterContainer.lightsPresenter(),
                                           *controlUi_));
        homePageView_.reset(new HomePageView(*homepageUi_));
    }
}

ViewContainer::~ViewContainer()
{
}
