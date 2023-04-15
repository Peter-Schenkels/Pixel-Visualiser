#include "Pixel-Visualiser/headers/pixelVisualiser.hpp"
#include "Pixel-Visualiser/headers/window.hpp"

// Declare static members
int PV::PixelVisualiser::currentWindow = 0;
std::vector<std::shared_ptr<PV::Window>> PV::PixelVisualiser::windows{};
PV::PixelVisualiser::UpdateMethod PV::PixelVisualiser::updateMethod = UpdateMethod::GlutEventHandler;

void PV::PixelVisualiser::createWindow(const std::string& name, const Vector2<int>& size, const Vector2<int>& startPosition)
{
    windows.push_back(std::make_shared<Window>(name, size, startPosition));
}

void PV::PixelVisualiser::display()
{
    loop();

    if(windows.empty())
        return;

    windows[currentWindow]->display();

    // Loop through window count every display update
    currentWindow = (currentWindow + 1) % windows.size();

    // Reschedule display call
    if(updateMethod == UpdateMethod::Continuous)
        glutPostRedisplay();
}

void PV::PixelVisualiser::start()
{
    // Create valid argc and argv variables whch are required by glutInit
    int argc = 0;
    char* argv[] = {0};

    main();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    int i = 'a';

    for (const std::shared_ptr<Window>& window : windows)
    {
        // Initialise the window
        window->start();

        // Link static display function to every window display  GLUT callback
        glutDisplayFunc(display);
    }

    // Start the main loop
    glutMainLoop();
}
