#include "windows/main_window.h"

namespace QTVR {
    MainWindow* MainWindow::m_singleton = nullptr;

    MainWindow* MainWindow::getInstance() {
        if (m_singleton == nullptr) m_singleton = new MainWindow();
        return m_singleton;
    }

    MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
        m_main_container = new QWidget(this);
        m_main_layout = new QHBoxLayout(m_main_container);


        m_left_camera_viewfinder = new QCameraViewfinder(this);
        m_left_player = new QMediaPlayer(this);
        m_left_player->setVideoOutput(m_left_camera_viewfinder);
        m_left_player->setMedia(QUrl("gst-pipeline: v4l2src device=/dev/video2 ! jpegdec ! xvimagesink name=\"qtvideosink\""));
        m_left_camera_viewfinder->show();
        m_left_player->play();

        m_right_camera_viewfinder = new QCameraViewfinder(this);
        m_right_player = new QMediaPlayer(this);
        m_right_player->setVideoOutput(m_right_camera_viewfinder);
        m_right_player->setMedia(QUrl("gst-pipeline: v4l2src device=/dev/video4 ! jpegdec ! xvimagesink name=\"qtvideosink\""));
        m_right_camera_viewfinder->show();
        m_right_player->play();

        m_main_layout->addWidget(m_left_camera_viewfinder);
        m_main_layout->addWidget(m_right_camera_viewfinder);

        this->setCentralWidget(m_main_container);
    }

    MainWindow::~MainWindow() {
        // NOP
    }

} // Namespace QTVR
