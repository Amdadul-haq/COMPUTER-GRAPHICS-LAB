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
    //first shiri
    glBegin(GL_QUADS);
    glColor3f(0.396, 0.263, 0.129); // Brown color
    glVertex2i(390, 10);
    glVertex2i(10,10);
    glVertex2i(10, 20);
    glVertex2i(390, 20);
    glEnd();

    //second shiri
    glBegin(GL_QUADS);
    glColor3f(0.710, 0.396, 0.114); // Brown color
    glVertex2i(385, 20);
    glVertex2i(15, 20);
    glVertex2i(15, 30);
    glVertex2i(385, 30);
    glEnd();

    //third shiri
    glBegin(GL_QUADS);
    glColor3f(0.588, 0.294, 0.196); // Brown color
    glVertex2i(380, 30);
    glVertex2i(20, 30);
    glVertex2i(20, 40);
    glVertex2i(380, 40);
    glEnd();

    //main pillar 1st
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3); //dark grey color
    glVertex2i(190, 40);
    glVertex2i(200, 40);
    glVertex2i(200, 250);
    glVertex2i(190, 250);
    glEnd();

    //drawing circle on top of main pillar 1st
    glColor3f(1.0, 0.0, 0.0); // Red color
    mid_point_circle(195, 190, 33);
    

    //main pillar 2nd(left)
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3); // dark grey color
    glVertex2i(170, 40);
    glVertex2i(180, 40);
    glVertex2i(180, 250);
    glVertex2i(170, 250);
    glEnd();

    //main pillar 3rd(right)
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3); // dark grey color
    glVertex2i(210, 40);
    glVertex2i(220, 40);
    glVertex2i(220, 250);
    glVertex2i(210, 250);
    glEnd();

    //upper part of main pillar (right)
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3); // Dark Grey color
    glVertex2i(210, 250);
    glVertex2i(220, 250);
    glVertex2i(240, 320);
    glVertex2i(230, 320);



    //upper part of main(middle)
    glVertex2i(190, 250);
    glVertex2i(200, 250);
    glVertex2i(200, 320);
    glVertex2i(190, 320);
    //upper part of main(left)
    glVertex2i(180, 250);
    glVertex2i(170, 250);
    glVertex2i(150, 320);
    glVertex2i(160, 320);

    //extra rectangle in the top of all pillars
    glVertex2i(150, 320);
    glVertex2i(240, 320);
    glVertex2i(240, 330);
    glVertex2i(150, 330);
    glEnd();

    //left side rectangle of main 3 pillars
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3); // Dark Grey color
    glVertex2i(150, 40);
    glVertex2i(160, 40);
    glVertex2i(160, 200);
    glVertex2i(150, 200);

    glVertex2i(120, 40);
    glVertex2i(130, 40);
    glVertex2i(130, 200);
    glVertex2i(120, 200);

    glVertex2i(120, 200);
    glVertex2i(160, 200);
    glVertex2i(160, 220);
    glVertex2i(120, 220);

    glEnd();

    //right side rectangle of main 3 pillars
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3); // Dark Grey color
    glVertex2i(230, 40);
    glVertex2i(240, 40);
    glVertex2i(240, 200);
    glVertex2i(230, 200);

    glVertex2i(260, 40);
    glVertex2i(270, 40);
    glVertex2i(270, 200);
    glVertex2i(260, 200);

    glVertex2i(230, 200);
    glVertex2i(270, 200);
    glVertex2i(270, 220);
    glVertex2i(230, 220);
    glEnd();

    //left side another smaller rectangle 
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3); // Dark Grey color
    glVertex2i(100, 40);
    glVertex2i(110, 40);
    glVertex2i(110, 160);
    glVertex2i(100, 160);

    glVertex2i(70, 40);
    glVertex2i(80, 40);
    glVertex2i(80, 160);
    glVertex2i(70, 160);

    glVertex2i(70, 160);
    glVertex2i(110, 160);
    glVertex2i(110, 180);
    glVertex2i(70, 180);
    glEnd();



    //right side another smaller rectangle
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3); // Dark Grey color
    glVertex2i(280, 40);
    glVertex2i(290, 40);
    glVertex2i(290, 160);
    glVertex2i(280, 160);

    glVertex2i(310, 40);
    glVertex2i(320, 40);
    glVertex2i(320, 160);
    glVertex2i(310, 160);

    glVertex2i(280, 160);
    glVertex2i(320, 160);
    glVertex2i(320, 180);
    glVertex2i(280, 180);
    glEnd();

    glFlush();
}

void init()
{
    glClearColor(0.0, 1.0, 0.0, 1.0); // Black background
    // glColor3f(1.0, 0.0, 1.0);
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
