#include "../DataLayer/DataContainer.h"
#include "PresenterContainer.h"

#include "AuxBmsPresenter/AuxBmsPresenter.h"
#include "BatteryPresenter/BatteryPresenter.h"
#include "BatteryFaultsPresenter/BatteryFaultsPresenter.h"
#include "CcsPresenter/CcsPresenter.h"
#include "DriverControlsPresenter/DriverControlsPresenter.h"
#include "KeyMotorPresenter/KeyMotorPresenter.h"
#include "LightsPresenter/LightsPresenter.h"
#include "MpptPresenter/MpptPresenter.h"
#include "MotorDetailsPresenter/MotorDetailsPresenter.h"
#include "MotorFaultsPresenter/MotorFaultsPresenter.h"

PresenterContainer::PresenterContainer(DataContainer& dataContainer)
    : auxBmsPresenter_(new AuxBmsPresenter(dataContainer.auxBmsData()))
    , batteryPresenter_(new BatteryPresenter(dataContainer.batteryData()))
    , batteryFaultsPresenter_(new BatteryFaultsPresenter(dataContainer.batteryFaultsData()))
    , ccsPresenter_(new CcsPresenter(dataContainer.ccsData()))
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

AuxBmsPresenter& PresenterContainer::auxBmsPresenter()
{
    return *auxBmsPresenter_;
}

BatteryPresenter& PresenterContainer::batteryPresenter()
{
    return *batteryPresenter_;
}
BatteryFaultsPresenter& PresenterContainer::batteryFaultsPresenter()
{
    return *batteryFaultsPresenter_;
}
CcsPresenter& PresenterContainer::ccsPresenter()
{
    return *ccsPresenter_;
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

