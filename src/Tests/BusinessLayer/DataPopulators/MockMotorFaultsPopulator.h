#pragma once
#include "gmock/gmock.h"
#include "../../../BusinessLayer/DataPopulators/MotorFaultsPopulator/I_MotorFaultsPopulator.h"

class MockMotorFaultsPopulator: public I_MotorFaultsPopulator
{
    Q_OBJECT
public:
    MOCK_METHOD1(populateData, void(const QJsonObject&));
};
