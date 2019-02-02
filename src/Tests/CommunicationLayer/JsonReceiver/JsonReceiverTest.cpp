#include "../CommunicationLayer/JsonReceiver/JsonReceiver.h"

#include "BusinessLayer/DataPopulators/mockbatterypopulator.h"
#include "BusinessLayer/DataPopulators/mockdrivercontrolspopulator.h"
#include "BusinessLayer/DataPopulators/mockmotorfaultspopulator.h"
#include "BusinessLayer/DataPopulators/mocklightspopulator.h"
#include "BusinessLayer/DataPopulators/mockbatteryfaultspopulator.h"
#include "BusinessLayer/DataPopulators/mockkeymotorpopulator.h"
#include "BusinessLayer/DataPopulators/mockauxbmspopulator.h"
#include "BusinessLayer/DataPopulators/mockmotordetailspopulator.h"
#include "BusinessLayer/DataPopulators/mockmpptpopulator.h"
#include "BusinessLayer/CommunicationsMonitoringService/mocki_communicationsmonitoringservice.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <QScopedPointer>


class JsonReceiverTest : public ::testing::Test
{


    virtual void SetUp()
    {
        auxBmsData_.reset(new MockAuxBmsData());
        batteryData_.reset(new MockBatteryData());
        batteryFaultsData_.reset(new MockBatteryFaultsData());
        driverControlsData_.reset(new MockDriverControlsData());
        keyMotorData_.reset(new MockKeyMotorData());
        lightsData_.reset(new MockLightsData());
        motorDetailsData_.reset(new MockMotorDetailsData());
        motorFaultsData_.reset(new MockMotorFaultsData());
        jsonMessageBuilder_.reset(new NiceMock<MockJsonMessageBuilder>());
        mpptData_.reset(new MockMpptData());
        messageForwarder_.reset(new MockMessageForwarder());
        settings_.reset(new MockSettings());
        EXPECT_CALL(*settings_, forwardPeriod())
        .WillRepeatedly(Return(FORWARD_INTERVAL_MSEC)); // Action must be set before jsonForwarder constructor
        EXPECT_CALL(*settings_, packetTitle())
        .WillRepeatedly(Return(PACKET_TITLE)); // Action must be set before jsonForwarder constructor
        JsonReceiver(AuxBmsPopulator& auxBmsPopulator,
                     BatteryPopulator& batteryPopulator,
                     BatteryFaultsPopulator& batteryFaultsPopulator,
                     DriverControlsPopulator& driverControlsPopulator,
                     KeyMotorPopulator& keyMotorPopulator,
                     LightsPopulator& lightsPopulator,
                     MpptPopulator& mpptPopulator,
                     MotorDetailsPopulator& motorDetailsPopulator,
                     MotorFaultsPopulator& motorFaultsPopulator,
                     I_CommunicationsMonitoringService& communicationsMonitoringService,
                     bool loggingEnabled);
    }
};
