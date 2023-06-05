#include <iostream>
#include <math.h>

#include "headers/pixelVisualiser.hpp"
#include "headers/window.hpp"

// Define window
static PV::Window& window       = PV::PixelVisualiser::createWindow("Colored boxes!", { 500, 500 }, { 100, 100 });

// Define objects drawn in window
static PV::Buffer& box1    = window.createBuffer({ 0,0 }, { 10, 10}, { 0.01f, 0.01f });
static PV::Buffer& box2    = window.createBuffer({ 0,0 }, { 10, 10 }, { 0.01f, 0.01f });
static PV::Buffer& trials       = window.createBuffer({ 0,0 }, { 10, 10 }, { 0.01f, 0.01f });

int8_t pvTimeIn = -122;

int PV::PixelVisualiser::pulse(int input, int speed, int max)
{
    const float sinTime = static_cast<float>(input) / speed;
    const float sinMax = max;
    return sinMax * sinf(sinTime);
}

// Decide what to draw this frame
void PV::PixelVisualiser::loop()
{
    // Set movement speed ratio 1/speed!
    constexpr int speedRatio = 1;

    // Update frame tickNr
    pvTimeIn += 1;

    // Define pos of the boxes
    const auto box1Pos = Vector2(pvTimeIn / speedRatio, pvTimeIn / speedRatio + pulse(pvTimeIn + 20, 10, 23));
    const auto box2Pos = Vector2(pvTimeIn / speedRatio + pulse(pvTimeIn, 100, 30), pulse(pvTimeIn + 20, 10, 23));

    // Set to corresponding positions in absolute coordinates
    box1.setPosition(box1Pos);
    box2.setPosition(box2Pos);

    // Define color for box 1 based on time
    const auto box1Color = Color{box1Pos.x%120 / 30.f,1.f, box1Pos.y % 30 / 30.f };

    // Draw rectangles in the buffer on relative positon zero with size 10x10
    // Note: draws them on absolute position (See set position)
    drawRectangleBorders(box1, {0,0} , {10, 10}, box1Color);
    drawRectangleBorders(box2, { 0,0 }, { 10, 10 }, { 1, 0, 1 });

    // Draw Trials
    // Note: draws them based on relative position
    trials.drawPixel(Pixel(box1Color, box1Pos + Vector2(5, 5)));
    trials.drawPixel(Pixel({ 1,0,1 }, box2Pos + Vector2(5,5)));

    // Clear trials from window/buffer
    if(pvTimeIn == -122)
        trials.clear();

}

void PV::PixelVisualiser::drawRectangleBorders(const Buffer& buffer, Vector2<int> position, Vector2<int> size, Color color)
{
    for (int x = 0; x < size.x; ++x)
    {
        buffer.drawPixel({ color,  Vector2(x, 0) + position });
        buffer.drawPixel({ color,  Vector2(x, size.y-1) + position });
    }

    for (int y = 0; y < size.y; ++y)
    {
        buffer.drawPixel({ color, Vector2(0, y) + position });
        buffer.drawPixel({ color, Vector2(size.x-1, y) + position });
    }
}

void PV::PixelVisualiser::start()
{
    window.focus(box1);
    window.focus(box2);
    window.focus(trials);

    std::cout << "Hello World";
}

int main(int argc, char** argv)
{
    PV::PixelVisualiser::execute();
    return 0;
}
