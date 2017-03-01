#include "DataLayer/DataContainer.h"
#include "CommunicationLayer/CommunicationContainer.h"
#include "BusinessLayer/BusinessContainer.h"
#include "PresenterLayer/PresenterContainer.h"
#include "ViewLayer/ViewContainer.h"

#include <QCommandLineParser>

#include "EpsilonDashboard.h"

EpsilonDashboard::EpsilonDashboard(int& argc, char** argv)
    : QApplication(argc, argv)
    , dataContainer_(new DataContainer())
    , communicationContainer_(new CommunicationContainer())
    , businessContainer_(new BusinessContainer(*communicationContainer_, *dataContainer_))
    , presenterContainer_(new PresenterContainer(*dataContainer_))
{
    char mode = parseCommandLineArgs();
    viewContainer_.reset(new ViewContainer(*presenterContainer_, mode));
}

EpsilonDashboard::~EpsilonDashboard()
{
}

char EpsilonDashboard::parseCommandLineArgs()
{
    //This function returns 'd' for display mode and 'r' for race mode
    //The default mode is display mode
    QCommandLineParser parser;

    QCommandLineOption raceModeOption("r");
    parser.addOption(raceModeOption);

    parser.process(*this);

    char mode = 'd';

    if (parser.isSet(raceModeOption))
    {
        mode = 'r';
    }

    return mode;

}
