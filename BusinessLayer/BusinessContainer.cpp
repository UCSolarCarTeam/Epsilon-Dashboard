#include "BusinessContainer.h"
#include "CommunicationLayer/CommunicationContainer.h"
#include "CommunicationLayer/JsonReceiver/I_JsonReceiver.h"
#include "CommunicationsMonitoringService/CommunicationsMonitoringService.h"
#include "DataLayer/DataContainer.h"
#include "DataPopulators/BatteryFaultsPopulator.h"
#include "DataPopulators/BatteryPopulator.h"
#include "DataPopulators/CmuPopulator.h"
#include "DataPopulators/DriverControlsPopulator.h"
#include "DataPopulators/KeyMotorPopulator.h"
#include "DataPopulators/LightsPopulator.h"
#include "DataPopulators/MpptPopulator.h"
#include "DataPopulators/MotorDetailsPopulator.h"
#include "DataPopulators/MotorFaultsPopulator.h"

class BusinessContainerPrivate
{
public:
    BusinessContainerPrivate(CommunicationContainer& communicationContainer, DataContainer& dataContainer)
        : jsonReceiver_(communicationContainer.jsonReceiver())
        , batteryPopulator_(
              jsonReceiver_,
              dataContainer.batteryData())
        , batteryFaultsPopulator_(
              jsonReceiver_,
              dataContainer.batteryFaultsData())
        , cmuPopulator_(
              jsonReceiver_,
              dataContainer.cmuData())
        , driverControlsPopulator_(
              jsonReceiver_,
              dataContainer.driverControlsData())
        , keyMotorPopulator_(
              jsonReceiver_,
              dataContainer.keyMotorData())
        , lightsPopulator_(
              jsonReceiver_,
              dataContainer.lightsData())
        , mpptPopulator_(
              jsonReceiver_,
              dataContainer.mpptData())
        , motorDetailsPopulator_(
              jsonReceiver_,
              dataContainer.motorDetailsData())
        , motorFaultsPopulator_(
              jsonReceiver_,
              dataContainer.motorFaultsData())
    {
    }
    I_JsonReceiver& jsonReceiver_;
    BatteryPopulator batteryPopulator_;
    BatteryFaultsPopulator batteryFaultsPopulator_;
    CmuPopulator cmuPopulator_;
    DriverControlsPopulator driverControlsPopulator_;
    KeyMotorPopulator keyMotorPopulator_;
    LightsPopulator lightsPopulator_;
    MpptPopulator mpptPopulator_;
    MotorDetailsPopulator motorDetailsPopulator_;
    MotorFaultsPopulator motorFaultsPopulator_;
};
BusinessContainer::BusinessContainer(CommunicationContainer& communicationContainer, DataContainer& dataContainer)
    : communicationsMonitoringService_(new CommunicationsMonitoringService(
                                           communicationContainer.jsonReceiver()))
    , impl_(new BusinessContainerPrivate(communicationContainer, dataContainer))
{
}

BusinessContainer::~BusinessContainer()
{
}


I_CommunicationsMonitoringService& BusinessContainer::communicationsMonitoringService()
{
    return *communicationsMonitoringService_;
}
