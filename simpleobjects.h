#ifndef SIMPLEOBJECTS_H
#define SIMPLEOBJECTS_H

#include "renderobject.h"

class SimpleTriangle : public RenderObject
{
    Q_OBJECT
private:
    QOpenGLBuffer posBuffer,colBuffer;
public:
    SimpleTriangle(QObject *parent = nullptr);
protected:
    virtual void initObject();
    virtual void paintObject();

};

class CoordSys : public RenderObject
{
private:
    QOpenGLBuffer posBuffer,colBuffer,iBuf;
public:
    CoordSys(QObject *parent = nullptr);
protected:
    virtual void initObject();
    virtual void paintObject();

};

#endif // SIMPLEOBJECTS_H
