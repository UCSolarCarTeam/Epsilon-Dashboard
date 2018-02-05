#include <QUdpSocket>

#include "../DataLayer/DataContainer.h"
#include "CommunicationContainer.h"
#include "CommDeviceControl/ConnectionController.h"
#include "CommDeviceControl/CommDeviceManager.h"
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
        :
        connectionController_(infrastructureContainer.settings().exchange(),
                                infrastructureContainer.settings().queue(),
                                infrastructureContainer.settings().ipAddress(),
                                infrastructureContainer.settings().port())
        , commDeviceManager_(connectionController_.getChannel(),
                             infrastructureContainer.settings().queue())
        , jsonReceiver_(businessContainer.batteryPopulator(),
                        businessContainer.batteryFaultsPopulator(),
                        businessContainer.driverControlsPopulator(),
                        businessContainer.keyMotorPopulator(),
                        businessContainer.lightsPopulator(),
                        businessContainer.mpptPopulator(),
                        businessContainer.motorDetailsPopulator(),
                        businessContainer.motorFaultsPopulator(),
                        businessContainer.communicationsMonitoringService())
    {
        QObject::connect(&commDeviceManager_, SIGNAL(dataReceived(QByteArray)), &jsonReceiver_, SLOT(handleIncomingData(QByteArray)));
    }
    //InternetConnectionService internetConnectionService_;
    ConnectionController connectionController_;
    CommDeviceManager commDeviceManager_;
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

I_JsonReceiver& CommunicationContainer::jsonReceiver()
{
    return impl_->jsonReceiver_;
}

CommDeviceManager& CommunicationContainer::commDeviceManager()
{
    return impl_->commDeviceManager_;
}
