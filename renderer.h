#ifndef RENDERER_H
#define RENDERER_H

#include "camera.h"
#include "mesh.h"

#include <QColor>
#include <QImage>
#include <QMatrix4x4>
#include <QVector2D>
#include <QVector3D>
#include <QObject>

class Renderer
{
public:
    Renderer();
    void setImage(QImage image);
    QImage getImage() const;
    void clear(const QColor& color);
    void present();
    void putPixel(int x, int y, const QColor& color);
    void drawPoint(const QVector2D& point, const QColor& color);
    void drawLine(const QVector2D& point1, const QVector2D& point2, const QColor& color);
    void render(const Camera& camera, const QVector<Mesh>& meshList);

signals:

private:
    QImage m_image;
    QImage m_backBuffer;
};

#endif // RENDERER_H
