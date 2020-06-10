#include "simpleobjects.h"

#include <QOpenGLVertexArrayObject>
#include <QOpenGLShaderProgram>
#include <QOpenGLFunctions_4_0_Core>
#include <QOpenGLFunctions>
#include <QOpenGLContext>


SimpleTriangle::SimpleTriangle(QObject *parent)
    :RenderObject(":/res/simple.shader",parent),posBuffer(QOpenGLBuffer::VertexBuffer),colBuffer(QOpenGLBuffer::VertexBuffer)
{}



void SimpleTriangle::initObject()
{
    QVector<QVector2D> coords = {
        {-0.5f,0.0f},
        {0.5f,-0.5f},
        {0.5f,0.5f}
    };
    QVector<QVector3D> colors= {
        {1.0f,0.0f,0.0f},
        {0.0f,1.0f,0.0f},
        {0.0f,0.0f,1.0f}
    };
    posBuffer.setUsagePattern(QOpenGLBuffer::StaticDraw);
    posBuffer.create();
    posBuffer.bind();
    posBuffer.allocate(coords.data(),coords.size()*sizeof (QVector2D));
    program->enableAttributeArray(0);
    program->setAttributeBuffer(0,GL_FLOAT,0,2,sizeof(QVector2D));
    colBuffer.setUsagePattern(QOpenGLBuffer::StaticDraw);
    colBuffer.create();
    colBuffer.bind();
    colBuffer.allocate(colors.data(),colors.size()*sizeof (QVector3D));
    program->enableAttributeArray(1);
    program->setAttributeBuffer(1,GL_FLOAT,0,3,sizeof(QVector3D));
}

void SimpleTriangle::paintObject()
{
    gl->glDrawArrays(GL_TRIANGLES,0,3);
}



CoordSys::CoordSys(QObject *parent)
    :RenderObject(":/res/simple.shader",parent),posBuffer(QOpenGLBuffer::VertexBuffer),colBuffer(QOpenGLBuffer::VertexBuffer),iBuf(QOpenGLBuffer::IndexBuffer)
{}

void CoordSys::initObject()
{
    QVector<QVector3D> coords = {
        {0.0f,0.0f,0.0f},
        {1.0f,0.0f,0.0f},
        {0.0f,1.0f,0.0f},
        {0.0f,0.0f,1.0f}
    };
    QVector<QVector3D> colors = {
        {0.5f,0.5f,0.5f},
        {1.0f,0.0f,0.0f},
        {0.0f,1.0f,0.0f},
        {0.0f,0.0f,1.0f}
    };
    QVector<unsigned int> indices = {
        0,1,0,2,0,3
    };

    posBuffer.setUsagePattern(QOpenGLBuffer::StaticDraw);
    posBuffer.create();
    posBuffer.bind();
    posBuffer.allocate(coords.data(),coords.size()*sizeof (QVector3D));
    program->enableAttributeArray(0);
    program->setAttributeBuffer(0,GL_FLOAT,0,3,sizeof(QVector3D));
    colBuffer.setUsagePattern(QOpenGLBuffer::StaticDraw);
    colBuffer.create();
    colBuffer.bind();
    colBuffer.allocate(colors.data(),colors.size()*sizeof (QVector3D));
    program->enableAttributeArray(1);
    program->setAttributeBuffer(1,GL_FLOAT,0,3,sizeof(QVector3D));
    iBuf.setUsagePattern(QOpenGLBuffer::StaticDraw);
    iBuf.create();
    iBuf.bind();
    iBuf.allocate(indices.data(),sizeof(unsigned int)*indices.size());
}

void CoordSys::paintObject()
{
    //iBuf.bind();
    gl->glDrawElements(GL_LINES,6,GL_UNSIGNED_INT,0);
}
