#ifndef PADDLE_H
#define PADDLE_H 
#include <GL/freeglut.h>
#include "Vertex.h"

class Paddle {
    Vertex _vertices[6];
    Vertex _topLeftCorner;
    GLfloat _height;
    GLfloat _width;

    public:
        Paddle(GLfloat height, GLfloat width);
        void moveVertical(GLfloat change);
        void moveHorizontal(GLfloat change);
        void moveTo(GLfloat x, GLfloat y);
        Vertex getVertex(int index) { return _vertices[index]; }
        Vertex* getVertices()  { return _vertices; }
        Vertex getCenter()     { return Vertex(_topLeftCorner.getX() + _width/2,
                                               _topLeftCorner.getY() - _height/2); }
        GLfloat getMaxY()      { return _topLeftCorner.getY(); }
        GLfloat getMinY()      { return _topLeftCorner.getY() - _height; }
        GLfloat getMaxX()      { return _topLeftCorner.getX() + _width; }
        GLfloat getMinX()      { return _topLeftCorner.getX(); }
        GLfloat size()         { return 6 * sizeof(Vertex); }
};

#endif
