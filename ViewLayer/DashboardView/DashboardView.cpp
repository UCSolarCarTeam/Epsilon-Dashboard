#include "DashboardView.h"
#include "PresenterLayer/BatteryPresenter/BatteryPresenter.h"
#include "PresenterLayer/CommunicationPresenter/CommunicationPresenter.h"
#include "PresenterLayer/FaultsPresenter/FaultsPresenter.h"
#include "PresenterLayer/MpptPresenter/MpptPresenter.h"
#include "PresenterLayer/PowerPresenter/PowerPresenter.h"
#include "PresenterLayer/VehiclePresenter/VehiclePresenter.h"
#include "ViewLayer/DashboardUI/DashboardUI.h"
#include <QDateTime>

DashboardView::DashboardView(BatteryPresenter& batteryPresenter,
                             VehiclePresenter& vehiclePresenter,
                             PowerPresenter& powerPresenter,
                             CommunicationPresenter& communicationPresenter,
                             FaultsPresenter& faultsPresenter,
                             MpptPresenter& mpptPresenter,
                             DashboardUI& ui): ui_(ui)
{
	ui_.show();
}



DashboardView::~DashboardView()
{
}

