#include "../CommunicationLayer/JsonReceiver/JsonReceiver.h"

#include "BusinessLayer/DataPopulators/MockBatteryPopulator.h"
#include "BusinessLayer/DataPopulators/MockDriverControlsPopulator.h"
#include "BusinessLayer/DataPopulators/MockMotorFaultsPopulator.h"
#include "BusinessLayer/DataPopulators/MockLightsPopulator.h"
#include "BusinessLayer/DataPopulators/MockBatteryFaultsPopulator.h"
#include "BusinessLayer/DataPopulators/MockKeyMotorPopulator.h"
#include "BusinessLayer/DataPopulators/MockAuxBmsPopulator.h"
#include "BusinessLayer/DataPopulators/MockMotorDetailsPopulator.h"
#include "BusinessLayer/DataPopulators/MockMpptPopulator.h"
#include "BusinessLayer/CommunicationsMonitoringService/MockCommunicationMonitoringService.h"
#include <gtest/gtest.h>
#include <QScopedPointer>


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
    QScopedPointer<JsonReceiver> jsonReceiver_;

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


        jsonReceiver_.reset(new JsonReceiver(*auxBmsPopulator_,
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
TEST_F(JsonReceiverTest, receivedData)
{
    ASSERT_EQ(1, 1);
}
