#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/freeglut_ext.h>
#include <GL/glut.h>
#include <math.h>

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); //sets background color
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clears buffers
    glColor3f(0.0f, 0.0f, 0.0f); // sets color to black.
    glBegin(GL_LINE_STRIP);
        glVertex2f(0.5f, 0.5f);
        glVertex2f(-0.5f, 0.5f);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.5f, -0.5f);
    glEnd();
    glutSwapBuffers(); // swaps buffers
}

int main(int argc, char **argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutCreateWindow("simple OpenGL example");
    init();
    glutDisplayFunc(display);    
    glutMainLoop();
    return 0;

}
