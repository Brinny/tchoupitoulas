#include "Paddle.h"

/**
 * 0-----2 3   
 * |    / /|
 * |   / / |
 * |  / /  |
 * | / /   |
 * |/ /    |
 * 1 4-----5 
 *
 **/
Paddle::Paddle(GLfloat height, GLfloat width) {
    _topLeftCorner = Vertex(0,0);
    _height = height;
    _width = width;
    GLfloat tlcX = _topLeftCorner.getX();
    GLfloat tlcY = _topLeftCorner.getY();
    _vertices[0] = Vertex(tlcX         , tlcY);
    _vertices[1] = Vertex(tlcX         , tlcY - height);
    _vertices[2] = Vertex(tlcX + width , tlcY);
    _vertices[3] = Vertex(tlcX + width , tlcY);
    _vertices[4] = Vertex(tlcX         , tlcY - height);
    _vertices[5] = Vertex(tlcX + width , tlcY - height);
}

void Paddle::moveVertical(GLfloat change) {
    for(int i = 0; i < 6; i++) {
        _vertices[i].moveYTo(_vertices[i].getY() + change);
    }
    _topLeftCorner.moveYTo(_topLeftCorner.getY() + change);
}

void Paddle::moveHorizontal(GLfloat change) {
    for(int i = 0; i < 6; i++) {
        _vertices[i].moveXTo(_vertices[i].getX() + change);
    }
    _topLeftCorner.moveXTo(_topLeftCorner.getX() + change);
}

void Paddle::moveTo(GLfloat x, GLfloat y) {
    moveVertical(y - _topLeftCorner.getY());
    moveHorizontal(x - _topLeftCorner.getX());
}
