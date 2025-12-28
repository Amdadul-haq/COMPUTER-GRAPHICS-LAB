// #include <GL/glut.h>

// void display()
// {
//     glClear(GL_COLOR_BUFFER_BIT);
//     glBegin(GL_POINTS);
//     glVertex2i(0, 0);
//     glEnd();
//     glFlush();
// }

// int main(int argc, char **argv)
// {
//     glutInit(&argc, argv);
//     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//     glutCreateWindow("Test");
//     glutDisplayFunc(display);
//     glutMainLoop();
//     return 0;
// }

#include <GL/glut.h>
#include <cmath>
#include <iostream>
using namespace std;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 0.0); // Black color
    // Draw the base of the house
    glBegin(GL_QUADS);
    // draw the walls
    glColor3f(1.0, 0.0, 0.0); // red color
    glVertex2i(50, 50);
    glVertex2i(350, 50);

    glVertex2i(350, 50);
    glVertex2i(350, 400);

    glVertex2i(350, 400);
    glVertex2i(50, 400);

    glVertex2i(50, 400);
    glVertex2i(50, 50);

    glColor3f(1.0, 0.0, 1.0); // Red color
    // Draw the door
    
    glVertex2i(150, 50);
    glVertex2i(250, 50);

    glVertex2i(250, 50);
    glVertex2i(250, 250);

    glVertex2i(250, 250);
    glVertex2i(150, 250);

    glVertex2i(150, 250);
    glVertex2i(150, 50);

    // draw the window
    glColor3f(0.0, 1.0, 0.0); // Green color
    glVertex2i(75, 125);
    glVertex2i(125, 125);

    glVertex2i(125, 125);
    glVertex2i(125, 175);

    glVertex2i(125, 175);
    glVertex2i(75, 175);

    glVertex2i(75, 175);
    glVertex2i(75, 125);
    // draw the second window

    glVertex2i(275, 125);
    glVertex2i(325, 125);

    glVertex2i(325, 125);
    glVertex2i(325, 175);

    glVertex2i(325, 175);
    glVertex2i(275, 175);

    glVertex2i(275, 175);
    glVertex2i(275, 125);

    // draw the roof
    glColor3f(0.0, 0.0, 1.0); // Orange color
    glVertex2i(200, 480);
    glVertex2i(50, 400);

    // glVertex2i(50, 400);
    // glVertex2i(350, 400);

    glVertex2i(350, 400);
    glVertex2i(200, 480);

    glEnd();

    glFlush();
}

void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0); // Yellow background
    // glColor3f(1.0, 0.0, 1.0);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500); // Coordinate system
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(400, 100);
    glutCreateWindow("Home Building");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
