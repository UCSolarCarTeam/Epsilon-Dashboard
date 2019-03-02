#pragma once
#include "gmock/gmock.h"
#include "../../../BusinessLayer/CommunicationsMonitoringService/I_CommunicationsMonitoringService.h"

class MockCommuncationMonitoringService: public I_CommunicationsMonitoringService
{

    Q_OBJECT
public:
    MOCK_METHOD0(start, void());
    MOCK_METHOD0(stop, void());

signals:
    MOCK_METHOD1(secondsSinceLastPacketReceivedUpdate, void(int));
    MOCK_METHOD1(packetsReceivedInLastMinuteUpdate, void(int));
    MOCK_METHOD1(secondsSinceLastValidPacketReceivedUpdate, void(int));
    MOCK_METHOD1(validPacketsReceivedInLastMinuteUpdate, void(int));
    MOCK_METHOD1(invalidPacketsReceivedInLastMinuteUpdate, void(int));
};
