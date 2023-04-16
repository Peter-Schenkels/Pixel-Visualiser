#include <iostream>
#include <headers/pixelVisualiser.hpp>

#include "headers/window.hpp"


static PV::Window& window1 = PV::PixelVisualiser::createWindow("Hello", { 500, 500 }, { 100, 100 });
static PV::Window& window2 = PV::PixelVisualiser::createWindow("World", { 500, 500 }, { 300, 300 });

static PV::Buffer& buffer1 = window1.createBuffer({ 0, 0 }, { 0.05f, 0.05f });
static PV::Buffer& buffer2 = window2.createBuffer({ 0, 10 }, { 0.05f,0.05f});



void PV::PixelVisualiser::loop()
{
    window1.clear();
    window2.clear();

    drawRectangleBorders(buffer1, {10, 20}, {1, 1, 0});
    drawRectangleBorders(buffer2, {10, 10 }, { 1, 0, 1 });

    window1.draw(buffer1);
    window2.draw(buffer2);
}

void PV::PixelVisualiser::drawRectangleBorders(const Buffer& buffer, Vector2<int> size, Color color)
{
    for (int x = 0; x < size.x; ++x)
    {
        for (int y = 0; y < size.y; ++y)
        {
            if (x == 0 || y == 0 || x == size.x - 1 || y == size.y - 1)
            {
                buffer.drawPixel({ color, {x, y} });
            }
        }
    }
}

void PV::PixelVisualiser::main()
{
    std::cout << "Hello World";
}

int main(int argc, char** argv)
{
    PV::PixelVisualiser::start();
    return 0;
}
