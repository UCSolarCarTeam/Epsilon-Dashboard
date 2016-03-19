#pragma once

#include <QObject>
#include <QLabel>
#include "CommunicationLayer/MessagingFramework/BatteryFaults.h"
#include "CommunicationLayer/MessagingFramework/LimitFlags.h"
#include "CommunicationLayer/MessagingFramework/MotorFaults.h"
#include "ViewLayer/DashboardUI/DashboardUI.h"

class BatteryPresenter;
class CommunicationPresenter;
class DashboardUI;
class FaultsPresenter;
class MpptPresenter;
class PowerPresenter;
class VehiclePresenter;

class DashboardView : public QObject
{
    Q_OBJECT

public:
    DashboardView(BatteryPresenter& batteryPresenter,
                  VehiclePresenter& vehiclePresenter,
                  PowerPresenter& powerPresenter,
                  CommunicationPresenter& communicationPresenter,
                  FaultsPresenter& faultsPresenter,
                  MpptPresenter& mpptPresenter,
                  DashboardUI& ui);
    ~DashboardView();

private:
    DashboardUI& ui_;
};

