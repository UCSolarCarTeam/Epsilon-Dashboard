#include "TabUi.h"
#include "ui_TabUi.h"
#include <QTimer>
#include <QDateTime>
#include <QPixmap>

TabUi::TabUi(QWidget *parent) :
    ui_(new Ui::TabUi)
{
    ui_->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start();
    QPixmap bkgnd(":/Resources/Background.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette background = palette();
    background.setBrush(QPalette::Background, bkgnd);

    ui_->controlButton->setIcon(QIcon(":/Resources/SteeringIcon.png"));
    ui_->controlButton->setIconSize(QSize(30,30));
    ui_->batteryButton->setIcon(QIcon(":/Resources/BatteryIcon.png"));
    ui_->batteryButton->setIconSize(QSize(30,30));
    ui_->motorButton->setIcon(QIcon(":/Resources/EngineIcon.png"));
    ui_->motorButton->setIconSize(QSize(35,35));
    ui_->faultButton->setIcon(QIcon(":/Resources/GearIcon.png"));
    ui_->faultButton->setIconSize(QSize(35,35));
    ui_->mpptButton->setIcon(QIcon(":/Resources/MPPTIcon.png"));
    ui_->mpptButton->setIconSize(QSize(38,38));

    QPixmap pix(":/Resources/MPPTIcon.png");
    //correct logo below
    //QPixmap pix(":/Resources/SolarCarTeam.png");
    //
    pix = pix.scaled(QSize(25,25));
    ui_->calgaryTeam->setPixmap(pix);

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
QPushButton& TabUi::faultButton()
{
    return *ui_->faultButton;
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
    QString time_text = time.toString("hh:mm:ss");
    ui_->Digital_Clock->setText(time_text);
}
