#include "InfrastructureContainer.h"
#include "Settings/Settings.h"
#include <QCoreApplication>
#include <QDebug>

namespace
{
    const char* RACE_QUEUE = "raceQueue";
    const char* DISPLAY_QUEUE = "displayQueue";
    const char* DEBUG_QUEUE = "debugQueue";
    const char* DEFAULT_QUEUE = "dashboardQueue";
}

InfrastructureContainer::InfrastructureContainer()
{
    settings_.reset(new Settings(QCoreApplication::applicationDirPath() + "/config.ini"));
}

InfrastructureContainer::~InfrastructureContainer()
{
}

void InfrastructureContainer::setQueueName(const char* queueName)
{
    if (settings_->queue() == RACE_QUEUE ||
            settings_->queue() == DISPLAY_QUEUE ||
            settings_->queue() == DEBUG_QUEUE ||
            settings_->queue() == DEFAULT_QUEUE)
    {
        settings_->setQueueName(queueName);
    }
}

I_Settings& InfrastructureContainer::settings()
{
    return *settings_;
}
