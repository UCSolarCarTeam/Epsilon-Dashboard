#include "InfrastructureContainer.h"
#include "Settings/Settings.h"
#include <QCoreApplication>
#include <QDebug>

InfrastructureContainer::InfrastructureContainer()
{
    settings_.reset(new Settings(QCoreApplication::applicationDirPath() + "/config.ini"));
}

InfrastructureContainer::~InfrastructureContainer()
{
}

I_Settings& InfrastructureContainer::settings()
{
    return *settings_;
}
