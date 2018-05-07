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

void InfrastructureContainer::setQueueName(const char* queueName)
{
    if (settings_->queue() == raceQueue_ ||
            settings_->queue() == displayQueue_ ||
            settings_->queue() == debugQueue_ ||
            settings_->queue() == defaultQueue_)
    {
        settings_->setQueueName(queueName);
    }
}

const char* InfrastructureContainer::getRaceQueueName()
{
    return raceQueue_;
}
const char* InfrastructureContainer::getDisplayQueueName()
{
    return displayQueue_;
}
const char* InfrastructureContainer::getDebugQueueName()
{
    return debugQueue_;
}
const char* InfrastructureContainer::getDefaultQueueName()
{
    return defaultQueue_;
}

I_Settings& InfrastructureContainer::settings()
{
    return *settings_;
}
