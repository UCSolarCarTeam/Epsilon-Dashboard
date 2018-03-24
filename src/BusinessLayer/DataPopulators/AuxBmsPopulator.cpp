#include <QJsonObject>
#include <QJsonArray>

#include "AuxBmsPopulator.h"

#include "../BusinessLayer/DataPopulators/JsonDefines.h"
#include "../DataLayer/AuxBmsData/I_AuxBmsData.h"

AuxBmsPopulator::AuxBmsPopulator(I_AuxBmsData& auxBmsData)
    : auxBmsData_(auxBmsData)
{
}

void AuxBmsPopulator::populateData(const QJsonObject& data)
{
    QJsonValue value = data.value(JsonFormat::AUXBMS);

    auxBmsData_.setPrechargeState(value.toObject().value(JsonFormat::AUXBMS_PRECHARGESTATE).toString());
    auxBmsData_.setAuxVoltage(value.toObject().value(JsonFormat::AUXBMS_AUXVOLTAGE).toInt());
    auxBmsData_.setAuxBmsAlive(value.toObject().value(JsonFormat::AUXBMS_AUXBMSALIVE).toBool());
    auxBmsData_.setStrobeBmsLight(value.toObject().value(JsonFormat::AUXBMS_STROBEBMSLIGHT).toBool());
    auxBmsData_.setAllowCharge(value.toObject().value(JsonFormat::AUXBMS_ALLOWCHARGE).toBool());
    auxBmsData_.setContactorError(value.toObject().value(JsonFormat::AUXBMS_CONTACTORERROR).toBool());
}
