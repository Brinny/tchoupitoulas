#ifndef PONG_H
#define PONG_H

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/freeglut_ext.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include "FreeImage.h"
#include "Utilities.h"
#include "Vertex.h"
#include "Ball.h"
#include "Paddle.h"

const int NUM_PADDLE_VERTICES = 6;
const int NUM_KEYS = 258;
const int NUM_DIGITS = 10;
const int UP_KEY = 256;
const int DOWN_KEY = 257;

const GLfloat ERROR = 0.01;
const GLfloat PADDLE_SPEED = 0.002;
const GLfloat X_INCREMENT = 0.00001;
const GLfloat Y_INCREMENT = 0.00001;

#endif 
