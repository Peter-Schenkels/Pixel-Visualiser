#pragma once

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "vector2.hpp"


namespace PV
{
    struct Pixel;
    class Buffer;
    class Window;

    class PixelVisualiser
    {
    public:
        enum class UpdateMethod
        {
            Continuous,
            GlutEventHandler,
        };

    private:
        friend class Window;

        static int bufferIdCounter;
        static std::map<int, std::shared_ptr<Buffer>>& buffers();

        static std::vector<std::shared_ptr<Window>> windows;
        static int currentWindow;
        static UpdateMethod updateMethod;

        static void display();
        static void start();
        static void loop();

        // function for turning a pixel with pixel size into a square in a grid on screen using glut using the correct color
        static void drawPixel(const Vector2<float>& pixelSize, const Pixel& pixel);



    public:
        // function to create a window and add to the list of windows
        static Window& createWindow(const std::string& name, const Vector2<int>& size,
                                    const Vector2<int>& startPosition);

        static [[nodiscard]] Buffer& createBuffer(Vector2<int> position, Vector2<int> size, Vector2<float> pixelSize);

        // Start the application
        static void execute();
    };
}
