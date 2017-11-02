#include "InfrastructureContainer.h"
#include "Settings/Settings.h"
#include <QDir>
#include <QDebug>

namespace
{
    QString SETTINGS_FILE_PATH = (QDir::currentPath() + "/../Epsilon-Dashboard/config.ini");
}

InfrastructureContainer::InfrastructureContainer()
    : settings_(new Settings(SETTINGS_FILE_PATH))
{
}

InfrastructureContainer::~InfrastructureContainer()
{
}

I_Settings& InfrastructureContainer::settings()
{
    return *settings_;
}
