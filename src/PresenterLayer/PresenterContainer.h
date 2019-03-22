#pragma once

#include <QScopedPointer>

class BusinessContainer;
class CommunicationContainer;
class DataContainer;

class AuxBmsPresenter;
class BatteryPresenter;
class BatteryFaultsPresenter;
class CcsPresenter;
class DriverControlsPresenter;
class KeyMotorPresenter;
class LightsPresenter;
class MpptPresenter;
class MotorDetailsPresenter;
class MotorFaultsPresenter;

class PresenterContainer
{
public:
    PresenterContainer(DataContainer& dataContainer);
    ~PresenterContainer();
    AuxBmsPresenter& auxBmsPresenter();
    BatteryPresenter& batteryPresenter();
    BatteryFaultsPresenter& batteryFaultsPresenter();
    CcsPresenter& ccsPresenter();
    DriverControlsPresenter& driverControlsPresenter();
    KeyMotorPresenter& keyMotorPresenter();
    LightsPresenter& lightsPresenter();
    MpptPresenter& mpptPresenter();
    MotorDetailsPresenter& motorDetailsPresenter();
    MotorFaultsPresenter& motorFaultsPresenter();


private:
    QScopedPointer<AuxBmsPresenter> auxBmsPresenter_;
    QScopedPointer<BatteryPresenter> batteryPresenter_;
    QScopedPointer<BatteryFaultsPresenter> batteryFaultsPresenter_;
    QScopedPointer<CcsPresenter> ccsPresenter_;
    QScopedPointer<DriverControlsPresenter> driverControlsPresenter_;
    QScopedPointer<KeyMotorPresenter> keyMotorPresenter_;
    QScopedPointer<LightsPresenter> lightsPresenter_;
    QScopedPointer<MpptPresenter> mpptPresenter_;
    QScopedPointer<MotorDetailsPresenter> motorDetailsPresenter_;
    QScopedPointer<MotorFaultsPresenter> motorFaultsPresenter_;
};
