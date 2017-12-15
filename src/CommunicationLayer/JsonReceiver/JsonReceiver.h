#pragma once

#include <QObject>
#include "I_JsonReceiver.h"

#include "../BusinessLayer/DataPopulators/BatteryFaultsPopulator.h"
#include "../BusinessLayer/DataPopulators/BatteryPopulator.h"
#include "../BusinessLayer/DataPopulators/DriverControlsPopulator.h"
#include "../BusinessLayer/DataPopulators/KeyMotorPopulator.h"
#include "../BusinessLayer/DataPopulators/LightsPopulator.h"
#include "../BusinessLayer/DataPopulators/MpptPopulator.h"
#include "../BusinessLayer/DataPopulators/MotorDetailsPopulator.h"
#include "../BusinessLayer/DataPopulators/MotorFaultsPopulator.h"
#include "../BusinessLayer/DataPopulators/MotorFaultsPopulator.h"
#include "../BusinessLayer/CommunicationsMonitoringService/I_CommunicationsMonitoringService.h"

#include "CommDeviceControl/I_CommDevice.h"

class BatteryPopulator;
class BatteryFaultsPopulator;
class DriverControlsPopulator;
class KeyMotorPopulator;
class LightsPopulator;
class MpptPopulator;
class MotorDetailsPopulator;
class MotorFaultsPopulator;
class I_CommunicationsMonitoringService;

class JsonReceiver : public I_JsonReceiver
{
    Q_OBJECT
public:
    JsonReceiver(I_CommDevice& inputDevice,
                 BatteryPopulator& batteryPopulator,
                 BatteryFaultsPopulator& batteryFaultsPopulator,
                 DriverControlsPopulator& driverControlsPopulator,
                 KeyMotorPopulator& keyMotorPopulator,
                 LightsPopulator& lightsPopulator,
                 MpptPopulator& mpptPopulator,
                 MotorDetailsPopulator& motorDetailsPopulator,
                 MotorFaultsPopulator& motorFaultsPopulator,
                 I_CommunicationsMonitoringService& communicationsMonitoringService);
    virtual ~JsonReceiver() {}

public slots:
    void handleIncomingData(const QByteArray&);

private:
    BatteryPopulator& batteryPopulator_;
    BatteryFaultsPopulator& batteryFaultsPopulator_;
    DriverControlsPopulator& driverControlsPopulator_;
    KeyMotorPopulator& keyMotorPopulator_;
    LightsPopulator& lightsPopulator_;
    MpptPopulator& mpptPopulator_;
    MotorDetailsPopulator& motorDetailsPopulator_;
    MotorFaultsPopulator& motorFaultsPopulator_;
    I_CommunicationsMonitoringService& communicationsMonitoringService_;
};
