#include "Ball.h"
using namespace std;

Ball::Ball(Vertex center, GLfloat radius) {
    _center = center;
    _radius = radius;
    _xDirection = POS;
    _yDirection = POS;
    _xSpeed = 0.0005;
    _ySpeed = 0.0005;
    
    GLfloat theta = 2.0f * M_PI / GLfloat(NUM_SEGMENTS);
    GLfloat tangetial_factor = tanf(theta);
    GLfloat radial_factor = cosf(theta);
    GLfloat x = _radius;
    GLfloat y = 0;

    for(int segment = 0; segment < NUM_SEGMENTS; segment++) {
        _vertices[segment] = Vertex(x + _center.getX(), y + _center.getY());
        GLfloat tx = -y; 
        GLfloat ty = x;

        x += tx * tangetial_factor;
        y += ty * tangetial_factor;

        x *= radial_factor;
        y *= radial_factor;
    }
}

void Ball::move() {
    _center.moveTo(_center.getX() + _xDirection * _xSpeed,
                   _center.getY() + _yDirection * _ySpeed);
    for(int i = 0; i < NUM_SEGMENTS; i++) {
        _vertices[i].moveTo(_vertices[i].getX() + _xDirection * _xSpeed,
                            _vertices[i].getY() + _yDirection * _ySpeed);
    }
}

void Ball::reset() {
    GLfloat xDistance = _center.getX();
    GLfloat yDistance = _center.getY();
    cout << "reset: x = " << xDistance << ", y = " << yDistance << endl;
    _center.moveTo(0.0, 0.0);
    for(int i = 0; i < NUM_SEGMENTS; i++) {
        _vertices[i].moveTo(_vertices[i].getX() - xDistance,
                            _vertices[i].getY() - yDistance);
    }
    this->_xSpeed = 0.0005;
    this->_ySpeed = 0.0005;
}
