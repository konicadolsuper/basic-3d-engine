#include "loader.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <QImage>
#include <QGraphicsPixmapItem>
#include <QString>
#include <QtCore>
#include <QThread>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    qDebug("MainWindow");

    // Model
    p_camera = new Camera();
    p_camera->setTarget(QVector3D(0, 0, 0));
    p_camera->setPosition(QVector3D(10, 3, 5));
    p_camera->setDirection(QVector3D(0, -1, 0));
    Loader::load(m_meshList);

    // View
    // UI
    ui->setupUi(this);

    // scene, render
    p_scene = new QGraphicsScene(this);
    ui->mainView->setScene(p_scene);
    p_render = new Render(*p_camera, m_meshList, this);
    p_scene->addItem(p_render);

//    p_pixmapItem = new QGraphicsPixmapItem();
//    p_pixmap = new QPixmap(640, 480);
//    p_pixmapItem->setPixmap(*p_pixmap);
//    p_scene->addItem(p_pixmapItem);
//    ui->mainView->update();

    // renderer
//    p_image = new QImage(640, 480, QImage::Format_ARGB32);
//    p_renderer = new Renderer();
//    p_renderer->setImage(*p_image); // TODO move width, height, format to the constructor
//    p_renderer->clear(Qt::black);

    // Thread
//    p_thread = new QThread;
//    p_modelLoop = new ModelLoop(*p_camera, m_meshList);
//    p_modelLoop->moveToThread(p_thread);
//    connect(p_thread, &QThread::started, p_modelLoop, &ModelLoop::start);
//    connect(p_thread, &QThread::finished, p_thread, &QObject::deleteLater);
//    p_thread->start();
}

MainWindow::~MainWindow()
{
    qDebug("~MainWindow");

    // Thread
//    p_modelLoop->stop();
//    p_thread->quit();
//    p_thread->wait();
//    delete p_modelLoop;
//    delete p_thread;

    // Model
    delete p_camera;
//    delete p_renderer;

    // View
    delete ui;
//    delete p_image;
//    delete p_scene;
    delete p_render;
}
