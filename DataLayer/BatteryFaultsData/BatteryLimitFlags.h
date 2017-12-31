#pragma once

class BatteryLimitFlags
{
public:
    BatteryLimitFlags();

    /* getter */
    bool dclReducedDueToLowSoc() const;
    bool dclReducedDueToHighCellResistance() const;
    bool dclReducedDueToTemperature() const;
    bool dclReducedDueToLowCellVoltage() const;
    bool dclReducedDueToLowPackVoltage() const;
    bool dclandCclReducedDueToVoltageFailsafe() const;
    bool dclandCclReducedDueToCommunicationFailsafe() const;
    bool cclReducedDueToHighSoc() const;
    bool cclReducedDueToHighCellResistance() const;
    bool cclReducedDueToTemperature() const;
    bool cclReducedDueToHighCellVoltage() const;
    bool cclReducedDueToHighPackVoltage() const;
    bool cclReducedDueToChargerLatch() const;
    bool cclReducedDueToAlternateCurrentLimit() const;

    /* setter */
    void setDclReducedDueToLowSoc(bool dclReducedDueToLowSoc);
    void setDclReducedDueToHighCellResistance(bool dclReducedDueToHighCellResistance);
    void setDclReducedDueToTemperature(bool dclReducedDueToTemperature);
    void setDclReducedDueToLowCellVoltage(bool dclReducedDueToLowCellVoltage);
    void setDclReducedDueToLowPackVoltage(bool dclReducedDueToLowPackVoltage);
    void setDclandCclReducedDueToVoltageFailsafe(bool dclandCclReducedDueToVoltageFailsafe);
    void setDclandCclReducedDueToCommunicationFailsafe(bool dclandCclReducedDueToCommunicationFailsafe);
    void setCclReducedDueToHighSoc(bool cclReducedDueToHighSoc);
    void setCclReducedDueToHighCellResistance(bool cclReducedDueToHighCellResistance);
    void setCclReducedDueToTemperature(bool cclReducedDueToTemperature);
    void setCclReducedDueToHighCellVoltage(bool cclReducedDueToHighCellVoltage);
    void setCclReducedDueToHighPackVoltage(bool cclReducedDueToHighPackVoltage);
    void setCclReducedDueToChargerLatch(bool cclReducedDueToChargerLatch);
    void setCclReducedDueToAlternateCurrentLimit(bool cclReducedDueToAlternateCurrentLimit);

private:
    bool dclReducedDueToLowSoc_;
    bool dclReducedDueToHighCellResistance_;
    bool dclReducedDueToTemperature_;
    bool dclReducedDueToLowCellVoltage_;
    bool dclReducedDueToLowPackVoltage_;
    bool dclandCclReducedDueToVoltageFailsafe_;
    bool dclandCclReducedDueToCommunicationFailsafe_;
    bool cclReducedDueToHighSoc_;
    bool cclReducedDueToHighCellResistance_;
    bool cclReducedDueToTemperature_;
    bool cclReducedDueToHighCellVoltage_;
    bool cclReducedDueToHighPackVoltage_;
    bool cclReducedDueToChargerLatch_;
    bool cclReducedDueToAlternateCurrentLimit_;
};
