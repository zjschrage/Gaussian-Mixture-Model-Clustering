#pragma once
#include <cstdlib>

struct Vector2D {
    float a, b;

    Vector2D() : a(0), b(0) {}
    Vector2D(float a, float b) : a(a), b(b) {}
    Vector2D operator+(const Vector2D& v) const { return Vector2D(a + v.a, b + v.b);}
    Vector2D operator-(const Vector2D& v) const { return Vector2D(a - v.a, b - v.b);}
    Vector2D operator*(float s) const { return Vector2D(a*s, b*s);}
    float operator*(const Vector2D& v) const { return a*v.a + b*v.b;}

    void set(float a, float b) {
        this->a = a;
        this->b = b;
    }
};


