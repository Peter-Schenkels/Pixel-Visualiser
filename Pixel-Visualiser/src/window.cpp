#include <GL/glut.h>
#include <Pixel-Visualiser/headers/window.hpp>
#include "Pixel-Visualiser/headers/pixelVisualiser.hpp"


PV::Window::Window(std::string name, const Vector2<int>& size, const Vector2<int>& startPosition):
    name(std::move(name)),
    size(size),
    startPosition(startPosition)
{
}

void PV::Window::display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    // Draw a circle with radius 0.4 at position (0.0, 0.0)
    glColor3f(0.0, 0.0, 1.0);
    drawCircle(0.0, 0.0, 0.4, 10);
    glutSwapBuffers();
}

void PV::Window::start() const
{
    glutInitWindowSize(size.x, size.y);
    glutInitWindowPosition(startPosition.x, startPosition.y);
    glutCreateWindow(name.c_str());
    glClearColor(1.0, 1.0, 1.0, 0.0);
}
