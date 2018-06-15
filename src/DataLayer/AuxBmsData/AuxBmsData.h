#pragma once

#include "I_AuxBmsData.h"

class AuxBmsData : public I_AuxBmsData
{
public:
    AuxBmsData();
    virtual ~AuxBmsData();

    /* Data getter */
    QString prechargeState() const;
    int auxVoltage() const;
    bool auxBmsAlive() const;
    bool strobeBmsLight() const;
    bool allowCharge() const;
    bool contactorError() const;
    bool highVoltageEnable() const;

    /* Data setter */
    void setPrechargeState(const QString& prechargeState);
    void setAuxVoltage(const int& auxVoltage);
    void setAuxBmsAlive(const bool& auxBmsAlive);
    void setStrobeBmsLight(const bool& strobeBmsLight);
    void setAllowCharge(const bool& allowCharge);
    void setContactorError(const bool& contactorError);
    void setHighVoltageEnable(const bool& highVoltageEnable);

private:
    QString prechargeState_;
    int auxVoltage_;
    bool auxBmsAlive_;
    bool strobeBmsLight_;
    bool allowCharge_;
    bool contactorError_;
    bool highVoltageEnable_;
};
