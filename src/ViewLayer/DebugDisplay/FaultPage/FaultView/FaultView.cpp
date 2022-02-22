#include "FaultView.h"

namespace
{
    int HEIGHT = 30;
    int WIDTH = 665;
    int LABEL_RESIZE_LIMIT = 5;
    QString FAULT_STYLESHEET = "font: 20px 'Arial';\nfont-weight:500;\nmargin-left: 10px;\ncolor:";
    QString SCROLLBAR_STYLESHEET = "QScrollBar:vertical {"
                                   "    background:rgb(83, 83, 84);"
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
FaultView::FaultView(BatteryFaultsPresenter& batteryFaultsPresenter,
                     I_FaultUi& ui,
                     I_MotorFaultList& motorZeroFaultList,
                     I_MotorFaultList& motorOneFaultList,
                     BatteryFaultList batteryFaultList)
    : batteryFaultsPresenter_(batteryFaultsPresenter)
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

    connectBatteryFaults(batteryFaultsPresenter_);
}

FaultView::~FaultView()
{
}

void FaultView::initializeLabel(FaultDisplayData& faultData, QLayout*& layout, QString& styleSheet)
{
    QLabel faultLabel(faultData.name());
    faultLabelList_.insert(faultData.name(), &faultLabel);
    faultLabel.resize(WIDTH, HEIGHT);
    faultLabel.setStyleSheet(QString("%1%2").arg(styleSheet, faultData.color().name()));
    faultLabel.setFixedSize(WIDTH, HEIGHT);
    layout->addWidget(&faultLabel);
    faultLabel.hide();
}

void FaultView::initializeLabels(QLayout*& layoutM0, QLayout*& layoutM1, QLayout*& layoutB)
{
    // Motor 0
    QMapIterator<MotorFaults, FaultDisplayData> motorZeroFaultIterator(motorZeroFaultList_.faults());
    while(motorZeroFaultIterator.hasNext())
    {
        motorZeroFaultIterator.next();
        initializeLabel(motorZeroFaultList_.faults()[motorZeroFaultIterator.key()], layoutM0, FAULT_STYLESHEET);
    }

    // Motor 1
    QMapIterator<MotorFaults, FaultDisplayData> j(motorOneFaultList_.faults());
    while(j.hasNext())
    {
        j.next();
        initializeLabel(motorOneFaultList_.faults()[j.key()], layoutM1, FAULT_STYLESHEET);
    }

    // Battery
    for (int i = 0; i < batteryFaultList_.faultLabels().size(); i++)
    {
        initializeLabel(batteryFaultList_.faultLabels()[i], layoutB, FAULT_STYLESHEET);
    }
}

void FaultView::updateLabel(FaultDisplayData& faultData)
{
    if (faultData.isActive())
    {
        faultLabelList_[faultData.name()]->show();
    }
    else
    {
        faultLabelList_[faultData.name()]->hide();
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

void FaultView::updateMotor0Faults()
{
    label0Count_ = motorZeroFaultList_.numberOfActiveFaults();

    QMapIterator<MotorFaults, FaultDisplayData> i(motorZeroFaultList_.faults());
    while(i.hasNext())
    {
        i.next();
        updateLabel(motorZeroFaultList_.faults()[i.key()]);
    }

    updateLabelListHeight(ui_.motor0ContentsWidget(), label0Count_);
}

void FaultView::updateMotor1Faults()
{
    label1Count_ = motorOneFaultList_.numberOfActiveFaults();

    QMapIterator<MotorFaults, FaultDisplayData> i(motorOneFaultList_.faults());
    while(i.hasNext())
    {
        i.next();
        updateLabel(motorOneFaultList_.faults()[i.key()]);
    }

    updateLabelListHeight(ui_.motor1ContentsWidget(), label1Count_);
}

void FaultView::connectBatteryFaults(BatteryFaultsPresenter& batteryFaultsPresenter)
{
    connect(&batteryFaultsPresenter, SIGNAL(errorFlagsReceived(BatteryErrorFlags)),
            this, SLOT(errorFlagsReceived(BatteryErrorFlags)));
    connect(&batteryFaultsPresenter, SIGNAL(limitFlagsReceived(BatteryLimitFlags)),
            this, SLOT(limitFlagsReceived(BatteryLimitFlags)));
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
