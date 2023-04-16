#include "../headers/buffer.hpp"

void PV::Buffer::clearBuffer() const
{
    buffer.clear();
}

void PV::Buffer::drawPixel(const Pixel pixel) const
{
       buffer.push_back(pixel);
}
