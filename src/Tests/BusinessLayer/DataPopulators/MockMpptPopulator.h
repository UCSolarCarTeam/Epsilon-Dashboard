#pragma once
#include "gmock/gmock.h"
#include "../../../BusinessLayer/DataPopulators/MpptPopulator/I_MpptPopulator.h"

class MockMpptPopulator: public I_MpptPopulator
{
    Q_OBJECT
public:
    MOCK_METHOD1(populateData, void(const QJsonObject&));
};
