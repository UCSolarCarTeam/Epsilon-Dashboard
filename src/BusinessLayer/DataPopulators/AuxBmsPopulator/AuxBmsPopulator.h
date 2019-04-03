#pragma once

#include "I_AuxBmsPopulator.h"
#include <QJsonObject>
class I_AuxBmsData;

class AuxBmsPopulator : public I_AuxBmsPopulator
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
