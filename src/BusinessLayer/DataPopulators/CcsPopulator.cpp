#include <QJsonObject>
#include <QJsonArray>

#include "CcsPopulator.h"

#include "../BusinessLayer/DataPopulators/JsonDefines.h"

CcsPopulator::CcsPopulator(I_CcsData& ccsData)
    : ccsData_(ccsData)
{
}

void CcsPopulator::populateData(const QJsonObject& data)
{
    QJsonValue value = data.value(JsonFormat::CCS);
    ccsData_.setCcsAlive(value.toObject().value(JsonFormat::CCS_ALIVE).toBool());
}
