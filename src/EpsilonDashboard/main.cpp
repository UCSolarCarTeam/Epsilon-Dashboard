#include "EpsilonDashboard.h"
#include <QApplication>

int main(int argc, char* argv[])
{
    QScopedPointer<EpsilonDashboard> app;
    app.reset(new EpsilonDashboard(argc, argv));
    return app->exec();
}
