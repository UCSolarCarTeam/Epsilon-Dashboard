#pragma once

#include <QScopedPointer>
class I_Settings;

class InfrastructureContainer
{
public:
    InfrastructureContainer();
    ~InfrastructureContainer();
    void setQueueName(const char* queueName);

    I_Settings& settings();

private:
    QScopedPointer<I_Settings> settings_;
};
