#include <GL/glut.h>
#include <cmath>
#include <iostream>
using namespace std;

void mid_point_circle(int xc, int yc, int r)
{
    int x = 0;
    int y = r;
    int p = 1 - r; // Initial decision parameter

    glBegin(GL_POLYGON);
    while (x <= y)
    {
        // Plot the points in all octants
        glVertex2i(xc + x, yc + y);
        glVertex2i(xc - x, yc + y);
        glVertex2i(xc + x, yc - y);
        glVertex2i(xc - x, yc - y);
        glVertex2i(xc + y, yc + x);
        glVertex2i(xc - y, yc + x);
        glVertex2i(xc + y, yc - x);
        glVertex2i(xc - y, yc - x);

        x++;
        if (p < 0)
        {
            p += 2 * x + 1; // Midpoint is inside the circle
        }
        else
        {
            y--;
            p += 2 * x - 2 * y + 1; // Midpoint is outside or on the circle
        }
    }
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0); // Red color
    mid_point_circle(195, 190, 100);
    glFlush();
}

void init()
{
    glClearColor(0.0, 1.0, 0.0, 1.0); // Black background
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 400, 0, 400); // Coordinate system
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(500, 100);
    glutCreateWindow("Shaheed Minar drawing");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
