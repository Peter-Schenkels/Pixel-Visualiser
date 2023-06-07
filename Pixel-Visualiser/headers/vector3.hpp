#pragma once
#include "../headers/vector2.hpp"

namespace PV
{
    template<typename T>
    struct Vector3
    {
        T x;
        T y;
        T z;

        T r() const { return x; }
        T g() const { return y; }
        T b() const { return z; }

        Vector3<T> operator+(const Vector3<T>& rhs) const
        {
            return Vector3<T>{ x + rhs.x, y + rhs.y, z + rhs.z };
        }

        Vector3<T> operator-(const Vector3<T>& rhs) const
        {
            return Vector3<T>{ x - rhs.x, y - rhs.y, z - rhs.z };
        }

        Vector3<T> operator*(const Vector3<T>& rhs) const
        {
            return Vector3<T>{ x * rhs.x, y * rhs.y, z * rhs.z };
        }

        Vector3<T> operator/(const Vector3<T>& rhs) const
        {
            return Vector3<T>{ x / rhs.x, y / rhs.y, z / rhs.z };
        }

        //Operators for Vector3 and Vector2
        Vector3<T> operator+(const Vector2<T>& rhs) const
        {
            return Vector3<T>{ x + rhs.x, y + rhs.y, z };
        }

        Vector3<T> operator-(const Vector2<T>& rhs) const
        {
            return Vector3<T>{ x - rhs.x, y - rhs.y, z };
        }

        Vector3<T> operator*(const Vector2<T>& rhs) const
        {
            return Vector3<T>{ x * rhs.x, y * rhs.y, z };
        }

        Vector3<T> operator/(const Vector2<T>& rhs) const
        {
            return Vector3<T>{ x / rhs.x, y / rhs.y, z };
        }

        //Operators for Vector3 and T
        Vector3<T> operator+(const T& rhs) const
        {
            return Vector3<T>{ x + rhs, y + rhs, z + rhs };
        }

        Vector3<T> operator-(const T& rhs) const
        {
            return Vector3<T>{ x - rhs, y - rhs, z - rhs };
        }

        Vector3<T> operator*(const T& rhs) const
        {
            return Vector3<T>{ x * rhs, y * rhs, z * rhs };
        }

        Vector3<T> operator/(const T& rhs) const
        {
            return Vector3<T>{ x / rhs, y / rhs, z / rhs };
        }

        //Operators for Vector3 and Vector3
        Vector3<T>& operator+=(const Vector3<T>& rhs)
        {
            x += rhs.x;
            y += rhs.y;
            z += rhs.z;
            return *this;
        }

        Vector3<T>& operator-=(const Vector3<T>& rhs)
        {
            x -= rhs.x;
            y -= rhs.y;
            z -= rhs.z;
            return *this;
        }

        Vector3<T>& operator*=(const Vector3<T>& rhs)
        {
            x *= rhs.x;
            y *= rhs.y;
            z *= rhs.z;
            return *this;
        }

        Vector3<T>& operator/=(const Vector3<T>& rhs)
        {
            x /= rhs.x;
            y /= rhs.y;
            z /= rhs.z;
            return *this;
        }

        Vector3<T>& operator+=(const Vector2<T>& rhs)
        {
            x += rhs.x;
            y += rhs.y;
            return *this;
        }

        Vector3<T>& operator-=(const Vector2<T>& rhs)
        {
            x -= rhs.x;
            y -= rhs.y;
            return *this;
        }

        Vector3<T>& operator*=(const Vector2<T>& rhs)
        {
            x *= rhs.x;
            y *= rhs.y;
            return *this;
        }

        Vector3<T>& operator/=(const Vector2<T>& rhs)
        {
            x /= rhs.x;
            y /= rhs.y;
            return *this;
        }

        //Create operators for Vector3 and T
        Vector3<T>& operator+=(const T& rhs)
        {
            x += rhs;
            y += rhs;
            z += rhs;
            return *this;
        }

        Vector3<T>& operator-=(const T& rhs)
        {
            x -= rhs;
            y -= rhs;
            z -= rhs;
            return *this;
        }

        Vector3<T>& operator*=(const T& rhs)
        {
            x *= rhs;
            y *= rhs;
            z *= rhs;
            return *this;
        }

        Vector3<T>& operator/=(const T& rhs)
        {
            x /= rhs;
            y /= rhs;
            z /= rhs;
            return *this;
        }
    };
}
