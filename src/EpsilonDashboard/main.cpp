#include "EpsilonDashboard.h"
#include <QApplication>
#include <QMessageBox>
#include <QSystemSemaphore>

int main(int argc, char* argv[])
{
    QSystemSemaphore sema("epsilonDashboardSemaphore", 1);
    sema.acquire();

    // on linux/unix shared memory is not freed upon crash
    // so if there is any trash from previous instance, clean it
    QSharedMemory nix_fix_shmem("epsilonDashboardSharedMem");
    if(nix_fix_shmem.attach()){
        nix_fix_shmem.detach();
    }

    QSharedMemory shmem("epsilonDashboardSharedMem");
    bool is_running;
    if (shmem.attach()){
        is_running = true;
    }else{
        shmem.create(1);
        is_running = false;
    }
    sema.release();

    if(is_running){
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("You already have this app running."
                        "\r\nOnly one instance is allowed.");
        msgBox.exec();
        return 1;
    }

    QScopedPointer<EpsilonDashboard> app;
    app.reset(new EpsilonDashboard(argc, argv));
    return app->exec();
}
