#include "MotorFaultUi.h"
#include "ui_MotorFaultUi.h"
MotorFaultUi::MotorFaultUi():
    ui_(new Ui::MotorFaultUi)
{
    ui_->setupUi(this);
    QPixmap bkgnd(":/Resources/Background.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette background;
    background.setBrush(QPalette::Background, bkgnd);
    this->setPalette(background);
}

MotorFaultUi::~MotorFaultUi()
{
    delete ui_;
}

QWidget& MotorFaultUi::motor0ContentsWidget()
{
    return *ui_->motor0ContentsWidget;
}

QWidget& MotorFaultUi::motor1ContentsWidget()
{
    return *ui_->motor1ContentsWidget;
}

QWidget& MotorFaultUi::batteryContentsWidget()
{
    return *ui_->batteryContentsWidget;
}

QScrollArea& MotorFaultUi::motor0ScrollArea()
{
    return *ui_->motor0ScrollArea;
}

QScrollArea& MotorFaultUi::motor1ScrollArea()
{
    return *ui_->motor1ScrollArea;
}

QScrollArea& MotorFaultUi::batteryScrollArea()
{
    return *ui_->batteryScrollArea;
}
