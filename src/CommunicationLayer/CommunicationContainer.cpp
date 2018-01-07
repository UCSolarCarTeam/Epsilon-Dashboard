#include <QUdpSocket>

#include "../DataLayer/DataContainer.h"
#include "CommunicationContainer.h"
#include "CommDeviceControl/ConnectionController.h"
#include "CommDeviceControl/CommDeviceManager.h"
#include "CommDeviceControl/InternetCommDevice.h"
#include "CommDeviceControl/InternetConnectionService.h"
#include "JsonReceiver/JsonReceiver.h"
#include "../BusinessLayer/BusinessContainer.h"
#include "../InfrastructureLayer/InfrastructureContainer.h"
#include "../InfrastructureLayer/Settings/I_Settings.h"

class CommunicationContainerPrivate
{

public:
    CommunicationContainerPrivate(BusinessContainer& businessContainer,
                                  InfrastructureContainer& infrastructureContainer)
        : internetConnectionService_(infrastructureContainer.settings().exchange(),
                                     infrastructureContainer.settings().queue(),
                                     infrastructureContainer.settings().ipAddress(),
                                     infrastructureContainer.settings().port())
        , internetCommDevice_(internetConnectionService_.getChannel(),
                              infrastructureContainer.settings().queue())
        , connectionController_(internetConnectionService_)
        , jsonReceiver_(internetCommDevice_,
                        businessContainer.batteryPopulator(),
                        businessContainer.batteryFaultsPopulator(),
                        businessContainer.driverControlsPopulator(),
                        businessContainer.keyMotorPopulator(),
                        businessContainer.lightsPopulator(),
                        businessContainer.mpptPopulator(),
                        businessContainer.motorDetailsPopulator(),
                        businessContainer.motorFaultsPopulator(),
                        businessContainer.communicationsMonitoringService())
    {
    }
    InternetConnectionService internetConnectionService_;
    InternetCommDevice internetCommDevice_;
    ConnectionController connectionController_;
    JsonReceiver jsonReceiver_;
};

CommunicationContainer::CommunicationContainer(BusinessContainer& businessContainer, InfrastructureContainer& infrastructureContainer)
    : impl_(new CommunicationContainerPrivate(businessContainer, infrastructureContainer))
{
}

CommunicationContainer::~CommunicationContainer()
{
}

ConnectionController& CommunicationContainer::connectionController()
{
    return impl_->connectionController_;
}

InternetConnectionService& CommunicationContainer::internetConnectionService()
{
    return impl_->internetConnectionService_;
}

I_JsonReceiver& CommunicationContainer::jsonReceiver()
{
    return impl_->jsonReceiver_;
}

InternetCommDevice& CommunicationContainer::commDeviceManager()
{
    return impl_->internetCommDevice_;
}
