#pragma once
#include <algorithm>
#include <functional>
#include <memory>
#include <string>
#include <vector>
#include <GL/glut.h>
#include "vector3.hpp"


namespace PV
{
    class Window;

    const float M_PI = 3.14159265358979323846;
    const int NUM_SQUARES = 64;

    inline void drawSquare(float x, float y, float size) {
        // Calculate the coordinates of the square vertices
        float x1 = x - size / 2;
        float y1 = y - size / 2;
        float x2 = x + size / 2;
        float y2 = y + size / 2;

        // Draw the square using two triangles
        glBegin(GL_TRIANGLES);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(x1, y1);
        glVertex2f(x2, y1);
        glVertex2f(x1, y2);

        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(x1, y2);
        glVertex2f(x2, y1);
        glVertex2f(x2, y2);
        glEnd();
    }

    inline void drawCircle(float x, float y, float radius, int num_segments) {
        for (int i = 0; i < num_segments; i++) {
            float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
            float cx = radius * cosf(theta);
            float cy = radius * sinf(theta);
            drawSquare(x + cx, y + cy, 0.1);
        }
    }

    class PixelVisualiser
    {
    public:
        enum class UpdateMethod
        {
            Continuous,
            GlutEventHandler,
        };

    private:
        static std::vector<std::shared_ptr<Window>> windows;
        static int currentWindow;
        static UpdateMethod updateMethod;

        static void display();
        static void main();
        static void loop();

    public:
        // function to create a window and add to the list of windows
        static void createWindow(const std::string& name, const Vector2<int>& size, const Vector2<int>& startPosition);

        // Start the application
        static void start();
    };
}
