#pragma once

#include <QScopedPointer>

class BusinessContainer;
class CommunicationContainer;
class DataContainer;

class BatteryPresenter;
class BatteryFaultsPresenter;
class CmuPresenter;
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
    BatteryPresenter& batteryPresenter();
    BatteryFaultsPresenter& batteryFaultsPresenter();
    CmuPresenter& cmuPresenter();
    DriverControlsPresenter& driverControlsPresenter();
    KeyMotorPresenter& keyMotorPresenter();
    LightsPresenter& lightsPresenter();
    MpptPresenter& mpptPresenter();
    MotorDetailsPresenter& motorDetailsPresenter();
    MotorFaultsPresenter& motorFaultsPresenter();


private:
    QScopedPointer<BatteryPresenter> batteryPresenter_;
    QScopedPointer<BatteryFaultsPresenter> batteryFaultsPresenter_;
    QScopedPointer<CmuPresenter> cmuPresenter_;
    QScopedPointer<DriverControlsPresenter> driverControlsPresenter_;
    QScopedPointer<KeyMotorPresenter> keyMotorPresenter_;
    QScopedPointer<LightsPresenter> lightsPresenter_;
    QScopedPointer<MpptPresenter> mpptPresenter_;
    QScopedPointer<MotorDetailsPresenter> motorDetailsPresenter_;
    QScopedPointer<MotorFaultsPresenter> motorFaultsPresenter_;
};
