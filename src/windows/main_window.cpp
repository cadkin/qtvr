#include "windows/main_window.h"

namespace QTVR {
    MainWindow* MainWindow::m_singleton = nullptr;

    MainWindow* MainWindow::getInstance() {
        if (m_singleton == nullptr) m_singleton = new MainWindow();
        return m_singleton;
    }

    MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
        // NOP
    }

    MainWindow::~MainWindow() {
        // NOP
    }

} // Namespace QTVR
