#include "TabUi.h"
#include "ui_TabUi.h"
#include <QDebug>

TabUi::TabUi() :
    ui_(new Ui::TabUi)
{
    ui_->setupUi(this);
    QPixmap bkgnd(":/Resources/Background.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette background = palette();
    background.setBrush(QPalette::Background, bkgnd);
    this->setAutoFillBackground(true);
    this->setPalette(background);
    this->show();
}
TabUi::~TabUi()
{
    delete ui_;
}
QPushButton& TabUi::homepageButton()
{
    return *ui_->homepageButton;
}
QPushButton& TabUi::batteryButton()
{
    return *ui_->batteryButton;
}
QPushButton& TabUi::controlButton()
{
    return *ui_->controlButton;
}
QPushButton& TabUi::motorFaultButton()
{
    return *ui_->motorFaultButton;
}
QPushButton& TabUi::motorButton()
{
    return *ui_->motorButton;
}
QPushButton& TabUi::mpptButton()
{
    return *ui_->mpptButton;
}
