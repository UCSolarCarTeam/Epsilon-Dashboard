#include "EpsilonDashboard.h"
#include <QApplication>
#include <QDebug>
#include <QSystemSemaphore>
#include <QSharedMemory>

int main(int argc, char* argv[])
{
    QSystemSemaphore sema("epsilonDashboardSemaphore", 1);
    sema.acquire();

    // on linux/unix shared memory is not freed upon crash
    // so if there is any trash from previous instance, clean it
    QSharedMemory nix_fix_shmem("epsilonDashboardSharedMem");

    if (nix_fix_shmem.attach())
    {
        nix_fix_shmem.detach();
    }

    QSharedMemory shmem("epsilonDashboardSharedMem");
    bool is_running;

    if (shmem.attach())
    {
        is_running = true;
    }
    else
    {
        shmem.create(1);
        is_running = false;
    }

    sema.release();

    if (is_running)
    {
        qDebug() << "An instance of dashboard already exists.\nQuitting...\n";
        return 1;
    }
    else
    {
        qDebug() << "No other instance of dashboard exists.\nLaunching dashboard...\n";
    }

    QScopedPointer<EpsilonDashboard> app;
    app.reset(new EpsilonDashboard(argc, argv));
    return app->exec();
}
