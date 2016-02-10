/**
 *  Gen 5 Dashboard
 *  Copyright (C) 2015 University of Calgary Solar Car Team
 *
 *  This file is part of the Gen 5 Dashboard
 *
 *  The Gen 5 Dashboard is free software: 
 *  you can redistribute it and/or modify it under the terms 
 *  of the GNU Affero General Public License as published by 
 *  the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  The Gen 5 Dashboard is distributed 
 *  in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
 *  without even the implied warranty of MERCHANTABILITY or 
 *  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero 
 *  General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General 
 *  Public License along with the Gen 5 Dashboard.
 *  If not, see <http://www.gnu.org/licenses/>.
 *
 *  For further contact, email <software@calgarysolarcar.ca>
 */

#include <QApplication>
#include <QDesktopWidget>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QWidget>
#include <QKeyEvent>
#include <QFontDatabase>
#include <QDir>
#include <QDebug>
#include "OverlordWidget.h"
#include "../I_SolarCarWindow/I_SolarCarWindow.h"
#include "../EscapeDialog/EscapeDialog.h"

OverlordWidget::OverlordWidget(QList<I_SolarCarWindow*> viewWindows,
                               EscapeDialog* escapeDialog,
                               QWidget *parent)
: QWidget(parent)
, viewWindows_(viewWindows)
, state_("Single")
// , settingsWindow_(settings)
, escapeDialog_(escapeDialog)
{
    setupEscapeDialog();

    QTabWidget* tabBar = createTabWidget();

    escapeDialog_->setAttribute(Qt::WA_TranslucentBackground);

    QVBoxLayout* overlordLayout = new QVBoxLayout;
    overlordLayout->setContentsMargins(0, 0, 0, 0);
    setLayout(overlordLayout);
    setWindowIcon(QIcon(":/Resources/Solar Car Team Icon.ico"));
    setStyleSheet("background-color: rgb(30,30,30);");

    overlordLayout->addWidget(tabBar);

    addFonts();

    showMaximized();

    connect(escapeDialog_, SIGNAL(changeWindowState(int)),
            this, SLOT(changeWindowState(int)));
}

OverlordWidget::~OverlordWidget()
{
}
void OverlordWidget::changeWindowState(int state)
{
    qDebug() << "state changed";
    if(state == Qt::Unchecked){
        qDebug() << "toggled off";
        showNormal();
        //setWindowFlags(0);
    }
    else if(state == Qt::Checked){
        qDebug() << "toggled on";
        showFullScreen();
        //setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    }
}

void OverlordWidget::keyPressEvent(QKeyEvent * event)
{
    if (event->key() == Qt::Key_Escape){
        escapeDialog_->show();
    }
}

QString OverlordWidget::changeState()
{
   if(state_ .compare("Single") == 0){
      state_ = "Multi";
   }
   else if(state_.compare("Multi") == 0){
      state_ = "Single";
   }
   return state_;
}

QString OverlordWidget::getState()
{
   return state_;
}

void OverlordWidget::addFonts(){
    QDir fontDirectory = QDir(":/Resources/Fonts/");

    QStringList fonts =  fontDirectory.entryList();
    foreach(QString font, fonts){
        QFontDatabase::addApplicationFont(":/Resources/Fonts/" + font);
    }
}
void OverlordWidget::setupEscapeDialog()
{
    QRect rec = QApplication::desktop()->screenGeometry();
    int height = rec.height();
    int width = rec.width();
    escapeDialog_->resize(width, height);
    escapeDialog_->hide();
    escapeDialog_->setParent(this, Qt::Popup | Qt::CustomizeWindowHint);
    escapeDialog_->move(QApplication::desktop()->screen()->rect().center()
                        - escapeDialog_->rect().center());
}

QTabWidget* OverlordWidget::createTabWidget()
{
    QTabWidget* tabBar = new QTabWidget();
    foreach(I_SolarCarWindow* window, viewWindows_){
        tabBar->addTab(window, window->windowTitle());
        window->hideHeaderBar();
    }
    tabBar->setStyleSheet("QTabBar::tab { height: 40px;\n width: 175px;\n"
                          "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40,40,40), stop: 1 rgb(60,60,60));"
                          "font-family: \"AvenirLTStd\";\n"
                          "font-size: 20px;\n"
                          "color: white;"
                          "border: 1px solid rgb(30,30,30);"
                          "border-left: 1px solid rgb(120,120,120); }"
                          "QTabBar::tab:selected { height: 40px;\n width: 175px;\n"
                          "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(90, 90, 90), stop: 1 rgb(120,120,120));"
                          "font-family: \"AvenirLTStd\";\n"
                          "font-size: 20px;\ncolor: white;"
                          "border: 1px solid rgb(30,30,30);"
                          "border-left: 1px solid rgb(120,120,120); }");
    return tabBar;
}

// void OverlordWidget::showSettings()
// {
// }
