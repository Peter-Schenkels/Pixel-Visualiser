#pragma once

#include <vector>

#include "../headers/vector3.hpp"


namespace PV
{
    typedef Vector3<float> Color;

    struct Pixel
    {
        Color color = {1,1,1};
        Vector2<int> position = {0,0};

        Pixel(const Color color, const Vector2<int> position):
            color(color),
            position(position)
        {
        }
    };

    class Buffer
    {
        int id;
        Vector2<int> size = Vector2(0, 0);
        Vector2<int> position = Vector2(0, 0);
        Vector2<float> pixelSize = Vector2(0.f, 0.f);

        std::vector<Pixel>& buffer;

    public:
        Buffer(const Vector2<int> size, const Vector2<float> pixelSize, const Vector2<int> position, const int id) :
            id(id),
            size(size),
            position(position),
            pixelSize(pixelSize),
            buffer(*new std::vector<Pixel>())
        {
        }

        void clear() const;
        void drawPixel(Pixel pixel) const;

        // Set position (based on buffer pixel size) of the buffer in the window
        void setPosition(const Vector2<int> pos) { position = pos; }

        [[nodiscard]] int getId() const { return id; }
        [[nodiscard]] std::vector<Pixel>& getPixels() const { return buffer; }
        [[nodiscard]] Vector2<float> getPixelSize() const { return pixelSize; }
        [[nodiscard]] Vector2<int> getPosition() const { return position; }
    };
}