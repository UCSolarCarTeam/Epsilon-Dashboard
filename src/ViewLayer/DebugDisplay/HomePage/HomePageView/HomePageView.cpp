#include "HomePageView.h"
#include <QDebug>

namespace
{
    const QString ON = "background-color: green; color: white;";
    const QString OFF = "background-color: rgb(45, 45, 45,150); color: white;";
    const int INTERVAL = 2000;
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

/*
 * Connects the signal on the main timeout to restart the loop
 */
void HomePageView::connectTimer(QTimer* timer)
{
    startLoop();
    connect(timer, SIGNAL(timeout()), this, SLOT(startLoop()));
    timer->start(INTERVAL * buttons.length());
}


/* Starts 2 timers that controls the styling of the buttons
 * One timer lights up the button and the other turns it
 * back to its original styling
 */
void HomePageView::startLoop()
{
    for (int i = 0; i < buttons.count(); i++)
    {
        QTimer* timer1 = new QTimer(this);
        QTimer* timer2 = new QTimer(this);

        timer1->setSingleShot(true);
        timer2->setSingleShot(true);

        // The [=] represents a lambda or anonymous function
        // that changes the button colour and removes the timer
        // after it finishes
        connect(timer1, &QTimer::timeout, [ = ]()
        {
            buttons[i]->setStyleSheet(ON);
            ui_.carLabel().setPixmap(carImages[i]);
            timer1->deleteLater();
        });
        connect(timer2, &QTimer::timeout, [ = ]()
        {
            buttons[i]->setStyleSheet(OFF);
            timer2->deleteLater();
        });
        timer1->start((i + 1) * INTERVAL);
        timer2->start(INTERVAL + (i + 1) * INTERVAL);
    }
}
