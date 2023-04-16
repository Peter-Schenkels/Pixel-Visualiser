#pragma once
#include <map>
#include <memory>
#include <string>

#include "buffer.hpp"
#include "vector3.hpp"

namespace PV
{
    class Window
    {
        int idCounter = 0;
        std::string name;
        Vector2<int> size;
        Vector2<int> startPosition;
        std::map<int, std::shared_ptr<Buffer>> buffers;

        std::vector<int> bufferStack;


    public:
        Window(std::string name, const Vector2<int>& size, const Vector2<int>& startPosition);

        void display() const;

        void start() const;

        [[nodiscard]] Buffer& createBuffer(Vector2<int> position, Vector2<float> pixelSize);

        void draw(const Buffer& buffer);

        void clear() { bufferStack.clear(); }
    };
}