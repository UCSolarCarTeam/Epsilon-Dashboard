#include "FaultView.h"

namespace
{
    int HEIGHT = 25;
    int WIDTH = 665;
    QString ERROR_STYLESHEET = "font: 20px 'Arial';\nfont-weight:500;color:#89c2d3; margin-left: 10px;";
    QString LIMIT_STYLESHEET = "font: 20px 'Arial';\nfont-weight:500;color:#CCBF14; margin-left: 10px;";
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
FaultView::FaultView(MotorFaultsPresenter& motorFaultsPresenter,
                     BatteryFaultsPresenter& batteryFaultsPresenter,
                     I_FaultUi& ui,
                     MotorFaultList motorZeroFaultList,
                     MotorFaultList motorOneFaultList)
    : motorFaultsPresenter_(motorFaultsPresenter)
    , batteryFaultsPresenter_(batteryFaultsPresenter)
    , ui_(ui)
    , motorZeroFaultList_(motorZeroFaultList)
    , label0Count_(0)
    , motorOneFaultList_(motorOneFaultList)
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
    QScrollBar* verticalBarM0 = new QScrollBar();
    QScrollBar* verticalBarM1 = new QScrollBar();
    QScrollBar* verticalBarB = new QScrollBar();

    verticalBarM0->setStyleSheet(SCROLLBAR_STYLESHEET);
    verticalBarM1->setStyleSheet(SCROLLBAR_STYLESHEET);
    verticalBarB->setStyleSheet(SCROLLBAR_STYLESHEET);

    ui_.motor0ScrollArea().setVerticalScrollBar(verticalBarM0);
    ui_.motor1ScrollArea().setVerticalScrollBar(verticalBarM1);
    ui_.batteryScrollArea().setVerticalScrollBar(verticalBarB);

    QLayout* layoutM0 = ui_.motor0ContentsWidget().layout();
    QLayout* layoutM1 = ui_.motor1ContentsWidget().layout();
    QLayout* layoutB = ui_.batteryContentsWidget().layout();

    initializeLabels(layoutM0, layoutM1, layoutB);

    ui_.motor0ContentsWidget().setLayout(layoutM0);
    ui_.motor1ContentsWidget().setLayout(layoutM1);
    ui_.batteryContentsWidget().setLayout(layoutB);

    connectMotorFaults(motorFaultsPresenter_);
    connectBatteryFaults(batteryFaultsPresenter_);
}

FaultView::~FaultView()
{
}

void FaultView::initializeLabel(QLabel& label, QLayout*& layout, QString& styleSheet)
{
    label.resize(WIDTH, HEIGHT);
    label.setStyleSheet(styleSheet);
    label.setFixedSize(WIDTH, HEIGHT);
    layout->addWidget(&label);
    label.hide();
}

void FaultView::initializeLabels(QLayout*& layoutM0, QLayout*& layoutM1, QLayout*& layoutB)
{
    // Motor 0
    for(int i = 0; i < motorZeroFaultList_.getErrorLabels().size(); i++)
    {
        initializeLabel(motorZeroFaultList_.getErrorLabels()[i], layoutM0, ERROR_STYLESHEET);
    }

    for(int i = 0; i < motorZeroFaultList_.getLimitLabels().size(); i++)
    {
        initializeLabel(motorZeroFaultList_.getLimitLabels()[i], layoutM0, LIMIT_STYLESHEET);
    }

    // Motor 1
    for(int i = 0; i < motorOneFaultList_.getErrorLabels().size(); i++)
    {
        initializeLabel(motorOneFaultList_.getErrorLabels()[i], layoutM1, ERROR_STYLESHEET);
    }

    for(int i = 0; i < motorOneFaultList_.getLimitLabels().size(); i++)
    {
        initializeLabel(motorOneFaultList_.getLimitLabels()[i], layoutM1, LIMIT_STYLESHEET);
    }

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
}

void FaultView::updateLabel(const bool& receivedValue, QLabel& label, QWidget& contentsWidget, int& labelCount)
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

void FaultView::connectMotorFaults(MotorFaultsPresenter& motorFaultsPresenter)
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

void FaultView::connectBatteryFaults(BatteryFaultsPresenter& batteryFaultsPresenter)
{
    connect(&batteryFaultsPresenter, SIGNAL(errorFlagsReceived(BatteryErrorFlags)),
            this, SLOT(errorFlagsReceived(BatteryErrorFlags)));
    connect(&batteryFaultsPresenter, SIGNAL(limitFlagsReceived(BatteryLimitFlags)),
            this, SLOT(limitFlagsReceived(BatteryLimitFlags)));
}

void FaultView::motorZeroErrorFlagsReceived(ErrorFlags motorZeroErrorFlags)
{
    motorZeroFaultList_.updateErrors(motorZeroErrorFlags);

    for(int i = 0; i < motorZeroFaultList_.getErrorLabels().size(); i++)
    {
        updateLabel(motorZeroFaultList_.getErrorLabels()[i].isActive(),  motorZeroFaultList_.getErrorLabels()[i], ui_.motor0ContentsWidget(), label0Count_);
    }
}

void FaultView::motorZeroLimitFlagsReceived(LimitFlags motorZeroLimitFlags)
{
    motorZeroFaultList_.updateLimits(motorZeroLimitFlags);

    for(int i = 0; i < motorZeroFaultList_.getLimitLabels().size(); i++)
    {
        updateLabel(motorZeroFaultList_.getLimitLabels()[i].isActive(), motorZeroFaultList_.getLimitLabels()[i], ui_.motor0ContentsWidget(), label0Count_);
    }
}

void FaultView::motorOneErrorFlagsReceived(ErrorFlags motorOneErrorFlags)
{
    motorOneFaultList_.updateErrors(motorOneErrorFlags);

    for(int i = 0; i < motorOneFaultList_.getErrorLabels().size(); i++)
    {
        updateLabel(motorOneFaultList_.getErrorLabels()[i].isActive(), motorOneFaultList_.getErrorLabels()[i], ui_.motor1ContentsWidget(), label1Count_);
    }
}

void FaultView::motorOneLimitFlagsReceived(LimitFlags motorOneLimitFlags)
{
    motorOneFaultList_.updateLimits(motorOneLimitFlags);

    for(int i = 0; i < motorOneFaultList_.getLimitLabels().size(); i++)
    {
        updateLabel(motorOneFaultList_.getLimitLabels()[i].isActive(), motorOneFaultList_.getLimitLabels()[i], ui_.motor1ContentsWidget(), label1Count_);
    }
}

void FaultView::errorFlagsReceived(BatteryErrorFlags batteryErrorFlags)
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

void FaultView::limitFlagsReceived(BatteryLimitFlags batteryLimitFlags)
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
