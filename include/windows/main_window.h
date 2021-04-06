#include <QMainWindow>

namespace QTVR {

    // Get instance shortcut.
    #define MWIN MainWindow::getInstance()

    class MainWindow: public QMainWindow {
        Q_OBJECT

        public:
            // Singleton get instance.
            static MainWindow* getInstance();

            // Destructor
            ~MainWindow();

        private:
            // Constructor
            explicit MainWindow(QWidget* parent = nullptr);

            // Singleton pointer (not smart to avoid double free).
            static MainWindow* m_singleton;
    };
} // Namespace QTVR
