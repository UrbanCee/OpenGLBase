#include "renderobject.h"

#include <QFile>
#include <QPair>
#include <QFile>
#include <QTextStream>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLFunctions_4_0_Core>
#include <QOpenGLContext>

QOpenGLFunctions_4_0_Core *RenderObject::gl=nullptr;


QPair<QString,QString> parseShader(QString filename)
{
    QStringList shaders{QString(), QString()};
    enum class shaderType {NO_TYPE=-1,VERTEX=0,FRAGMENT=1} type = shaderType::NO_TYPE;
    QFile shaderFile(filename);
    shaderFile.open(QFile::ReadOnly | QFile::Text);
    QTextStream shaderStream(&shaderFile);
    while(!shaderStream.atEnd())
    {
        QString line = shaderStream.readLine().append("\n");
        if (line.startsWith("#shader"))
        {
            if (line.toLower().contains("vertex"))
                type=shaderType::VERTEX;
            else if (line.toLower().contains("fragment"))
                type=shaderType::FRAGMENT;
            else
                type=shaderType::NO_TYPE;
        }else{
            if ((int)type>=0)
            {
                shaders[(int)type].append(line);
            }
        }
    }
    return QPair<QString,QString>(shaders.at(0),shaders.at(1));
}


RenderObject::RenderObject(const QString &shaderFile,QObject *parent)
    :QObject(parent),ao(nullptr),program(nullptr),shaderFile(shaderFile)
{}


void RenderObject::initialize()
{
    auto shaders = parseShader(shaderFile);
    program = new QOpenGLShaderProgram(this);
    program->addShaderFromSourceCode(QOpenGLShader::Vertex,shaders.first);
    program->addShaderFromSourceCode(QOpenGLShader::Fragment,shaders.second);
    program->link();
    program->bind();
    if (!program->log().isEmpty())
        qDebug() << program->log();
    this->ao = new QOpenGLVertexArrayObject(this);
    ao->create();
    ao->bind();
    initObject();
    ao->release();
    program->release();
}

void RenderObject::paint()
{

    program->bind();
    ao->bind();
    paintObject();
    ao->release();
    program->release();
}

void RenderObject::initializeOpenGLFunctions()
{
    gl=QOpenGLContext::currentContext()->versionFunctions<QOpenGLFunctions_4_0_Core>();
}


