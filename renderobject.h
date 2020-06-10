#ifndef RENDEROBJECT_H
#define RENDEROBJECT_H

#include <QString>
#include <QObject>
#include <QOpenGLBuffer>

QT_FORWARD_DECLARE_CLASS(QOpenGLVertexArrayObject)
QT_FORWARD_DECLARE_CLASS(QOpenGLShaderProgram)
QT_FORWARD_DECLARE_CLASS(QOpenGLFunctions_4_0_Core)

class RenderObject : public QObject
{
    Q_OBJECT
protected:
    QOpenGLVertexArrayObject *ao;
    QOpenGLShaderProgram *program;
    static QOpenGLFunctions_4_0_Core *gl;
private:
    QString shaderFile;
public:
    RenderObject(const QString &shaderFile,QObject *parent = nullptr);
    void initialize();
    void paint();
    static void initializeOpenGLFunctions();
protected:
    virtual void initObject()=0;
    virtual void paintObject()=0;
};


#endif // RENDEROBJECT_H
