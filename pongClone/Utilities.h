#ifndef UTILITIES_H
#define UTILITIES_H

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/freeglut_ext.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <IL/il.h>
#include <IL/ilu.h>

GLuint init_shaders(const char* vertex_shader, const char* fragment_shader);
void loadTexture(const char* fileName, int count, GLuint* textures);
#endif
