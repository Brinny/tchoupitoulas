#include "Vertex.h"

Vertex::Vertex() {
    _x = 0.0;
    _y = 0.0;
}

Vertex::Vertex(GLfloat x, GLfloat y) {
    _x = x;
    _y = y;
}

Vertex Vertex::operator+ (const Vertex &vertex) const {
    Vertex result;
    result._x = this->_x + vertex._x;
    result._y = this->_y + vertex._y;
    return result;
}

Vertex Vertex::operator- (const Vertex &vertex) const {
    Vertex result;
    result._x = this->_x - vertex._x;
    result._y = this->_y - vertex._y;
    return result;
}

Vertex Vertex::operator* (const GLfloat &scalar) const {
    Vertex result;
    result._x = this->_x * scalar;
    result._y = this->_y * scalar;
    return result;
}

GLfloat Vertex::dot(const Vertex &vertex) const {
    GLfloat result;
    GLfloat x = this->_x * vertex._x;
    GLfloat y = this->_y * vertex._y;
    result = x + y;
    return result;
}

void Vertex::moveTo(GLfloat x, GLfloat y) {
    _x = x;
    _y = y;
}

void Vertex::moveXTo(GLfloat x) {
    _x = x;
}

void Vertex::moveYTo(GLfloat y) {
    _y = y;
}

