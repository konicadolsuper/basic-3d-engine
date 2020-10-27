#ifndef RENDER_H
#define RENDER_H

#include "renderer.h"
#include "camera.h"
#include "mesh.h"

#include <QGraphicsItem>
#include <QObject>
#include <QPainter>
#include <QTimer>

class Render : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    explicit Render(Camera &camera, QVector<Mesh> &meshList, QObject *parent = nullptr);

signals:

private slots:
    void nextFrame();

private:
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    QRectF boundingRect() const;

    // View
    QTimer* p_timer;
    QPixmap m_pixmap;
    QImage* p_image;
    Renderer* p_renderer;

    // Model
    Camera& m_camera;
    QVector<Mesh>& m_meshList;

};

#endif // RENDER_H
