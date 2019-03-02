#pragma once
#include "gmock/gmock.h"
#include "../../../BusinessLayer/DataPopulators/BatteryFaultsPopulator/I_BatteryFaultsPopulator.h"

class MockBatteryFaultsPopulator: public I_BatteryFaultsPopulator
{
    Q_OBJECT
    public slots:
        MOCK_METHOD1(populateData, void(const QJsonObject&));
};
