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
    char mode = parseCommandLineArgs(argc, argv);
    viewContainer_.reset(new ViewContainer(*presenterContainer_, mode));
}

EpsilonDashboard::~EpsilonDashboard()
{
}

char Gen5Dashboard::parseCommandLineArgs(int &argc, char **argv)
{
    //This function returns 'd' for display mode and 'r' for race mode
    //The default mode is display mode
    if(argc == 2)
    {
        if(QString(argv[1]) == "-d" || QString(argv[1]) == "-D")
            return 'd';
        if(QString(argv[1]) == "-r" || QString(argv[1]) == "-R")
            return 'r';
    }
    return 'd';
}
