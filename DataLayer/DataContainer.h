#pragma once

#include <QScopedPointer>

class I_BatteryData;
class I_BatteryFaultsData;
class I_CMUData;
class I_DriverControlsData;
class I_KeyMotorData;
class I_LightsData;
class I_MPPTData;
class I_MotorDetailsData;
class I_MotorFaultsData;

class DataContainer
{
public:
    DataContainer();
    ~DataContainer();

    I_BatteryData& batteryData();
    I_BatteryFaultsData& batteryFaultsData();
    I_CMUData& CMUData();
    I_DriverControlsData& driverControlsData();
    I_KeyMotorData& keyMotorData();
    I_LightsData& lightsData();
    I_MPPTData& MPPTData();
    I_MotorDetailsData& motorDetailsData();
    I_MotorFaultsData& motorFaultsData();

private:
    QScopedPointer<I_BatteryData> batteryData_;
    QScopedPointer<I_BatteryFaultsData> batteryFaultsData_;
    QScopedPointer<I_CMUData> CMUData_;
    QScopedPointer<I_DriverControlsData> driverControlsData_;
    QScopedPointer<I_KeyMotorData> keyMotorData_;
    QScopedPointer<I_LightsData> lightsData_;
    QScopedPointer<I_MPPTData> MPPTData_;
    QScopedPointer<I_MotorDetailsData> motorDetailsData_;
    QScopedPointer<I_MotorFaultsData> motorFaultsData_;
};
