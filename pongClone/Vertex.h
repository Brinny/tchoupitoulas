#ifndef VERTEX_H
#define VERTEX_H
#include <GL/freeglut.h>

class Vertex {
    GLfloat _x;
    GLfloat _y;
    public:
        Vertex();
        Vertex(GLfloat x, GLfloat y);
        Vertex operator+(const Vertex&) const;
        Vertex operator-(const Vertex&) const;
        Vertex operator*(const GLfloat&) const;
        GLfloat dot(const Vertex&) const;
        void moveTo(GLfloat x, GLfloat y);
        void moveXTo(GLfloat x);
        void moveYTo(GLfloat y);
        GLfloat getX() { return _x; }
        GLfloat getY() { return _y; }
};

#endif
