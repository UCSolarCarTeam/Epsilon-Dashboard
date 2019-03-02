#pragma once
#include <QObject>
#include "gmock/gmock.h"
#include "../BusinessLayer/DataPopulators/AuxBmsPopulator/I_AuxBmsPopulator.h"
class MockAuxBmsPopulator: public I_AuxBmsPopulator
{
    Q_OBJECT
    public slots:
        MOCK_METHOD1(populateData, void(const QJsonObject&));
};
