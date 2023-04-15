#include <iostream>
#include <headers/pixelVisualiser.hpp>

void PV::PixelVisualiser::loop()
{
    std::cout << "Hello World";
}

void PV::PixelVisualiser::main()
{
    createWindow("Hello", { 500, 500 }, { 100, 100 });
    createWindow("World", { 500, 500 }, { 300, 300 });
}

int main(int argc, char** argv)
{
    PV::PixelVisualiser::start();
    return 0;
}
