#include <GL/glut.h>
#include <cmath>
#include <iostream>
using namespace std;

void DDA(int x0, int y0, int x1, int y1)
{
    int dx = x1 - x0;
    int dy = y1 - y0;

    int steps = max(abs(dx), abs(dy));

    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;

    float x = x0;
    float y = y0;

    glBegin(GL_POINTS);
    for (int i = 0; i <= steps; i++)
    {
        glVertex2i(round(x), round(y));
        x += Xinc;
        y += Yinc;
    }
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw a DDA line from (50,50) to (300,200)
    glColor3f(0.0, 0.0, 1.0); // Blue color
    DDA(50, 50, 300, 200);

    glFlush();
}

void init()
{
    glClearColor(1.0, 1.0, 0.0, 1.0); // Black background
    glColor3f(1.0, 0.0, 1.0);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 400, 0, 400); // Coordinate system
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DDA Line Drawing Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
// g++ dda.cpp -o dda -lfreeglut -lopengl32 -lglu32
// ./dda