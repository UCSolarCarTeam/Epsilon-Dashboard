#include "Cmu.h"

Cmu::Cmu()
{
}

Cmu::~Cmu()
{
}

QList<double> Cmu::voltages() const
{
    return voltages_;
}
double Cmu::pcbTemp() const
{
    return pcbTemp_;
}
QList<double> Cmu::cellTemps() const
{
    return cellTemps_;
}

void Cmu::setVoltages(QList<double> voltages)
{
    voltages_ = voltages;
}
void Cmu::setPcbTemp(double pcbTemp)
{
    pcbTemp_ = pcbTemp;
}
void Cmu::setCellTemps(QList<double> cellTemps)
{
    cellTemps_ = cellTemps;
}