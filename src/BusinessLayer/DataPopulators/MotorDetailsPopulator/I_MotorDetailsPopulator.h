#pragma once

#include <QObject>
#include <QJsonObject>

class I_MotorDetailsPopulator : public QObject
{
    Q_OBJECT

public slots:
    virtual void populateData(const QJsonObject&) = 0;

public:
    virtual ~I_MotorDetailsPopulator() {}
};
