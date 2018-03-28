#include "TabUi.h"
#include "ui_TabUi.h"
#include <QTimer>
#include <QDateTime>
#include <QPixmap>
#include <QPainter>
#include <QBitmap>
#include <QImage>

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

   QPixmap pix(":/Resources/SteeringIcon.png");
    //QPixmap pixr(pix.size());
    //pixr.fill(Qt::red);
    //pixr.setMask(pix.createMaskFromColor(Qt::black));
    //ui_->controlButton->setIcon(pixr);
  /* QImage tmp = pix.toImage();
    QColor color (Qt::red);
    for(int y = 0; y < pix.height(); y++)
        for(int x = 0; x < pix.width(); x++)
            color.setAlpha(tmp.pixel(x,y).alpha());
            tmp.setPixel(x,y,color);
    pix = QPixmap::fromImage(tmp);
    ui_->controlButton->setIcon(pix);

  /* QPixmap newPix(pix.size());
    newPix.fill(Qt::white);
   QBitmap mask = pix.createMaskFromColor(Qt::black, Qt::MaskOutColor);
    QPainter p(&newPix);
    p.setRenderHint(QPainter::SmoothPixmapTransform);
    p.setRenderHint(QPainter::Antialiasing);
    p.setBackgroundMode(Qt::TransparentMode);
    p.setPen(Qt::red);
    p.drawPixmap(newPix.rect(),mask,pix.rect());
    p.end();
    ui_->controlButton->setIcon(newPix);
   */

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
