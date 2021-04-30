// Qt
#include <QMainWindow>

#include <QHBoxLayout>
#include <QWidget>

#include <QCamera>
#include <QCameraViewfinder>
#include <QMediaPlayer>


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

            // Camera handles
            //QCamera* m_left_camera;
            //QCamera* m_right_camera;

            // Player handles
            QMediaPlayer* m_left_player;
            QMediaPlayer* m_right_player;

            // Main widget
            QWidget* m_main_container;

            // Camera viewer widgets
            QCameraViewfinder* m_left_camera_viewfinder;
            QCameraViewfinder* m_right_camera_viewfinder;

            // Layouts
            QHBoxLayout* m_main_layout;
    };
} // Namespace QTVR
