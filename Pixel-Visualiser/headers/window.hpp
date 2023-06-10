#pragma once
#include <map>
#include <memory>
#include <string>

#include "buffer.hpp"
#include "vector2.hpp"

namespace PV
{
    class Window
    {
        friend class PixelVisualiser;

        std::string name;
        Vector2<int> size;
        Vector2<int> startPosition;
        std::vector<int> bufferStack;
        int identifier{};

        void start();

        void display() const;

    public:

        int getId() const { return identifier; }

        Window(std::string name, const Vector2<int>& size, const Vector2<int>& startPosition);

        void focus(const Buffer& buffer);

        void unfocusAll() { bufferStack.clear(); }

        bool unfocus(const Buffer& buffer) { return std::remove(bufferStack.begin(), bufferStack.end(), buffer.getId()) != bufferStack.end(); }
    };
}