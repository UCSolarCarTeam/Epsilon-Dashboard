#pragma once
#include <QObject>
#include <QTimer>

#include "../../HomePage/HomePageUi/I_HomePageUi.h"

class HomePageView : public QObject
{
    Q_OBJECT
public:
    HomePageView(I_HomePageUi& ui);
    ~HomePageView();
private:
    I_HomePageUi& ui_;
    QList<QPushButton*> buttons;
    QList<QPixmap> carImages;
    QTimer* mainTimer;
    void connectTimer(QTimer*);

private slots:
    void startLoop();
};
