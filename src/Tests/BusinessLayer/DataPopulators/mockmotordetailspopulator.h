#pragma once
#include "gmock/gmock.h"
#include <QJsonObject>
#include "../../../BusinessLayer/DataPopulators/MotorDetailsPopulator/I_MotorDetailsPopulator.h"

class MockMotorDetailsPopulator: public I_MotorDetailsPopulator
{
    Q_OBJECT
    public:
        MOCK_METHOD1(populateData, void(const QJsonObject&));
};
