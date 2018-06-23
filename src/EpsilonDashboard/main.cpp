#include "EpsilonDashboard.h"
#include <QApplication>
#include <QLockFile>
#include <QDebug>
#include <QDir>
#include <QMessageBox>

int main(int argc, char* argv[])
{
    QLockFile lockFile(QDir::temp().absoluteFilePath("epsilonDashboard.lock"));

    /* Trying to close the Lock File, if the attempt is unsuccessful for 100 milliseconds,
     * then there is a Lock File already created by another process.
     * Therefore, we throw a warning and close the program
     */
    lockFile.setStaleLockTime(5000);
    if(!lockFile.tryLock(100)){
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("The application is already running.\n"
                       "Allowed to run only one instance of the application.");
        msgBox.exec();
        return 1;
    }

    QScopedPointer<EpsilonDashboard> app;
    app.reset(new EpsilonDashboard(argc, argv));
    return app->exec();
}
