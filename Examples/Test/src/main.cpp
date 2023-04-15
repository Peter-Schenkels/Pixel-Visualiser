#include <GL/glut.h>
#include <cmath>

const float M_PI = 3.14159265358979323846;
const int NUM_SQUARES = 64;

void drawSquare(float x, float y, float size) {
    // Calculate the coordinates of the square vertices
    float x1 = x - size / 2;
    float y1 = y - size / 2;
    float x2 = x + size / 2;
    float y2 = y + size / 2;

    // Draw the square using two triangles
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x1, y2);

    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(x1, y2);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glEnd();
}

void drawCircle(float x, float y, float radius, int num_segments) {
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float cx = radius * cosf(theta);
        float cy = radius * sinf(theta);
        drawSquare(x + cx, y + cy, 0.1);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw a circle with radius 0.4 at position (0.0, 0.0)
    glColor3f(0.0, 0.0, 1.0);
    drawCircle(0.0, 0.0, 0.4, 10);

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("GLUT Example");
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
