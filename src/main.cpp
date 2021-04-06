#include <QApplication>

// Local
#include "windows/main_window.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    // Get the instance of the main window and show it.
    QTVR::MainWindow* w = QTVR::MainWindow::getInstance();
    w->show();

    int ret = a.exec();
    delete w;

    return ret;
}
