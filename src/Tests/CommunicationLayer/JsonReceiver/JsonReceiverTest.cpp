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
#include "BusinessLayer/CommunicationsMonitoringService/mock_communicationsmonitoringservice.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <QScopedPointer>(


class JsonReceiverTest : public ::testing::Test
{
protected:
    QScopedPointer<MockAuxBmsPopulator> auxBmsPopulator_;
    QScopedPointer<MockBatteryFaultsPopulator> batteryFaultsPopulator_;
    QScopedPointer<MockBatteryPopulator> batteryPopulator_;
    QScopedPointer<MockDriverControlsPopulator> driverControlsPopulator_;
     QScopedPointer<MockKeyMotorPopulator> keyMotorPopulator_;
     QScopedPointer<MockLightsPopulator> lightsPopulator_;
    QScopedPointer<MockMotorDetailsPopulator> motorDetailsPopulator_;
    QScopedPointer<MockMotorFaultsPopulator> motorFaultsPopulator_;
    QScopedPointer<MockMpptPopulator> mpptPopulator_;
    QScopedPointer<MockCommuncationMonitoringService> communicationsMonitoringService_;
    QScopedPointer<JsonReceiver> jasonReceiver_;

    virtual void SetUp()
    {
                auxBmsPopulator_.reset(new MockAuxBmsPopulator());
                batteryFaultsPopulator_.reset(new MockBatteryFaultsPopulator());
                batteryPopulator_.reset(new MockBatteryPopulator());
                driverControlsPopulator_.reset(new MockDriverControlsPopulator());
                keyMotorPopulator_.reset(new MockKeyMotorPopulator());
                lightsPopulator_.reset(new MockLightsPopulator());
                motorDetailsPopulator_.reset(new MockMotorDetailsPopulator());
                motorFaultsPopulator_.reset(new MockMotorFaultsPopulator());
                mpptPopulator_.reset(new MockMpptPopulator());
                communicationsMonitoringService_.reset(new MockCommuncationMonitoringService());


                jasonReceiver_.reset(new JsonReceiver(*auxBmsPopulator_,
                             *batteryPopulator_,
                             *batteryFaultsPopulator_,
                             *driverControlsPopulator_,
                             *keyMotorPopulator_,
                             *lightsPopulator_,
                             *mpptPopulator_,
                             *motorDetailsPopulator_,
                             *motorFaultsPopulator_,
                             *communicationsMonitoringService_,
                             false));
            }
};
