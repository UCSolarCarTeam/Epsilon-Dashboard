#include "HomePageView.h"
#include <QDebug>

namespace
{
    const QString ON = "background-color: green; color: white;";
    const QString OFF = "background-color: rgb(45, 45, 45,150); color: white;";
}

HomePageView::HomePageView(I_HomePageUi& ui)
    : ui_(ui)
{
    buttons = ui_.findChildren<QPushButton*>();
    carImages = QList<QPixmap>() << QPixmap(":/Resource/MPPT.png")
                << QPixmap(":/Resource/Control.png")
                << QPixmap(":/Resource/Faults1.png")
                << QPixmap(":/Resource/Motor.png")
                << QPixmap(":/Resource/Battery.png");
    mainTimer = new QTimer(this);
    connectTimer(mainTimer);
}

HomePageView::~HomePageView()
{
}

void HomePageView::connectTimer(QTimer* timer)
{
    startLoop();
    connect(timer, SIGNAL(timeout()), this, SLOT(startLoop()));
    timer->start(10000);
}

void HomePageView::startLoop()
{
    for (int i = 0; i < buttons.count(); i++)
    {
        QTimer* timer = new QTimer(this);
        QTimer* timer2 = new QTimer(this);

        timer->setSingleShot(true);
        timer2->setSingleShot(true);

        connect(timer, &QTimer::timeout, [ = ]()
        {
            buttons[i]->setStyleSheet(ON);
            timer->deleteLater();
            ui_.carLabel().setPixmap(carImages[i]);
        });
        connect(timer2, &QTimer::timeout, [ = ]()
        {
            buttons[i]->setStyleSheet(OFF);
            timer2->deleteLater();
        });
        timer->start((i + 1) * 2000);
        timer2->start(2000 + (i + 1) * 2000);
    }
}
