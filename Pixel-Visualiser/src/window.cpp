#include <GL/glut.h>
#include <Pixel-Visualiser/headers/window.hpp>
#include "Pixel-Visualiser/headers/pixelVisualiser.hpp"



PV::Window::Window(std::string name, const Vector2<int>& size, const Vector2<int>& startPosition):
    name(std::move(name)),
    size(size),
    startPosition(startPosition)
{
}


void PV::Window::display() const
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for (int bufferId : bufferStack)
    {
        const Buffer& buffer = *buffers.at(bufferId);
        const Vector2<float> pixelSize = buffer.getPixelSize();

        const std::vector<Pixel>& pixels = buffer.getPixels();
        for (Pixel pixel: pixels)
        {
            pixel.position += buffer.getPosition();
            drawPixel(pixelSize, pixel);
        }
    }

    glutSwapBuffers();
}

void PV::Window::start() const
{
    glutInitWindowSize(size.x, size.y);
    glutInitWindowPosition(startPosition.x, startPosition.y);
    glutCreateWindow(name.c_str());
    glClearColor(1.0, 1.0, 1.0, 0.0);
}

PV::Buffer& PV::Window::createBuffer(PV::Vector2<int> position, PV::Vector2<int> size, PV::Vector2<float> pixelSize)
{
    idCounter++;
    buffers[idCounter] = std::make_shared<Buffer>(size, pixelSize, position, idCounter);
    return *buffers[idCounter];
}

void PV::Window::focus(const Buffer& buffer)
{
    bufferStack.push_back(buffer.getId());
}
