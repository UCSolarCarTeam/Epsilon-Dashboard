#pragma once

#include <QObject>

class I_AuxBmsData;

class AuxBmsPopulator : public QObject
{
    Q_OBJECT
public:
    AuxBmsPopulator(I_AuxBmsData& auxBmsData);
    virtual ~AuxBmsPopulator() {}

public slots:
    void populateData(const QJsonObject&);

private:
    I_AuxBmsData& auxBmsData_;
};
