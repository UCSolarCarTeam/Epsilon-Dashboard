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

    auxBmsData_.setPrechargeState(value.toObject().value(JsonFormat::AUXBMS_PRECHARGE_STATE).toString());
    auxBmsData_.setAuxVoltage(value.toObject().value(JsonFormat::AUXBMS_VOLTAGE).toInt());
    auxBmsData_.setAuxBmsAlive(value.toObject().value(JsonFormat::AUXBMS_ALIVE).toBool());
    auxBmsData_.setStrobeBmsLight(value.toObject().value(JsonFormat::AUXBMS_STROBE_LIGHT).toBool());
    auxBmsData_.setAllowCharge(value.toObject().value(JsonFormat::AUXBMS_ALLOW_CHARGE).toBool());
    auxBmsData_.setHighVoltageEnableState(value.toObject().value(JsonFormat::AUXBMS_HIGH_VOLTAGE_ENABLE_STATE).toBool());
    auxBmsData_.setAllowDischarge(value.toObject().value(JsonFormat::AUXBMS_ALLOW_DISCHARGE).toBool());
    auxBmsData_.setOrionCanReceivedRecently(value.toObject().value(JsonFormat::AUXBMS_ORION_CAN_RECEIVED_RECENTLY).toBool());
    auxBmsData_.setChargeContactorError(value.toObject().value(JsonFormat::AUXBMS_CHARGE_CONTACTOR_ERROR).toBool());
    auxBmsData_.setDischargeContactorError(value.toObject().value(JsonFormat::AUXBMS_DISCHARGE_CONTACTOR_ERROR).toBool());
    auxBmsData_.setCommonContactorError(value.toObject().value(JsonFormat::AUXBMS_COMMON_CONTACTOR_ERROR).toBool());
    auxBmsData_.setDischargeShouldTrip(value.toObject().value(JsonFormat::AUXBMS_DISCHARGE_SHOULD_TRIP).toBool());
    auxBmsData_.setChargeShouldTrip(value.toObject().value(JsonFormat::AUXBMS_CHARGE_SHOULD_TRIP).toBool());
    auxBmsData_.setChargeOpenButShouldBeClosed(value.toObject().value(JsonFormat::AUXBMS_CHARGE_OPEN_BUT_SHOULD_BE_CLOSED).toBool());
    auxBmsData_.setDischargeOpenButShouldBeClosed(value.toObject().value(JsonFormat::AUXBMS_DISCHARGE_OPEN_BUT_SHOULD_BE_CLOSED).toBool());
    auxBmsData_.setChargeTripHighVoltage(value.toObject().value(JsonFormat::AUXBMS_CHARGE_TRIP_HIGH_VOLTAGE).toBool());
    auxBmsData_.setChargeTripHighTemperatureCurrent(value.toObject().value(JsonFormat::AUXBMS_CHARGE_TRIP_HIGH_TEMPERATURE_CURRENT).toBool());
    auxBmsData_.setChargeTripPackCurrent(value.toObject().value(JsonFormat::AUXBMS_CHARGE_TRIP_PACK_CURRENT).toBool());
    auxBmsData_.setDischargeTripLowVoltage(value.toObject().value(JsonFormat::AUXBMS_DISCHARGE_TRIP_LOW_VOLTAGE).toBool());
    auxBmsData_.setDischargeTripHighTemperatureCurrent(value.toObject().value(JsonFormat::AUXBMS_DISCHARGE_TRIP_HIGH_TEMPERATURE_CURRENT).toBool());
    auxBmsData_.setDischargeTripPackCurrent(value.toObject().value(JsonFormat::AUXBMS_DISCHARGE_TRIP_PACK_CURRENT).toBool());
    auxBmsData_.setProtectionTrip(value.toObject().value(JsonFormat::AUXBMS_PROTECTION_TRIP).toBool());
    auxBmsData_.setTripContactorDisconnectedUnexpectedly(value.toObject().value(JsonFormat::AUXBMS_TRIP_CONTACTOR_DISCONNECTED_UNEXPECTEDLY).toBool());
    auxBmsData_.setTripOrionMessageTimeout(value.toObject().value(JsonFormat::AUXBMS_TRIP_ORION_MESSAGE_TIMEOUT).toBool());
    auxBmsData_.setChargeNotClosedHighCurrent(value.toObject().value(JsonFormat::AUXBMS_TRIP_CHARGE_NOT_CLOSED_HIGH_CURRENT).toBool());
    auxBmsData_.setDischargeNotClosedHighCurrent(value.toObject().value(JsonFormat::AUXBMS_TRIP_DISCHARGE_NOT_CLOSED_HIGH_CURRENT).toBool());
}
