#include "Pixel-Visualiser/headers/pixelVisualiser.hpp"
#include "Pixel-Visualiser/headers/window.hpp"


std::vector<std::shared_ptr<PV::Window>> PV::PixelVisualiser::windows{};
std::map<int, std::shared_ptr<PV::Buffer>>& PV::PixelVisualiser::buffers()
{
    static std::map<int, std::shared_ptr<PV::Buffer>> map;
    return map;
}

// Declare static members
int PV::PixelVisualiser::currentWindow = 0;
int PV::PixelVisualiser::idCounter = 0;


PV::PixelVisualiser::UpdateMethod PV::PixelVisualiser::updateMethod = UpdateMethod::Continuous;

PV::Window& PV::PixelVisualiser::createWindow(const std::string& name, const Vector2<int>& size,
                                              const Vector2<int>& startPosition)
{
    const auto newWindow = std::make_shared<Window>(name, size, startPosition);
    windows.push_back(newWindow);
    return *newWindow;
}


void PV::drawPixel(const Vector2<float>& pixelSize, const Pixel pixel)
{
    glBegin(GL_TRIANGLES);
    glColor3f(pixel.color.r(), pixel.color.g(), pixel.color.b());
    glVertex2f(pixel.position.x * pixelSize.x, pixel.position.y * pixelSize.y);
    glVertex2f((pixel.position.x + 1) * pixelSize.x, pixel.position.y * pixelSize.y);
    glVertex2f(pixel.position.x * pixelSize.x, (pixel.position.y + 1) * pixelSize.y);
    glColor3f(pixel.color.r(), pixel.color.g(), pixel.color.b());
    glVertex2f(pixel.position.x * pixelSize.x, (pixel.position.y + 1) * pixelSize.y);
    glVertex2f((pixel.position.x + 1) * pixelSize.x, pixel.position.y * pixelSize.y);
    glVertex2f((pixel.position.x + 1) * pixelSize.x, (pixel.position.y + 1) * pixelSize.y);
    glEnd();
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

    // Reschedule display call
    if (updateMethod == UpdateMethod::Continuous)
        glutPostRedisplay();
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
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

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


PV::Buffer& PV::PixelVisualiser::createBuffer(PV::Vector2<int> position, PV::Vector2<int> size, PV::Vector2<float> pixelSize)
{
    idCounter++;
    buffers()[idCounter] = std::make_shared<Buffer>(size, pixelSize, position, idCounter);
    return *buffers()[idCounter];
}
