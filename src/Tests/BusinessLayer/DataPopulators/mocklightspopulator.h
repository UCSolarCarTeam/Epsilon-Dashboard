#pragma once
#include "gmock/gmock.h"
#include "../../../BusinessLayer/DataPopulators/LightsPopulator/I_LightsPopulator.h"

class MockLightsPopulator: public I_LightsPopulator
{
    Q_OBJECT
    public slots:
        MOCK_METHOD1(populateData, void(const QJsonObject&));
};
