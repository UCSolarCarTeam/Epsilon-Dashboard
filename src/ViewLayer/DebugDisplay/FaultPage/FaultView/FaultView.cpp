#include "FaultView.h"

namespace
{
    int HEIGHT = 30;
    int WIDTH = 665;
    int LABEL_RESIZE_LIMIT = 5;
    QString ERROR_STYLESHEET = "font: 20px 'Arial';\nfont-weight:500;\nmargin-left: 10px;\ncolor:";
    QString LIMIT_STYLESHEET = "font: 20px 'Arial';\nfont-weight:500;\nmargin-left: 10px;\ncolor:";
    QString FAULT_STYLESHEET = "font: 20px 'Arial';\nfont-weight:500;\nmargin-left: 10px;\ncolor:";
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
}
FaultView::FaultView(MotorFaultsPresenter& motorFaultsPresenter,
                     BatteryFaultsPresenter& batteryFaultsPresenter,
                     I_FaultUi& ui,
                     MotorFaultList motorZeroFaultList,
                     MotorFaultList motorOneFaultList,
                     BatteryFaultList batteryFaultList)
    : motorFaultsPresenter_(motorFaultsPresenter)
    , batteryFaultsPresenter_(batteryFaultsPresenter)
    , ui_(ui)
    , motorZeroFaultList_(motorZeroFaultList)
    , label0Count_(0)
    , motorOneFaultList_(motorOneFaultList)
    , label1Count_(0)
    , batteryFaultList_(batteryFaultList)
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

void FaultView::initializeLabel(FaultLabel& label, QLayout*& layout, QString& styleSheet)
{
    label.resize(WIDTH, HEIGHT);
    label.setStyleSheet(QString("%1%2").arg(styleSheet).arg(label.color().name()));
    label.setFixedSize(WIDTH, HEIGHT);
    layout->addWidget(&label);
    label.hide();
}

void FaultView::initializeLabels(QLayout*& layoutM0, QLayout*& layoutM1, QLayout*& layoutB)
{
    // Motor 0
    for (int i = 0; i < motorZeroFaultList_.errorLabels().size(); i++)
    {
        initializeLabel(motorZeroFaultList_.errorLabels()[i], layoutM0, ERROR_STYLESHEET);
    }

    for (int i = 0; i < motorZeroFaultList_.limitLabels().size(); i++)
    {
        initializeLabel(motorZeroFaultList_.limitLabels()[i], layoutM0, LIMIT_STYLESHEET);
    }

    // Motor 1
    for (int i = 0; i < motorOneFaultList_.errorLabels().size(); i++)
    {
        initializeLabel(motorOneFaultList_.errorLabels()[i], layoutM1, ERROR_STYLESHEET);
    }

    for (int i = 0; i < motorOneFaultList_.limitLabels().size(); i++)
    {
        initializeLabel(motorOneFaultList_.limitLabels()[i], layoutM1, LIMIT_STYLESHEET);
    }

    // Battery
    for (int i = 0; i < batteryFaultList_.faultLabels().size(); i++)
    {
        initializeLabel(batteryFaultList_.faultLabels()[i], layoutB, FAULT_STYLESHEET);
    }
}

void FaultView::updateLabel(FaultLabel& label)
{
    if (label.isActive())
    {
        label.show();
    }
    else
    {
        label.hide();
    }
}

void FaultView::updateLabelListHeight(QWidget& contentsWidget, int& labelCount)
{
    if (labelCount >= LABEL_RESIZE_LIMIT)
    {
        contentsWidget.setFixedSize(WIDTH, labelCount * HEIGHT);
    }
    else
    {
        contentsWidget.setFixedSize(WIDTH, LABEL_RESIZE_LIMIT * HEIGHT);
    }
}

void FaultView::updateBatteryFaults()
{
    labelBCount_ = batteryFaultList_.numberOfActiveLabels();

    for (int i = 0; i < batteryFaultList_.faultLabels().size(); i++)
    {
        updateLabel(batteryFaultList_.faultLabels()[i]);
    }
    updateLabelListHeight(ui_.batteryContentsWidget(), labelBCount_);
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
    label0Count_ = motorZeroFaultList_.numberOfActiveLabels();

    for (int i = 0; i < motorZeroFaultList_.errorLabels().size(); i++)
    {
        updateLabel(motorZeroFaultList_.errorLabels()[i]);
    }

    updateLabelListHeight(ui_.motor0ContentsWidget(), label0Count_);
}

void FaultView::motorZeroLimitFlagsReceived(LimitFlags motorZeroLimitFlags)
{
    motorZeroFaultList_.updateLimits(motorZeroLimitFlags);
    label0Count_ = motorZeroFaultList_.numberOfActiveLabels();

    for (int i = 0; i < motorZeroFaultList_.limitLabels().size(); i++)
    {
        updateLabel(motorZeroFaultList_.limitLabels()[i]);
    }

    updateLabelListHeight(ui_.motor0ContentsWidget(), label0Count_);
}

void FaultView::motorOneErrorFlagsReceived(ErrorFlags motorOneErrorFlags)
{
    motorOneFaultList_.updateErrors(motorOneErrorFlags);
    label1Count_ = motorOneFaultList_.numberOfActiveLabels();

    for (int i = 0; i < motorOneFaultList_.errorLabels().size(); i++)
    {
        updateLabel(motorOneFaultList_.errorLabels()[i]);
    }

    updateLabelListHeight(ui_.motor1ContentsWidget(), label1Count_);
}

void FaultView::motorOneLimitFlagsReceived(LimitFlags motorOneLimitFlags)
{
    motorOneFaultList_.updateLimits(motorOneLimitFlags);
    label1Count_ = motorOneFaultList_.numberOfActiveLabels();

    for (int i = 0; i < motorOneFaultList_.limitLabels().size(); i++)
    {
        updateLabel(motorOneFaultList_.limitLabels()[i]);
    }

    updateLabelListHeight(ui_.motor1ContentsWidget(), label1Count_);
}

void FaultView::errorFlagsReceived(BatteryErrorFlags batteryErrorFlags)
{
    batteryFaultList_.updateErrors(batteryErrorFlags);
    updateBatteryFaults();
}

void FaultView::limitFlagsReceived(BatteryLimitFlags batteryLimitFlags)
{
    batteryFaultList_.updateLimits(batteryLimitFlags);
    updateBatteryFaults();
}
