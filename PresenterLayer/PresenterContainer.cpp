#include "DataLayer/DataContainer.h"
#include "PresenterContainer.h"

#include "BatteryPresenter/BatteryPresenter.h"
#include "BatteryFaultsPresenter/BatteryFaultsPresenter.h"
#include "CmuPresenter/CmuPresenter.h"
#include "DriverControlsPresenter/DriverControlsPresenter.h"
#include "KeyMotorPresenter/KeyMotorPresenter.h"
#include "LightsPresenter/LightsPresenter.h"
#include "MpptPresenter/MpptPresenter.h"
#include "MotorDetailsPresenter/MotorDetailsPresenter.h"
#include "MotorFaultsPresenter/MotorFaultsPresenter.h"

PresenterContainer::PresenterContainer(DataContainer& dataContainer)
    : batteryPresenter_(new BatteryPresenter(dataContainer.batteryData()))
    , batteryFaultsPresenter_(new BatteryFaultsPresenter(dataContainer.batteryFaultsData()))
    , cmuPresenter_(new CmuPresenter(dataContainer.cmuData()))
    , driverControlsPresenter_(new DriverControlsPresenter(dataContainer.driverControlsData()))
    , keyMotorPresenter_(new KeyMotorPresenter(dataContainer.keyMotorData()))
    , lightsPresenter_(new LightsPresenter(dataContainer.lightsData()))
    , mpptPresenter_(new MpptPresenter(dataContainer.mpptData()))
    , motorDetailsPresenter_(new MotorDetailsPresenter(dataContainer.motorDetailsData()))
    , motorFaultsPresenter_(new MotorFaultsPresenter(dataContainer.motorFaultsData()))
{
}

PresenterContainer::~PresenterContainer()
{
}

BatteryPresenter& PresenterContainer::batteryPresenter()
{
    return *batteryPresenter_;
}
BatteryFaultsPresenter& PresenterContainer::batteryFaultsPresenter()
{
    return *batteryFaultsPresenter_;
}
CmuPresenter& PresenterContainer::cmuPresenter()
{
    return *cmuPresenter_;
}
DriverControlsPresenter& PresenterContainer::driverControlsPresenter()
{
    return *driverControlsPresenter_;
}
KeyMotorPresenter& PresenterContainer::keyMotorPresenter()
{
    return *keyMotorPresenter_;
}
LightsPresenter& PresenterContainer::lightsPresenter()
{
    return *lightsPresenter_;
}
MpptPresenter& PresenterContainer::mpptPresenter()
{
    return *mpptPresenter_;
}
MotorDetailsPresenter& PresenterContainer::motorDetailsPresenter()
{
    return *motorDetailsPresenter_;
}
MotorFaultsPresenter& PresenterContainer::motorFaultsPresenter()
{
    return *motorFaultsPresenter_;
}

