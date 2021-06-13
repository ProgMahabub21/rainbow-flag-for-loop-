#include <windows.h>  // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */

struct color
{
    int r;
    int g;
    int b;
};

void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
    glLineWidth(12);

    //colors
    struct color colors[7] = {{0, 255, 0},
                              {0, 255, 255},
                              {0, 0, 255},
                              {191, 0, 255},
                              {255, 255, 0},
                              {255, 255, 0},
                              {255, 0, 0}};

    // Draw a Red 1x1 Square centered at origin
    glBegin(GL_QUADS); // Each set of 4 vertices form a quad
    for (int i = 0; i < 7; i++)
    {
        glColor3ub(colors[i].r, colors[i].g, colors[i].b); //rgb color code
        glVertex2i(0, (700 - (i * 100)));                  // x, y
        glVertex2i(500, (700 - (i * 100)));                // x, y
        glVertex2i(500, (600 - (i * 100)));
        glVertex2i(0, (600 - (i * 100)));
    }

    glEnd();

    glFlush(); // Render now
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char **argv)
{
    glutInit(&argc, argv);            // Initialize GLUT
    glutInitWindowSize(1080, 600);    // Set the window's initial width & height
    glutCreateWindow("Rainbow flag"); // Create a window with the given title
    gluOrtho2D(-1000.0, 1000.0, -1000.0, 1000.0);
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop();           // Enter the event-processing loop
    return 0;
}
