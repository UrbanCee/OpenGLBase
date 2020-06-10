#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions_4_0_Core>
#include <QOpenGLBuffer>

#include "renderobject.h"

QT_FORWARD_DECLARE_CLASS(QOpenGLBuffer)
QT_FORWARD_DECLARE_CLASS(QOpenGLVertexArrayObject)
QT_FORWARD_DECLARE_CLASS(QOpenGLShaderProgram)


class MyGLWidget : public QOpenGLWidget, protected QOpenGLFunctions_4_0_Core
{
    Q_OBJECT
private:
    RenderObject *obj, *coordSys;
public:
    MyGLWidget(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
};

#endif // MYGLWIDGET_H
