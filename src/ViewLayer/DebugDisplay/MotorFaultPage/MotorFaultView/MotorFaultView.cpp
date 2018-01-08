#include "MotorFaultView.h"

namespace
{
    int HEIGHT = 25;
    int WIDTH = 665;
    QString ERROR_STYLESHEET = "font: 20px 'Arial';\nfont-weight:500;color:#89c2d3; margin-left: 10px;";
    QString LIMIT_STYLESHEET = "font: 20px 'Arial';\nfont-weight:500;color:#a18cce; margin-left: 10px;";
    QString SCROLLBAR_STYLESHEET = "QScrollBar:vertical {"
                                   "    background:rgba(83, 83, 84);"
                                   "    width:10px;    "
                                   "    margin: 0px 0px 0px 0px;"
                                   "}"
                                   "QScrollBar::handle:vertical {"
                                   "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                                   "    stop: 0 rgb(255, 192, 33), stop: 0.5 rgb(255, 192, 33), stop:1 rgb(255, 192, 33));"
                                   "    min-height: 0px;"
                                   "    border-radius: 5px;"
                                   "}"
                                   "QScrollBar::add-line:vertical {"
                                   "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                                   "    stop: 0 rgb(255, 192, 33), stop: 0.5 rgb(255, 192, 33),  stop:1 rgb(255, 192, 33));"
                                   "    height: 0px;"
                                   "    subcontrol-position: bottom;"
                                   "    subcontrol-origin: margin;"
                                   "}"
                                   "QScrollBar::sub-line:vertical {"
                                   "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                                   "    stop: 0  rgb(255, 192, 33), stop: 0.5 rgb(255, 192, 33),  stop:1 rgb(255, 192, 33));"
                                   "    height: 0 px;"
                                   "    subcontrol-position: top;"
                                   "    subcontrol-origin: margin;"
                                   "}";
    int LABEL_RESIZE_LIMIT = 5;
}
MotorFaultView::MotorFaultView(MotorFaultsPresenter& motorFaultsPresenter,
                               BatteryFaultsPresenter& batteryFaultsPresenter,
                               I_MotorFaultUi& ui)
    : motorFaultsPresenter_(motorFaultsPresenter)
    , batteryFaultsPresenter_(batteryFaultsPresenter)
    , ui_(ui)
    , badMotorPositionHallSequence0Fault_("Bad Motor Position Hall Sequence Error")
    , configReadError0Fault_("Config Read Error")
    , dcBusOverVoltage0Fault_("DC Bus Over Voltage Error")
    , desaturationFault0Fault_("Desaturation Fault Error")
    , motorOverSpeed0Fault_("Motor Over Speed Error")
    , railUnderVoltageLockOut0Fault_("Rail Under Voltage Lockout Error")
    , watchdogCausedLastReset0Fault_("Watchdog Caused Last Reset Error")
    , softwareOverCurrent0Fault_("Software Over Current Error")
    , busCurrentLimit0Fault_("Bus Current Limit")
    , busVoltageUpperLimit0Fault_("Bus Voltage Upper Limit")
    , busVoltageLowerLimit0Fault_ ("Bus Voltage Lower Limit")
    , ipmOrMotorTelemetryLimit0Fault_ ("IPM or Motor Telemetry Limit")
    , motorCurrentLimit0Fault_ ("Motor Current Limit")
    , outputVoltagePwmLimit0Fault_ ("Output Voltage PWM Limit")
    , velocityLimit0Fault_ ("Velocity Limit")
    , label0Count_(0)
    , badMotorPositionHallSequence1Fault_("Bad Motor Position Hall Sequence Error")
    , configReadError1Fault_("Config Read Error")
    , dcBusOverVoltage1Fault_("DC Bus Over Voltage Error")
    , desaturationFault1Fault_("Desaturation Fault Error")
    , motorOverSpeed1Fault_("Motor Over Speed Error")
    , railUnderVoltageLockOut1Fault_("Rail Under Voltage Lockout Error")
    , watchdogCausedLastReset1Fault_("Watchdog Caused Last Reset Error")
    , softwareOverCurrent1Fault_("Software Over Current Error")
    , busCurrentLimit1Fault_("Bus Current Limit")
    , busVoltageUpperLimit1Fault_("Bus Voltage Upper Limit")
    , busVoltageLowerLimit1Fault_ ("Bus Voltage Lower Limit")
    , ipmOrMotorTelemetryLimit1Fault_ ("IPM or Motor Telemetry Limit")
    , motorCurrentLimit1Fault_ ("Motor Current Limit")
    , outputVoltagePwmLimit1Fault_ ("Output Voltage PWM Limit")
    , velocityLimit1Fault_ ("Velocity Limit")
    , label1Count_(0)
    , alwaysOnSupplyFault_ ("Always On Supply Fault")
    , canbusCommunicationsFault_ ("CAN Bus Communications Fault")
    , chargeLimitEnforcementFault_ ("Charge Limit Enforcement Fault")
    , chargerSafetyRelayFault_ ("Charger Safety Relay Fault")
    , currentSensorFault_ ("Current Sensor Fault")
    , dischargeLimitEnforcementFault_ ("Discharge Limit Enforcement Fault")
    , fanMonitorFault_ ("Fan Monitor Fault")
    , highVoltageIsolationFault_ ("High Voltage Isolation Fault")
    , internalCommununicationFault_ ("Internal Communication Fault")
    , internalConversionFault_ ("Internal Conversion Fault")
    , internalLogicFault_ ("Internal Logic Fault")
    , internalMemoryFault_ ("Internal Memory Fault")
    , internalThermistorFault_ ("Internal Thermistor Fault")
    , lowCellVoltageFault_ ("Low Cell Voltage Fault")
    , openWiringFault_ ("Open Wiring Fault")
    , packVoltageSensorFault_ ("Pack Voltage Sensor Fault")
    , powerSupplyFault12V_ ("12V Power Supply Fault")
    , thermistorFault_ ("Thermistor Fault")
    , voltageRedundancyFault_ ("Voltage Redundancy Fault")
    , weakCellFault_ ("Weak Cell Fault")
    , weakPackFault_ ("Weak Pack Fault")
    , cclReducedDueToAlternateCurrentLimit_ ("CCL Reduced Due To Alternate Current")
    , cclReducedDueToChargerLatch_ ("CCL Reduced Due To Charger Latch")
    , cclReducedDueToHighCellResistance_ ("CCL Reduced Due To High Cell Resistance")
    , cclReducedDueToHighCellVoltage_ ("CCL Reduced Due To High Cell Voltage")
    , cclReducedDueToHighPackVoltage_ ("CCL Reduced Due To High Pack Voltage")
    , cclReducedDueToHighSoc_ ("CCL Reduced Due To High SOC")
    , cclReducedDueToTemperature_ ("CCL Reduced Due To Temperature")
    , dclandCclReducedDueToCommunicationFailsafe_ ("DCL and CCL Reduced Due To Communication Fail Safe")
    , dclandCclReducedDueToVoltageFailsafe_ ("DCL and CCL Reduced Due To Voltage Fail Safe")
    , dclReducedDueToHighCellResistance_ ("DCL Reduced Due To High Cell Resistance")
    , dclReducedDueToLowCellVoltage_ ("DCL Reduced Due To Low Cell Voltage")
    , dclReducedDueToLowPackVoltage_ ("DCL Reduced Due To Low Pack Voltage")
    , dclReducedDueToLowSoc_ ("DCL Reduced Due To Low SOC")
    , dclReducedDueToTemperature_ ("DCL Reduced Due To Temperature")
    , labelBCount_ (0)
{

    // Setting up Vertical bar
    QScrollBar* verticalBar0 = new QScrollBar();
    QScrollBar* verticalBar1 = new QScrollBar();
    QScrollBar* verticalBarB = new QScrollBar();

    verticalBar0->setStyleSheet(SCROLLBAR_STYLESHEET);
    verticalBar1->setStyleSheet(SCROLLBAR_STYLESHEET);
    verticalBarB->setStyleSheet(SCROLLBAR_STYLESHEET);

    ui_.motor0ScrollArea().setVerticalScrollBar(verticalBar0);
    ui_.motor1ScrollArea().setVerticalScrollBar(verticalBar1);
    ui_.batteryScrollArea().setVerticalScrollBar(verticalBarB);

    QLayout* layout0 = ui_.motor0ContentsWidget().layout();
    QLayout* layout1 = ui_.motor1ContentsWidget().layout();
    QLayout* layoutB = ui_.batteryContentsWidget().layout();

    // Motor 0
    initializeLabel(badMotorPositionHallSequence0Fault_, layout0, ERROR_STYLESHEET);
    initializeLabel(configReadError0Fault_, layout0, ERROR_STYLESHEET);
    initializeLabel(dcBusOverVoltage0Fault_, layout0, ERROR_STYLESHEET);
    initializeLabel(desaturationFault0Fault_, layout0, ERROR_STYLESHEET);
    initializeLabel(motorOverSpeed0Fault_, layout0, ERROR_STYLESHEET);
    initializeLabel(railUnderVoltageLockOut0Fault_, layout0, ERROR_STYLESHEET);
    initializeLabel(watchdogCausedLastReset0Fault_, layout0, ERROR_STYLESHEET);
    initializeLabel(softwareOverCurrent0Fault_, layout0, ERROR_STYLESHEET);

    initializeLabel(busCurrentLimit0Fault_, layout0, LIMIT_STYLESHEET);
    initializeLabel(busVoltageLowerLimit0Fault_, layout0, LIMIT_STYLESHEET);
    initializeLabel(busVoltageUpperLimit0Fault_, layout0, LIMIT_STYLESHEET);
    initializeLabel(ipmOrMotorTelemetryLimit0Fault_, layout0, LIMIT_STYLESHEET);
    initializeLabel(motorCurrentLimit0Fault_, layout0, LIMIT_STYLESHEET);
    initializeLabel(outputVoltagePwmLimit0Fault_, layout0, LIMIT_STYLESHEET);
    initializeLabel(velocityLimit0Fault_, layout0, LIMIT_STYLESHEET);

    // Motor 1
    initializeLabel(badMotorPositionHallSequence1Fault_, layout1, ERROR_STYLESHEET);
    initializeLabel(configReadError1Fault_, layout1, ERROR_STYLESHEET);
    initializeLabel(dcBusOverVoltage1Fault_, layout1, ERROR_STYLESHEET);
    initializeLabel(desaturationFault1Fault_, layout1, ERROR_STYLESHEET);
    initializeLabel(motorOverSpeed1Fault_, layout1, ERROR_STYLESHEET);
    initializeLabel(railUnderVoltageLockOut1Fault_, layout1, ERROR_STYLESHEET);
    initializeLabel(watchdogCausedLastReset1Fault_, layout1, ERROR_STYLESHEET);
    initializeLabel(softwareOverCurrent1Fault_, layout1, ERROR_STYLESHEET);

    initializeLabel(busCurrentLimit1Fault_, layout1, LIMIT_STYLESHEET);
    initializeLabel(busVoltageLowerLimit1Fault_, layout1, LIMIT_STYLESHEET);
    initializeLabel(busVoltageUpperLimit1Fault_, layout1, LIMIT_STYLESHEET);
    initializeLabel(ipmOrMotorTelemetryLimit1Fault_, layout1, LIMIT_STYLESHEET);
    initializeLabel(motorCurrentLimit1Fault_, layout1, LIMIT_STYLESHEET);
    initializeLabel(outputVoltagePwmLimit1Fault_, layout1, LIMIT_STYLESHEET);
    initializeLabel(velocityLimit1Fault_, layout1, LIMIT_STYLESHEET);

    // Battery
    initializeLabel(alwaysOnSupplyFault_, layoutB, ERROR_STYLESHEET);
    initializeLabel(canbusCommunicationsFault_, layoutB, ERROR_STYLESHEET);
    initializeLabel(chargeLimitEnforcementFault_, layoutB, ERROR_STYLESHEET);
    initializeLabel(chargerSafetyRelayFault_, layoutB, ERROR_STYLESHEET);
    initializeLabel(currentSensorFault_, layoutB, ERROR_STYLESHEET);
    initializeLabel(dischargeLimitEnforcementFault_, layoutB, ERROR_STYLESHEET);
    initializeLabel(fanMonitorFault_, layoutB, ERROR_STYLESHEET);
    initializeLabel(highVoltageIsolationFault_, layoutB, ERROR_STYLESHEET);
    initializeLabel(internalCommununicationFault_, layoutB, ERROR_STYLESHEET);
    initializeLabel(internalConversionFault_, layoutB, ERROR_STYLESHEET);
    initializeLabel(internalLogicFault_, layoutB, ERROR_STYLESHEET);
    initializeLabel(internalMemoryFault_, layoutB, ERROR_STYLESHEET);
    initializeLabel(internalThermistorFault_, layoutB, ERROR_STYLESHEET);
    initializeLabel(lowCellVoltageFault_, layoutB, ERROR_STYLESHEET);
    initializeLabel(openWiringFault_, layoutB, ERROR_STYLESHEET);
    initializeLabel(packVoltageSensorFault_, layoutB, ERROR_STYLESHEET);
    initializeLabel(powerSupplyFault12V_, layoutB, ERROR_STYLESHEET);
    initializeLabel(thermistorFault_, layoutB, ERROR_STYLESHEET);
    initializeLabel(voltageRedundancyFault_, layoutB, ERROR_STYLESHEET);
    initializeLabel(weakCellFault_, layoutB, ERROR_STYLESHEET);
    initializeLabel(weakPackFault_, layoutB, ERROR_STYLESHEET);

    initializeLabel(cclReducedDueToAlternateCurrentLimit_, layoutB, LIMIT_STYLESHEET);
    initializeLabel(cclReducedDueToChargerLatch_, layoutB, LIMIT_STYLESHEET);
    initializeLabel(cclReducedDueToHighCellResistance_, layoutB, LIMIT_STYLESHEET);
    initializeLabel(cclReducedDueToHighCellVoltage_, layoutB, LIMIT_STYLESHEET);
    initializeLabel(cclReducedDueToHighPackVoltage_, layoutB, LIMIT_STYLESHEET);
    initializeLabel(cclReducedDueToHighSoc_, layoutB, LIMIT_STYLESHEET);
    initializeLabel(cclReducedDueToTemperature_, layoutB, LIMIT_STYLESHEET);
    initializeLabel(dclandCclReducedDueToCommunicationFailsafe_, layoutB, LIMIT_STYLESHEET);
    initializeLabel(dclandCclReducedDueToVoltageFailsafe_, layoutB, LIMIT_STYLESHEET);
    initializeLabel(dclReducedDueToHighCellResistance_, layoutB, LIMIT_STYLESHEET);
    initializeLabel(dclReducedDueToLowCellVoltage_, layoutB, LIMIT_STYLESHEET);
    initializeLabel(dclReducedDueToLowPackVoltage_, layoutB, LIMIT_STYLESHEET);
    initializeLabel(dclReducedDueToLowSoc_, layoutB, LIMIT_STYLESHEET);
    initializeLabel(dclReducedDueToTemperature_, layoutB, LIMIT_STYLESHEET);

    ui_.motor0ContentsWidget().setLayout(layout0);
    ui_.motor1ContentsWidget().setLayout(layout1);
    ui_.batteryContentsWidget().setLayout(layoutB);

    connectMotorFaults(motorFaultsPresenter_);
    connectBatteryFaults(batteryFaultsPresenter_);

    ErrorFlags teste;
    teste.setBadMotorPositionHallSequence(true);
    LimitFlags testl;
    testl.setBusCurrentLimit(true);

    motorZeroErrorFlagsReceived(teste);
    motorZeroLimitFlagsReceived(testl);

}

MotorFaultView::~MotorFaultView()
{
}

void MotorFaultView::initializeLabel(QLabel& label, QLayout*& layout, QString& styleSheet)
{
    label.resize(WIDTH, HEIGHT);
    label.setStyleSheet(styleSheet);
    label.setFixedSize(WIDTH, HEIGHT);
    layout->addWidget(&label);
    label.hide();
}

void MotorFaultView::updateLabel(const bool& receivedValue, QLabel& label, QWidget& contentsWidget, int& labelCount)
{
    if (receivedValue)
    {
        if (!label.isVisible())
        {
            labelCount++;

            if (labelCount >= LABEL_RESIZE_LIMIT)
            {
                contentsWidget.setFixedSize(contentsWidget.width(), contentsWidget.height() + HEIGHT);
            }

            label.show();
        }
    }
    else
    {
        if (label.isVisible())
        {

            if (labelCount >= LABEL_RESIZE_LIMIT)
            {
                contentsWidget.setFixedSize(contentsWidget.width(), contentsWidget.height() - HEIGHT);
            }

            labelCount--;
            label.hide();
        }
    }
}

void MotorFaultView::connectMotorFaults(MotorFaultsPresenter& motorFaultsPresenter)
{
    connect(&motorFaultsPresenter, SIGNAL(motorZeroErrorFlagsReceived(ErrorFlags)),
            this, SLOT(motorZeroErrorFlagsReceived(ErrorFlags)));
    connect(&motorFaultsPresenter, SIGNAL(motorZeroLimitFlagsReceived(LimitFlags)),
            this, SLOT(motorZeroLimitFlagsReceived(LimitFlags)));
    connect(&motorFaultsPresenter, SIGNAL(motorOneErrorFlagsReceived(ErrorFlags)),
            this, SLOT(motorOneErrorFlagsReceived(ErrorFlags)));
    connect(&motorFaultsPresenter, SIGNAL(motorOneLimitFlagsReceived(LimitFlags)),
            this, SLOT(motorOneLimitFlagsReceived(LimitFlags)));
}

void MotorFaultView::connectBatteryFaults(BatteryFaultsPresenter& batteryFaultsPresenter)
{
    connect(&batteryFaultsPresenter, SIGNAL(errorFlagsReceived(BatteryErrorFlags)),
            this, SLOT(errorFlagsReceived(BatteryErrorFlags)));
    connect(&batteryFaultsPresenter, SIGNAL(limitFlagsReceived(BatteryLimitFlags)),
            this, SLOT(limitFlagsReceived(BatteryLimitFlags)));
}

void MotorFaultView::motorZeroErrorFlagsReceived(ErrorFlags motorZeroErrorFlags)
{
    updateLabel(motorZeroErrorFlags.badMotorPositionHallSequence(), badMotorPositionHallSequence0Fault_, ui_.motor0ContentsWidget(), label0Count_);
    updateLabel(motorZeroErrorFlags.configReadError(), configReadError0Fault_, ui_.motor0ContentsWidget(), label0Count_);
    updateLabel(motorZeroErrorFlags.dcBusOverVoltage(), dcBusOverVoltage0Fault_, ui_.motor0ContentsWidget(), label0Count_);
    updateLabel(motorZeroErrorFlags.desaturationFault(), desaturationFault0Fault_, ui_.motor0ContentsWidget(), label0Count_);
    updateLabel(motorZeroErrorFlags.motorOverSpeed(), motorOverSpeed0Fault_, ui_.motor0ContentsWidget(), label0Count_);
    updateLabel(motorZeroErrorFlags.railUnderVoltageLockOut(), railUnderVoltageLockOut0Fault_, ui_.motor0ContentsWidget(), label0Count_);
    updateLabel(motorZeroErrorFlags.watchdogCausedLastReset(), watchdogCausedLastReset0Fault_, ui_.motor0ContentsWidget(), label0Count_);
    updateLabel(motorZeroErrorFlags.softwareOverCurrent(), softwareOverCurrent0Fault_, ui_.motor0ContentsWidget(), label0Count_);
}

void MotorFaultView::motorZeroLimitFlagsReceived(LimitFlags motorZeroLimitFlags)
{
    updateLabel(motorZeroLimitFlags.busCurrentLimit(), busCurrentLimit0Fault_, ui_.motor0ContentsWidget(), label0Count_);
    updateLabel(motorZeroLimitFlags.busVoltageUpperLimit(), busVoltageUpperLimit0Fault_, ui_.motor0ContentsWidget(), label0Count_);
    updateLabel(motorZeroLimitFlags.busVoltageLowerLimit(), busVoltageLowerLimit0Fault_, ui_.motor0ContentsWidget(), label0Count_);
    updateLabel(motorZeroLimitFlags.ipmOrMotorTelemetryLimit(), ipmOrMotorTelemetryLimit0Fault_, ui_.motor0ContentsWidget(), label0Count_);
    updateLabel(motorZeroLimitFlags.motorCurrentLimit(), motorCurrentLimit0Fault_, ui_.motor0ContentsWidget(), label0Count_);
    updateLabel(motorZeroLimitFlags.outputVoltagePwmLimit(), outputVoltagePwmLimit0Fault_, ui_.motor0ContentsWidget(), label0Count_);
    updateLabel(motorZeroLimitFlags.velocityLimit(), velocityLimit0Fault_, ui_.motor0ContentsWidget(), label0Count_);
}

void MotorFaultView::motorOneErrorFlagsReceived(ErrorFlags motorOneErrorFlags)
{
    updateLabel(motorOneErrorFlags.badMotorPositionHallSequence(), badMotorPositionHallSequence1Fault_, ui_.motor1ContentsWidget(), label1Count_);
    updateLabel(motorOneErrorFlags.configReadError(), configReadError1Fault_, ui_.motor1ContentsWidget(), label1Count_);
    updateLabel(motorOneErrorFlags.dcBusOverVoltage(), dcBusOverVoltage1Fault_, ui_.motor1ContentsWidget(), label1Count_);
    updateLabel(motorOneErrorFlags.desaturationFault(), desaturationFault1Fault_, ui_.motor1ContentsWidget(), label1Count_);
    updateLabel(motorOneErrorFlags.motorOverSpeed(), motorOverSpeed1Fault_, ui_.motor1ContentsWidget(), label1Count_);
    updateLabel(motorOneErrorFlags.railUnderVoltageLockOut(), railUnderVoltageLockOut1Fault_, ui_.motor1ContentsWidget(), label1Count_);
    updateLabel(motorOneErrorFlags.watchdogCausedLastReset(), watchdogCausedLastReset1Fault_, ui_.motor1ContentsWidget(), label1Count_);
    updateLabel(motorOneErrorFlags.softwareOverCurrent(), softwareOverCurrent1Fault_, ui_.motor1ContentsWidget(), label1Count_);
}

void MotorFaultView::motorOneLimitFlagsReceived(LimitFlags motorOneLimitFlags)
{
    updateLabel(motorOneLimitFlags.busCurrentLimit(), busCurrentLimit1Fault_, ui_.motor1ContentsWidget(), label1Count_);
    updateLabel(motorOneLimitFlags.busVoltageUpperLimit(), busVoltageUpperLimit1Fault_, ui_.motor1ContentsWidget(), label1Count_);
    updateLabel(motorOneLimitFlags.busVoltageLowerLimit(), busVoltageLowerLimit1Fault_, ui_.motor1ContentsWidget(), label1Count_);
    updateLabel(motorOneLimitFlags.ipmOrMotorTelemetryLimit(), ipmOrMotorTelemetryLimit1Fault_, ui_.motor1ContentsWidget(), label1Count_);
    updateLabel(motorOneLimitFlags.motorCurrentLimit(), motorCurrentLimit1Fault_, ui_.motor1ContentsWidget(), label1Count_);
    updateLabel(motorOneLimitFlags.outputVoltagePwmLimit(), outputVoltagePwmLimit1Fault_, ui_.motor1ContentsWidget(), label1Count_);
    updateLabel(motorOneLimitFlags.velocityLimit(), velocityLimit1Fault_, ui_.motor1ContentsWidget(), label1Count_);
}

void MotorFaultView::errorFlagsReceived(BatteryErrorFlags batteryErrorFlags)
{
    updateLabel(batteryErrorFlags.alwaysOnSupplyFault(), alwaysOnSupplyFault_, ui_.batteryContentsWidget(), labelBCount_);
    updateLabel(batteryErrorFlags.canbusCommunicationsFault(), canbusCommunicationsFault_, ui_.batteryContentsWidget(), labelBCount_);
    updateLabel(batteryErrorFlags.chargeLimitEnforcementFault(), chargeLimitEnforcementFault_, ui_.batteryContentsWidget(), labelBCount_);
    updateLabel(batteryErrorFlags.chargerSafetyRelayFault(), chargerSafetyRelayFault_, ui_.batteryContentsWidget(), labelBCount_);
    updateLabel(batteryErrorFlags.currentSensorFault(), currentSensorFault_, ui_.batteryContentsWidget(), labelBCount_);
    updateLabel(batteryErrorFlags.dischargeLimitEnforcementFault(), dischargeLimitEnforcementFault_, ui_.batteryContentsWidget(), labelBCount_);
    updateLabel(batteryErrorFlags.fanMonitorFault(), alwaysOnSupplyFault_, ui_.batteryContentsWidget(), labelBCount_);
    updateLabel(batteryErrorFlags.highVoltageIsolationFault(), alwaysOnSupplyFault_, ui_.batteryContentsWidget(), labelBCount_);
    updateLabel(batteryErrorFlags.internalCommununicationFault(), alwaysOnSupplyFault_, ui_.batteryContentsWidget(), labelBCount_);
    updateLabel(batteryErrorFlags.internalConversionFault(), alwaysOnSupplyFault_, ui_.batteryContentsWidget(), labelBCount_);
    updateLabel(batteryErrorFlags.internalLogicFault(), alwaysOnSupplyFault_, ui_.batteryContentsWidget(), labelBCount_);
    updateLabel(batteryErrorFlags.internalMemoryFault(), alwaysOnSupplyFault_, ui_.batteryContentsWidget(), labelBCount_);
    updateLabel(batteryErrorFlags.internalThermistorFault(), alwaysOnSupplyFault_, ui_.batteryContentsWidget(), labelBCount_);
    updateLabel(batteryErrorFlags.lowCellVoltageFault(), alwaysOnSupplyFault_, ui_.batteryContentsWidget(), labelBCount_);
    updateLabel(batteryErrorFlags.openWiringFault(), alwaysOnSupplyFault_, ui_.batteryContentsWidget(), labelBCount_);
    updateLabel(batteryErrorFlags.packVoltageSensorFault(), alwaysOnSupplyFault_, ui_.batteryContentsWidget(), labelBCount_);
    updateLabel(batteryErrorFlags.powerSupplyFault12V(), alwaysOnSupplyFault_, ui_.batteryContentsWidget(), labelBCount_);
    updateLabel(batteryErrorFlags.thermistorFault(), alwaysOnSupplyFault_, ui_.batteryContentsWidget(), labelBCount_);
    updateLabel(batteryErrorFlags.voltageRedundancyFault(), alwaysOnSupplyFault_, ui_.batteryContentsWidget(), labelBCount_);
    updateLabel(batteryErrorFlags.weakCellFault(), alwaysOnSupplyFault_, ui_.batteryContentsWidget(), labelBCount_);
    updateLabel(batteryErrorFlags.weakPackFault(), alwaysOnSupplyFault_, ui_.batteryContentsWidget(), labelBCount_);
}

void MotorFaultView::limitFlagsReceived(BatteryLimitFlags batteryLimitFlags)
{
    updateLabel(batteryLimitFlags.cclReducedDueToAlternateCurrentLimit(), cclReducedDueToAlternateCurrentLimit_, ui_.batteryContentsWidget(), labelBCount_);
    updateLabel(batteryLimitFlags.cclReducedDueToChargerLatch(), cclReducedDueToChargerLatch_, ui_.batteryContentsWidget(), labelBCount_);
    updateLabel(batteryLimitFlags.cclReducedDueToHighCellResistance(), cclReducedDueToHighCellResistance_, ui_.batteryContentsWidget(), labelBCount_);
    updateLabel(batteryLimitFlags.cclReducedDueToHighCellVoltage(), cclReducedDueToHighCellVoltage_, ui_.batteryContentsWidget(), labelBCount_);
    updateLabel(batteryLimitFlags.cclReducedDueToHighPackVoltage(), cclReducedDueToHighPackVoltage_, ui_.batteryContentsWidget(), labelBCount_);
    updateLabel(batteryLimitFlags.cclReducedDueToHighSoc(), cclReducedDueToHighSoc_, ui_.batteryContentsWidget(), labelBCount_);
    updateLabel(batteryLimitFlags.cclReducedDueToTemperature(), cclReducedDueToTemperature_, ui_.batteryContentsWidget(), labelBCount_);
    updateLabel(batteryLimitFlags.dclandCclReducedDueToCommunicationFailsafe(), dclandCclReducedDueToCommunicationFailsafe_, ui_.batteryContentsWidget(), labelBCount_);
    updateLabel(batteryLimitFlags.dclandCclReducedDueToVoltageFailsafe(), dclandCclReducedDueToVoltageFailsafe_, ui_.batteryContentsWidget(), labelBCount_);
    updateLabel(batteryLimitFlags.dclReducedDueToHighCellResistance(), dclReducedDueToHighCellResistance_, ui_.batteryContentsWidget(), labelBCount_);
    updateLabel(batteryLimitFlags.dclReducedDueToLowCellVoltage(), dclReducedDueToLowCellVoltage_, ui_.batteryContentsWidget(), labelBCount_);
    updateLabel(batteryLimitFlags.dclReducedDueToLowPackVoltage(), dclReducedDueToLowPackVoltage_, ui_.batteryContentsWidget(), labelBCount_);
    updateLabel(batteryLimitFlags.dclReducedDueToLowSoc(), dclReducedDueToLowSoc_, ui_.batteryContentsWidget(), labelBCount_);
    updateLabel(batteryLimitFlags.dclReducedDueToTemperature(), dclReducedDueToTemperature_, ui_.batteryContentsWidget(), labelBCount_);
}
