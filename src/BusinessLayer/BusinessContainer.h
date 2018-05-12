#pragma once

#include <QScopedPointer>

class DataContainer;

class AuxBmsPopulator;
class BatteryPopulator;
class BatteryFaultsPopulator;
class DriverControlsPopulator;
class KeyMotorPopulator;
class LightsPopulator;
class MpptPopulator;
class MotorDetailsPopulator;
class MotorFaultsPopulator;
class I_CommunicationsMonitoringService;

class BusinessContainerPrivate;

class BusinessContainer
{
public:
    explicit BusinessContainer(DataContainer& dataContainer);
    ~BusinessContainer();

    AuxBmsPopulator& auxBmsPopulator();
    BatteryPopulator& batteryPopulator();
    BatteryFaultsPopulator& batteryFaultsPopulator();
    DriverControlsPopulator& driverControlsPopulator();
    KeyMotorPopulator& keyMotorPopulator();
    LightsPopulator& lightsPopulator();
    MpptPopulator& mpptPopulator();
    MotorDetailsPopulator& motorDetailsPopulator();
    MotorFaultsPopulator& motorFaultsPopulator();
    I_CommunicationsMonitoringService& communicationsMonitoringService();
private:
    QScopedPointer<I_CommunicationsMonitoringService> communicationsMonitoringService_;
    QScopedPointer<BusinessContainerPrivate> impl_;
};
