#include "TabUi.h"
#include "ui_TabUi.h"
#include <QDebug>
#include <QTimer>
#include <QDateTime>

TabUi::TabUi(QWidget *parent) :
    I_TabUi(parent),
    ui_(new Ui::TabUi())
{
    ui_->setupUi(this);
    showTime();
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
void TabUi::showTime()
{
    QTime time = QTime::currentTime();
    QString time_text = time.toString("hh : mm : ss");
    ui_->Digital_Clock->setText(time_text);
}
