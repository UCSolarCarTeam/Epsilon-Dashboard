#pragma once

#include <QObject>
#include "I_JsonReceiver.h"

#include "../BusinessLayer/DataPopulators/AuxBmsPopulator/I_AuxBmsPopulator.h"
#include "../BusinessLayer/DataPopulators/BatteryFaultsPopulator/I_BatteryFaultsPopulator.h"
#include "../BusinessLayer/DataPopulators/BatteryPopulator/I_BatteryPopulator.h"
#include "../BusinessLayer/DataPopulators/DriverControlsPopulator/I_DriverControlsPopulator.h"
#include "../BusinessLayer/DataPopulators/KeyMotorPopulator/I_KeyMotorPopulator.h"
#include "../BusinessLayer/DataPopulators/LightsPopulator/I_LightsPopulator.h"
#include "../BusinessLayer/DataPopulators/MpptPopulator/I_MpptPopulator.h"
#include "../BusinessLayer/DataPopulators/MotorDetailsPopulator/I_MotorDetailsPopulator.h"
#include "../BusinessLayer/DataPopulators/MotorFaultsPopulator/I_MotorFaultsPopulator.h"
#include "../BusinessLayer/DataPopulators/CcsPopulator.h"
#include "../BusinessLayer/CommunicationsMonitoringService/I_CommunicationsMonitoringService.h"

#include "../CommDeviceControl/I_CommDevice.h"
#include "../Logging/Logging.h"

class I_AuxBmsPopulator;
class I_BatteryPopulator;
class I_BatteryFaultsPopulator;
class I_DriverControlsPopulator;
class I_KeyMotorPopulator;
class I_LightsPopulator;
class I_MpptPopulator;
class I_MotorDetailsPopulator;
class I_MotorFaultsPopulator;

class CcsPopulator;
class I_CommunicationsMonitoringService;
class Logging;

class JsonReceiver : public I_JsonReceiver
{
    Q_OBJECT
public:
    JsonReceiver(I_AuxBmsPopulator& auxBmsPopulator,
                 I_BatteryPopulator& batteryPopulator,
                 I_BatteryFaultsPopulator& batteryFaultsPopulator,
                 CcsPopulator& ccsPopulator,
                 I_DriverControlsPopulator& driverControlsPopulator,
                 I_KeyMotorPopulator& keyMotorPopulator,
                 I_LightsPopulator& lightsPopulator,
                 I_MpptPopulator& mpptPopulator,
                 I_MotorDetailsPopulator& motorDetailsPopulator,
                 I_MotorFaultsPopulator& motorFaultsPopulator,
                 I_CommunicationsMonitoringService& communicationsMonitoringService,
                 bool loggingEnabled);
    virtual ~JsonReceiver() {}

public slots:
    void handleIncomingData(const QByteArray&);

private:
    I_AuxBmsPopulator& auxBmsPopulator_;
    I_BatteryPopulator& batteryPopulator_;
    I_BatteryFaultsPopulator& batteryFaultsPopulator_;
    I_DriverControlsPopulator& driverControlsPopulator_;
    I_KeyMotorPopulator& keyMotorPopulator_;
    I_LightsPopulator& lightsPopulator_;
    I_MpptPopulator& mpptPopulator_;
    I_MotorDetailsPopulator& motorDetailsPopulator_;
    I_MotorFaultsPopulator& motorFaultsPopulator_;
    CcsPopulator& ccsPopulator_;
    I_CommunicationsMonitoringService& communicationsMonitoringService_;
    bool loggingEnabled_;
    Logging* logger_;
};
