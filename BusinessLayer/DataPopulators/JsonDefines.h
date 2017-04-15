/**
 *  Schulich Delta Android Telemetry
 *  Copyright (C) 2015 University of Calgary Solar Car Team
 *
 *  This file is part of Schulich Delta Android Telemetry
 *
 *  Schulich Delta Android Telemetry is free software:
 *  you can redistribute it and/or modify it under the terms
 *  of the GNU Affero General Public License as published by
 *  the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  Schulich Delta Android Telemetry is distributed
 *  in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or
 *  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero
 *  General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General
 *  Public License along with Schulich Delta Android Telemetry.
 *  If not, see <http://www.gnu.org/licenses/>.
 *
 *  For further contact, email <software@calgarysolarcar.ca>
 */

#include <QString>
//TODO finish by adding voltages with all the numbers in them... ask managers how they want it formatted
namespace JsonFormat
{
    // meta info
    const int DECIMAL_PRECISION = 2;
    const QString DATA_TYPE = "datatype";

    const QString PACKETTITLE = "PacketTitle";
    const QString TIMESTAMP = "TimeStamp";

    // Key motor data
    const QString KEYMOTOR = "KeyMotor";
    const QString KEYMOTOR_ALIVE = "Alive";
    const QString KEYMOTOR_SETCURRENT = "SetCurrent";
    const QString KEYMOTOR_SETVELOCITY = "SetVelocity";
    const QString KEYMOTOR_BUSCURRENT = "BusCurrent";
    const QString KEYMOTOR_BUSVOLTAGE = "BusVoltage";
    const QString KEYMOTOR_VEHICLEVELOCITY = "VehicleVelocity";

    // Motor details data
    const QString MOTORDETAILS = "MotorDetails";
    const QString MOTORDETAILS_PHASECCURRENT = "PhaseCCurrent";
    const QString MOTORDETAILS_PHASEBCURRENT = "PhaseBCurrent";
    const QString MOTORDETAILS_MOTORVOLTAGEREAL = "MotorVoltageReal";
    const QString MOTORDETAILS_MOTORVOLTAGEIMAGINARY = "MotorVoltageImaginary";
    const QString MOTORDETAILS_MOTORCURRENTREAL = "MotorCurrentReal";
    const QString MOTORDETAILS_MOTORCURRENTIMAGINARY = "MotorCurrentImaginary";
    const QString MOTORDETAILS_BACKEMFREAL = "BackEmfReal";
    const QString MOTORDETAILS_VOLTAGERAIL15VSUPPLY = "VoltageRail15VSupply";
    const QString MOTORDETAILS_VOLTAGERAIL3VSUPPLY = "VoltageRail3VSupply";
    const QString MOTORDETAILS_VOLTAGERAIL1VSUPPLY = "VoltageRail1VSupply";
    const QString MOTORDETAILS_HEATSINKTEMP = "HeatSinkTemp";
    const QString MOTORDETAILS_MOTORTEMP = "MotorTemp";
    const QString MOTORDETAILS_DSPBOARDTEMP = "DspBoardTemp";
    const QString MOTORDETAILS_DCBUSAMPHOURS = "DcBusAmpHours";
    const QString MOTORDETAILS_ODOMETER = "Odometer";
    const QString MOTORDETAILS_SLIPSPEED = "SlipSpeed";

    // Driver controls data
    const QString DRIVERCONTROLS = "DriverControl";
    const QString DRIVERCONTROLS_ALIVE = "Alive";
    const QString DRIVERCONTROLS_HEADLIGHTSOFF = "HeadlightsOff";
    const QString DRIVERCONTROLS_HEADLIGHTSLOW = "HeadlightsLow";
    const QString DRIVERCONTROLS_HEADLIGHTSHIGH = "HeadlightsHigh";
    const QString DRIVERCONTROLS_SIGNALRIGHT = "SignalRight";
    const QString DRIVERCONTROLS_SIGNALLEFT = "SignalLeft";
    const QString DRIVERCONTROLS_HAZARD = "Hazard";
    const QString DRIVERCONTROLS_INTERIOR = "Interior";
    const QString DRIVERCONTROLS_AUX = "Aux";
    const QString DRIVERCONTROLS_VOLUMEUP = "VolumeUp";
    const QString DRIVERCONTROLS_VOLUMEDOWN = "VolumeDown";
    const QString DRIVERCONTROLS_NEXTSONG = "NextSong";
    const QString DRIVERCONTROLS_PREVSONG = "PrevSong";
    const QString DRIVERCONTROLS_ACCELERATION = "Acceleration";
    const QString DRIVERCONTROLS_REGENBRAKING = "RegenBraking";
    const QString DRIVERCONTROLS_BRAKES = "Brakes";
    const QString DRIVERCONTROLS_FORWARD = "Forward";
    const QString DRIVERCONTROLS_REVERSE = "Reverse";
    const QString DRIVERCONTROLS_PUSHTOTALK = "PushToTalk";
    const QString DRIVERCONTROLS_HORN = "Horn";
    const QString DRIVERCONTROLS_RESET = "Reset";

    // Motor faults data
    const QString MOTORFAULTS = "MotorFaults";
    const QString MOTORFAULTS_ERRORFLAGS = "ErrorFlags";
    const QString MOTORFAULTS_ERRORFLAGS_MOTOROVERSPEED = "MotorOverSpeed";
    const QString MOTORFAULTS_ERRORFLAGS_SOFTWAREOVERCURRENT = "SoftwareOverCurrent";
    const QString MOTORFAULTS_ERRORFLAGS_DCBUSOVERVOLTAGE = "DcBusOverVoltage";
    const QString MOTORFAULTS_ERRORFLAGS_BADMOTORPOSITIONHALLSEQUENCE = "BadMotorPositionHallSequence";
    const QString MOTORFAULTS_ERRORFLAGS_WATCHDOGCAUSEDLASTRESET = "WatchdogCausedLastReset";
    const QString MOTORFAULTS_ERRORFLAGS_CONFIGREADERROR = "ConfigReadError";
    const QString MOTORFAULTS_ERRORFLAGS_RAIL15VUNDERVOLTAGELOCKOUT = "Rail15VUnderVoltageLockOut";
    const QString MOTORFAULTS_ERRORFLAGS_DESATURATIONFAULT = "DesaturationFault";

    const QString MOTORFAULTS_LIMITFLAGS = "LimitFlags";
    const QString MOTORFAULTS_LIMITFLAGS_OUTPUTVOLTAGEPWM = "OutputVoltagePwm";
    const QString MOTORFAULTS_LIMITFLAGS_MOTORCURRENT = "MotorCurrent";
    const QString MOTORFAULTS_LIMITFLAGS_VELOCITY = "Velocity";
    const QString MOTORFAULTS_LIMITFLAGS_BUSCURRENT = "BusCurrent";
    const QString MOTORFAULTS_LIMITFLAGS_BUSVOLTAGEUPPER = "BusVoltageUpper";
    const QString MOTORFAULTS_LIMITFLAGS_BUSVOLTAGELOWER = "BusVoltageLower";
    const QString MOTORFAULTS_LIMITFLAGS_IPMORMOTORTEMPERATURE = "IpmOrMotorTemperature";
    const QString MOTORFAULTS_RXERRORCOUNT = "RxErrorCount";
    const QString MOTORFAULTS_TXERRORCOUNT = "TxErrorCount";

    // Battery faults data (TODO)
    const QString BATTERYFAULTS = "BatteryFaults";

    const QString BATTERYFAULTS_ERRORFLAGS = "ErrorFlags";
    const QString BATTERYFAULTS_ERRORFLAGS_INTERNALCOMMUNICATIONFAULT = "InternalCommununicationFault";
    const QString BATTERYFAULTS_ERRORFLAGS_INTERNALCONVERSIONFAULT = "InternalConversionFault";

    const QString BATTERYFAULTS_ERRORFLAGS_WEAKCELLFAULT = "WeakCellFault";
    const QString BATTERYFAULTS_ERRORFLAGS_LOWCELLVOLTAGEFAULT = "LowCellVoltageFault";
    const QString BATTERYFAULTS_ERRORFLAGS_OPENWIRINGFAULT = "OpenWiringFault";
    const QString BATTERYFAULTS_ERRORFLAGS_CURRENTSENSORFAULT = "CurrentSensorFault";
    const QString BATTERYFAULTS_ERRORFLAGS_PACKVOLTAGESENSORFAULT = "PackVoltageSensorFault";
    const QString BATTERYFAULTS_ERRORFLAGS_WEAKPACKFAULT = "WeakPackFault";
    const QString BATTERYFAULTS_ERRORFLAGS_VOLTAGEREDUNDANCYFAULT = "VoltageRedundancyFault";
    const QString BATTERYFAULTS_ERRORFLAGS_FANMONITORFAULT = "FanMonitorFault";
    const QString BATTERYFAULTS_ERRORFLAGS_THERMISTORFAULT = "ThermistorFault";
    const QString BATTERYFAULTS_ERRORFLAGS_INTERNALCONVERSIONFAULT = "CANBUSCommunicationsFault";
    const QString BATTERYFAULTS_ERRORFLAGS_INTERNALCONVERSIONFAULT = "AlwaysOnSupplyFault";
    const QString BATTERYFAULTS_ERRORFLAGS_INTERNALCONVERSIONFAULT = "HighVoltageIsolationFault";
    const QString BATTERYFAULTS_ERRORFLAGS_INTERNALCONVERSIONFAULT = "PowerSupplyFault12V";
    const QString BATTERYFAULTS_ERRORFLAGS_INTERNALCONVERSIONFAULT = "ChargeLimitEnforcementFault";
    const QString BATTERYFAULTS_ERRORFLAGS_INTERNALCONVERSIONFAULT = "DischargeLimitEnforcementFault";
    const QString BATTERYFAULTS_ERRORFLAGS_INTERNALCONVERSIONFAULT = "ChargerSafetyRelayFault";
    const QString BATTERYFAULTS_ERRORFLAGS_INTERNALCONVERSIONFAULT = "InternalMemoryFault";
    const QString BATTERYFAULTS_ERRORFLAGS_INTERNALCONVERSIONFAULT = "InternalThermistorFault";
    const QString BATTERYFAULTS_ERRORFLAGS_INTERNALCONVERSIONFAULT = "InternalLogicFault";

    const QString BATTERYFAULTS_CELLOVERVOLTAGE = "CellOverVoltage";
    const QString BATTERYFAULTS_CELLUNDERVOLTAGE = "CellUnderVoltage";
    const QString BATTERYFAULTS_CELLOVERTEMP = "CellOverTemp";
    const QString BATTERYFAULTS_MEASUREMENTUNTRUSTED = "MeasurementUntrusted";
    const QString BATTERYFAULTS_CMUCOMMTIMEOUT = "CMUCommTimeout";
    const QString BATTERYFAULTS_BMUSETUPMODE = "BMUSetupMode";
    const QString BATTERYFAULTS_CMUCANBUSPOWERSTATUS = "CMUCANBusPowerStatus";
    const QString BATTERYFAULTS_PACKISOLATIONFAILURE = "PackIsolationFailure";
    const QString BATTERYFAULTS_SOFTWAREOVERCURRENT = "SoftwareOverCurrent";
    const QString BATTERYFAULTS_CAN12VSUPPLYLOW = "CAN12VSupplyLow";
    const QString BATTERYFAULTS_CONTACTORSTUCK = "ContactorStuck";
    const QString BATTERYFAULTS_CMUDETECTEDEXTRACELL = "CMUDetectedExtraCell";

    // Battery data
    const QString BATTERY = "Battery";
    const QString BATTERY_ALIVE = "Alive";

    const QString BATTERY_BMSRELAYSTATUSFLAGS = "BMSRelayStatusFlags";
    const QString BATTERY_BMSRELAYSTATUSFLAGS_DISCHARGERELAYENABLED = "DischargeRelayEnabled";
    const QString BATTERY_BMSRELAYSTATUSFLAGS_CHARGERELAYENABLED = "ChargeRelayEnabled";
    const QString BATTERY_BMSRELAYSTATUSFLAGS_CHARGERSAFETYENABLED = "ChargerSafetyEnabled";
    const QString BATTERY_BMSRELAYSTATUSFLAGS_MALFUNCTIONINDICATORACTIVE = "MalfunctionIndicatorActive";
    const QString BATTERY_BMSRELAYSTATUSFLAGS_MULTIPURPOSEINPUTSIGNALSTATUS = "MultiPurposeInputSignalStatus";
    const QString BATTERY_BMSRELAYSTATUSFLAGS_ALWAYSONSIGNALSTATUS = "AlwaysOnSignalStatus";
    const QString BATTERY_BMSRELAYSTATUSFLAGS_ISREADYSIGNALSTATUS = "IsReadySignalStatus";
    const QString BATTERY_BMSRELAYSTATUSFLAGS_ISCHARGINGSIGNALSTATUS = "IsChargingSignalStatus";

    const QString BATTERY_POPULATEDCELLS = "PopulatedCells";
    const QString BATTERY_12VINPUTVOLTAGE = "12vInputVoltage";
    const QString BATTERY_FANVOLTAGE = "FanVoltage";

    const QString BATTERY_PACKCURRENT = "PackCurrent";
    const QString BATTERY_PACKVOLTAGE = "PackVoltage";
    const QString BATTERY_PACKSTATEOFCHARGE = "PackStateofCharge";
    const QString BATTERY_PACKAMPHOURS = "PackAmphours";
    const QString BATTERY_PACKDEPTHOFDISCHARGE = "PackDepthofDischarge";

    const QString BATTERY_HIGHTEMPERATURE = "HighTemperature";
    const QString BATTERY_HIGHTHERMISTORID = "HighThermistorId";
    const QString BATTERY_LOWTEMPERATURE = "LowTemperature";
    const QString BATTERY_LOWTHERMISTORID = "LowThermistorId";
    const QString BATTERY_AVERAGETEMPERATURE = "AverageTemperature";
    const QString BATTERY_INTERNALTEMPERATURE = "InternalTemperature";
    const QString BATTERY_FANSPEED = "FanSpeed";
    const QString BATTERY_REQUESTEDFANSPEED = "RequestedFanSpeed";

    const QString BATTERY_LOWCELLVOLTAGE = "LowCellVoltage";
    const QString BATTERY_LOWCELLVOLTAGEID = "LowCellVoltageId";
    const QString BATTERY_HIGHCELLVOLTAGE = "HighCellVoltage";
    const QString BATTERY_HIGHCELLVOLTAGEID = "HighCellVoltageId";
    const QString BATTERY_AVERAGECELLVOLTAGE = "AverageCellVoltage";

    const QString BATTERY_PRECHARGESTATE = "PrechargeState";
    const QString BATTERY_AUXVOLTAGE = "AuxVoltage";
    const QString BATTERY_AUXBMSALIVE = "AuxBmsAlive";

    // MPPT data
    const QString MPPT = "MPPT";
    const QString MPPT_ALIVE = "Alive";
    const QString MPPT_ARRAYVOLTAGE = "ArrayVoltage";
    const QString MPPT_ARRAYCURRENT = "ArrayCurrent";
    const QString MPPT_BATTERYVOLTAGE = "BatteryVoltage";
    const QString MPPT_TEMPERATURE = "Temperature";

    // Lights data
    const QString LIGHTS = "Lights";
    const QString LIGHTS_ALIVE = "Alive";
    const QString LIGHTS_LOWBEAMS = "LowBeams";
    const QString LIGHTS_HIGHBEAMS = "HighBeams";
    const QString LIGHTS_BRAKES = "Brakes";
    const QString LIGHTS_LEFTSIGNAL = "LeftSignal";
    const QString LIGHTS_RIGHTSIGNAL = "RightSignal";
    const QString LIGHTS_BMSSTROBELIGHT = "BmsStrobeLight";
}
