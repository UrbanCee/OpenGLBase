#include "myglwidget.h"

#include <QtDebug>
#include <QOpenGLFunctions_4_0_Core>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QOpenGLShader>
#include <QOpenGLVertexArrayObject>
#include "simpleobjects.h"


MyGLWidget::MyGLWidget(QWidget *parent, Qt::WindowFlags f)
    :QOpenGLWidget(parent,f)
{}

void MyGLWidget::initializeGL()
{
    if (!initializeOpenGLFunctions())
        qDebug() << "Error intializing OpenGL functions";
    RenderObject::initializeOpenGLFunctions();
    glEnable(GL_DEPTH_TEST);
    qDebug() << "OpenGL Version: " << QLatin1String(reinterpret_cast<const char*>(glGetString(GL_VERSION)));

    obj = new SimpleTriangle(this);
    obj->initialize();

    coordSys = new CoordSys(this);
    coordSys->initialize();
}

void MyGLWidget::resizeGL(int w, int h)
{
    Q_UNUSED(w)
    Q_UNUSED(h)
}


void MyGLWidget::paintGL()
{
    glClearColor(0.0,0.0,0.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    coordSys->paint();
    obj->paint();
}
