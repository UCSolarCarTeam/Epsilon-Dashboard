#include "DataLayer/DataContainer.h"
#include "CommunicationLayer/CommunicationContainer.h"
#include "BusinessLayer/BusinessContainer.h"
#include "PresenterLayer/PresenterContainer.h"
#include "ViewLayer/ViewContainer.h"

#include "EpsilonDashboard.h"

EpsilonDashboard::EpsilonDashboard(int& argc, char** argv)
    : QApplication(argc, argv)
    , dataContainer_(new DataContainer())
    , communicationContainer_(new CommunicationContainer())
    , businessContainer_(new BusinessContainer(*communicationContainer_, *dataContainer_))
    , presenterContainer_(new PresenterContainer(*dataContainer_))
{
    viewContainer_.reset(new ViewContainer(*presenterContainer_, 1);
    parseCommandLineArgs(argc, argv);
}

EpsilonDashboard::~EpsilonDashboard()
{
}

void Gen5Dashboard::parseCommandLineArgs(int &argc, char **argv)
{
    if(argc == 1)
    {
        qDebug() << "Running in default mode";
    }
    else if(argc == 2)
    {
        qDebug() << "The second argument is";
        if(QString(argv[1]) == "-d")
            qDebug() << "-d";
    }
    else
    {
        qDebug() << "Invalid number of arguments";
    }
}
