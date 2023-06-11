#include <GL/glut.h>
#include <iostream>

#include "Pixel-Visualiser/headers/pixelVisualiser.hpp"
#include "Pixel-Visualiser/headers/keyboard.hpp"
#include "Pixel-Visualiser/headers/mouse.hpp"
#include "Pixel-Visualiser/headers/window.hpp"


std::vector<std::shared_ptr<PV::Window>> PV::PixelVisualiser::windows{};

// Declare static members
int PV::PixelVisualiser::currentWindow = 0;
int PV::PixelVisualiser::bufferIdCounter = 0;
uint64_t PV::PixelVisualiser::tick = 0;

PV::PixelVisualiser::UpdateMethod PV::PixelVisualiser::updateMethod = UpdateMethod::Continuous;

// Define a window
// arg[1] = window title
// arg[2] = window size
// arg[3] = window position
PV::Window& PV::PixelVisualiser::createWindow(const std::string& name, const Vector2<int>& size,
                                              const Vector2<int>& startPosition)
{
    const std::shared_ptr<Window> newWindow = std::make_shared<Window>(name, size, startPosition);
    windows.push_back(newWindow);
    return *newWindow;
}

std::map<int, std::shared_ptr<PV::Buffer>>& PV::PixelVisualiser::buffers()
{
    static std::map<int, std::shared_ptr<PV::Buffer>> map;
    return map;
}


void PV::PixelVisualiser::drawPixel(const Vector2<float>& pixelSize, const Pixel& pixel)
{
    glBegin(GL_TRIANGLES);
    glColor3f(pixel.color.r(), pixel.color.g(), pixel.color.b());
    glVertex2i(pixel.position.x * pixelSize.x, pixel.position.y * pixelSize.y);
    glVertex2i((pixel.position.x + 1) * pixelSize.x, pixel.position.y * pixelSize.y);
    glVertex2i(pixel.position.x * pixelSize.x, (pixel.position.y + 1) * pixelSize.y);
    glColor3f(pixel.color.r(), pixel.color.g(), pixel.color.b());
    glVertex2i(pixel.position.x * pixelSize.x, (pixel.position.y + 1) * pixelSize.y);
    glVertex2i((pixel.position.x + 1) * pixelSize.x, pixel.position.y * pixelSize.y);
    glVertex2i((pixel.position.x + 1) * pixelSize.x, (pixel.position.y + 1) * pixelSize.y);
    glEnd();
}

uint64_t PV::PixelVisualiser::getTick()
{
    return tick;
}


void PV::PixelVisualiser::display()
{
    // Call start loop callback
    loop();


    if (!windows.empty())
    {
        windows[currentWindow]->display();
        // Loop through window count every display update
        currentWindow = (currentWindow + 1) % windows.size();
    }

    // Set mouse callback
    glutMouseFunc(Input::Mouse::handleMouseEvents);
    glutPassiveMotionFunc(Input::Mouse::handlePassiveMouseEvents);
    glutKeyboardFunc(Input::Keyboard::handleKeyboardDownEvents);
    glutKeyboardUpFunc(Input::Keyboard::handleKeyboardUpEvents);
    Input::Keyboard::updateKeyboardEvents();

    // Reschedule display call
    if (updateMethod == UpdateMethod::Continuous)
        glutPostRedisplay();

    tick++;
}


void PV::PixelVisualiser::execute()
{
    // Create valid argc and argv variables which are required by glutInit
    int argc = 0;
    char* argv[] = {nullptr};

    // Call start callback
    start();

    // Init glut
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    for (const std::shared_ptr<Window>& window : windows)
    {
        // Initialise the window
        window->start();
        // Link the static display callback to every window GLUT callback
        glutDisplayFunc(display);
    }

    // Start the start loop
    glutMainLoop();
}

// Define a buffer and a window
// arg[1] = position inside window
// arg[2] = dimensions of the buffer in pixels
// arg[3] = size of a single pixel in the buffer
PV::Buffer& PV::PixelVisualiser::createBuffer(PV::Vector2<int> position, PV::Vector2<int> size, PV::Vector2<float> pixelSize)
{
    bufferIdCounter++;
    buffers()[bufferIdCounter] = std::make_shared<Buffer>(size, pixelSize, position, bufferIdCounter);
    return *buffers()[bufferIdCounter];
}
