#pragma once

#include <QObject>
#include "I_AuxBmsPopulator.h"
class I_AuxBmsData;

class AuxBmsPopulator : public I_AuxBmsPopulator
{
    Q_OBJECT
public:
    AuxBmsPopulator(I_AuxBmsData& auxBmsData);
    virtual ~AuxBmsPopulator() {}

public slots:
    virtual void populateData(const QJsonObject&);

private:
    I_AuxBmsData& auxBmsData_;
};
