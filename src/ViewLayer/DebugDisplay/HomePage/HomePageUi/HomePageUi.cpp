#include "ui_HomePageUi.h"
#include "HomePageUi.h"

HomePageUi::HomePageUi() :
    ui_(new Ui::HomePageUi),
    fontLoader_(new FontLoader)
{
    ui_->setupUi(this);
    QPixmap background(":/Resource/Background.png");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, background);
    this->setPalette(palette);
}

HomePageUi::~HomePageUi()
{
    delete ui_;
}

QPushButton& HomePageUi::batteryButton()
{
    return *ui_->batteryButton;
}

QPushButton& HomePageUi::controlButton()
{
    return *ui_->controlButton;
}

QPushButton& HomePageUi::faultButton()
{
    return *ui_->faultButton;
}

QPushButton& HomePageUi::motorButton()
{
    return *ui_->motorButton;
}

QPushButton& HomePageUi::mpptButton()
{
    return *ui_->MPPT;
}

QLabel& HomePageUi::carLabel()
{
    return *ui_->carLabel;
}
