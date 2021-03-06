#ifndef BALL_H 
#define BALL_H
#include <GL/freeglut.h>
#include <iostream> 
#include <math.h>
#include "Vertex.h"

const int NUM_SEGMENTS = 100;
const int POS = 1;
const int NEG = -1;

class Ball {

    Vertex _vertices[NUM_SEGMENTS];
    Vertex _center; 
    GLfloat _radius;

    GLfloat _xDirection;
    GLfloat _yDirection;

    GLfloat _xSpeed;
    GLfloat _ySpeed;
    
    public:
        Ball(Vertex center, GLfloat radius);

        void move();
        void reset();
        void setXDirection(GLfloat xDirection) { _xDirection = xDirection; }
        void setYDirection(GLfloat yDirection) { _yDirection = yDirection; }
        void increaseXSpeed(GLfloat change)    { _xSpeed = _xSpeed + change; }
        void increaseYSpeed(GLfloat change)    { _ySpeed = _ySpeed + change; }

        Vertex* getVertices()   { return _vertices; }
        Vertex getCenter()      { return _center; }
        GLfloat getRadius()     { return _radius; }
        GLfloat getXDirection() { return _xDirection; }
        GLfloat getYDirection() { return _yDirection; }
        GLfloat size()          { return NUM_SEGMENTS * sizeof(Vertex); }
};

#endif
