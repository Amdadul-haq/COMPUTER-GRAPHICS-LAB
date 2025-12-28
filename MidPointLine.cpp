#include <GL/glut.h>
#include <cmath>
#include <iostream>
using namespace std;

// Plot a single pixel at (x, y)
static inline void plot(int x, int y)
{
    glVertex2i(x, y);
}

// Midpoint (Bresenham) line drawing algorithm supporting all octants
void mid_point_line(int x0, int y0, int x1, int y1)
{
    // Begin plotting points
    glBegin(GL_POINTS);

    int dx = x1 - x0;
    int dy = y1 - y0;

    int absDx = std::abs(dx);
    int absDy = std::abs(dy);

    // Handle gentle slopes (|m| <= 1)
    if (absDy <= absDx)
    {
        // Ensure we iterate left-to-right in x
        int xStart = x0, yStart = y0;
        int xEnd = x1, yEnd = y1;
        if (xStart > xEnd)
        {
            std::swap(xStart, xEnd);
            std::swap(yStart, yEnd);
            dx = xEnd - xStart;
            dy = yEnd - yStart;
            absDx = std::abs(dx);
            absDy = std::abs(dy);
        }

        int y = yStart;
        int yStep = (dy >= 0) ? 1 : -1;
        int d = 2 * absDy - absDx; // initial decision parameter

        for (int x = xStart; x <= xEnd; ++x)
        {
            plot(x, y);
            if (d > 0)
            {
                y += yStep;
                d += 2 * (absDy - absDx);
            }
            else
            {
                d += 2 * absDy;
            }
        }
    }
    else // Steep slopes (|m| > 1): iterate over y
    {
        // Ensure we iterate bottom-to-top in y
        int xStart = x0, yStart = y0;
        int xEnd = x1, yEnd = y1;
        if (yStart > yEnd)
        {
            std::swap(xStart, xEnd);
            std::swap(yStart, yEnd);
            dx = xEnd - xStart;
            dy = yEnd - yStart;
            absDx = std::abs(dx);
            absDy = std::abs(dy);
        }

        int x = xStart;
        int xStep = (dx >= 0) ? 1 : -1;
        int d = 2 * absDx - absDy; // initial decision parameter

        for (int y = yStart; y <= yEnd; ++y)
        {
            plot(x, y);
            if (d > 0)
            {
                x += xStep;
                d += 2 * (absDx - absDy);
            }
            else
            {
                d += 2 * absDx;
            }
        }
    }

    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw a few sample lines using midpoint algorithm
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    mid_point_line(50, 50, 350, 300);     // gentle positive slope

    glColor3f(0.0f, 0.0f, 1.0f); // Blue
    mid_point_line(350, 350, 50, 150);    // gentle negative slope (right-to-left)

    glColor3f(0.0f, 0.5f, 0.0f); // Green
    mid_point_line(100, 350, 120, 50);    // steep positive slope

    glColor3f(0.7f, 0.0f, 0.7f); // Purple
    mid_point_line(300, 100, 100, 350);   // steep negative slope

    glFlush();
}

void init()
{
    glClearColor(0.0f, 1.0f, 0.0f, 1.0f); // background
    glPointSize(1.0f);
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
    glutCreateWindow("Midpoint Line Drawing");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
