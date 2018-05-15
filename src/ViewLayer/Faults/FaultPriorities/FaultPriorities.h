#pragma once

#include <QColor>

namespace FaultPriorities
{
    enum PRIORITY {INVALID_PRIORITY = -1,
                   HIGH_PRIORITY = 0,
                   MEDIUM_PRIORITY = 1,
                   LOW_PRIORITY = 2};

    const QColor HIGH_PRIORITY_COLOR = QColor("#ff0000");     //Red
    const QColor MEDIUM_PRIORITY_COLOR = QColor("#ccbf14");   //Yellow
    const QColor LOW_PRIORITY_COLOR = QColor("#89c2d3");      //Blue
    const QColor DEFAULT_COLOR = QColor("#00000000");         //Black
}
