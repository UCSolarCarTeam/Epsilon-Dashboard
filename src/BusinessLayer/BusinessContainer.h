#pragma once

#include <QScopedPointer>

class DataContainer;

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

class BusinessContainerPrivate;

class BusinessContainer
{
public:
    explicit BusinessContainer(DataContainer& dataContainer);
    ~BusinessContainer();
    I_AuxBmsPopulator& auxBmsPopulator();
    I_BatteryPopulator& batteryPopulator();
    I_BatteryFaultsPopulator& batteryFaultsPopulator();
    I_DriverControlsPopulator& driverControlsPopulator();
    I_KeyMotorPopulator& keyMotorPopulator();
    I_LightsPopulator& lightsPopulator();
    I_MpptPopulator& mpptPopulator();
    I_MotorDetailsPopulator& motorDetailsPopulator();
    I_MotorFaultsPopulator& motorFaultsPopulator();
    CcsPopulator& ccsPopulator();
    I_CommunicationsMonitoringService& communicationsMonitoringService();
private:
    QScopedPointer<I_CommunicationsMonitoringService> communicationsMonitoringService_;
    QScopedPointer<BusinessContainerPrivate> impl_;
};
