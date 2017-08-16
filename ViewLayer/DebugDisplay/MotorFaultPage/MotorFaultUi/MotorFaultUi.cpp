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

