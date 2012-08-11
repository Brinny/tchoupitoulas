/**
 * Pong clone!
 * Written as an exercise to further study OpenGL.
 * Author: Brittany A.
 **/
#include "pong.h"

using namespace std;

Ball ball(Vertex(0.0f, 0.0f), 0.025f);
Paddle leftPaddle(0.3f, 0.1f);
Paddle rightPaddle(0.3f, 0.1f);
bool keyStates[NUM_KEYS];
GLuint numberTextures[NUM_DIGITS];
GLuint letterTextures[26];

void loadTextures() {
    string file = "../images/digit_";
    for(int texture = 0; texture < NUM_DIGITS; texture++) {
        file.push_back(texture);
        loadTexture(file, texture, numberTextures);
    }

}

void init() {
    glClearColor(0.0f, 0.0f, 1.0f, 0.0f);

    fill_n(keyStates, 258, false);
    loadTextures();
    leftPaddle.moveTo(-0.95, 0.3f);
    rightPaddle.moveTo(0.85, 0.0f);

    GLuint vao;
    glGenVertexArrays( 1, &vao );
    glBindVertexArray( vao );

    GLuint buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, leftPaddle.size() + rightPaddle.size() 
        + ball.size(), NULL, GL_STATIC_DRAW);

    GLuint program = init_shaders( "vshader.glsl", "fshader.glsl" );
    glUseProgram( program );

    GLuint vPosition = glGetAttribLocation( program, "vPosition" );
    glEnableVertexAttribArray( vPosition );
    glVertexAttribPointer( vPosition, 2, GL_FLOAT, GL_FALSE, 0,
                           0);

    glBindVertexArray(vao);
}

void movePaddle(Paddle &paddle, GLfloat change) {
    if(paddle.getMaxY() + change > 1.0f) {
        return;
    }
    if(paddle.getMinY() + change < -1.0f) {
        return;
    }
    paddle.moveVertical(change);
    glutPostRedisplay();
}

bool isCollision(Vertex start, Vertex end, Ball ball) {
    Vertex onLineSegment = end - start;
    Vertex onLineToBall = start - ball.getCenter();
    GLfloat a = onLineSegment.dot(onLineSegment);
    GLfloat b = (onLineToBall * 2).dot(onLineSegment);
    GLfloat c = (onLineToBall.dot(onLineToBall)) - (ball.getRadius() * ball.getRadius());
    GLfloat discriminant = (b * b) - (4 * a * c);
    if(discriminant < 0) {
        return false;
    } else if (discriminant == 0) {
        GLfloat root = -b / (2 * a);
        if(root >= 0 && root <= 1) {
            return true;
        } else {
            return false;
        }
    } else {
        discriminant = sqrt(discriminant);
        GLfloat root1 = (-b + discriminant) / (2 * a);
        GLfloat root2 = (-b - discriminant) / (2 * a);
        if(root1 >= 0 && root1 <= 1 && root2 >= 0 && root2 <= 1) {
            return true;
        } else {
            return false;
        }
    }
}

void checkCollisions() {
    if(isCollision(leftPaddle.getVertex(2), leftPaddle.getVertex(5), ball)) {
        ball.setXDirection(POS);
        ball.increaseXSpeed(X_INCREMENT);
        ball.increaseYSpeed(Y_INCREMENT);
    } else if(isCollision(leftPaddle.getVertex(0), leftPaddle.getVertex(2), ball)) {
        ball.setYDirection(POS);
    } else if(isCollision(leftPaddle.getVertex(1), leftPaddle.getVertex(5), ball)) {
        ball.setYDirection(NEG);
    } else if(isCollision(rightPaddle.getVertex(0), rightPaddle.getVertex(1), ball)) {
        ball.setXDirection(NEG);
        ball.increaseXSpeed(X_INCREMENT);
        ball.increaseYSpeed(Y_INCREMENT);
    } else if(isCollision(rightPaddle.getVertex(0), rightPaddle.getVertex(2), ball)) {
        ball.setYDirection(POS);
    } else if(isCollision(rightPaddle.getVertex(1), rightPaddle.getVertex(5), ball)) {
        ball.setYDirection(NEG);
    } else if(isCollision(Vertex(-1.0, 1.0), Vertex(1.0, 1.0), ball)) {
        ball.setYDirection(NEG);
    } else if(isCollision(Vertex(-1.0, -1.0), Vertex(1.0, -1.0), ball)) {
        ball.setYDirection(POS);
    }
}

void checkWinners() {
    if(isCollision(Vertex(-1.0 - ball.getRadius() * 2, 1.0), 
                   Vertex(-1.0 - ball.getRadius() * 2, -1.0), ball)) {
        ball.reset();
    } else if(isCollision(Vertex(1.0 + ball.getRadius() * 2, 1.0), 
                          Vertex(1.0 + ball.getRadius() * 2, -1.0), ball)) {
        ball.reset();
    }
}

void keyOperations(void) {
    if(keyStates[033]) {
        exit(0);
    }
    if(keyStates['w']) {
        movePaddle(leftPaddle, PADDLE_SPEED);
    }
    if(keyStates['W']) {
        movePaddle(leftPaddle, PADDLE_SPEED);
    }
    if(keyStates['s']) {
        movePaddle(leftPaddle, -PADDLE_SPEED);
    }
    if(keyStates['S']) {
        movePaddle(leftPaddle, -PADDLE_SPEED);
    }
    if(keyStates[UP_KEY]) {
        movePaddle(rightPaddle, PADDLE_SPEED);
    }
    if(keyStates[DOWN_KEY]) {
        movePaddle(rightPaddle, -PADDLE_SPEED);
    }
}

void keyPressed( unsigned char key, int x, int y ) {
    keyStates[key] = true;
    keyOperations();
}

void keyUp( unsigned char key, int x, int y ) {
    keyStates[key] = false;
    keyOperations();
}

void specialPressed( int key, int x, int y ) {
    switch ( key ) {
    case GLUT_KEY_UP: keyStates[UP_KEY] = true; break;
    case GLUT_KEY_DOWN: keyStates[DOWN_KEY] = true; break;
    }
    keyOperations();
}

void specialUp( int key, int x, int y ) {
    switch ( key ) {
    case GLUT_KEY_UP: keyStates[UP_KEY] = false; break;
    case GLUT_KEY_DOWN: keyStates[DOWN_KEY] = false; break;
    }
    keyOperations();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBufferSubData(GL_ARRAY_BUFFER, 0, leftPaddle.size(), leftPaddle.getVertices());
    glBufferSubData(GL_ARRAY_BUFFER, leftPaddle.size(), 
        rightPaddle.size(), rightPaddle.getVertices());
    glBufferSubData(GL_ARRAY_BUFFER, leftPaddle.size() + rightPaddle.size(),
        ball.size(), ball.getVertices());   
    keyOperations();
    glDrawArrays(GL_TRIANGLES, 0, NUM_PADDLE_VERTICES * 2);
    glDrawArrays(GL_POLYGON, NUM_PADDLE_VERTICES * 2, NUM_SEGMENTS);
    glutSwapBuffers();
}

void idle() {
    ball.move();
    checkCollisions();
    checkWinners();
    glutPostRedisplay();
}

int main(int argc, char **argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutCreateWindow("Pong");

    glewInit();
    init();

    glutDisplayFunc(display); 
    glutIdleFunc(idle); 
    glutKeyboardFunc(keyPressed); 
    glutKeyboardUpFunc(keyUp);
    glutSpecialFunc(specialPressed); 
    glutSpecialUpFunc(specialUp);

    glutMainLoop();
    return 0;
}
