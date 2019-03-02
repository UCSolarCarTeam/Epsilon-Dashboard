#include "BusinessContainer.h"
#include "CommunicationsMonitoringService/CommunicationsMonitoringService.h"
#include "../DataLayer/DataContainer.h"
#include "DataPopulators/AuxBmsPopulator/AuxBmsPopulator.h"
#include "DataPopulators/BatteryFaultsPopulator/BatteryFaultsPopulator.h"
#include "DataPopulators/BatteryPopulator/BatteryPopulator.h"
#include "DataPopulators/DriverControlsPopulator/DriverControlsPopulator.h"
#include "DataPopulators/KeyMotorPopulator/KeyMotorPopulator.h"
#include "DataPopulators/LightsPopulator/LightsPopulator.h"
#include "DataPopulators/MpptPopulator/MpptPopulator.h"
#include "DataPopulators/MotorDetailsPopulator/MotorDetailsPopulator.h"
#include "DataPopulators/MotorFaultsPopulator/MotorFaultsPopulator.h"

class BusinessContainerPrivate
{
public:
    BusinessContainerPrivate(DataContainer& dataContainer)
        : auxBmsPopulator_(dataContainer.auxBmsData())
        , batteryPopulator_(dataContainer.batteryData())
        , batteryFaultsPopulator_(dataContainer.batteryFaultsData())
        , driverControlsPopulator_(dataContainer.driverControlsData())
        , keyMotorPopulator_(dataContainer.keyMotorData())
        , lightsPopulator_(dataContainer.lightsData())
        , mpptPopulator_(dataContainer.mpptData())
        , motorDetailsPopulator_(dataContainer.motorDetailsData())
        , motorFaultsPopulator_(dataContainer.motorFaultsData())
    {
    }
    AuxBmsPopulator auxBmsPopulator_;
    BatteryPopulator batteryPopulator_;
    BatteryFaultsPopulator batteryFaultsPopulator_;
    DriverControlsPopulator driverControlsPopulator_;
    KeyMotorPopulator keyMotorPopulator_;
    LightsPopulator lightsPopulator_;
    MpptPopulator mpptPopulator_;
    MotorDetailsPopulator motorDetailsPopulator_;
    MotorFaultsPopulator motorFaultsPopulator_;
};
BusinessContainer::BusinessContainer(DataContainer& dataContainer)
    : communicationsMonitoringService_(new CommunicationsMonitoringService())
    , impl_(new BusinessContainerPrivate(dataContainer))
{
}

BusinessContainer::~BusinessContainer()
{
}

AuxBmsPopulator& BusinessContainer::auxBmsPopulator()
{
    return impl_->auxBmsPopulator_;
}

BatteryPopulator& BusinessContainer::batteryPopulator()
{
    return impl_->batteryPopulator_;
}

BatteryFaultsPopulator& BusinessContainer::batteryFaultsPopulator()
{
    return impl_->batteryFaultsPopulator_;
}

DriverControlsPopulator& BusinessContainer::driverControlsPopulator()
{
    return impl_->driverControlsPopulator_;
}

KeyMotorPopulator& BusinessContainer::keyMotorPopulator()
{
    return impl_->keyMotorPopulator_;
}

LightsPopulator& BusinessContainer::lightsPopulator()
{
    return impl_->lightsPopulator_;
}

MpptPopulator& BusinessContainer::mpptPopulator()
{
    return impl_->mpptPopulator_;
}

MotorDetailsPopulator& BusinessContainer::motorDetailsPopulator()
{
    return impl_->motorDetailsPopulator_;
}

MotorFaultsPopulator& BusinessContainer::motorFaultsPopulator()
{
    return impl_->motorFaultsPopulator_;
}

I_CommunicationsMonitoringService& BusinessContainer::communicationsMonitoringService()
{
    return *communicationsMonitoringService_;
}
