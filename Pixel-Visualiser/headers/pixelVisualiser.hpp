#pragma once
#include <algorithm>
#include <functional>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include <GL/glut.h>

#include "buffer.hpp"
#include "vector3.hpp"


namespace PV
{
    class Buffer;
    class Window;

    const float M_PI = 3.14159265358979323846;
    const int NUM_SQUARES = 64;


    //function for turning a pixel with pixel size into a square in a grid on screen using glut using the correct color
    void drawPixel(const Vector2<float>& pixelSize, const Pixel pixel);

    //function for drawing a circle using squares
    //inline void drawCircleSquares(float x, float y, float radius, int num_segments)
    //{
    //    for (int i = 0; i < num_segments; i++) {
    //        float theta = 2.0f * M_PI * float(i) / float(num_segments);
    //        float cx = radius * cosf(theta);
    //        float cy = radius * sinf(theta);
    //        drawSquare(x + cx, y + cy, 0.1);
    //    }
    //}


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

        static int idCounter;
        static std::map<int, std::shared_ptr<Buffer>>& buffers();

        static std::vector<std::shared_ptr<Window>> windows;
        static int currentWindow;
        static UpdateMethod updateMethod;

        static void display();
        static void start();
        static void loop();


    public:
        // function to create a window and add to the list of windows
        static Window& createWindow(const std::string& name, const Vector2<int>& size,
                                    const Vector2<int>& startPosition);

        static [[nodiscard]] Buffer& createBuffer(Vector2<int> position, Vector2<int> size, Vector2<float> pixelSize);

        // Start the application
        static void execute();
    };
}
