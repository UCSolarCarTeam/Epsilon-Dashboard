#include "DashboardUI.h"
#include "ui_DashboardUI.h"

DashboardUI::DashboardUI()
    :ui(new Ui::DashboardUI)
{
    ui->setupUi(this);
}

DashboardUI::~DashboardUI()
{
    delete ui;
}

