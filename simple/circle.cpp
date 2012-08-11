#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/freeglut_ext.h>
#include <GL/glut.h>
#include <math.h>

int num_lines = 10000;

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); //sets background color
}

void display() {
    float angle;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clears buffers
    glColor3f(0.0f, 0.0f, 0.0f); // sets color to black.
    glBegin(GL_LINE_LOOP);
        for(int i = 0; i < num_lines; i++) {
            angle = i * 2 * M_PI / num_lines;
            glVertex2f(cos(angle)*0.1f, sin(angle)*0.1f);
        }
    glEnd();
    glutSwapBuffers(); // swaps buffers
}

int main(int argc, char **argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutCreateWindow("simple OpenGL example");
    init();
    glutDisplayFunc(display);    
    glutMainLoop();
    return 0;

}
