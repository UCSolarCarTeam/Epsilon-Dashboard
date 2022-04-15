#include "FaultView.h"
#include <QTimer>

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
    const int FAULT_UPDATE_PERIOD = 1500;
}
FaultView::FaultView(I_FaultUi& ui,
                     I_MotorFaultList& motorZeroFaultList,
                     I_MotorFaultList& motorOneFaultList,
                     I_BatteryFaultList& batteryFaultList)
    : ui_(ui)
    , faultsTimer_(new QTimer())
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
    connect(faultsTimer_.data(), SIGNAL(timeout()), this, SLOT(updateBatteryFaults()));
    connect(faultsTimer_.data(), SIGNAL(timeout()), this, SLOT(updateMotor0Faults()));
    connect(faultsTimer_.data(), SIGNAL(timeout()), this, SLOT(updateMotor1Faults()));
    faultsTimer_->start(FAULT_UPDATE_PERIOD);
    ui_.motor0ContentsWidget().setLayout(layoutM0);
    ui_.motor1ContentsWidget().setLayout(layoutM1);
    ui_.batteryContentsWidget().setLayout(layoutB);

}

FaultView::~FaultView()
{
}

void FaultView::initializeLabel(FaultDisplayData& faultData, QLayout*& layout, QString& styleSheet)
{
    QLabel* faultLabel = new QLabel(faultData.name());
    faultLabel->resize(WIDTH, HEIGHT);
    faultLabel->setStyleSheet(QString("%1%2").arg(styleSheet, faultData.color().name()));
    faultLabel->setFixedSize(WIDTH, HEIGHT);
    layout->addWidget(faultLabel);
    faultLabel->hide();
    faultLabelList_.insert(&faultData, faultLabel);
}

void FaultView::initializeLabels(QLayout*& layoutM0, QLayout*& layoutM1, QLayout*& layoutB)
{
    // Motor 0
    QMap<MotorFaults, FaultDisplayData>& motorZeroFaults = motorZeroFaultList_.faults();
    QMap<MotorFaults, FaultDisplayData>::iterator motorZeroFaultIterator;

    for (motorZeroFaultIterator = motorZeroFaults.begin(); motorZeroFaultIterator != motorZeroFaults.end(); ++motorZeroFaultIterator)
    {
        initializeLabel(motorZeroFaultIterator.value(), layoutM0, FAULT_STYLESHEET);
    }

    // Motor 1
    QMap<MotorFaults, FaultDisplayData>& motorOneFaults = motorOneFaultList_.faults();
    QMap<MotorFaults, FaultDisplayData>::iterator motorOneFaultIterator;

    for (motorOneFaultIterator = motorOneFaults.begin(); motorOneFaultIterator != motorOneFaults.end(); ++motorOneFaultIterator)
    {
        initializeLabel(motorOneFaultIterator.value(), layoutM1, FAULT_STYLESHEET);
    }

    // Battery
    QMap<BatteryFaults, FaultDisplayData>& batteryFaults = batteryFaultList_.faults();
    QMap<BatteryFaults, FaultDisplayData>::iterator batteryFaultIterator;

    for (batteryFaultIterator = batteryFaults.begin(); batteryFaultIterator != batteryFaults.end(); ++batteryFaultIterator)
    {
        initializeLabel(batteryFaultIterator.value(), layoutB, FAULT_STYLESHEET);
    }
}

void FaultView::updateLabel(FaultDisplayData& faultData)
{
    if (faultData.isActive())
    {
        faultLabelList_[&faultData]->show();
    }
    else
    {
        faultLabelList_[&faultData]->hide();
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
    labelBCount_ = batteryFaultList_.numberOfActiveFaults();

    QMap<BatteryFaults, FaultDisplayData>& batteryFaults = batteryFaultList_.faults();
    QMap<BatteryFaults, FaultDisplayData>::iterator batteryFaultIterator;

    for (batteryFaultIterator = batteryFaults.begin(); batteryFaultIterator != batteryFaults.end(); ++batteryFaultIterator)
    {
        updateLabel(batteryFaultIterator.value());
    }

    updateLabelListHeight(ui_.batteryContentsWidget(), labelBCount_);
}

void FaultView::updateMotor0Faults()
{
    label0Count_ = motorZeroFaultList_.numberOfActiveFaults();

    QMap<MotorFaults, FaultDisplayData>& motorZeroFaults = motorZeroFaultList_.faults();
    QMap<MotorFaults, FaultDisplayData>::iterator motorZeroFaultIterator;

    for (motorZeroFaultIterator = motorZeroFaults.begin(); motorZeroFaultIterator != motorZeroFaults.end(); ++motorZeroFaultIterator)
    {
        updateLabel(motorZeroFaultIterator.value());
    }

    updateLabelListHeight(ui_.motor0ContentsWidget(), label0Count_);
}

void FaultView::updateMotor1Faults()
{
    label1Count_ = motorOneFaultList_.numberOfActiveFaults();

    QMap<MotorFaults, FaultDisplayData>& motorOneFaults = motorOneFaultList_.faults();
    QMap<MotorFaults, FaultDisplayData>::iterator motorOneFaultIterator;

    for (motorOneFaultIterator = motorOneFaults.begin(); motorOneFaultIterator != motorOneFaults.end(); ++motorOneFaultIterator)
    {
        updateLabel(motorOneFaultIterator.value());
    }

    updateLabelListHeight(ui_.motor1ContentsWidget(), label1Count_);
}
