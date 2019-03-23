#pragma once
#include "gmock/gmock.h"
#include "../../../BusinessLayer/DataPopulators/BatteryPopulator/BatteryPopulator.h"

class MockBatteryPopulator: public I_BatteryPopulator
{
    Q_OBJECT
public:
    MOCK_METHOD1(populateData, void(const QJsonObject&));
};
