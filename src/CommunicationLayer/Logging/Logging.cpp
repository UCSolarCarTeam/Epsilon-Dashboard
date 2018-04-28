#include <iostream>

#include <QDebug>
#include <QFile>

#include "Logging.h"

Logging& Logging::instance()
{
    static Logging instance_;
    return instance_;
}


