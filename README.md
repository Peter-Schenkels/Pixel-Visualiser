# Pixel Visualiser

Pixel Visualiser is a lightweight C++ graphics library designed for rendering pixel-based visuals on the screen. It's built upon OpenGL Utility Toolkit (GLUT). This library abstracts the complexities of direct OpenGL and GLUT interactions, providing a more easier-to-use API.

## Features

- Easy-to-use pixel drawing interface
- Individual control of each pixel.
- Buffer sharing between windows.

![Colored Squares Example](Examples/Colored%20Squares/squares.gif)

## Quick Start

```cpp
#include "headers/pixelVisualiser.hpp"
#include "headers/window.hpp"

// Define a buffer and a window (pos, borders(wip), pixel size)
static PV::Buffer& buffer = PV::PixelVisualiser::createBuffer({ 0, 0 }, { 1, 1 }, { 10, 10 });

// Define a window (title, size, position)
static PV::Window& window = PV::PixelVisualiser::createWindow("Simple Example!", { 200, 200 }, { 100, 100 });

// This function is called when PV::PixelVisualiser::execute() is called.
void PV::PixelVisualiser::start()
{
	// Add the buffer to the window for rendering
	window.focus(buffer);
}

// This function is called for each frame of the rendering loop.
void PV::PixelVisualiser::loop()
{
	// Clear the buffer at the beginning of each frame
	buffer.clear();

	// Set the position of the buffer in the window (units are in pixels)
	buffer.setPosition(Vector2(10, 10));

	// Define a pixel color (red)
	const auto pixelColor = Color{ 1, 0, 0 };

	// Draw a pixel at position (1, 1) in the buffer with the defined color
	buffer.drawPixel(Pixel(pixelColor, Vector2(1, 1)));
}

// Entry point for the program
int main()
{
	// Begin the rendering loop
	PV::PixelVisualiser::execute();
	return 0;
}
```

## Example

In this project, we've created an example that demonstrates the creation of multiple buffers and windows, movement, and color changes over time. Refer to `main.cpp` for a detailed view.

## Building

This project uses a CMake-based build system. Ensure you have a C++ compiler and CMake installed on your system to build it.

```shell
mkdir build
cd build
cmake ..
make
```

Then, you can run the example with:

```shell
./PixelVisualiser
```

## Dependencies

- A modern C++ compiler with C++17 support.
- CMake 3.8 or higher.
- FreeGLUT for handling windowing and input.

## Contributing

Contributions are welcome. Please submit a pull request or create an issue for any improvements or bug fixes.

## License

This project is licensed under the MIT License. See `LICENSE` for more details.
