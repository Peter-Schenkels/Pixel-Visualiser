#pragma once
#include <memory>
#include <string>
#include "vector3.hpp"

namespace PV
{
    class Window
    {
        std::string name;
        Vector2<int> size;
        Vector2<int> startPosition;

    public:
        Window(std::string name, const Vector2<int>& size, const Vector2<int>& startPosition);

        void display();

        void start() const;
    };
}