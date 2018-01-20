#include "RaceModeDashboardUI.h"
#include "ui_RaceModeDashboardUI.h"

RaceModeDashboardUI::RaceModeDashboardUI()
    : ui_(new Ui::RaceModeDashboardUI)
{
    ui_->setupUi(this);
    QWidget::setWindowFlags(Qt::FramelessWindowHint);
}

RaceModeDashboardUI::~RaceModeDashboardUI()
{
    delete ui_;
}

