#pragma once
#include "gmock/gmock.h"
#include <QJsonObject>
#include "../../../BusinessLayer/DataPopulators/KeyMotorPopulator/I_KeyMotorPopulator.h"

class MockKeyMotorPopulator: public I_KeyMotorPopulator
{
    Q_OBJECT
    public:
        MOCK_METHOD1(populateData, void(const QJsonObject&));
};
