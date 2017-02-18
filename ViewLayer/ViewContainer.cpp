#include "DisplayDashboardUI/DisplayDashboardUI.h"
#include "DisplayDashboardUI/RaceModeDashboardUI.h"
#include "DisplayDashboardView/DisplayDashboardView.h"
#include "PresenterLayer/PresenterContainer.h"
#include "ViewContainer.h"

ViewContainer::ViewContainer(PresenterContainer& presenterContainer, int mode)
{
    //TODO: Change this so that modes are switched with command line arguments
    //TODO: Mode should not be a magic number
    mode = 1;
    if(mode == 1)
    {
        DisplayDashboardUI_ = new DisplayDashboardUI();
        DisplayDashboardView_.reset(new DisplayDashboardView(
                                        presenterContainer.batteryPresenter(),
                                        presenterContainer.batteryFaultsPresenter(),
                                        presenterContainer.cmuPresenter(),
                                        presenterContainer.driverControlsPresenter(),
                                        presenterContainer.keyMotorPresenter(),
                                        presenterContainer.lightsPresenter(),
                                        presenterContainer.mpptPresenter(),
                                        presenterContainer.motorDetailsPresenter(),
                                        presenterContainer.motorFaultsPresenter(),
                                        *DisplayDashboardUI_));
    }
    else if(mode == 2)
    {
        RaceModeDashboardUI_ = new RaceModeDashboardUI();
        RaceModeDashboardUI_->show();
    }
}

ViewContainer::~ViewContainer()
{
}
