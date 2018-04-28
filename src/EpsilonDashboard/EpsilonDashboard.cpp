#include <QCommandLineParser>

#include "../DataLayer/DataContainer.h"
#include "../CommunicationLayer/CommunicationContainer.h"
#include "../BusinessLayer/BusinessContainer.h"
#include "../PresenterLayer/PresenterContainer.h"
#include "../ViewLayer/ViewContainer.h"
#include "../InfrastructureLayer/InfrastructureContainer.h"
#include "EpsilonDashboard.h"

#include <QDebug>
#include <QString>

EpsilonDashboard::EpsilonDashboard(int& argc, char** argv)
    : QApplication(argc, argv)
    , dataContainer_(new DataContainer())
    , businessContainer_(new BusinessContainer(*dataContainer_))
    , presenterContainer_(new PresenterContainer(*dataContainer_))
{
    QCommandLineParser parser;
    QString queueName;
    QCommandLineOption raceModeOption("r");
    QCommandLineOption debugModeOption("d");
    QCommandLineOption queueNameOption("qn", "", "queueName");
    parser.addOption(raceModeOption);
    parser.addOption(debugModeOption);
    parser.addOption(queueNameOption);

    parser.process(*this);
    Mode mode = Mode::DISPLAY;
    queueName = "displayQueue";

    if (parser.isSet(raceModeOption))
    {
        mode = Mode::RACE;
        queueName = "raceQueue";
    }

    if (parser.isSet(debugModeOption))
    {
        mode = Mode::DEBUG;
        queueName = "debugQueue";
    }

    QString queueSpecified = parser.value(queueNameOption);
    if (queueSpecified != ""){
        queueName = queueSpecified;
    }

    infrastructureContainer_.reset(new InfrastructureContainer(queueName));
    viewContainer_.reset(new ViewContainer(*presenterContainer_, mode));
    communicationContainer_.reset(new CommunicationContainer(*businessContainer_, *infrastructureContainer_));
}

EpsilonDashboard::~EpsilonDashboard()
{
}
