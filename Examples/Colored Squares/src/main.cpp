#include "headers/pixelVisualiser.hpp"
#include "headers/window.hpp"


static PV::Buffer& box1      = PV::PixelVisualiser::createBuffer({ 0,0 }, { 10, 10 }, { 2, 2 });
static PV::Buffer& box2      = PV::PixelVisualiser::createBuffer({ 0,0 }, { 10, 10 }, { 2, 2 });
static PV::Buffer& box3      = PV::PixelVisualiser::createBuffer({ 0,0 }, { 10, 10 }, { 2, 2 });
static PV::Buffer& box4      = PV::PixelVisualiser::createBuffer({ 0,0 }, { 10, 10 }, { 2, 2 });
static PV::Buffer& boxShared = PV::PixelVisualiser::createBuffer({ 0,0 }, { 10, 10 }, { 2, 2 });

static PV::Buffer& trials1   = PV::PixelVisualiser::createBuffer({ 0,0 }, { 10, 10 }, { 2, 2 });
static PV::Buffer& trials2   = PV::PixelVisualiser::createBuffer({ 0,0 }, { 10, 10 }, { 2, 2 });

// Define window
static PV::Window& window1   = PV::PixelVisualiser::createWindow("Colored boxes 1!", { 500, 500 }, { 100, 100 });
static PV::Window& window2   = PV::PixelVisualiser::createWindow("Colored boxes 2!", { 500, 500 }, { 600, 100 });

// Is run after calling PV::Execute
void PV::PixelVisualiser::start()
{
    // Add all rendering buffers inside the window
    window1.focus(box1);
    window1.focus(box2);
    window2.focus(box3);
    window2.focus(box4);
    window1.focus(trials1);
    window2.focus(trials2);

    // Add buffer which is shared between windows.
    window1.focus(boxShared);
    window2.focus(boxShared);
}


int main()
{
    // Run visualiser loop
    PV::PixelVisualiser::execute();
    return 0;
}


static int pulse(const int input, const int speed, const int max)
{
    const float sinTime = static_cast<float>(input) / speed;
    const float sinMax = max;
    return sinf(sinTime) * sinMax;
}


static void drawRectangleBorders(const PV::Buffer& buffer, const PV::Vector2<int>& position,
                                 const PV::Vector2<int>& size, const PV::Color& color)
{
    for (int x = 0; x < size.x; ++x)
    {
        buffer.drawPixel({ color, PV::Vector2(x, 0) + position });
        buffer.drawPixel({ color, PV::Vector2(x, size.y - 1) + position });
    }

    for (int y = 0; y < size.y; ++y)
    {
        buffer.drawPixel({ color, PV::Vector2(0, y) + position });
        buffer.drawPixel({ color, PV::Vector2(size.x - 1, y) + position });
    }
}

// Decide what to draw this frame
void PV::PixelVisualiser::loop()
{
    // Clear buffers this frame
    box1.clear();
    box2.clear();
    box3.clear();
    box4.clear();
    boxShared.clear();

    // Set movement speed ratio 1/speed!
    constexpr int speedRatio = 1;

    // Update frame tickNr
    int tickPos = PV::PixelVisualiser::getTick() % 300;

    // Define pos of the boxes
    const auto box1Pos = Vector2(tickPos / speedRatio, tickPos / speedRatio + pulse(tickPos + 20, 10, 23));
    const auto box2Pos = Vector2(tickPos / speedRatio + pulse(tickPos, 100, 30), pulse(tickPos + 20, 10, 23) + 30);
    const auto box3Pos = Vector2(tickPos / speedRatio + pulse(tickPos, 100, 30),  pulse(tickPos + 40, 30, 12) + 30);
    const auto box4Pos = Vector2(tickPos / speedRatio + pulse(tickPos, 100, 30), tickPos / speedRatio + pulse(tickPos + 50, 20, 33) + 30);
    const auto boxSharedPos = Vector2(tickPos / speedRatio, tickPos / speedRatio);

    // Set to corresponding positions in absolute coordinates
    box1.setPosition(box1Pos);
    box2.setPosition(box2Pos);
    box3.setPosition(box3Pos);
    box4.setPosition(box4Pos);
    boxShared.setPosition(boxSharedPos);

    // Define color for box 1 based on time
    const auto box1Color     = Color{box1Pos.x%120 / 30.f,1.f, box1Pos.y % 30 / 30.f };
    constexpr auto box2Color = Color{ 1, 0, 1 };
    constexpr auto box3Color = Color{ 0, 0, 1 };
    constexpr auto box4Color = Color{ 0, 1, 1 };
    constexpr auto boxSharedColor = Color{ 1, 1, 1 };

    // Draw rectangles in the buffer on relative positon zero with size 10x10
    // Note: draws them on absolute position (See set position)
    drawRectangleBorders(box1, {0,0} , {10, 10}, box1Color);
    drawRectangleBorders(box2, {0,0} , {10, 10}, box2Color);
    drawRectangleBorders(box3, {0,0} , {10, 10}, box3Color);
    drawRectangleBorders(box4, {0,0} , {10, 10}, box4Color);
    drawRectangleBorders(boxShared, {0,0} , {10, 10}, boxSharedColor);

    // Draw Trials
    // Note: draws them based on relative position
    trials1.drawPixel(Pixel(box1Color, box1Pos + Vector2(5,5)));
    trials1.drawPixel(Pixel(box2Color, box2Pos + Vector2(5,5)));
    trials2.drawPixel(Pixel(box3Color, box3Pos + Vector2(5,5)));
    trials2.drawPixel(Pixel(box4Color, box4Pos + Vector2(5,5)));

    // Clear trials from window/buffer
    if(tickPos == 299)
    {
        trials1.clear();
        trials2.clear();
    }
}

