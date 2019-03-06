#pragma once
#include "gmock/gmock.h"
#include <QJsonObject>
#include "../../../BusinessLayer/DataPopulators/LightsPopulator/I_LightsPopulator.h"

class MockLightsPopulator: public I_LightsPopulator
{
    Q_OBJECT
    public:
        MOCK_METHOD1(populateData, void(const QJsonObject&));
};
