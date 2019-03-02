#pragma once
#include "gmock/gmock.h"
#include "../../../BusinessLayer/DataPopulators/DriverControlsPopulator/I_DriverControlsPopulator.h"

class MockDriverControlsPopulator: public I_DriverControlsPopulator
{
    Q_OBJECT
    public slots:
        MOCK_METHOD1(populateData, void(const QJsonObject&));
};
