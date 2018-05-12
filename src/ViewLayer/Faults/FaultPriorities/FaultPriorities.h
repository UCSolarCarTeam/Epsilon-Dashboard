#pragma once

#include <QColor>

namespace FaultPriorities
{
    enum PRIORITY {HIGH_PRIORITY, MEDIUM_PRIORITY, LOW_PRIORITY};

    const QColor HIGH_PRIORITY_COLOR = QColor("#ff0000");     //Red
    const QColor MEDIUM_PRIORITY_COLOR = QColor("#ccbf14");   //Yellow
    const QColor LOW_PRIORITY_COLOR = QColor("#89c2d3");      //Blue
}
