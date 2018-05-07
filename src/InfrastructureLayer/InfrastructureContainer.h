#pragma once

#include <QScopedPointer>
class I_Settings;

class InfrastructureContainer
{
public:
    InfrastructureContainer();
    ~InfrastructureContainer();
    void setQueueName(const char* queueName);
    const char* getRaceQueueName();
    const char* getDisplayQueueName();
    const char* getDebugQueueName();
    const char* getDefaultQueueName();

    I_Settings& settings();

private:
    QScopedPointer<I_Settings> settings_;
    const char* raceQueue_ = "raceQueue";
    const char* displayQueue_ = "displayQueue";
    const char* debugQueue_ = "debugQueue";
    const char* defaultQueue_ = "dashboardQueue";
};
